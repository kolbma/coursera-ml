include_directories("${CMAKE_CURRENT_SOURCE_DIR}")

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

add_executable(computeCost computeCost.cpp computeCost_main.cpp)
target_link_libraries(computeCost ${ARMADILLO_LIBRARIES})

add_executable(featureNormalize featureNormalize.cpp featureNormalize_main.cpp)
# target_link_libraries(featureNormalize ${ARMADILLO_LIBRARIES})
