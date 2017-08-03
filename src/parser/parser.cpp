#ifndef WPP_PARSER
#define WPP_PARSER

#include "parser.h"

namespace wpp {

    void parser(const wpp::TokenList &tokens) noexcept {
        while (wpp::INSTR_POINTER < tokens.size()) {
            wpp::TokenPair token = tokens[wpp::INSTR_POINTER];
            std::cout << "PARSING: " << token.op << "<" << token.arg << ">\n";
            wpp::CALLBACKS.at(token.op)(token.arg); // calling function pointer while passing arg.
        }
    }

}

#endif