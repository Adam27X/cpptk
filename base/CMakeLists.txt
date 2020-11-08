add_library(cpptkbase cpptkbase.cc)
target_include_directories(cpptkbase PUBLIC .)
target_include_directories(cpptkbase PUBLIC /usr/include/tcl8.6) #TODO: Package this directly
target_include_directories(cpptkbase PUBLIC /usr/include/) #For tk, which should also be packaged directly
target_compile_options(cpptkbase PUBLIC -std=c++17 -Wno-parentheses -Wall -Wno-long-long -pedantic)
#TODO: Rather than assuming these libraries exist on the system we should instead package them
target_link_libraries(cpptkbase PUBLIC tcl8.6)
target_link_libraries(cpptkbase PUBLIC tk8.6)

install(TARGETS cpptkbase DESTINATION lib)
