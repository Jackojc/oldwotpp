#ifndef TYPES_H
#define TYPES_H

    #include <array>
    #include <tuple>
    #include <string>
    #include <vector>
    #include <stdint.h>
    #include <stddef.h>
    #include "stack_group/stack_group.h"

    namespace wot {

        using ptr = uint8_t*;
        using instr_ptr = wot::ptr;

        using op_return = std::tuple<bool, wot::instr_ptr>;
        using op = op_return(*)(ptr, wot::stack_group&);
        using op_group = std::array<wot::op, 256>;

        using code = std::string;

    }

#endif