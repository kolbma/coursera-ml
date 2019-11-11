
if(BUILD_TESTING)
    include_directories(${CMAKE_SOURCE_DIR}/ex1)
    include_directories(${CMAKE_SOURCE_DIR}/ex1_mlpack)

    add_definitions(-DCMAKE_TESTING_ENABLED)

    FIND_PACKAGE(PkgConfig REQUIRED)

    pkg_check_modules(MLPACK REQUIRED mlpack)

    add_executable(test_predictHousePrice predictHousePrice_main.cpp)
    add_dependencies(test_predictHousePrice predictHousePrice)
    target_link_libraries(test_predictHousePrice ${MLPACK_LIBRARIES} ${CMAKE_BINARY_DIR}/ex1_mlpack/CMakeFiles/predictHousePrice.dir/predictHousePrice.cpp.o)

    add_test(NAME predictHousePriceTest COMMAND test_predictHousePrice)

endif()
