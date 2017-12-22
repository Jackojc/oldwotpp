#ifndef STACK_CPP
#define STACK_CPP

#include "stack.h"

namespace wot {

    stack::stack(int s):
        top(0),
        size(s)
    {
        stk.resize(size);
    }

    int stack::push(wot::obj_t* o) {
        stk[top++] = o;
        return top;
    }

    wot::obj_t stack::pop() {
        wot::obj_t* old_o = stk[--top];
        wot::obj_t new_o(*old_o);
        delete old_o;
        return new_o;
    }

    wot::obj_t* stack::peek(int i) {
        return stk[i];
    }

    wot::obj_t* stack::peek() {
        return stk[top - 1];
    }

}

#endif