// For the functions used in the parser.

#ifndef WPP_FUNCS_H
#define WPP_FUNCS_H

#include <math.h>

#include "constants.h"



namespace wpp {

    // BUILT INS
    inline unsigned int count_char(const std::string& code, const std::string& tokens) noexcept;
    inline void do_nothing(const std::string& arg = "-1") noexcept;
    inline void do_something(const std::string& arg = "-1") noexcept;
    inline void initialise() noexcept;


    // PARSER FUNCS
    inline void set_data_cell(const wpp::DATATYPE& value, unsigned int index = wpp::DATA_POINTER) noexcept;
    inline wpp::DATATYPE get_data_cell(unsigned int index = wpp::DATA_POINTER) noexcept;

    inline void set_reg_cell(const wpp::DATATYPE& value, unsigned int index = wpp::REG_POINTER) noexcept;
    inline wpp::DATATYPE get_reg_cell(unsigned int index = wpp::REG_POINTER) noexcept;


    // FUNCTIONS
    inline void exec(const std::string& arg = "-1") noexcept;
    inline void open_function(const std::string& arg = "-1") noexcept;
    inline void close_function(const std::string& arg = "-1") noexcept;


    // BRANCHING/BOOLEAN
    inline void not_sofast(const std::string& arg = "-1") noexcept;

    inline void open_if(const std::string& arg = "-1") noexcept;
    inline void close_if(const std::string& arg = "-1") noexcept;


    // LOOPING
    inline void open_loop(const std::string& arg = "-1") noexcept;
    inline void close_loop(const std::string& arg = "-1") noexcept;


    // POINTERS
    inline void set_reg_ptr(const std::string& arg = "-1") noexcept;
    inline void set_data_pointer(const std::string& arg = "-1") noexcept;
    inline void set_instr_pointer(const std::string& arg = "-1") noexcept;
    inline void up_cell(const std::string& arg = "-1") noexcept;
    inline void down_cell(const std::string& arg = "-1") noexcept;


    // MATHS
    inline void add_cell(const std::string& arg = "-1") noexcept;
    inline void sub_cell(const std::string& arg = "-1") noexcept;
    inline void mul_cell(const std::string& arg = "-1") noexcept;
    inline void div_cell(const std::string& arg = "-1") noexcept;
    inline void mod_cell(const std::string& arg = "-1") noexcept;


    // IO
    inline void include_file(const std::string& arg = "-1") noexcept;
    inline void out_raw_cell(const std::string& arg = "-1") noexcept;
    inline void out_ascii_cell(const std::string& arg = "-1") noexcept;
    inline void getch_cell(const std::string& arg = "-1") noexcept;


    // REGISTER SET/GET
    inline void set_register(const std::string& arg = "-1") noexcept;
    inline void get_register(const std::string& arg = "-1") noexcept;


    // STACK
    inline void push_reg(const std::string& arg = "-1") noexcept;
    inline void pop_reg(const std::string& arg = "-1") noexcept;
    inline void peek_reg(const std::string& arg = "-1") noexcept;


    // SETTERS
    inline void set_cell(const std::string& arg = "-1") noexcept;
    inline void set_reg(const std::string& arg = "-1") noexcept;


    // MEMES
    inline void add_none(const std::string& arg = "-1") noexcept;
}


#endif