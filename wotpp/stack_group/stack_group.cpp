#ifndef WOTPP_STACK_GROUP_CPP
#define WOTPP_STACK_GROUP_CPP


#include "stack_group.h"


namespace wotpp {
    stack_group::stack_group(
        const std::unordered_map<uint8_t, wotpp::stack&>& group
    ) {
        // Place stacks at proper indexes.
        stacks.resize(group.size());
        for (auto& x: group) {
            stacks[x.first] = &x.second;
        }
    }


    wotpp::stack& stack_group::operator[](int index) {
        return *stacks[index];
    }
}


#endif