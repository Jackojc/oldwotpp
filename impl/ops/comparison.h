OPERATION(op_cmeq) {
    uint8_t stack_id = *(ip + 1);
    auto ab          = stacks[stack_id].pop(2);

    wotpp::obj_t o;

    o.type = wotpp::TYPE::CHR;
    o.chr  = ab[0].chr == ab[1].chr;

    stacks[stack_id].push(o);

    ip += 2;
}


OPERATION(op_cmnl) {
    uint8_t stack_id = *(ip + 1);
    auto ab          = stacks[stack_id].pop(2);

    wotpp::obj_t o;

    o.type = wotpp::TYPE::CHR;
    o.chr  = ab[0].chr != ab[1].chr;

    stacks[stack_id].push(o);

    ip += 2;
}


OPERATION(op_cmlt) {
    uint8_t stack_id = *(ip + 1);
    auto ab          = stacks[stack_id].pop(2);

    wotpp::obj_t o;

    o.type = wotpp::TYPE::CHR;
    o.chr  = ab[0].chr < ab[1].chr;

    stacks[stack_id].push(o);

    ip += 2;
}


OPERATION(op_cmmt) {
    uint8_t stack_id = *(ip + 1);
    auto ab          = stacks[stack_id].pop(2);

    wotpp::obj_t o;

    o.type = wotpp::TYPE::CHR;
    o.chr  = ab[0].chr > ab[1].chr;

    stacks[stack_id].push(o);

    ip += 2;
}
