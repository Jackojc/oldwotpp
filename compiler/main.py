#!/usr/bin/env python
import os
import sys

import passes


OPCODE_DICT = {
    "PSHL" : 0,
    "PUSH" : 1,
    "STOR" : 2,
    "POP" : 3,

    "PRNT" : 4,
    "EMIT" : 5,
    "PRNL" : 6,
    "EMTL" : 7,

    "SUM" : 8,
    "PROD" : 9,

    "ADD" : 10,
    "SUB" : 11,
    "MUL" : 12,
    "DIV" : 13,
    "MOD" : 14,
    "NEG" : 15,
    "INCR" : 16,
    "DECR" : 17,

    "LSHF" : 18,
    "RSHF" : 19,
    "LROT" : 20,
    "RROT" : 21,

    "AND" : 22,
    "OR" : 23,
    "XOR" : 24,
    "NOT" : 25,

    "ALL" : 26,
    "ANY" : 27,

    "CMEQ" : 28,
    "CMNL" : 29,
    "CMLT" : 30,
    "CMMT" : 31,

    "JUMP" : 32,
    "JPEQ" : 33,
    "JPNL" : 34,

    "JMPR" : 35,
    "JREQ" : 36,
    "JRNL" : 37,

    "CALL" : 38,
    "RET" : 39,

    "HALT" : 40,
    "NOOP" : 41
}


PERSIST = {
    "opcodes" : OPCODE_DICT,
    "labels" : {},
    "functions" : {},

    "whitelist" : [x for x in
        "abcdefghijklmnopqrstuvwxyz\
        ABCDEFGHIJKLMNOPQRSTUVWXYZ\
        0123456789\
         ,->:[]_'\"\\"
    ],

    "tokens" : {
        "single_comment" : "//",
        "multi_comment" : ["/*", "*/"],
        "label" : "::",
        "character" : "'",
        "string" : '"'
    }
}


FUNCTIONS = [
    passes.remove_comments,
    passes.split_statements,
    passes.sanitise,
    passes.tokenise,
    passes.print_tokens,
    passes.match_opcodes,
    passes.expand_strings_to_characters,
    passes.convert_character_literals,
    passes.get_label_positions,
    passes.parse_label_usage,
    passes.parse_to_bytecode,
    passes.print_bytecode
]


def usage():
    print("usage: <input> <output>")


def run_pipeline(code, pipeline, persist = {}):
    c = code

    for fn in pipeline:
        c = fn(c, persist)

    return c


def run():

    # Check for valid cmdline parameters.
    if len(sys.argv) > 1 and len(sys.argv) < 4:
        inf = sys.argv[1]
        ouf = sys.argv[2]

    else:
        usage()
        return -1;

    # Open input file.
    with open(inf, 'r') as f:
        code = f.read()

    # If there is no code in the file, raise an error.
    if len(code) == 0 or code.isspace():
        raise ValueError("Empty input file!")

    # If all is good, run the compiler and return bytecode.
    bytecode = bytearray(run_pipeline(code, FUNCTIONS, PERSIST))

    # Write bytes to output file.
    with open(ouf, "wb") as f:
        f.write(bytecode)


if __name__ == "__main__":
    run()

