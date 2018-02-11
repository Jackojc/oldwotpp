#include <cstdio>


OPERATION(op_emit) {
    uint8_t stack_id = *(ip + 1);
    uint8_t n        = *(ip + 2);

    for (int i = 0; i < n; ++i) {
        wotpp::obj_t o = stacks[stack_id].pop();
        std::printf("%i", o.chr);
    }

    ip += 3;
}


OPERATION(op_prnt) {
    uint8_t stack_id = *(ip + 1);
    uint8_t n        = *(ip + 2);

    for (int i = 0; i < n; ++i) {
        wotpp::obj_t o = stacks[stack_id].pop();
        std::putchar(o.chr);
    }

    ip += 3;
}


OPERATION(op_emtl) {
    int8_t x = *(ip + 1);

    std::printf("%i", x);

    ip += 2;
}


OPERATION(op_prnl) {
    int8_t x = *(ip + 1);

    std::putchar(x);

    ip += 2;
}