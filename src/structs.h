#ifndef WPP_STRUCTS_H
#define WPP_STRUCTS_H

namespace wpp {

    struct TokenPair {
        char op;
        std::string arg;

        TokenPair(char OP, const std::string& ARG): op(OP), arg(ARG) {}
        TokenPair(): op('\0'), arg("-1") {}
        ~TokenPair() {}
    };


    struct Function {
        std::string name;
        std::vector<wpp::TokenPair> tokens;

        Function(const std::string& NAME): name(NAME) {}
        Function(): name("") {}
        ~Function() {}

        inline void reset() noexcept {
            name = "";
            tokens.clear();
        }
    };

}

#endif