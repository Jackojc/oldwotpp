#ifndef WPP_DEBUGGING_H
#define WPP_DEBUGGING_H

namespace wpp {

    inline void print_data(unsigned int range0 = 0,
                           unsigned int range1 = 20) noexcept;
    inline void print_reg() noexcept;
    inline void print_stack() noexcept;
    inline void print_functions() noexcept;
    inline void print_pointers() noexcept;

}

#endif