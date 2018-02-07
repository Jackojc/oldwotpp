#ifndef WOTPP_STACK_CPP
#define WOTPP_STACK_CPP


#include "stack.h"


namespace wotpp {
    stack::stack(int s):
        top(0),
        size(s)
    {
        stk.resize(size);
    }


    int stack::push(wotpp::obj_t* o) {
        stk[top++] = o;
        return top;
    }


    wotpp::obj_t stack::pop() {
        wotpp::obj_t* old_o = stk[--top];
        wotpp::obj_t new_o(*old_o);
        delete old_o;
        return new_o;
    }


    wotpp::obj_t* stack::peek(int i) {
        return stk[i];
    }


    wotpp::obj_t* stack::peek() {
        return stk[top - 1];
    }
}


#endif