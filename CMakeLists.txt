cmake_minimum_required(VERSION 3.31.6)
project(Salute VERSION 0.0.0)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


# BlueJay Include
add_subdirectory(
        submodules/BlujayEngine
        submodules/rapidxml
)
blu_add_module(Framework ENGINE)

#SET(CMAKE_BUILD_TYPE Debug)

add_executable(Salute
        src/main.cpp
        src/layers.hpp
        src/layers.cpp
        src/elements/header.cpp
        src/types/percentage.hpp
        src/terminal.hpp
        src/terminal.cpp
        src/elements/square.cpp
        src/types/size.hpp
        src/elements/text.cpp
        src/utils/additions/BlujayEngine/ANSI.h
        src/types/clamp.hpp
        src/elements/input.hpp
        src/elements/input.cpp
        src/types/clamp.cpp
        src/utils/misc/graphics.cpp
        src/utils/misc/graphics.hpp
        src/elements/line.cpp
        src/elements/line.hpp
        src/types/vector3.hpp
        src/engine/screen.cpp
        src/engine/screen.hpp
)

target_compile_options(Salute PUBLIC
        -g
        -std=c++23
        -O0
        -fsanitize=address

        -Wall
        -Werror
        -pedantic

#        Werror Suppressions
        -Wno-error=unused-variable
        -Wno-error=unused-but-set-variable
)

target_link_options(Salute PUBLIC
        -fsanitize=address
)

target_link_libraries(Salute
        PUBLIC
        Blujay::Framework
)

set_target_properties(Salute PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/lib"
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/lib"
)

target_include_directories(Salute PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/src"
)

