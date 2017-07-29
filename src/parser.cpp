// For the token parser.

#ifndef WPP_PARSER
#define WPP_PARSER

#include "parser.h"


namespace wpp {

    void parser(const std::vector<wpp::TokenPair> &tokens) noexcept {
        for (; wpp::INSTR_POINTER < tokens.size() ;) {

            auto chr = tokens[wpp::INSTR_POINTER];

            auto opcode = chr.op;
            auto arg = chr.arg;

            std::cout << "PARSING: " << opcode << "<" << arg << ">\n";

            wpp::CALLBACKS.at(opcode)(arg); // calling function pointer while passing arg.

        }
    }

}


#endif