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


    int stack::push(const wotpp::obj_t& o) {
        stk[top++] = o;
        return top;
    }


    wotpp::obj_t stack::pop() {
        return stk[--top];
    }


    std::vector<wotpp::obj_t> stack::pop(int n) {
        std::vector<wotpp::obj_t> popped(n);


        for (int i = 0; i < n; ++i)
            popped[i] = pop();

        return popped;
    }


    const wotpp::obj_t& stack::peek(int i) {
        return stk[i];
    }


    const wotpp::obj_t& stack::peek() {
        return stk[top - 1];
    }
}


#endif