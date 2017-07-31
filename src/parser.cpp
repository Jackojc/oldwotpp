// For the token parser.

#ifndef WPP_PARSER
#define WPP_PARSER

#include "parser.h"


namespace wpp {

    void parser(const std::vector<wpp::TokenPair> &tokens) noexcept {
        wpp::INSTR_POINTER = 0;

        while (wpp::INSTR_POINTER < tokens.size()) {

            auto chr = tokens[wpp::INSTR_POINTER];

            auto opcode = chr.op;
            auto arg = chr.arg;


            if (wpp::WHITELIST.find(opcode) == wpp::WHITELIST.end()) {
                wpp::INSTR_POINTER++;
                continue;
            }



            std::cout << "PARSING: " << opcode << "<" << arg << ">\n";

            wpp::CALLBACKS.at(opcode)(arg); // calling function pointer while passing arg.

        }
    }

}


#endif