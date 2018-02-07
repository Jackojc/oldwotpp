#ifndef WOTPP_STACK_GROUP_H
#define WOTPP_STACK_GROUP_H


#include <unordered_map>
#include <vector>
#include <stdint.h>
#include "../stack/stack.h"


namespace wotpp {
    struct stack_group {
        std::vector<wotpp::stack*> stacks;


        stack_group(const std::unordered_map<uint8_t, wotpp::stack&>& group);


        wotpp::stack& operator[](int index);
    };
}


#endif