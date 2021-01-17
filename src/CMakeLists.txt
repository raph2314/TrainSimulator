project(TrainSimulation)

cmake_minimum_required(VERSION 3.17)
set(CMAKE_CXX_STANDARD 14)

#header files
include_directories(../inc)

#curses lib for custom terminal settings
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

#set the default path for built executables to the "bin" directory
set(EXECUTABLE_OUTPUT_PATH ../../bin)

#set the default path for built libraries to the "lib" directory
set(LIBRARY_OUTPUT_PATH ${TRAIN_SIMULATION_SOURCE_DIR}/lib)

add_executable(TrainSimulation main.cpp TrackSystem.cpp ../inc/TrackSystem.h TrackBuilder.cpp ../inc/TrackBuilder.h TrackComponent.cpp ../inc/TrackComponent.h)
target_link_libraries(TrainSimulation ${CURSES_LIBRARIES})
