#ifndef WOTPP_STACK_H
#define WOTPP_STACK_H


#include <vector>
#include "../object/object.h"


namespace wotpp {
    struct stack {
        int top, size;
        std::vector<wotpp::obj_t*> stk;


        stack(int s);


        int push(wotpp::obj_t* o);
        wotpp::obj_t pop();
        wotpp::obj_t* peek(int i);
        wotpp::obj_t* peek();
    };
}


#endif