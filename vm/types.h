#ifndef TYPES_H
#define TYPES_H

    #include <array>
    #include <vector>
    #include <stdint.h>
    #include <stddef.h>

    #include "stack_group/stack_group.h"

    namespace wot {

        using ptr = uint8_t*;

        using op = ptr (*)(ptr, stack_group&);

        using op_group = std::array<op, 256>;

        using instr_ptr = ptr;

        using code = ptr;

    }

#endif