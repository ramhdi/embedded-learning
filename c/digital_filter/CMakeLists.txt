cmake_minimum_required(VERSION 3.10)

# set the project name
project(digital_filter)

add_library(filter include/filter.h src/filter.c)
target_include_directories(filter PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

# add the executable
add_executable(digital_filter src/main.c)
target_link_libraries(digital_filter PRIVATE filter)