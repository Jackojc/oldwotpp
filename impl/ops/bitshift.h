#include <cassert>


// Helper functions
int8_t rotl8b(int8_t x, int8_t n) {
    assert(n < 8);
    if (!n) return x;
    return (x << n) | (x >> (8 - n));
}


int8_t rotr8b(int8_t x, int8_t n) {
    assert(n < 8);
    if (!n) return x;
    return (x >> n) | (x << (8 - n));
}


// Operations
OPERATION(op_lshf) {
    uint8_t stack_id = *(ip + 1);
    uint8_t shift    = *(ip + 2);
    auto o           = stacks[stack_id].pop();

    o.chr <<= shift;

    stacks[stack_id].push(o);

    ip += 3;
}


OPERATION(op_rshf) {
    uint8_t stack_id = *(ip + 1);
    uint8_t shift    = *(ip + 2);
    auto o           = stacks[stack_id].pop();

    o.chr >>= shift;

    stacks[stack_id].push(o);

    ip += 3;
}


OPERATION(op_lrot) {
    uint8_t stack_id = *(ip + 1);
    uint8_t shift    = *(ip + 2);
    auto o           = stacks[stack_id].pop();

    o.chr = rotl8b(o.chr, shift);

    stacks[stack_id].push(o);

    ip += 3;
}


OPERATION(op_rrot) {
    uint8_t stack_id = *(ip + 1);
    uint8_t shift    = *(ip + 2);
    auto o           = stacks[stack_id].pop();

    o.chr = rotr8b(o.chr, shift);

    stacks[stack_id].push(o);

    ip += 3;
}