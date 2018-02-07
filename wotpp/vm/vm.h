#ifndef WOTPP_VM_H
#define WOTPP_VM_H


#include <string>
#include <algorithm>
#include <iostream>
#include "../utils/types.h"


namespace wotpp {
    struct vm {
        wotpp::stack_group& stacks;
        const wotpp::op_group& operations;
        wotpp::code& code;


        vm(
            wotpp::stack_group& stks,
            const wotpp::op_group& ops,
            wotpp::code& cde
        );


        void execute();
    };
}


#endif