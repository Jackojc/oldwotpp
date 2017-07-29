#ifndef WPP_CONSTS
#define WPP_CONSTS


namespace wpp {

    using DATATYPE = double;
    typedef void (*TokenCallback)(std::string);

    constexpr unsigned int STACK_SIZE = 500;
    constexpr unsigned int DATA_SIZE  = 65536;
    constexpr unsigned int REG_SIZE   = 8;

    // NOT CONSTANTS BUT FUCK IT, IT WORKS
    unsigned int DATA_POINTER  = 0;
    unsigned int REG_POINTER   = 0;
    unsigned int INSTR_POINTER = 0;

}



#endif