#ifndef STACK_H
#define STACK_H

#include <vector>
#include "../object/object.h"

namespace wot {

    struct stack {
        int top, size;
        std::vector<wot::obj_t*> stk;

        stack(int s);

        int push(wot::obj_t* o);
        wot::obj_t pop();
        wot::obj_t* peek(int i);
        wot::obj_t* peek();
    };

}

#endif