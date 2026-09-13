#!/usr/bin/env python3
import argparse
import ast
import hashlib
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent


def versions(root=ROOT):
    tree = ast.parse((Path(root) / "configure.py").read_text())
    for node in tree.body:
        if isinstance(node, ast.Assign) and any(getattr(t, "id", None) == "VERSIONS" for t in node.targets):
            return ast.literal_eval(node.value)
    raise SystemExit("error: VERSIONS not found in configure.py")


def resolve(version, root=ROOT):
    known = versions(root)
    if version in known:
        return version, *known[version]
    for name, (code, sha1) in known.items():
        if code == version:
            return name, code, sha1
    raise SystemExit(f"error: unknown version {version}; expected one of {', '.join(known)}")


def candidates(version, root=ROOT):
    name, code, _sha1 = resolve(version, root)
    root = Path(root)
    return [root / "roms" / f"{code}.gba", root / "build" / name / "verified.gba"]


def load(version, root=ROOT):
    name, code, sha1 = resolve(version, root)
    for path in candidates(name, root):
        if not path.exists():
            continue
        data = path.read_bytes()
        if hashlib.sha1(data).hexdigest() != sha1:
            raise SystemExit(f"error: {path} has SHA-1 {hashlib.sha1(data).hexdigest()}, expected {sha1} for {code}")
        return path, data
    return None, None


def missing_message(version, root=ROOT, purpose="this tool"):
    name, code, _sha1 = resolve(version, root)
    rom, verified = candidates(name, root)
    return (f"error: {purpose} needs {code} bytes: put the original ROM at {rom.relative_to(root)}"
            f" or build {name} once so {verified.relative_to(root)} exists")


def path(version, root=ROOT, purpose="this tool"):
    found, _data = load(version, root)
    if found is None:
        raise SystemExit(missing_message(version, root, purpose))
    return found


def read(version, root=ROOT, purpose="this tool"):
    found, data = load(version, root)
    if found is None:
        raise SystemExit(missing_message(version, root, purpose))
    return data


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("version")
    parser.add_argument("--purpose", default="this tool")
    args = parser.parse_args()
    print(path(args.version, purpose=args.purpose))


if __name__ == "__main__":
    sys.exit(main())
