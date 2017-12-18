#ifndef VM_H
#define VM_H

#include <string>
#include <algorithm>

#include "../types.h"

namespace wot {

    struct vm {
        wot::stack_group& stacks;
        const wot::op_group& operations;
        wot::code code;
        wot::instr_ptr ip;

        vm(
            wot::stack_group& stks,
            const wot::op_group& ops,
            std::string& cde
        );
        ~vm();
        void execute(char terminator);
    };

}

#endif