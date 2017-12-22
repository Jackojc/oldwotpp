def no_transform(code):
    return [int(x) for x in code.split(" ")]






FUNCTIONS = [
    no_transform
]


def run(code, pipeline = FUNCTIONS):
    c = code

    for fn in pipeline:
        c = fn(c)

    return c