cmake_minimum_required(VERSION 3.5) 
project(test)		


file(GLOB_RECURSE
SOURCE_FILES
	test.cpp
	list.h
	print.h

)

add_library(test STATIC ${SOURCE_FILES})

set_target_properties(
	test PROPERTIES
	LINKER_LANGUAGE CXX
	cxx_STANDARD 11
	cxx_STANDARD_REQUIRED ON
)