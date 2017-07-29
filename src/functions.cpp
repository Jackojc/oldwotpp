// For the functions used in the parser.

#ifndef WPP_FUNCS
#define WPP_FUNCS



#include "functions.h"
#include "globals.h"
#include "getch.h"
#include "parser.h"


namespace wpp {


    // OTHER
    inline unsigned int conv(const std::string &str) noexcept {
        return std::stoi(str, nullptr, 10);
    }







    // BUILT INS
    inline void do_nothing(std::string arg) noexcept {
        wpp::INSTR_POINTER++;
        return;
    }

    inline void do_something(std::string arg) noexcept {
        wpp::INSTR_POINTER++;
        std::cout << "I did something: " << arg << '\n';
        return;
    }

    inline void initialise() noexcept {
        for (auto& item: wpp::CALLBACKS) {
            wpp::WHITELIST.insert(item.first);
        }
    }









    // PARSER FUNCS
    // BUILT INS
    inline void set_data_cell(const wpp::DATATYPE& value, unsigned int index) noexcept {
        wpp::DATA[index] = value;
    }

    inline wpp::DATATYPE get_data_cell(unsigned int index) noexcept {
        return wpp::DATA[index];
    }

    inline void set_reg_cell(const wpp::DATATYPE& value, unsigned int index) noexcept {
        wpp::REGISTERS[index] = value;
    }

    inline wpp::DATATYPE get_reg_cell(unsigned int index) noexcept {
        return wpp::REGISTERS[index];
    }








    // FUNCTIONS
    inline void exec(std::string arg) noexcept {
        unsigned int old_instr_ptr = wpp::INSTR_POINTER;
        wpp::INSTR_POINTER = 0;

        wpp::parser(wpp::FUNC_DECLARATIONS.at(arg).tokens);

        wpp::INSTR_POINTER = old_instr_ptr + 1;
    }


    inline void open_function(std::string arg) noexcept {
        wpp::INSTR_POINTER++;

        while (true) {
            auto token = wpp::TOKENS[wpp::INSTR_POINTER];

            auto opcode = token.op;
            auto arg   = token.arg;

            wpp::GLOB_FUNC.tokens.push_back(token); // JAVA style, amirite

            wpp::INSTR_POINTER++;
            if (wpp::TOKENS[wpp::INSTR_POINTER].op == '}') {

                return;
            }





        }
    }


    inline void close_function(std::string arg) noexcept {
        wpp::GLOB_FUNC.name = arg;
        wpp::FUNC_DECLARATIONS.insert( { arg, wpp::GLOB_FUNC } );
        wpp::GLOB_FUNC = { "", { } };
        wpp::INSTR_POINTER++;
    }









    // BOOLEAN / BRANCHING
    inline void not_sofast(std::string arg) noexcept {
        wpp::INSTR_POINTER++;
        if (arg == "-1") {
            wpp::set_data_cell(!wpp::get_data_cell());
            return;
        }
        wpp::set_data_cell(!wpp::get_data_cell(conv(arg)));
    }


    inline void open_if(std::string arg) noexcept {
        wpp::INSTR_POINTER++;
    }


    inline void close_if(std::string arg) noexcept {
        wpp::INSTR_POINTER++;
    }








    // LOOPING
    inline void open_loop(std::string arg) noexcept {
        wpp::INSTR_POINTER++;
    }


    inline void close_loop(std::string arg) noexcept {
        wpp::INSTR_POINTER++;
    }









    // POINTER OPS
    inline void set_reg_ptr(std::string arg) noexcept {
        wpp::INSTR_POINTER++;
        if (arg == "-1") {
            wpp::REG_POINTER = 0;
            return;
        }
        wpp::REG_POINTER = conv(arg);
    }


    inline void set_data_pointer(std::string arg) noexcept {
        wpp::INSTR_POINTER++;
        if (arg == "-1") {
            wpp::DATA_POINTER = 0;
            return;
        }
        wpp::DATA_POINTER = conv(arg);
    }


    inline void set_instr_pointer(std::string arg) noexcept {
        if (arg == "-1") {
            wpp::INSTR_POINTER += 2;
            return;
        }
        wpp::DATA_POINTER += conv(arg) + 1;
    }


    inline void up_cell(std::string arg) noexcept {
        wpp::INSTR_POINTER++;
        if (arg == "-1") {
            wpp::DATA_POINTER -= 1;
            return;
        }
        wpp::DATA_POINTER -= conv(arg);
    }


