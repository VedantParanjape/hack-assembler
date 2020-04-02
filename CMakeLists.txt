cmake_minimum_required(VERSION 3.4)
project(hack-assembler)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")
set(CMAKE_CXX_STANDARD 17)

add_executable( hack_assembler src/assembler.cpp src/symbol.cpp src/translate.cpp src/util.cpp)