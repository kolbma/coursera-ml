cmake_minimum_required(VERSION 3.0.0)
project(coursera-ml VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

add_compile_options(-Wall)

include(CTest)
enable_testing()

add_subdirectory(ex1)
add_subdirectory(tests/ex1)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
