// For helpful debug functions.

#ifndef WPP_DEBUG
#define WPP_DEBUG


#include <iostream>


namespace wpp {

    inline void print_data(unsigned int range0 = 0,
                           unsigned int range1 = 20) noexcept {

        // Slow and inefficient, pls fix.
        std::cout << "DATA      : [ ";
        for (; range0 < range1; ++range0){
            std::cout << wpp::DATA[range0] << ' ';
        }
        std::cout << "]" << std::endl;
    }


    inline void print_reg() noexcept {

        // Slow and inefficient, pls fix.
        std::cout << "REG       : [ ";
        for (unsigned int i = 0; i < wpp::REGISTERS.size(); ++i){
            std::cout << wpp::REGISTERS[i] << ' ';
        }
        std::cout << "]" << std::endl;
    }


    inline void print_stack() noexcept {

        // Slow and inefficient, pls fix.
        std::cout << "STACK     : [ ";
        auto stackref = wpp::STACK.get_ref();

        for (unsigned int i = 0; i < wpp::STACK.size(); ++i){
            std::cout << (*stackref)[i] << ' ';
        }
        std::cout << "]" << std::endl;
    }


    inline void print_functions() noexcept {
        for (auto &func: wpp::FUNC_DECLARATIONS) {
            std::cout << func.first << ": ";
            for (auto &arg: func.second.tokens) {
                std::cout << arg.op << '<';
                std::cout << arg.arg << ">, ";
            }
            std::cout << std::endl;
        }
    }


    inline void print_pointers() noexcept {
        std::cout << "DataPtr   : " << wpp::DATA_POINTER << std::endl;
        std::cout << "RegPtr    : " << wpp::REG_POINTER << std::endl;
        std::cout << "InstrPtr  : " << wpp::INSTR_POINTER << std::endl;
    }

}


#endif