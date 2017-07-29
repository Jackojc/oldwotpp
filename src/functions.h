// For the functions used in the parser.

#ifndef WPP_FUNCS_H
#define WPP_FUNCS_H

#include <math.h>

#include "constants.h"



namespace wpp {

    // BUILT INS
    inline void do_nothing(std::string arg = "-1") noexcept;
    inline void do_something(std::string arg = "-1") noexcept;
    inline void initialise() noexcept;


    // PARSER FUNCS
    inline void set_data_cell(const wpp::DATATYPE& value, unsigned int index = wpp::DATA_POINTER) noexcept;
    inline wpp::DATATYPE get_data_cell(unsigned int index = wpp::DATA_POINTER) noexcept;

    inline void set_reg_cell(const wpp::DATATYPE& value, unsigned int index = wpp::REG_POINTER) noexcept;
    inline wpp::DATATYPE get_reg_cell(unsigned int index = wpp::REG_POINTER) noexcept;


    // FUNCTIONS
    inline void exec(std::string arg = "-1") noexcept;
    inline void open_function(std::string arg = "-1") noexcept;
    inline void close_function(std::string arg = "-1") noexcept;


    // BRANCHING/BOOLEAN
    inline void not_sofast(std::string arg = "-1") noexcept;

    inline void open_if(std::string arg = "-1") noexcept;
    inline void close_if(std::string arg = "-1") noexcept;


    // LOOPING
    inline void open_loop(std::string arg = "-1") noexcept;
    inline void close_loop(std::string arg = "-1") noexcept;


    // POINTERS
    inline void set_reg_ptr(std::string arg = "-1") noexcept;
    inline void set_data_pointer(std::string arg = "-1") noexcept;
    inline void set_instr_pointer(std::string arg = "-1") noexcept;
    inline void up_cell(std::string arg = "-1") noexcept;
    inline void down_cell(std::string arg = "-1") noexcept;


    // MATHS
    inline void add_cell(std::string arg = "-1") noexcept;
    inline void sub_cell(std::string arg = "-1") noexcept;
    inline void mul_cell(std::string arg = "-1") noexcept;
    inline void div_cell(std::string arg = "-1") noexcept;
    inline void mod_cell(std::string arg = "-1") noexcept;


    // IO
    inline void out_raw_cell(std::string arg = "-1") noexcept;
    inline void out_ascii_cell(std::string arg = "-1") noexcept;
    inline void getch_cell(std::string arg = "-1") noexcept;


    // REGISTER SET/GET
    inline void set_register(std::string arg = "-1") noexcept;
    inline void get_register(std::string arg = "-1") noexcept;


    // STACK
    inline void push_reg(std::string arg = "-1") noexcept;
    inline void pop_reg(std::string arg = "-1") noexcept;
    inline void peek_reg(std::string arg = "-1") noexcept;


    // SETTERS
    inline void set_cell(std::string arg = "-1") noexcept;
    inline void set_reg(std::string arg = "-1") noexcept;


    // MEMES
    inline void add_none(std::string arg = "-1") noexcept;
}


#endif