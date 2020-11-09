add_library(cpptk cpptk.cc)
target_include_directories(cpptk PUBLIC .)

if(WIN32)
	target_include_directories(cpptk PUBLIC "C:/Program Files/Tcl86/include")
	target_include_directories(cpptk PUBLIC "C:/Program Files/boost_1_74_0/boost_1_74_0")
	target_compile_options(cpptk PUBLIC -std=c++17)
else()
	target_include_directories(cpptk PUBLIC /usr/include/tcl8.6) #TODO: Package this directly
	target_include_directories(cpptk PUBLIC /usr/include/) #For tk, which should also be packaged directly
	target_compile_options(cpptk PUBLIC -std=c++17 -Wno-parentheses -Wall -Wno-long-long -pedantic)
endif()

if(WIN32)
	find_library(LIBTCL tcl86t HINTS "C:/Program Files/Tcl86/lib")
	find_library(LIBTK tk86t HINTS "C:/Program Files/Tcl86/lib")
	target_link_libraries(cpptk PUBLIC ${LIBTCL})
	target_link_libraries(cpptk PUBLIC ${LIBTK})
else()
	target_link_libraries(cpptk PUBLIC tcl8.6)
	target_link_libraries(cpptk PUBLIC tk8.6)
endif()

install(TARGETS cpptk DESTINATION lib)
