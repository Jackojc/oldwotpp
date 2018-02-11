#ifndef WOTPP_OBJECT_H
#define WOTPP_OBJECT_H


#include <cstdint>


namespace wotpp {
    // Types for obj_t
    enum class TYPE: uint8_t {
        CHR,
        NUM,
        PTR
    };


    struct __attribute__ ((packed)) obj_t {
        TYPE type;
        union {
            int8_t   chr;
            int32_t  num;
            void*    ptr;
        };
    };
}


#endif