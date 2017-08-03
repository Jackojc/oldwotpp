#ifndef WPP_SANITIZER
#define WPP_SANITIZER

#include "sanitizer.h"

namespace wpp {

    inline std::string strip_string(const std::string& code) noexcept {
        std::string temp = "";

        for (auto &chr: code) {
            if (wpp::ALL_WHITELIST.find(chr) != wpp::ALL_WHITELIST.end()) {
                temp += chr;
            }
        }

        return temp;
    }


    inline std::string fix_string(const std::string& code) noexcept {
        std::string temp = "";
        bool in_args = false;
        char chr = '\0';

        for (unsigned int i = 0; i < code.size(); ++i) {
            chr = code[i];
            temp += chr;

            if (chr != '<' && chr != '>' && !in_args && code[i + 1] != '<') {
                // opcode by itself with no arg list
                temp += "<-1>";

            } else if (chr == '<' && !in_args) {
                // start of args
                in_args = true;

            } else if (chr == '>' && in_args) {
                // end of args
                in_args = false;
            }

        }

        return temp;
    }


    inline std::string sanitize_string(const std::string& code) noexcept {
        std::string tmp = wpp::strip_string(code);
        return wpp::fix_string(tmp);
    }

}

#endif