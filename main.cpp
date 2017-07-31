#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <fstream>


#include "src/globals.h"
#include "src/debugging.cpp"
#include "src/stack.cpp"
#include "src/lexer.cpp"
#include "src/functions.cpp"
#include "src/parser.cpp"
#include "src/preprocessor.cpp"



// TODO:
/*
    Loops
    If statements
    Local include preprocessor directive
    Polish code
    Optimise code
    Add a-h register setters
    Fix directory structure...
    Nested function declarations...

*/



int main(int argc, char const *argv[]) {

    // INITIALISE
    wpp::initialise();
    wpp::preprocessor(wpp::read_file("tests/test.wpp"));
    wpp::lexer(wpp::clean_string(wpp::CODE));
    wpp::parser(wpp::TOKENS);

    // DARRTY DEEDS

    // TESTING
    //      this example reverses the registers 0 - 4
    /*wpp::REGISTERS[0] = 5;
    wpp::REGISTERS[1] = 4;
    wpp::REGISTERS[2] = 3;
    wpp::REGISTERS[3] = 2;
    wpp::REGISTERS[4] = 1;

    wpp::push_reg("0");
    wpp::push_reg("1");
    wpp::push_reg("2");
    wpp::push_reg("3");
    wpp::push_reg("4");

    wpp::pop_reg("0");
    wpp::pop_reg("1");
    wpp::pop_reg("2");
    wpp::pop_reg("3");
    wpp::pop_reg("4");*/



    // DEBUG INFO
    std::cout << "\n------- DATA -------\n";
    wpp::print_data();
    wpp::print_reg();
    wpp::print_stack();

    std::cout << "\n----- POINTERS -----\n";
    wpp::print_pointers();

    std::cout << "\n------- FUNK -------\n";
    wpp::print_functions();

    std::cout << "\n------- CODE -------\n";
    std::cout << wpp::clean_string(wpp::CODE) << std::endl;

    return 0;
}





