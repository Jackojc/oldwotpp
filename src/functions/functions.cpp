// For the functions used in the parser.

#ifndef WPP_FUNCS
#define WPP_FUNCS






namespace wpp {


    // OTHER
    inline unsigned int conv(const std::string &str) noexcept {
        return std::stoi(str, nullptr, 10);
    }







    // BUILT INS
    inline unsigned int count_char(const std::string& code, const std::string& tokens) noexcept {
        unsigned int num_char = 0;

        for (auto& chr: code) {
            for (auto& tok: tokens) {
                if (chr == tok) {
                    num_char++;
                }
            }
        }

        return num_char;
    }


    inline void do_nothing(const std::string& arg) noexcept {
        wpp::INSTR_POINTER++;
        return;
    }



    inline void initialise() noexcept {

        for (auto& item: wpp::PRE_CALLBACKS) {
            wpp::ALL_WHITELIST.insert(item.first);
            wpp::PRE_WHITELIST.insert(item.first);

        }

        for (auto& item: wpp::CALLBACKS) {
            wpp::WHITELIST.insert(item.first);
            wpp::ALL_WHITELIST.insert(item.first);
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
    inline void exec(const std::string& arg) noexcept {
        unsigned int old_instr_ptr = wpp::INSTR_POINTER;
        wpp::INSTR_POINTER = 0;

        wpp::parser(wpp::FUNC_DECLARATIONS.at(arg).tokens);

        wpp::INSTR_POINTER = old_instr_ptr + 1;
    }


    inline void open_function(const std::string& arg) noexcept {
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


    inline void close_function(const std::string& arg) noexcept {
        wpp::GLOB_FUNC.name = arg;
        wpp::FUNC_DECLARATIONS[arg] = std::move(wpp::GLOB_FUNC);
        wpp::GLOB_FUNC.reset();
        wpp::INSTR_POINTER++;
    }









    // BOOLEAN / BRANCHING
    inline void not_sofast(const std::string& arg) noexcept {
        wpp::INSTR_POINTER++;
        if (arg == "-1") {
            wpp::set_data_cell(!wpp::get_data_cell());
            return;
        }
        wpp::set_data_cell(!wpp::get_data_cell(conv(arg)));
    }


    inline void open_if(const std::string& arg) noexcept {
        wpp::INSTR_POINTER++;
    }


    inline void close_if(const std::string& arg) noexcept {
        wpp::INSTR_POINTER++;
    }








    // LOOPING
    inline void open_loop(const std::string& arg) noexcept {
        wpp::INSTR_POINTER++;
    }


    inline void close_loop(const std::string& arg) noexcept {
        wpp::INSTR_POINTER++;
    }









    // POINTER OPS
    inline void set_reg_ptr(const std::string& arg) noexcept {
        wpp::INSTR_POINTER++;
        if (arg == "-1") {
            wpp::REG_POINTER = 0;
            return;
        }
        wpp::REG_POINTER = conv(arg);
    }


    inline void set_data_pointer(const std::string& arg) noexcept {
        wpp::INSTR_POINTER++;
        if (arg == "-1") {
            wpp::DATA_PTRS[wpp::DATA_POINTER_INDEX] = 0;
            return;
        }
        wpp::DATA_PTRS[wpp::DATA_POINTER_INDEX] = conv(arg);
    }


    inline void use_data_ptr(const std::string& arg) noexcept {
        wpp::INSTR_POINTER++;
        if (arg == "-1") {
            wpp::DATA_POINTER_INDEX = 0;
            return;
        }
        wpp::DATA_POINTER_INDEX = conv(arg);
    }


    inline void set_instr_pointer(const std::string& arg) noexcept {
        if (arg == "-1") {
            wpp::INSTR_POINTER += 2;
            return;
        }
        wpp::INSTR_POINTER += conv(arg) + 1;
    }


    inline void up_cell(const std::string& arg) noexcept {
        wpp::INSTR_POINTER++;
        if (arg == "-1") {
            wpp::DATA_PTRS[wpp::DATA_POINTER_INDEX] -= 1;
            return;
        }
        wpp::DATA_PTRS[wpp::DATA_POINTER_INDEX] -= conv(arg);
    }


    inline void down_cell(const std::string& arg) noexcept {
        wpp::INSTR_POINTER++;
        if (arg == "-1") {
            wpp::DATA_PTRS[wpp::DATA_POINTER_INDEX] += 1;
            return;
        }
        wpp::DATA_PTRS[wpp::DATA_POINTER_INDEX] += conv(arg);
    }












    // MATH OPS
    inline void add_cell(const std::string& arg) noexcept {
        wpp::INSTR_POINTER++;
        if (arg == "-1") {
            set_data_cell(get_data_cell() + 1);
            return;
        }
        set_data_cell(get_data_cell() + get_data_cell(conv(arg)));
    }


    inline void sub_cell(const std::string& arg) noexcept {
        wpp::INSTR_POINTER++;
        if (arg == "-1") {
            set_data_cell(get_data_cell() - 1);
            return;
        }
        set_data_cell(get_data_cell() - get_data_cell(conv(arg)));
    }


    inline void mul_cell(const std::string& arg) noexcept {
        wpp::INSTR_POINTER++;
        if (arg == "-1") {
            set_data_cell(pow(get_data_cell(), 2));
            return;
        }
        set_data_cell(get_data_cell() * get_data_cell(conv(arg)));
    }


    inline void div_cell(const std::string& arg) noexcept {
        wpp::INSTR_POINTER++;
        if (arg == "-1") {
            if (get_data_cell() == 0) {
                set_data_cell(0);
                return;
            }
            set_data_cell(1);
            return;
        }
        set_data_cell(get_data_cell() / get_data_cell(conv(arg)));
    }


    inline void mod_cell(const std::string& arg) noexcept {
        wpp::INSTR_POINTER++;
        if (arg == "-1") {
            set_data_cell(0);
            return;
        }
        set_data_cell( fmod(get_data_cell(), get_data_cell(conv(arg))) );
    }









    // IO
    inline void out_raw_cell(const std::string& arg) noexcept {
        wpp::INSTR_POINTER++;
        if (arg == "-1") {
            std::cout << get_data_cell() << std::endl;
            return;
        }
        std::cout << get_data_cell(conv(arg)) << std::endl;
    }


    inline void out_ascii_cell(const std::string& arg) noexcept {
        wpp::INSTR_POINTER++;
        if (arg == "-1") {
            std::cout << (char)get_data_cell() << std::endl;
            return;
        }
        std::cout << (char)get_data_cell(conv(arg)) << std::endl;
    }


    inline void getch_cell(const std::string& arg) noexcept {
        wpp::INSTR_POINTER++;
        // this shit is about to get really hacky.
        if (arg == "-1") {
            set_data_cell(wpp::getche());
            return;
        }
        set_data_cell(wpp::getche(), conv(arg));
    }










    // REGISTER STUFF
    inline void set_register(const std::string& arg) noexcept {
        wpp::INSTR_POINTER++;
        if (arg == "-1") {
            set_reg_cell(get_data_cell());
            return;
        }
        set_reg_cell(get_data_cell(conv(arg)));
    }


    inline void get_register(const std::string& arg) noexcept {
        wpp::INSTR_POINTER++;
        if (arg == "-1") {
            set_data_cell(get_reg_cell());
            return;
        }
        set_data_cell(get_reg_cell(), conv(arg));
    }







    inline void goto_a(const std::string& arg) noexcept { set_reg_ptr("0"); }
    inline void goto_b(const std::string& arg) noexcept { set_reg_ptr("1"); }
    inline void goto_c(const std::string& arg) noexcept { set_reg_ptr("2"); }
    inline void goto_d(const std::string& arg) noexcept { set_reg_ptr("3"); }
    inline void goto_e(const std::string& arg) noexcept { set_reg_ptr("4"); }
    inline void goto_f(const std::string& arg) noexcept { set_reg_ptr("5"); }
    inline void goto_g(const std::string& arg) noexcept { set_reg_ptr("6"); }
    inline void goto_h(const std::string& arg) noexcept { set_reg_ptr("7"); }








    // STACK MANIPULATION
    inline void push_reg(const std::string& arg) noexcept {
        wpp::INSTR_POINTER++;
        if (arg == "-1") {
            wpp::STACK.push(get_reg_cell());
            return;
        }
        wpp::STACK.push(get_reg_cell(conv(arg)));
    }


    inline void pop_reg(const std::string& arg) noexcept {
        wpp::INSTR_POINTER++;
        if (arg == "-1") {
            set_reg_cell(wpp::STACK.pop());
            return;
        }
        set_reg_cell(wpp::STACK.pop(), conv(arg));
    }


    inline void peek_reg(const std::string& arg) noexcept {
        wpp::INSTR_POINTER++;
        if (arg == "-1") {
            set_reg_cell(wpp::STACK.peek_top());
            return;
        }
        set_reg_cell(wpp::STACK.peek_top(), conv(arg));
    }






    // SET CELL/REG
    inline void set_cell(const std::string& arg) noexcept {
        wpp::INSTR_POINTER++;
        if (arg == "-1") {
            set_data_cell(0);
            return;
        }
        set_data_cell(conv(arg));
    }


    inline void set_reg(const std::string& arg) noexcept {
        wpp::INSTR_POINTER++;
        if (arg == "-1") {
            set_reg_cell(0);
            return;
        }
        set_reg_cell(conv(arg));
    }


}


#endif