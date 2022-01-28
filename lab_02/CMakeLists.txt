cmake_minimum_required(VERSION 3.16.3)
project(lab_02)

set(CMAKE_CXX_STANDARD 14)

add_executable(lab_02
	src/main.cpp 
	inc/vector.h 
	inc/base_vector.h 
	inc/base_exceptions.h 
	inc/errors_list.h 
	src/iterator.hpp 
	inc/iterator.h 
	src/const_iterator.hpp 
	inc/const_iterator.h 
	src/vector.hpp 
	src/base_vector.cpp 
	src/base_exceptions.cpp)
