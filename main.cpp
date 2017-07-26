#include <iostream>
#include <string>
#include <array>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <fstream>

#include "src/globals.h"
#include "src/stack.cpp"
#include "src/lexer.cpp"
#include "src/functions.cpp"
#include "src/parser.cpp"




int main(int argc, char const *argv[]) {

    std::string code = wpp::read_file("tests/hello_world.wpp");

    for (int i = 0; i < code.size(); ++i) {
        std::cout << code[i] << std::endl;
    }

    return 0;
}





