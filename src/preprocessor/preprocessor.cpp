#ifndef WPP_PREPROCESSOR
#define WPP_PREPROCESSOR

#include "preprocessor.h"

namespace wpp {

    std::string preprocessor(const std::string& code) noexcept {
        std::string temp = "";
        std::string arg = "";
        char opcode = '\0';
        char chr = '\0';
        bool in_args = false;  // pirate in pain

        for (unsigned int i = 0; i < code.size(); ++i) {
            chr = code[i];

            if (wpp::PRE_WHITELIST.find(chr) != wpp::PRE_WHITELIST.end() &&
                code[i + 1] == '<' && !in_args) {
                // valid code and arg list
                opcode = chr;
                in_args = true;
                i++;

            } else if (chr == '>' && in_args) {
                wpp::PRE_CALLBACKS.at(opcode)(temp, arg);

                in_args = false;
                arg = "";
                opcode = '\0';

            } else if (in_args) {
                arg += chr;

            } else {
                temp += chr;
            }

        }

        return temp;

    }

}


#endif