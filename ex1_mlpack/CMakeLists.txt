include_directories("${CMAKE_CURRENT_SOURCE_DIR}")

FIND_PACKAGE(PkgConfig REQUIRED)

pkg_check_modules(MLPACK REQUIRED mlpack)

add_executable(predictHousePrice predictHousePrice.cpp predictHousePrice_main.cpp)
target_compile_definitions(predictHousePrice PUBLIC -DDATAFILE="${CMAKE_CURRENT_SOURCE_DIR}/ex1data2.txt")
target_include_directories(predictHousePrice PUBLIC ${MLPACK_INCLUDE_DIRS})
target_link_libraries(predictHousePrice ${MLPACK_LIBRARIES})
