#ifndef WPP_SANITIZER_H
#define WPP_SANITIZER_H

namespace wpp {

    inline std::string strip_string(const std::string& code) noexcept;
    inline std::string fix_string(const std::string& code) noexcept;
    inline std::string sanitize_string(const std::string& code) noexcept;

}

#endif