cmake_minimum_required(VERSION 3.0.0)
project(coursera-ml VERSION 0.1.0)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

add_compile_options(-Wall)

include(CTest)
enable_testing()

add_subdirectory(ex1)
add_subdirectory(tests/ex1)

FIND_PACKAGE(PkgConfig REQUIRED)

pkg_check_modules(MLPACK mlpack)

if (MLPACK_FOUND)
    add_subdirectory(ex1_mlpack)
    add_subdirectory(tests/ex1_mlpack)
endif()
