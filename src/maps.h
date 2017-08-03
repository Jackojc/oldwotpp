#ifndef WPP_MAPS_H
#define WPP_MAPS_H

namespace wpp {

    const std::unordered_map<char, ParserTokenCallback> CALLBACKS = {

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

        {'a', goto_a},
        {'b', goto_b},
        {'c', goto_c},
        {'d', goto_d},
        {'e', goto_e},
        {'f', goto_f},
        {'g', goto_g},
        {'h', goto_h},


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
        {'"', use_data_ptr},


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

    const std::unordered_map<char, PreprocessorTokenCallback> PRE_CALLBACKS = {
        {'@', include_file}
    };

}

#endif