#include <iostream>
#include "wot.h"


// STACK IDS
enum STACK {
    LOCAL,
    GLOBAL,
    RETURN
};




// USAGE MESSAGE
void usage() {
    std::cout << "usage: <file>\n";
}





// OPERATIONS
// No operation. (skip)
wot::instr_ptr op_nop(wot::instr_ptr ip, wot::stack_group& stacks) {
    return ip + 1;
}

// Push a character to the global stack.
wot::instr_ptr op_push_global_char(
    wot::instr_ptr ip,
    wot::stack_group& stacks
) {
    wot::obj_t o;

    o.type = wot::TYPE::U8;
    o.u8 = *(ip + 1);

    stacks[GLOBAL].push(o);
    return ip + 2;
}

// Emit a character from the global stack.
wot::instr_ptr op_emit_global(
    wot::instr_ptr ip,
    wot::stack_group& stacks
) {
    wot::obj_t o = stacks[GLOBAL].pop();
    std::cout << o.u8;
    return ip + 1;
}





int main(int argc, const char* argv[]) {

    // Load file.
    bool success;
    std::string code;

    if (argc != 2) {
        usage();
        return -1;
    }

    // Attempt to read a file and check if it was successful.
    std::tie(success, code) = wot::read_file(argv[1]);

    if (!success) {
        std::cerr << "Cannot open file!\n";
        usage();
        return -1;
    }

    // Setup stacks
    wot::stack global(256);
    wot::stack local(32);
    wot::stack returns(256);

    // Assign stack objects to IDS
    wot::stack_group stacks({
        {LOCAL, local},
        {GLOBAL, global},
        {RETURN, returns}
    });

    // Fill operations array with default instruction.
    wot::op_group ops;
    std::fill(ops.begin(), ops.end(), op_nop);

    // Setup operations.
    ops['c'] = op_push_global_char;
    ops['e'] = op_emit_global;

    // Run the VM.
    wot::vm interpreter(stacks, ops, code);
    interpreter.execute('h');

    return 0;
}