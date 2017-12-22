wot::op_return op_push_global_uint8_1(
    wot::instr_ptr ip,
    wot::stack_group& stacks
) {
    wot::obj_t* o = new wot::obj_t();

    o->type = wot::TYPE::U8;
    o->u8 = *(ip + 1);

    stacks[GLOBAL].push(o);

    return {true, ip + 2};
}


wot::op_return op_push_global_uint32_1(
    wot::instr_ptr ip,
    wot::stack_group& stacks
) {
    // Create object.
    wot::obj_t* o = new wot::obj_t();

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

    o->type = wot::TYPE::U32;
    o->u32 = ret;

    stacks[GLOBAL].push(o);

    return {true, ip + 5};
}






wot::op_return op_push_global_int8_1(
    wot::instr_ptr ip,
    wot::stack_group& stacks
) {
    wot::obj_t* o = new wot::obj_t();

    o->type = wot::TYPE::I8;
    o->i8 = *(ip + 1);

    stacks[GLOBAL].push(o);

    return {true, ip + 2};
}






wot::op_return op_push_global_str(
    wot::instr_ptr ip,
    wot::stack_group& stacks
) {
    wot::obj_t* o = new wot::obj_t();
    o->type = wot::TYPE::PTR;

    // Might want to change this later on to save on memory usage.
    char* str = new char[wot::STR_SIZE];

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