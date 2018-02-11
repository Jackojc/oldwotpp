#ifndef WOTPP_VM_CPP
#define WOTPP_VM_CPP

#include <iostream>
#include <thread>
#include <chrono>


#include "vm.h"


namespace wotpp {
    void execute(
        wotpp::stack_group& stacks,
        wotpp::heap& heap,
        const wotpp::op_group& operations,
        wotpp::code& code
    ) {
        bool running = true;

        // Set instruction pointer to the start of the code.
        wotpp::instr_ptr ip = (uint8_t*)&code[0];
        wotpp::instr_ptr initial_d = (uint8_t*)&code[0];

        do {
            //std::cerr << "\nOPCODE: " << (int)*ip << std::endl;
            operations[*ip](ip, initial_d, stacks, heap, running);
            //std::this_thread::sleep_for(std::chrono::milliseconds(200));
        } while (running);
    }
}


#endif