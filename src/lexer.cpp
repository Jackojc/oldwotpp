// For the code lexer.

#ifndef WPP_LEXER
#define WPP_LEXER


#include <fstream>
#include <sstream>
#include <string>


namespace wpp {

    inline std::string read_file(const std::string& fname) noexcept {
        return static_cast<std::ostringstream&>(std::ostringstream{} << std::ifstream(fname, std::ifstream::in).rdbuf()).str();
    }



}


#endif