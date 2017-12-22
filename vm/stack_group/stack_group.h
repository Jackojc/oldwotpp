#ifndef STACK_GROUP_H
#define STACK_GROUP_H

#include <unordered_map>
#include <vector>
#include <stdint.h>
#include "../stack/stack.h"

namespace wot {

    struct stack_group {
        std::vector<wot::stack*> stacks;

        stack_group(const std::unordered_map<uint8_t, wot::stack&>& group);

        wot::stack& operator[](int index);
    };

}

#endif