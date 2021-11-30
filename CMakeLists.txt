cmake_minimum_required(VERSION 3.20)
project(_4 C)

set(CMAKE_C_STANDARD 99)
set(BUILD_DIR "${CMAKE_BINARY_DIR}")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${BUILD_DIR}/bin")
set(BINARY_DIR "${CMAKE_BINARY_DIR}")

add_executable(_4 main.c data.h extdata.h input.c inrnd.c output.c)
