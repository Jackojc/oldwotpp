OPERATION(op_add) {
    uint8_t stack_id = *(ip + 1);
    auto ab          = stacks[stack_id].pop(2);

    wotpp::obj_t o;

    o.type = wotpp::TYPE::CHR;
    o.chr  = ab[0].chr + ab[1].chr;

    stacks[stack_id].push(o);

    ip += 2;
}


OPERATION(op_sub) {
    uint8_t stack_id = *(ip + 1);
    auto ab          = stacks[stack_id].pop(2);

    wotpp::obj_t o;

    o.type = wotpp::TYPE::CHR;
    o.chr  = ab[0].chr - ab[1].chr;

    stacks[stack_id].push(o);

    ip += 2;
}


OPERATION(op_mul) {
    uint8_t stack_id = *(ip + 1);
    auto ab          = stacks[stack_id].pop(2);

    wotpp::obj_t o;

    o.type = wotpp::TYPE::CHR;
    o.chr  = ab[0].chr * ab[1].chr;

    stacks[stack_id].push(o);

    ip += 2;
}


OPERATION(op_div) {
    uint8_t stack_id = *(ip + 1);
    auto ab          = stacks[stack_id].pop(2);

    wotpp::obj_t o;

    o.type = wotpp::TYPE::CHR;
    o.chr  = ab[0].chr / ab[1].chr;

    stacks[stack_id].push(o);

    ip += 2;
}


OPERATION(op_mod) {
    uint8_t stack_id = *(ip + 1);
    auto ab          = stacks[stack_id].pop(2);

    wotpp::obj_t o;

    o.type = wotpp::TYPE::CHR;
    o.chr  = ab[0].chr % ab[1].chr;

    stacks[stack_id].push(o);

    ip += 2;
}


OPERATION(op_neg) {
    uint8_t stack_id = *(ip + 1);
    wotpp::obj_t x   = stacks[stack_id].pop();

    x.chr = -x.chr;

    stacks[stack_id].push(x);

    ip += 2;
}


OPERATION(op_incr) {
    uint8_t stack_id = *(ip + 1);
    uint8_t x        = *(ip + 2);
    wotpp::obj_t o   = stacks[stack_id].pop();

    o.chr += x;

    stacks[stack_id].push(o);

    ip += 3;
}


OPERATION(op_decr) {
    uint8_t stack_id = *(ip + 1);
    uint8_t x        = *(ip + 2);
    wotpp::obj_t o   = stacks[stack_id].pop();

    o.chr -= x;

    stacks[stack_id].push(o);

    ip += 3;
}