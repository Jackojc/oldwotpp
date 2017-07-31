// For the token parser.

#ifndef WPP_PREPROCESSOR
#define WPP_PREPROCESSOR



namespace wpp {

    void preprocessor(const std::string& code) noexcept {
        bool in_args = false;  // pirate in pain
        std::string arg = "";
        char opcode = ' ';

        unsigned int ip = 0;

        while (ip < code.size()) {
            char chr = code[ip];

            if (chr != '<' && chr != '>' && !in_args && code[ip + 1] != '<') {
                wpp::CODE += chr;

            } else if (chr != '<' && chr != '>' && !in_args) {
                // add opcode.
                opcode = chr;

            } else if (chr == '<' && !in_args) {
                in_args = true;

            } else if (chr == '>' && in_args) {
                // parsed all arguments in the arglist.
                if (wpp::PRE_WHITELIST.find(opcode) != wpp::PRE_WHITELIST.end()) {
                    wpp::PRE_CALLBACKS.at(opcode)(arg);

                } else {
                    wpp::CODE += opcode + ('<' + arg + '>');
                }



                in_args = false;
                arg = "";
                opcode = ' ';

            } else if (in_args) {
                // if were inside an argument list, add the character to the arg string.
                arg += chr;
            }



            ip++;
        }

    }

}


#endif