#ifndef VM_CPP
#define VM_CPP

#include "vm.h"

namespace wot {

    vm::vm(
        wot::stack_group& stks,
        const wot::op_group& ops,
        wot::code& cde
    ):
        stacks(stks),
        operations(ops),
        code(cde)
    {}

    void vm::execute() {
        bool running = true;

        // Set instruction pointer to the start of the code.
        wot::instr_ptr ip = (uint8_t*)&code[0];

        do {
            std::tie(running, ip) = operations[*ip](ip, stacks);
        } while (running);
    }

}

#endif