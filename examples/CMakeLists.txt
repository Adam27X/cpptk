cmake_minimum_required(VERSION 3.10)

project(example1)

get_filename_component(PARENT_DIR ../ ABSOLUTE)
add_subdirectory(${PARENT_DIR} build_cpptk)
add_subdirectory(${PARENT_DIR}/base build_cpptkbase)

add_executable(example1 example1.cc)
target_compile_options(example1 PUBLIC -std=c++17 -Wno-parentheses -Wall -Wno-long-long -pedantic)
target_include_directories(example1 PUBLIC /usr/include/tcl8.6) #TODO: Package this directly
target_include_directories(example1 PUBLIC /usr/include/) #For tk, which should also be packaged directly

target_link_libraries(example1 cpptk)
target_link_libraries(example1 cpptkbase)

install(TARGETS example1 DESTINATION bin)

project(example2)

add_executable(example2 example2.cc)
target_compile_options(example2 PUBLIC -std=c++17 -Wno-parentheses -Wall -Wno-long-long -pedantic)
target_include_directories(example2 PUBLIC /usr/include/tcl8.6) #TODO: Package this directly
target_include_directories(example2 PUBLIC /usr/include/) #For tk, which should also be packaged directly

target_link_libraries(example2 cpptk)
target_link_libraries(example2 cpptkbase)

install(TARGETS example2 DESTINATION bin)
