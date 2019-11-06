
if(BUILD_TESTING)

    find_package(Armadillo REQUIRED)
    include_directories(${ARMADILLO_INCLUDE_DIRS})

    add_executable(test_warmUpExercise warmUpExercise_main.cpp)
    add_dependencies(test_warmUpExercise warmUpExercise)
    target_link_libraries(test_warmUpExercise ${ARMADILLO_LIBRARIES} ${CMAKE_BINARY_DIR}/ex1/CMakeFiles/warmUpExercise.dir/warmUpExercise.cpp.o)

    add_test(NAME warmUpExerciseTest COMMAND test_warmUpExercise)
endif()
