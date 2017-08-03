#ifndef WPP_LEXER
#define WPP_LEXER

#include "lexer.h"

namespace wpp {

    wpp::TokenList lexer(const std::string& code) noexcept {
        wpp::TokenList tokens;
        std::string arg;
        char opcode = '\0';
        char chr = '\0';
        bool in_args = false;  // pirate in pain

        for (unsigned int i = 0; i < code.size(); ++i) {
            chr = code[i];

            if (chr != '<' && chr != '>' && !in_args) {
                // add opcode.
                opcode = chr;

            } else if (chr == '<' && !in_args) {
                in_args = true;

            } else if (chr == '>' && in_args) {
                // parsed all arguments in the arglist.
                in_args = false;
                tokens.emplace_back(opcode, arg);
                wpp::TOKENS.emplace_back(opcode, arg);
                arg = "";
                opcode = '\0';

            } else {
                // if were inside an argument list, add the character to the arg string.
                arg += chr;
            }
        }

        return tokens;
    }

}

#endif