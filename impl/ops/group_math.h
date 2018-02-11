OPERATION(op_sum) {
    uint8_t stack_id = *(ip + 1);
    uint8_t n        = *(ip + 2);

    int8_t tally = 0;

    for (int i = 0; i < n; ++i) {
        wotpp::obj_t o = stacks[stack_id].pop();

        tally += o.chr;
    }

    wotpp::obj_t o;

    o.type = wotpp::TYPE::CHR;
    o.chr  = tally;

    stacks[stack_id].push(o);

    ip += 3;
}


OPERATION(op_prod) {
    uint8_t stack_id = *(ip + 1);
    uint8_t n        = *(ip + 2);

    int8_t tally = 0;

    for (int i = 0; i < n; ++i) {
        wotpp::obj_t o = stacks[stack_id].pop();

        tally *= o.chr;
    }

    wotpp::obj_t o;

    o.type = wotpp::TYPE::CHR;
    o.chr  = tally;

    stacks[stack_id].push(o);

    ip += 3;
}