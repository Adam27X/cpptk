add_library(cpptk cpptk.cc)
target_include_directories(cpptk PUBLIC .)
target_include_directories(cpptk PUBLIC /usr/include/tcl8.6) #TODO: Package this directly
target_include_directories(cpptk PUBLIC /usr/include/) #For tk, which should also be packaged directly
target_compile_options(cpptk PUBLIC -std=c++17 -Wno-parentheses -Wall -Wno-long-long -pedantic)
#TODO: Rather than assuming these libraries exist on the system we should instead package them
target_link_libraries(cpptk PUBLIC tcl8.6)
target_link_libraries(cpptk PUBLIC tk8.6)

install(TARGETS cpptk DESTINATION lib)
