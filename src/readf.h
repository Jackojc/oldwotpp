#ifndef WPP_READF_H
#define WPP_READF_H

namespace wpp {

    inline std::string read_file(const std::string& fname) noexcept {
        return static_cast<std::ostringstream&>(
            std::ostringstream{} << std::ifstream(fname, std::ifstream::in).rdbuf()
        ).str();
    }

}

#endif