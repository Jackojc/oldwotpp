cmake_minimum_required(VERSION 2.8)
set(PROJECT_NAME vm)
project(${PROJECT_NAME})


# SOURCE FILES
set(MAIN main.cpp)

file(GLOB_RECURSE OBJECT
    "object/*.cpp"
    "object/*.h"
)

file(GLOB_RECURSE STACK
    "stack/*.cpp"
    "stack/*.h"
)

file(GLOB_RECURSE VM
    "vm/*.cpp"
    "vm/*.h"
)

file(GLOB_RECURSE STACKGROUP
    "stack_group/*.cpp"
    "stack_group/*.h"
)

file(GLOB_RECURSE OPS
    "ops/*.cpp"
    "ops/*.h"
)


# EXECUTABLE
add_executable(${PROJECT_NAME} ${OBJECT} ${VM} ${STACK} ${STACKGROUP} ${OPS} ${MAIN})
#add_executable(${PROJECT_NAME} ${MAIN})


# FILTERS
source_group("object" FILES ${OBJECT})
source_group("stack" FILES ${STACK})
source_group("vm" FILES ${VM})
source_group("stack_group" FILES ${STACKGROUP})
source_group("ops" FILES ${OPS})
source_group("main" FILES ${MAIN})


# LINK
#target_link_libraries(${PROJECT_NAME})


# GCC
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Ofast -flto -m64")


# PROPERTIES
set_target_properties(${PROJECT_NAME} PROPERTIES
	CXX_STANDARD 14
	CXX_STANDARD_REQUIRED ON
	CXX_EXTENSIONS OFF
)
