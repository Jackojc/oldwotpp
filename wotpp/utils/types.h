#ifndef WOTPP_TYPES_H
#define WOTPP_TYPES_H


#include <array>
#include <tuple>
#include <string>
#include <vector>
#include <stdint.h>
#include <stddef.h>
#include "../stack_group/stack_group.h"


namespace wotpp {
    using ptr = uint8_t*;
    using instr_ptr = wotpp::ptr;

    using op_return = std::tuple<bool, wotpp::instr_ptr>;
    using op = op_return(*)(ptr, wotpp::stack_group&);
    using op_group = std::array<wotpp::op, 256>;

    using code = std::string;
}


#endif