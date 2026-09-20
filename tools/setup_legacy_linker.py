import argparse
import hashlib
import os
import platform
import shlex
import shutil
import subprocess
import urllib.request
from pathlib import Path


BINUTILS_SHA256 = 'b8b6363121a99aaf0309d0a6f63a18c203ddbb34f53683c9a56d568be2b6a549'


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--root', type=Path, default=Path(__file__).resolve().parents[1])
    parser.add_argument('--prefix', type=Path)
    parser.add_argument('--build-dir', type=Path)
    parser.add_argument('--jobs', type=int, default=min(os.cpu_count() or 1, 8))
    args = parser.parse_args()
    root = args.root.resolve()
    prefix = (args.prefix or root / 'tools/legacy').resolve()
    work = (args.build_dir or root / 'build/linker-toolchain').resolve()
    if args.jobs < 1:
        parser.error('--jobs must be positive')
    machine = {'arm64': 'aarch64', 'AMD64': 'x86_64'}.get(platform.machine(), platform.machine())
    if platform.system() == 'Darwin':
        host = machine + '-apple-darwin'
    elif platform.system() == 'Linux':
        host = machine + '-pc-linux-gnu'
    else:
        parser.error('legacy linker setup supports Linux and macOS')
    work.mkdir(parents=True, exist_ok=True)
    log_path = work / 'setup.log'
    env = os.environ.copy()
    env.update(CC='cc -std=gnu89 -Wno-implicit-function-declaration -Wno-int-conversion', CFLAGS='-O2',
               lt_cv_sys_max_cmd_len=str(os.sysconf('SC_ARG_MAX') * 3 // 4))

    def run(command, directory=work):
        with log_path.open('a') as log:
            print(shlex.join(map(str, command)), file=log, flush=True)
            subprocess.run(list(map(str, command)), cwd=directory, env=env,
                           stdout=log, stderr=subprocess.STDOUT, check=True)

    def replace(path, before, after):
        text = path.read_text()
        if before in text:
            path.write_text(text.replace(before, after))
        elif after not in text:
            raise ValueError(f'{path}: expected source for host compatibility edit is absent')

    print('Building the historical COMMON-compatible linker', flush=True)
    archive = work / 'binutils-2.17.tar.bz2'
    if not archive.exists():
        temporary = archive.with_suffix('.download')
        with urllib.request.urlopen('https://ftp.gnu.org/gnu/binutils/binutils-2.17.tar.bz2') as response, temporary.open('wb') as output:
            shutil.copyfileobj(response, output)
        temporary.replace(archive)
    if hashlib.sha256(archive.read_bytes()).hexdigest() != BINUTILS_SHA256:
        raise ValueError(f'{archive}: SHA-256 differs from the pinned source')
    source = work / 'binutils-2.17'
    if not source.exists():
        run(['tar', '-xjf', archive, '-C', work])
    replace(source / 'config.sub', '| arm-*  | armbe-*', '| aarch64-* | arm-*  | armbe-*')
    if platform.system() == 'Darwin':
        replace(source / 'libiberty/strerror.c', 'extern int sys_nerr;', 'extern const int sys_nerr;')
    build = work / 'binutils-build'
    build.mkdir(exist_ok=True)
    run([source / 'configure', '--host=' + host, '--build=' + host,
         '--target=arm-elf', '--disable-nls', '--disable-shared', '--disable-werror'], build)
    run(['make', '-j' + str(args.jobs), 'all-ld'], build)
    (prefix / 'bin').mkdir(parents=True, exist_ok=True)
    linker = prefix / 'bin/arm-elf-ld'
    shutil.copy2(build / 'ld/ld-new', linker)
    print('Legacy linker installed in ' + str(prefix), flush=True)


if __name__ == '__main__':
    main()
