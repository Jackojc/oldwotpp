#ifndef WOTPP_VM_CPP
#define WOTPP_VM_CPP


#include "vm.h"


namespace wotpp {
    vm::vm(
        wotpp::stack_group& stks,
        const wotpp::op_group& ops,
        wotpp::code& cde
    ):
        stacks(stks),
        operations(ops),
        code(cde)
    {}


    void vm::execute() {
        bool running = true;

        // Set instruction pointer to the start of the code.
        wotpp::instr_ptr ip = (uint8_t*)&code[0];

        do {
            std::tie(running, ip) = operations[*ip](ip, stacks);
        } while (running);
    }
}


#endif