    inline void down_cell(std::string arg) noexcept {
        wpp::INSTR_POINTER++;
        if (arg == "-1") {
            wpp::DATA_POINTER += 1;
            return;
        }
        wpp::DATA_POINTER += conv(arg);
    }












    // MATH OPS
    inline void add_cell(std::string arg) noexcept {
        wpp::INSTR_POINTER++;
        if (arg == "-1") {
            set_data_cell(get_data_cell() * 2);
            return;
        }
        set_data_cell(get_data_cell() + get_data_cell(conv(arg)));
    }


    inline void sub_cell(std::string arg) noexcept {
        wpp::INSTR_POINTER++;
        if (arg == "-1") {
            set_data_cell(0);
            return;
        }
        set_data_cell(get_data_cell() - get_data_cell(conv(arg)));
    }


    inline void mul_cell(std::string arg) noexcept {
        wpp::INSTR_POINTER++;
        if (arg == "-1") {
            set_data_cell(pow(get_data_cell(), 2));
            return;
        }
        set_data_cell(get_data_cell() * get_data_cell(conv(arg)));
    }


    inline void div_cell(std::string arg) noexcept {
        wpp::INSTR_POINTER++;
        if (arg == "-1") {
            set_data_cell(1);
            return;
        }
        set_data_cell(get_data_cell() / get_data_cell(conv(arg)));
    }


    inline void mod_cell(std::string arg) noexcept {
        wpp::INSTR_POINTER++;
        if (arg == "-1") {
            set_data_cell(0);
            return;
        }
        set_data_cell( fmod(get_data_cell(), get_data_cell(conv(arg))) );
    }









    // IO
    inline void out_raw_cell(std::string arg) noexcept {
        wpp::INSTR_POINTER++;
        if (arg == "-1") {
            std::cout << get_data_cell() << std::endl;
            return;
        }
        std::cout << get_data_cell(conv(arg)) << std::endl;
    }


    inline void out_ascii_cell(std::string arg) noexcept {
        wpp::INSTR_POINTER++;
        if (arg == "-1") {
            std::cout << (char)get_data_cell() << std::endl;
            return;
        }
        std::cout << (char)get_data_cell(conv(arg)) << std::endl;
    }


    inline void getch_cell(std::string arg) noexcept {
        wpp::INSTR_POINTER++;
        // this shit is about to get really hacky.
        if (arg == "-1") {
            set_data_cell(wpp::getche());
            return;
        }
        set_data_cell(wpp::getche(), conv(arg));
    }










    // REGISTER STUFF
    inline void set_register(std::string arg) noexcept {
        wpp::INSTR_POINTER++;
        if (arg == "-1") {
            set_reg_cell(get_data_cell());
            return;
        }
        set_reg_cell(get_data_cell(conv(arg)));
    }


    inline void get_register(std::string arg) noexcept {
        wpp::INSTR_POINTER++;
        if (arg == "-1") {
            set_data_cell(get_reg_cell());
            return;
        }
        set_data_cell(get_reg_cell(), conv(arg));
    }








    // STACK MANIPULATION
    inline void push_reg(std::string arg) noexcept {
        wpp::INSTR_POINTER++;
        if (arg == "-1") {
            wpp::STACK.push(get_reg_cell());
            return;
        }
        wpp::STACK.push(get_reg_cell(conv(arg)));
    }


    inline void pop_reg(std::string arg) noexcept {
        wpp::INSTR_POINTER++;
        if (arg == "-1") {
            set_reg_cell(wpp::STACK.pop());
            return;
        }
        set_reg_cell(wpp::STACK.pop(), conv(arg));
    }


    inline void peek_reg(std::string arg) noexcept {
        wpp::INSTR_POINTER++;
        if (arg == "-1") {
            set_reg_cell(wpp::STACK.peek_top());
            return;
        }
        set_reg_cell(wpp::STACK.peek_top(), conv(arg));
    }






    // SET CELL/REG
    inline void set_cell(std::string arg) noexcept {
        wpp::INSTR_POINTER++;
        if (arg == "-1") {
            set_data_cell(0);
            return;
        }
        set_data_cell(conv(arg));
    }


    inline void set_reg(std::string arg) noexcept {
        wpp::INSTR_POINTER++;
        if (arg == "-1") {
            set_reg_cell(0);
            return;
        }
        set_reg_cell(conv(arg));
    }


}


#endif