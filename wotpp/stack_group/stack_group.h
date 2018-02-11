#ifndef WOTPP_STACK_GROUP_H
#define WOTPP_STACK_GROUP_H


#include <vector>
#include "../stack/stack.h"


namespace wotpp {
    struct stack_group {
        std::vector<wotpp::stack> stacks;


        stack_group(const std::vector<wotpp::stack>& stacks_);


        wotpp::stack& operator[](int index);
    };
}


#endif