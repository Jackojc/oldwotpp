#ifndef WOTPP_TYPES_H
#define WOTPP_TYPES_H


#include <string>
#include <array>
#include <cstdint>
#include "../stack_group/stack_group.h"


namespace wotpp {
    using ptr = uint8_t*;
    using instr_ptr = wotpp::ptr;

    using heap = std::vector<wotpp::obj_t>;

    using op = void(*)(
        wotpp::instr_ptr&,
        wotpp::instr_ptr,
        wotpp::stack_group&,
        wotpp::heap&,
        bool&
    );
    using op_group = std::array<wotpp::op, 256>;

    using code = std::string;
}


#endif