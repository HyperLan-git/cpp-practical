#jamais utilisé ce truc de mor
cmake_minimum_required(VERSION 3.0)

project(TPCPP)

add_executable(main motive.cpp)

add_library(sources SHARED motive.cpp)

target_link_libraries(main sources)