#ifndef WPP_GLOBALS_H
#define WPP_GLOBALS_H

namespace wpp {

    using DATATYPE = double;
    using ParserTokenCallback = void(*)(const std::string&);
    using PreprocessorTokenCallback = void(*)(std::string&, const std::string&);
    using TokenList = std::vector<wpp::TokenPair>;

    constexpr unsigned int STACK_SIZE  = 500;
    constexpr unsigned int DATA_SIZE   = 65536;
    constexpr unsigned int REG_SIZE    = 16;
    constexpr unsigned int DATA_PTR_S  = 3;


    unsigned int DATA_POINTER_INDEX  = 0;
    unsigned int REG_POINTER         = 0;
    unsigned int INSTR_POINTER       = 0;


    std::array<DATATYPE, DATA_PTR_S>  DATA_PTRS = {};
    std::array<DATATYPE, REG_SIZE>    REGISTERS = {};
    std::array<DATATYPE, DATA_SIZE>   DATA      = {};
    wpp::stack<DATATYPE, STACK_SIZE>  STACK     = {};


    std::unordered_set<char> WHITELIST = {};
    std::unordered_set<char> PRE_WHITELIST = {};
    std::unordered_set<char> ALL_WHITELIST = {};


    std::unordered_map<std::string, wpp::Function> FUNC_DECLARATIONS = {};
    wpp::Function GLOB_FUNC("");
    wpp::TokenList TOKENS = {};

}



#endif