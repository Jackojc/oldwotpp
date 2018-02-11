OPERATION(op_pshl) {
    uint8_t stack_id = *(ip + 1);
    int8_t x         = *(ip + 2);

    wotpp::obj_t o;

    o.type = wotpp::TYPE::CHR;
    o.chr  = x;

    stacks[stack_id].push(o);

    ip += 3;
}


OPERATION(op_push) {
    uint8_t stack_id = *(ip + 1);
    uint8_t addr     = *(ip + 2);
    uint8_t n        = *(ip + 3);

    for (int i = 0; i < n; ++i) {
        wotpp::obj_t o;

        o.type = wotpp::TYPE::CHR;
        o.chr  = heap[addr + i].chr;

        stacks[stack_id].push(o);
    }

    ip += 4;
}


OPERATION(op_stor) {
    uint8_t stack_id = *(ip + 1);
    uint8_t addr     = *(ip + 2);
    uint8_t n        = *(ip + 3);

    for (int i = 0; i < n; ++i) {
        wotpp::obj_t o = stacks[stack_id].pop();
        heap[addr + i] = o;
    }

    ip += 4;
}


OPERATION(op_pop) {
    uint8_t stack_id = *(ip + 1);
    uint8_t n        = *(ip + 2);

    for (int i = 0; i < n; ++i) {
        stacks[stack_id].pop();
    }

    ip += 3;
}