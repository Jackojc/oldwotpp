#ifndef STACK_GROUP_CPP
#define STACK_GROUP_CPP

#include "stack_group.h"

namespace wot {

    stack_group::stack_group(
        const std::unordered_map<uint8_t, wot::stack&>& group
    ) {
        // Place stacks at proper indexes.
        stacks.resize(group.size());
        for (auto& x: group) {
            stacks[x.first] = &x.second;
        }
    }

    wot::stack& stack_group::operator[](int index) {
        return *stacks[index];
    }

}

#endif