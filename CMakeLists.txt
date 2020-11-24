cmake_minimum_required(VERSION 3.5)
project(static-member-function)

set(CMAKE_CXX_STANDARD 11)

# ------------------------------
add_executable(
    static-funcs-1
    static-funcs-1.cpp
    module-config/arm-config.cpp
)
target_link_libraries(
    static-funcs-1
    yaml-cpp
)

# ------------------------------
add_executable(
    static-funcs-2
    static-funcs-2.cpp
    module-config/arm-config.cpp
)
target_link_libraries(
    static-funcs-2
    yaml-cpp
)
