#include <iostream>
#include <chrono>

#include "wot.h"


// USAGE MESSAGE
void usage() {
    std::cout << "usage: <file>\n";
}


// No operation. (skip)
wot::op_return op_nop(wot::instr_ptr ip, wot::stack_group& stacks) {
    return {true, ip + 1};
}


// When encountered, halt the machine and exit.
wot::op_return op_halt(wot::instr_ptr ip, wot::stack_group& stacks) {
    return {false, ip};
}


int main(int argc, const char* argv[]) {

    // Load file.
    bool success;
    std::string code;

    // Make sure the correct number of arguments have been provided.
    if (argc != 2) {
        usage();
        return -1;
    }

    // Attempt to read a file and check if it was successful.
    std::tie(success, code) = wot::read_file(argv[1]);

    // If we cannot open the file, show an error.
    if (!success) {
        std::cerr << "Cannot open file!\n";
        usage();
        return -1;
    }

    // Setup stacks
    wot::stack global(256);
    wot::stack local(32);
    wot::stack args(32);
    wot::stack returns(256);

    // Assign stack objects to IDS
    wot::stack_group stacks({
        {LOCAL, local},
        {GLOBAL, global},
        {RETURN, returns},
        {ARGS, args}
    });

    // Create array for instructions.
    wot::op_group ops;

    // Fill operations array with default instruction.
    // This means if it encounters an instruction it
    // doesn't understand, it will skip it.
    std::fill(ops.begin(), ops.end(), op_nop);

    // Setup operations.
    ops[0] = op_push_global_uint8_1;
    ops[20] = op_push_global_int8_1;
    ops[30] = op_push_global_uint32_1;

    ops[100] = op_emit_global_uint32_1;
    ops[101] = op_emit_global_uint8_1;
    ops[101] = op_emit_global_int8_1;

    ops[200] = op_push_global_str;
    ops[201] = op_emit_global_str;

    ops[255] = op_halt;

    // Run the VM.
    wot::vm interpreter(stacks, ops, code);

    auto start = std::chrono::high_resolution_clock::now();
    interpreter.execute(); // Run the code.
    auto end = std::chrono::high_resolution_clock::now();

    std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << "ns" << std::endl;

    return 0;
}