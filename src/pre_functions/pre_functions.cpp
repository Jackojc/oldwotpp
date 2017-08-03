#ifndef WPP_PREPROCESSORFUNCTIONS
#define WPP_PREPROCESSORFUNCTIONS

#include "pre_functions.h"

namespace wpp {

    inline void include_file(std::string& out, const std::string& arg) noexcept {
        out += wpp::sanitize_string(wpp::read_file("stdlib/" + arg + ".wpp"));
    }

}

#endif