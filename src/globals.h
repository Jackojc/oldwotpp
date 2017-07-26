// For the global data.
// Stack, Data array, registers etc etc.

#ifndef WPP_GLOBS
#define WPP_GLOBS


#include <array>
#include "stack.cpp"


namespace wpp {

    using DATATYPE = long int;

    constexpr unsigned int STACK_SIZE = 500;
    constexpr unsigned int DATA_SIZE  = 65536;
    constexpr unsigned int REG_SIZE   = 8;

    std::array<DATATYPE, REG_SIZE>   REGISTERS;
    std::array<DATATYPE, DATA_SIZE>  DATA;
    wpp::stack<DATATYPE, STACK_SIZE> STACK;

    unsigned int DATA_POINTER = 0;
    unsigned int REG_POINTER  = 0;


    enum Tokens: unsigned int {
        STACK_PUSH,
        STACK_POP,
        STACK_CLEAR,
        STACK_PEEK,

        REG_SET,
        REG_CLEAR,

        REG_INCR,
        REG_DECR,

        PRINT_RAW,
        PRINT_ASCII,
        INPUT,

        DATA_COPY,

        LABEL,
        GOTO,

        JUMP_IFZERO,
        JUMP_IFEQUAL,
        JUMP_IFMORE,
        JUMP_IFLESS
    };

}


#endif