#ifndef WOTPP_STACK_GROUP_CPP
#define WOTPP_STACK_GROUP_CPP


#include "stack_group.h"


namespace wotpp {
    stack_group::stack_group(const std::vector<wotpp::stack>& stacks_):
        stacks(stacks_)
    {

    }

    wotpp::stack& stack_group::operator[](int index) {
        return stacks[index];
    }
}


#endif