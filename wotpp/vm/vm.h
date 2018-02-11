#ifndef WOTPP_VM_H
#define WOTPP_VM_H


#include "../utils/types.h"


namespace wotpp {
    void execute(
        wotpp::stack_group& stacks,
        wotpp::heap& heap,
        const wotpp::op_group& operations,
        wotpp::code& code
    );
}


#endif