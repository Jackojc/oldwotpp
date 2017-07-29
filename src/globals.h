// For the global data.
// Stack, Data array, registers etc etc.

#ifndef WPP_GLOBS
#define WPP_GLOBS


#include <array>
#include <string>
#include <unordered_set>
#include <unordered_map>

#include "constants.h"
#include "stack.cpp"
#include "functions.h"


namespace wpp {

    struct TokenPair {
        char op;
        std::string arg;
    };

    struct Function {
        std::string name;
        std::vector<wpp::TokenPair> tokens;
    };


    std::array<DATATYPE, REG_SIZE>   REGISTERS;
    std::array<DATATYPE, DATA_SIZE>  DATA;
    wpp::stack<DATATYPE, STACK_SIZE> STACK;

    const std::unordered_map<char, TokenCallback> CALLBACKS = {

        // FUNCTIONS
        {'#', exec},
        {'{', open_function},
        {'}', close_function},


        // BOOLEAN/BRANCHING
        {'!', not_sofast},
        {'(', open_if},
        {')', close_if},


        // LOOPING
        {'[', open_loop},
        {']', close_loop},


        // SETTERS
        {'=', set_cell},
        {'_', set_reg}, // WHAMMU


        // MATHS
        {'+', add_cell},
        {'-', sub_cell},
        {'*', mul_cell},
        {'/', div_cell},
        {'%', mod_cell},


        // INPUT/OUTPUT
        {':', out_raw_cell},
        {'.', out_ascii_cell},
        {',', getch_cell},


        // REGISTER SET/GET
        {'?', get_register},
        {'&', set_register},


        // STACK OPS
        {'~', push_reg},
        {'|', pop_reg},
        {'\\', peek_reg},


        // POINTER MANIPULATION
        {'^', up_cell},
        {'v', down_cell},
        {'$', set_data_pointer},
        {'r', set_reg_ptr},
        {'`', set_instr_pointer},


        // DO NOTHING WITH THIS
        {'<', do_nothing},
        {'>', do_nothing},

        {'0', do_nothing},   // SHIZZZZZZZA
        {'1', do_nothing},
        {'2', do_nothing},
        {'3', do_nothing},
        {'4', do_nothing},
        {'5', do_nothing},
        {'6', do_nothing},
        {'7', do_nothing},
        {'8', do_nothing},
        {'9', do_nothing},
        {'A', do_nothing},
        {'B', do_nothing},
        {'C', do_nothing},
        {'D', do_nothing},
        {'E', do_nothing},
        {'F', do_nothing},
        {'G', do_nothing},
        {'H', do_nothing},
        {'I', do_nothing},
        {'J', do_nothing},
        {'K', do_nothing},
        {'L', do_nothing},
        {'M', do_nothing},
        {'N', do_nothing},
        {'O', do_nothing},
        {'P', do_nothing},
        {'Q', do_nothing},
        {'R', do_nothing},
        {'S', do_nothing},
        {'T', do_nothing},
        {'U', do_nothing},
        {'V', do_nothing},
        {'W', do_nothing},
        {'X', do_nothing},
        {'Y', do_nothing},
        {'Z', do_nothing}

    };

    std::unordered_set<char> WHITELIST;
    std::unordered_map<std::string, wpp::Function> FUNC_DECLARATIONS;

    wpp::Function GLOB_FUNC;
    std::vector<wpp::TokenPair> TOKENS;


    /*enum Tokens: unsigned int {
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
    };*/


}


#endif