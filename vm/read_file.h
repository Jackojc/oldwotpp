#ifndef READ_FILE_H
#define READ_FILE_H

#include <iostream>
#include <vector>
#include <fstream>
#include <tuple>
#include <string>
#include <cstdint>
#include <cstddef>

#include "types.h"

namespace wot {

    std::tuple<bool, std::string> read_file(const std::string& fname) {
        std::ifstream is(fname, std::ios::binary | std::ios::ate);

        // If file does not exist, return empty string and error.
        if (!is.is_open()) {
            return std::make_tuple(false, "");
        }

        // Create and fill buffer.
        size_t size = is.tellg();
        std::string str(size, '\0');
        is.seekg(0);
        is.read(&str[0], size);

        // Cleanup.
        is.close();

        // Return string and success.
        return std::make_tuple(true, str);
    }

}

#endif