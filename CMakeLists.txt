cmake_minimum_required(VERSION 3.5)

project(06.allocator)
add_compile_options(-Werror)

add_executable(01_std_03_allocator simple_allocator.cpp)
set_target_properties(01_std_03_allocator PROPERTIES CXX_STANDARD 14 CXX_STANDARD_REQUIRED ON)
