import os
import sys

import passes

DEBUG = True


def usage():
    print("usage: <input> <output>")


def run():
    if len(sys.argv) > 1 and len(sys.argv) < 4 and not DEBUG:
        inf = sys.argv[1]
        ouf = sys.argv[2]

    elif not DEBUG:
        usage()
        return

    else:
        inf = "../scripts/test.wot"
        ouf = "../bin/test.wb"

    with open(inf, 'r') as f:
        code = f.read()

    bytecode = bytearray(passes.run(code))

    with open(ouf, "wb") as f:
        f.write(bytecode)


if __name__ == "__main__":
    run()


#data = bytearray([20, 10, 30, 0, 0, 0, 0, 100, 101, 255])