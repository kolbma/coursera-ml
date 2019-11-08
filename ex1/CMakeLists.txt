find_package(Armadillo REQUIRED)
include_directories(${ARMADILLO_INCLUDE_DIRS})

FIND_PACKAGE(PkgConfig REQUIRED)

add_executable(warmUpExercise warmUpExercise.cpp warmUpExercise_main.cpp)
target_link_libraries(warmUpExercise ${ARMADILLO_LIBRARIES})

pkg_check_modules(PLPLOT REQUIRED plplot-c++)

add_executable(plotData plotData.cpp plotData_main.cpp)
target_include_directories(plotData PUBLIC ${PLPLOT_INCLUDE_DIRS})
link_directories(${PLPLOT_LIBRARY_DIRS})
target_link_libraries(plotData ${PLPLOT_LIBRARIES})
