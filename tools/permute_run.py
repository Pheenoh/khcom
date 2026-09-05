#!/usr/bin/env python3
import os
import signal
import subprocess
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
PERMUTER = os.path.join(REPO, "tools", "decomp-permuter", "permuter.py")
PYTHON = os.path.join(REPO, ".venv", "bin", "python3")


def run(args, budget=None, log=None):
    env = dict(os.environ, TMPDIR=os.path.join(REPO, "permuter", "tmp"))
    os.makedirs(env["TMPDIR"], exist_ok=True)
    p = subprocess.Popen([PYTHON, PERMUTER] + list(args), cwd=REPO, env=env,
                         stdout=log, stderr=subprocess.STDOUT if log else None,
                         start_new_session=True)

    try:
        return p.wait(timeout=budget)
    except subprocess.TimeoutExpired:
        os.killpg(p.pid, signal.SIGTERM)

        try:
            p.wait(timeout=15)
        except subprocess.TimeoutExpired:
            os.killpg(p.pid, signal.SIGKILL)
            p.wait()
        return 124


def main():
    args = sys.argv[1:]
    budget = None

    if args and args[0] == "--budget":
        budget = float(args[1])
        args = args[2:]
    sys.exit(run(args, budget))


if __name__ == "__main__":
    main()
