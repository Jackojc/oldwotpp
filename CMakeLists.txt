cmake_minimum_required(VERSION 2.8)
set(PROJECT_NAME vm)
project(${PROJECT_NAME})


# SOURCE FILES
set(MAIN main.cpp)


file(GLOB_RECURSE OBJECT
    "wotpp/object/*.cpp"
)


file(GLOB_RECURSE STACK
    "wotpp/stack/*.cpp"
)


file(GLOB_RECURSE VM
    "wotpp/vm/*.cpp"
)


file(GLOB_RECURSE STACKGROUP
    "wotpp/stack_group/*.cpp"
)


file(GLOB_RECURSE OPS
    "wotpp/ops/*.cpp"
)


# EXECUTABLE
add_executable(${PROJECT_NAME} ${OBJECT} ${VM} ${STACK} ${STACKGROUP} ${OPS} ${MAIN})


# FILTERS
source_group("object"      FILES ${OBJECT})
source_group("stack"       FILES ${STACK})
source_group("vm"          FILES ${VM})
source_group("stack_group" FILES ${STACKGROUP})
source_group("ops"         FILES ${OPS})


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


# FILE DEPENDENCIES
# Copies scripts folder into build directory.
add_custom_command(
    TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/scripts $<TARGET_FILE_DIR:${PROJECT_NAME}>/scripts
)