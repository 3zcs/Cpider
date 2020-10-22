cmake_minimum_required(VERSION 2.6)
project(cpider)

include_directories(include)
file(GLOB SOURCES "src/*.cpp")

add_executable(cpider ${SOURCES})

set_property(TARGET cpider PROPERTY CXX_STANDARD 17)
target_link_libraries(cpider pthread curl)

target_compile_options(cpider PRIVATE -Wall -Wextra)