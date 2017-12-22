#ifndef OBJECT_H
#define OBJECT_H

#include <stdint.h>
#include <memory>


namespace wot {

    constexpr uint16_t STR_SIZE = 255;


    // Types for obj_t
    enum class TYPE: uint8_t {
        U8,
        I8,
        U32,
        I32,
        PTR
    };


    struct __attribute__ ((packed)) obj_t {
        TYPE type;

        union {
            uint8_t  u8;
            int8_t   i8;
            uint32_t u32;
            int32_t  i32;
            void*    ptr;
        };


        // Manually cleanup objects stored in `ptr` when needed.
        template <typename T>
        void clean() {
            delete static_cast<T*>(ptr);
        }
    };

}

#endif