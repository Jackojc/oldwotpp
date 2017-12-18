#ifndef OBJECT_H
#define OBJECT_H

#include <stdint.h>

namespace wot {

    // Types for obj_t
    enum class TYPE {
        U8,
        I8,
        U32,
        I32,
        PTR
    };

    struct obj_t {
        TYPE type;

        union {
            uint8_t  u8;
            int8_t   i8;
            uint32_t u32;
            int32_t  i32;
            void*    ptr;
        };
    };

}

#endif