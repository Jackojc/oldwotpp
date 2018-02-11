OPERATION(op_jmpr) {
    int8_t x = *(ip + 1);

    ip += x;
}


OPERATION(op_jreq) {
    uint8_t stack_id = *(ip + 1);
    int8_t x         = *(ip + 2);
    wotpp::obj_t o   = stacks[stack_id].pop();

    if (o.chr)
        ip += x;
    else
        ip += 3;
}


OPERATION(op_jrnl) {
    uint8_t stack_id = *(ip + 1);
    int8_t x         = *(ip + 2);
    wotpp::obj_t o   = stacks[stack_id].pop();

    if (!o.chr)
        ip += x;
    else
        ip += 3;
}
