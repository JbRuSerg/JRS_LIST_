cmake_minimum_required(VERSION 3.5)

project(List LANGUAGES CXX)

add_subdirectory(test)

add_executable(List 
	main.cpp
	${CMAKE_SOURCE_DIR}/include/list.h
	${CMAKE_SOURCE_DIR}/include/print.h
)

target_link_libraries(List test)

set_target_properties(
	List PROPERTIES
	cxx_STANDARD 11
	cxx_STANDARD_REQUIRED ON
)