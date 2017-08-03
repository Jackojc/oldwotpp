#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <fstream>


#include "src/wpp.h"



// TODO:
/*
    Loops
    set reg/cell pointer using negative indexes

    If statements
    Local include preprocessor directive
    Polish code
    Optimise code
    Add a-h register setters
    Fix directory structure...
    Nested function declarations...

*/



int main(int argc, char const *argv[]) {


     // VARS
    std::string code;
    std::string fname;
    wpp::TokenList tokens;


    // PARSE CMD ARGS
    if (argc > 1) {
        fname = argv[1];
    } else {
        return -1;
    }


    // INITIALISE
    wpp::initialise();
    code = wpp::read_file(fname);
    code = wpp::sanitize_string(code);
    code = wpp::preprocessor(code);

    std::cout << "\n------ CODE -----\n" << std::endl;
    std::cout << code << std::endl;

    tokens = wpp::lexer(code);

    std::cout << "\n---- LEXING ----\n" << std::endl;
    for (auto& item: tokens) { std::cout << item.op << ": " << item.arg << std::endl; }

    wpp::parser(tokens);





    // DEBUG INFO
    // std::cout << "\n------- DATA -------\n";
    // wpp::print_data();
    // wpp::print_reg();
    // wpp::print_stack();

    // std::cout << "\n----- POINTERS -----\n";
    // wpp::print_pointers();

    // std::cout << "\n------- FUNK -------\n";
    // wpp::print_functions();

    // std::cout << "\n------- CODE -------\n";
    // std::cout << wpp::clean_string(wpp::CODE) << std::endl;

    return 0;
}





