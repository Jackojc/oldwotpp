OPERATION(op_jump) {
    int8_t addr = *(ip + 1);

    ip = initial_ip + addr;
}


OPERATION(op_jpeq) {
    uint8_t stack_id = *(ip + 1);
    int8_t addr      = *(ip + 2);
    wotpp::obj_t o   = stacks[stack_id].pop();

    if (o.chr)
        ip = initial_ip + addr;
    else
        ip += 3;
}


OPERATION(op_jpnl) {
    uint8_t stack_id = *(ip + 1);
    int8_t addr      = *(ip + 2);
    wotpp::obj_t o   = stacks[stack_id].pop();

    if (!o.chr)
        ip = initial_ip + addr;
    else
        ip += 3;
}
