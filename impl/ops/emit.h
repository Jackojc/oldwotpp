#include <cstdio>


wotpp::op_return op_emit_global_uint32_1(
    wotpp::instr_ptr ip,
    wotpp::stack_group& stacks
) {
    wotpp::obj_t o = stacks[GLOBAL].pop();

    std::printf("%i", o.u32);

    return {true, ip + 1};
}


wotpp::op_return op_emit_global_uint8_1(
    wotpp::instr_ptr ip,
    wotpp::stack_group& stacks
) {
    wotpp::obj_t o = stacks[GLOBAL].pop();

    std::putchar(o.u8);

    return {true, ip + 1};
}


wotpp::op_return op_emit_global_int8_1(
    wotpp::instr_ptr ip,
    wotpp::stack_group& stacks
) {
    wotpp::obj_t o = stacks[GLOBAL].pop();

    std::putchar((char)o.i8);

    return {true, ip + 1};
}


wotpp::op_return op_emit_global_str(
    wotpp::instr_ptr ip,
    wotpp::stack_group& stacks
) {
    wotpp::obj_t o = stacks[GLOBAL].pop();

    std::printf("%s", static_cast<char*>(o.ptr));

    o.clean<char>();

    return {true, ip + 1};
}