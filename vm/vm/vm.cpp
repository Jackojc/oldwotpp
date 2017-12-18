#ifndef VM_CPP
#define VM_CPP

#include "vm.h"

namespace wot {

    vm::vm(
        wot::stack_group& stks,
        const wot::op_group& ops,
        std::string& cde
    ):
        stacks(stks),
        operations(ops)
    {
        code = reinterpret_cast<wot::code>(
            new char[cde.size()]
        );

        std::copy(cde.begin(), cde.end(), code);

        ip = code;
    }

    vm::~vm() {
        delete code;
    }

    void vm::execute(char terminator) {
        while (*ip != terminator) {
            ip = operations[*ip](ip, stacks);
        }
    }

}

#endif