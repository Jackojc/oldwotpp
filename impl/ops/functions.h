OPERATION(op_call) {
    uint8_t stack_id = *(ip + 1);
    int8_t addr      = *(ip + 2);

    wotpp::obj_t o;

    // save current instruction pointer to stack.
    o.type = wotpp::TYPE::PTR;
    o.ptr = static_cast<void*>(ip + 3);

    stacks[stack_id].push(o);

    ip = initial_ip + addr;
}


OPERATION(op_ret) {
    uint8_t stack_id = *(ip + 1);
    wotpp::obj_t o = stacks[stack_id].pop();

    ip = static_cast<uint8_t*>(o.ptr);
}