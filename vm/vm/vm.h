#ifndef VM_H
#define VM_H

#include <string>
#include <algorithm>
#include <iostream>
#include "../types.h"

namespace wot {

    struct vm {
        wot::stack_group& stacks;
        const wot::op_group& operations;
        wot::code& code;

        vm(
            wot::stack_group& stks,
            const wot::op_group& ops,
            wot::code& cde
        );


        void execute();
    };

}

#endif