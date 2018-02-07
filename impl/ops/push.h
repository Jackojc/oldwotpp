wotpp::op_return op_push_global_uint8_1(
    wotpp::instr_ptr ip,
    wotpp::stack_group& stacks
) {
    wotpp::obj_t* o = new wotpp::obj_t();

    o->type = wotpp::TYPE::U8;
    o->u8 = *(ip + 1);

    stacks[GLOBAL].push(o);

    return {true, ip + 2};
}


wotpp::op_return op_push_global_uint32_1(
    wotpp::instr_ptr ip,
    wotpp::stack_group& stacks
) {
    // Create object.
    wotpp::obj_t* o = new wotpp::obj_t();

    // Temporary buffer
    uint8_t buffer[4];

    buffer[0] = *(ip + 1);
    buffer[1] = *(ip + 2);
    buffer[2] = *(ip + 3);
    buffer[3] = *(ip + 4);

    uint32_t ret = 0;

    // Combine the 4 bytes into a single uint32
    for (size_t i = 0; i < 4; ++i) {
        ret = ret << 8;
        ret += buffer[i];
    }

    o->type = wotpp::TYPE::U32;
    o->u32 = ret;

    stacks[GLOBAL].push(o);

    return {true, ip + 5};
}






wotpp::op_return op_push_global_int8_1(
    wotpp::instr_ptr ip,
    wotpp::stack_group& stacks
) {
    wotpp::obj_t* o = new wotpp::obj_t();

    o->type = wotpp::TYPE::I8;
    o->i8 = *(ip + 1);

    stacks[GLOBAL].push(o);

    return {true, ip + 2};
}






wotpp::op_return op_push_global_str(
    wotpp::instr_ptr ip,
    wotpp::stack_group& stacks
) {
    wotpp::obj_t* o = new wotpp::obj_t();
    o->type = wotpp::TYPE::PTR;

    // Might want to change this later on to save on memory usage.
    char* str = new char[wotpp::STR_SIZE];

    int i = 1;
    char t;

    // Loop through all characters until we reach the null terminator.
    // Add them all to the array _including_ the null terminator.
    do {
        t = *(ip + i);
        str[i - 1] = t;
        i++;
    } while (t != '\0');

    // Cast char* to void* so we can store it in the obj_t.
    o->ptr = static_cast<void*>(str);

    stacks[GLOBAL].push(o);

    return {true, ip + i};
}