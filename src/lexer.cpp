// For the code lexer.

#ifndef WPP_LEXER
#define WPP_LEXER


#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <vector>

#include "globals.h"



namespace wpp {


    inline std::string clean_string(const std::string& code) noexcept {
        std::string temp;

        for (auto &chr: code) {
            if (wpp::WHITELIST.find(chr) == wpp::WHITELIST.end()) {
                continue;
            }

            temp += chr;
        }

        return temp;
    }


    inline std::string read_file(const std::string& fname) noexcept {
        return static_cast<std::ostringstream&>(
            std::ostringstream{} << std::ifstream(fname, std::ifstream::in).rdbuf()
        ).str();
    }



    inline std::vector<std::string> split_string(const std::string &str, const char token = ' ') {
        std::vector<std::string> words;

        std::istringstream iss(str);
        std::string buf;

        while (std::getline(iss, buf, token)) {
            words.push_back(buf);
        }

        return words; // PLUS ULTRAAAAAAAAAAAAAAA
    }



    void lexer(const std::string &code) {
        std::vector<wpp::TokenPair> tokens;
        bool in_args = false;  // pirate in pain
        std::string arg;
        char opcode;

        unsigned int ip = 0;

        for (; ip < code.size() ;) {
            char chr = code[ip];

            if (chr != '<' && chr != '>' && !in_args && code[ip + 1] != '<') {
                // an operation without an argument list. e.g: "+" instead of "+<>"
                wpp::TokenPair temp = {chr, "-1"};
                tokens.push_back(temp);
                arg = "";
                opcode = ' ';

            } else if (chr != '<' && chr != '>' && !in_args) {
                // add opcode.
                opcode = chr;

            } else if (chr == '<' && code[ip + 1] == '>' && !in_args) {
                // empty arg list
                wpp::TokenPair temp = {opcode, "-1"};
                tokens.push_back(temp);
                arg = "";
                opcode = ' ';

            } else if (chr == '<' && !in_args) {
                in_args = true;

            } else if (chr == '>' && in_args) {
                // parsed all arguments in the arglist.
                in_args = false;
                wpp::TokenPair temp = {opcode, arg};
                tokens.push_back(temp);
                arg = "";
                opcode = ' ';

            } else if (in_args) {
                // if were inside an argument list, add the character to the arg string.
                arg += chr;
            }

            ip++;
        }

        wpp::TOKENS = tokens;
    }



}


#endif