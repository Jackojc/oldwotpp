import copy
import codecs


def strip_single_comments(code, persist):
    code = code.split('\n');

    for i, line in enumerate(code):
        if "//" in line:
            line = line.split("//")[0]

        code[i] = line

    return '\n'.join(code)


def strip_multi_comments(code, persist):
    new_code = ""
    in_comment = False
    i = 0

    while i < len(code):
        char = code[i]

        # Start of comment and not already inside a comment.
        if char[i:i+1] == "/*" and not in_comment:
            in_comment = True


        # End of comment and already inside a comment.
        elif char[i:i+1] == "*/" and in_comment:
            in_comment = False
            i += 3
            continue

        # Only append characters _not_ inside the comment.
        if not in_comment:
            new_code += char

        i += 1

    return new_code


def strip_comments(code, persist):
    code = strip_single_comments(code, persist)
    code = strip_multi_comments(code, persist)

    return code


def format_statements(code, persist):
    code = code.split(';')[:-1]

    for i, statement in enumerate(code):
        code[i] = statement.strip().split("->")
        code[i] = [x.strip() for x in code[i]]

    return code


def format_arguments(statements, persist):
    for i, statement in enumerate(statements):
        if len(statements[i]) > 1:
            args = statements[i][1]
            args = args[1:-1]
            args = args.split(',')

            for x, arg in enumerate(args):
                arg = arg.strip()

                if arg.isdigit():
                    arg = int(arg)

                args[x] = arg

            statements[i][1] = args

    return statements


def fill_empty_arguments(statements, persist):
    for i, token in enumerate(statements):
        if len(token) == 1:
            statements[i].append([])

    return statements


def tokenise_statements(statements, persist):
    tokens = []

    for statement in statements:
        op, args = statement
        token = {}

        if op[:2] == "::":
            token = copy.deepcopy(persist["token_type"])

            token["type"] = persist["dir_typename"]
            token["body"]["name"] = op[2:]
            token["body"]["args"] = args

        else:
            token = copy.deepcopy(persist["token_type"])

            token["type"] = persist["op_typename"]
            token["body"]["name"] = op
            token["body"]["args"] = args

        tokens.append(token)

    return tokens


def match_token_ids(tokens, persist):
    for i, token in enumerate(tokens):
        if token["type"] == persist["op_typename"]:
            token["body"]["name"] = persist["opcodes"][token["body"]["name"].upper()]

        elif token["type"] == persist["dir_typename"]:
            token["body"]["name"] = persist["directives"][token["body"]["name"].upper()]

    return tokens


def is_char(arg):
    char = codecs.decode(arg, "unicode_escape")

    if char[::len(char) - 1] == "''":
        if len(char[1:-1]) == 1:
            return True

    return False


def is_string(arg):
    char = codecs.decode(arg, "unicode_escape")

    if char[::len(char) - 1] == '""':
        if len(char[1:-1]) > 1:
            return True

    return False


def tokenise_args(tokens, persist):
    for i, token in enumerate(tokens):
        args = token["body"]["args"]

        for x, arg in enumerate(args):
            if isinstance(arg, int):
                args[x] = {
                    "type" : persist["number_typename"],
                    "value" : arg
                }

            else:
                if is_char(arg):
                    args[x] = {
                        "type" : persist["char_typename"],
                        "value" : arg
                    }

                elif is_string(arg):
                    args[x] = {
                        "type" : persist["string_typename"],
                        "value" : arg
                    }

                else:
                    args[x] = {
                        "type" : persist["label_typename"],
                        "value" : arg
                    }

        tokens[i]["body"]["args"] = args

    return tokens


def parse_strings(tokens, persist):
    new_tokens = []

    for token in tokens:
        if token["type"] == persist["op_typename"]:
            args = token["body"]["args"]
            new_token = token
            contains_string = False

            for i, arg in enumerate(args):
                if arg["type"] == persist["string_typename"]:
                    contains_string = True

                    for char in codecs.decode(
                        arg["value"][1:-1],
                        "unicode_escape"
                    ):
                        char = char.encode('unicode_escape').decode()
                        new_token = copy.deepcopy(token)

                        new_token["body"]["args"][i]["type"] = persist["char_typename"]
                        new_token["body"]["args"][i]["value"] = "'{}'".format(char)

                        new_tokens.append(new_token)

            if not contains_string:
                new_tokens.append(token)

        else:
            new_tokens.append(token)

    return new_tokens


def parse_chars(tokens, persist):
    for i, token in enumerate(tokens):
        if token["type"] == persist["op_typename"]:
            args = token["body"]["args"]

            for x, arg in enumerate(args):
                if arg["type"] == persist["char_typename"]:
                    char = codecs.decode(arg["value"][1:-1], "unicode_escape")
                    args[x]["value"] = char

            token["body"]["args"] = args

    return tokens


def encode_chars(tokens, persist):
    for i, token in enumerate(tokens):
        if token["type"] == persist["op_typename"]:
            args = token["body"]["args"]

            for x, arg in enumerate(args):
                if arg["type"] == persist["char_typename"]:
                    args[x]["value"] = ord(arg["value"])

            token["body"]["args"] = args

    return tokens


def find_label_positions(tokens, persist):
    labels = {}
    opcodes = []

    bytes_so_far = 0

    for token in tokens:
        if token["type"] == persist["dir_typename"]:
            for arg in token["body"]["args"]:
                labels[arg["value"]] = bytes_so_far

        elif token["type"] == persist["op_typename"]:
            bytes_so_far += (1 + len(token["body"]["args"]))
            opcodes.append(token)

    persist["labels"] = labels

    return opcodes


def parse_label_usage(tokens, persist):
    for i, token in enumerate(tokens):
        if token["type"] == persist["op_typename"]:
            args = token["body"]["args"]

            for x, arg in enumerate(args):
                if arg["type"] == persist["label_typename"]:
                    #print(token, arg)
                    args[x]["value"] = persist["labels"][arg["value"]]

            token["body"]["args"] = args

    return tokens


def reduce(tokens, persist):
    bytecode = []

    for token in tokens:
        op = token["body"]["name"]
        args = token["body"]["args"]

        bytecode.append(op)

        for arg in args:
            bytecode.append(arg["value"])

    return bytecode


def debug(tokens, persist):
    print(tokens)
    return tokens