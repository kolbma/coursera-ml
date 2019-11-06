find_package(Armadillo REQUIRED)
include_directories(${ARMADILLO_INCLUDE_DIRS})

add_executable(warmUpExercise warmUpExercise.cpp warmUpExercise_main.cpp)
target_link_libraries(warmUpExercise ${ARMADILLO_LIBRARIES})
