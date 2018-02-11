import time
import codecs
import copy






# Utility functions
def get_string_from_quotes(
    code,
    quote_character = '"',
    escape_character = '\\'
):
    string = ""
    i = 0

    while i < len(code):
        char = code[i]

        if char == escape_character and \
            code[i + 1] == quote_character:
            i += 1

        string += char
        i += 1

    return string












def remove_single_comments(code, persist):
    """Remove single comment strings from the code."""

    print("[*] removing single line comments...")

    token_indicators = persist["tokens"]
    new_code = []

    for line in code.split('\n'):
        if token_indicators["single_comment"] in line:
            line = line.split(token_indicators["single_comment"])[0]

        new_code.append(line)

    return '\n'.join(new_code)


def remove_multi_comments(code, persist):
    """Remove multi-line comment strings from the code."""

    print("[*] removing multi line comments...")

    token_indicators = persist["tokens"]
    new_code = ""
    in_comment = False
    i = 0

    open_token = token_indicators["multi_comment"][0]
    close_token = token_indicators["multi_comment"][1]

    while i < len(code):
        char = code[i]

        # Start of comment and not already inside a comment.
        if char[i:i+1] == open_token and not in_comment:
            in_comment = True


        # End of comment and already inside a comment.
        elif char[i:i+1] == close_token and in_comment:
            in_comment = False
            i += 3
            continue

        # Only append characters _not_ inside the comment.
        if not in_comment:
            new_code += char

        i += 1

    return new_code


def remove_comments(code, persist):
    code = remove_single_comments(code, persist)
    code = remove_multi_comments(code, persist)
    return code























def sanitise(statements, persist):
    """Strip whitespace and blacklisted symbols from the code."""

    print("[*] sanitising code...")

    newcode = []
    whitelist = persist["whitelist"]

    for statement in statements:
        statement = statement.strip()
        statement = ''.join([x for x in statement if x in whitelist])
        newcode.append(statement)

    return newcode[:-1] # remove empty statement at the end...


def split_statements(code, persist):
    print("[*] seperating statements...")

    return code.split(";")



















def tokenise(statements, persist):
    """Convert the code string into a more rigid
    structure that is easier to parse"""

    print("[*] tokenising code...")

    token_indicators = persist["tokens"]
    tokens = []

    for statement in statements:
        if statement[:2] == token_indicators["label"]:  # label
            tokens.append({"type" : "LABEL", "name" : statement[2:]})

        else:  # operation
            if "->" in statement: # opcode with args
                op, args = statement.strip().split("->")
                args = args.strip()[1:-1]
                args = args.split(",")

                for i, arg in enumerate(args):
                    arg = arg.strip()

                    try: # try to convert arg to an int
                        arg = int(arg)

                    except: # or fallback to a string
                        pass

                    args[i] = arg

            else: # opcode without args
                op, args = statement, []

            tokens.append({"type" : "OPCODE", "name" : op.strip(), "args" : args})

    return tokens


def match_opcodes(tokens, persist):
    print("[*] converting strings to opcodes...")

    opcodes = persist["opcodes"]
    new_tokens = []

    # convert strings representing opcodes into their id.
    for token in tokens:
        name = token["name"]
        typename = token["type"]

        if typename == "OPCODE":
            token["name"] = opcodes[name.upper()]

        new_tokens.append(token)

    return new_tokens






def expand_strings_to_characters(statements, persist):
    print("[*] expanding strings...")

    quote = persist["tokens"]["string"]
    new_statements = []

    for statement in statements:
        if statement["type"] == "OPCODE":
            args = statement["args"]
            is_string = False

            for i, arg in enumerate(args):
                try:
                    if arg[0] == quote and arg[-1] == quote:
                        is_string = True

                        arg = arg[1:-1]
                        arg = codecs.decode(arg, "unicode_escape")
                        arg = arg[::-1]

                        for char in arg:
                            char = char.encode('unicode_escape').decode()
                            statement = copy.deepcopy(statement)
                            statement["args"][i] = f"'{char}'"
                            new_statements.append(statement)

                except TypeError:
                    pass

            if not is_string:
                new_statements.append(statement)

        else:
            new_statements.append(statement)

    return new_statements






def convert_character_literals(statements, persist):
    print("[*] converting character literals...")

    quote = persist["tokens"]["character"]

    for statement in statements:
        if statement["type"] == "OPCODE":
            args = statement["args"]

            for i, arg in enumerate(args):
                try:
                    if arg[0] == quote and arg[-1] == quote:
                        arg = codecs.decode(arg, "unicode_escape")
                        arg = ord(arg[1:-1])

                except TypeError:
                    continue


                args[i] = arg

    return statements














def get_label_positions(tokens, persist):
    """Get the position at which a label exists."""

    print("[*] getting label positions...")

    labels = {}
    opcodes = []

    bytes_so_far = 0

    for token in tokens:
        typename = token["type"]

        if typename == "LABEL":
            token["position"] = bytes_so_far
            labels[token["name"]] = token

        elif typename == "OPCODE": # if token type is OPCODE
            bytes_so_far += (1 + len(token["args"]))
            opcodes.append(token)

    persist["labels"] = labels

    return opcodes


def parse_label_usage(opcodes, persist):
    """Parse all usage of labels in arguments."""

    print("[*] parsing label usage in arguments...")

    labels = persist["labels"]

    opcodes_with_labels = []
    label_names = labels.keys()


    # Find out which opcodes are using labels.
    for i, op in enumerate(opcodes):
        for arg in op["args"]:
            if arg in label_names:
                opcodes_with_labels.append([arg, i])


    # Change the label string to a number.
    for op in opcodes_with_labels:
        lbl, index = op
        opcode_data = opcodes[index]
        args = opcode_data["args"]

        for i, arg in enumerate(args):
            if arg == lbl:
                args[i] = labels[lbl]["position"]

    return opcodes















def parse_to_bytecode(opcodes, persist):
    print("[*] flattening tokens to bytecode...")

    bytecode = []

    # flatten structure to 1D array.
    for opcode in opcodes:
        op, args = opcode["name"], opcode["args"]

        bytecode.extend([op, *args])

    return bytecode


def print_bytecode(bytecode, persist):
    print("code:", *bytecode, sep=' ')
    return bytecode


def print_tokens(tokens, persist):
    for token in tokens:
        if token["type"] == "OPCODE":
            print("{} {}".format(token["name"].upper(), ", ".join([str(x) for x in token["args"]])))

        elif token["type"] == "LABEL":
            print("::{}".format(token["name"]))

    return tokens

