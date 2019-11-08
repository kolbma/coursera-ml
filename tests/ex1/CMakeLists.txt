
if(BUILD_TESTING)
    add_definitions(-DCMAKE_TESTING_ENABLED)

    find_package(Armadillo REQUIRED)
    include_directories(${ARMADILLO_INCLUDE_DIRS})

    FIND_PACKAGE(PkgConfig REQUIRED)

    add_executable(test_warmUpExercise warmUpExercise_main.cpp)
    add_dependencies(test_warmUpExercise warmUpExercise)
    target_link_libraries(test_warmUpExercise ${ARMADILLO_LIBRARIES} ${CMAKE_BINARY_DIR}/ex1/CMakeFiles/warmUpExercise.dir/warmUpExercise.cpp.o)

    add_test(NAME warmUpExerciseTest COMMAND test_warmUpExercise)

    pkg_check_modules(PLPLOT REQUIRED plplot-c++)

    add_executable(test_plotData ${CMAKE_SOURCE_DIR}/ex1/plotData.cpp plotData_main.cpp)
    target_include_directories(test_plotData PUBLIC ${PLPLOT_INCLUDE_DIRS})
    link_directories(${PLPLOT_LIBRARY_DIRS})
    target_link_libraries(test_plotData ${PLPLOT_LIBRARIES})

    add_test(NAME plotDataTest COMMAND test_plotData)

    add_executable(test_util util_test.cpp)
    target_link_libraries(test_util ${ARMADILLO_LIBRARIES})

    add_executable(test_computeCost computeCost_main.cpp)
    add_dependencies(test_computeCost computeCost)
    target_link_libraries(test_computeCost ${ARMADILLO_LIBRARIES} ${CMAKE_BINARY_DIR}/ex1/CMakeFiles/computeCost.dir/computeCost.cpp.o)

    add_test(NAME computeCostTest COMMAND test_computeCost)

    add_executable(test_computeCostMulti computeCostMulti_main.cpp)
    add_dependencies(test_computeCostMulti computeCost)
    target_link_libraries(test_computeCostMulti ${ARMADILLO_LIBRARIES} ${CMAKE_BINARY_DIR}/ex1/CMakeFiles/computeCost.dir/computeCost.cpp.o)

    add_test(NAME computeCostMultiTest COMMAND test_computeCostMulti)

endif()
