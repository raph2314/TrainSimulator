project(TrainSimulation)

cmake_minimum_required(VERSION 3.17)
set(CMAKE_CXX_STANDARD 14)

include_directories(${TRAIN_SIMULATION_SOURCE_DIR}/inc)

#curses lib for custom terminal settings
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

#set the default path for built executables to the "bin" directory
set(EXECUTABLE_OUTPUT_PATH ../../bin)

#set the default path for built libraries to the "lib" directory
set(LIBRARY_OUTPUT_PATH ${TRAIN_SIMULATION_SOURCE_DIR}/lib)

add_executable(TrainSimulation main.cpp Track.cpp ../inc/Track.h TrackBuilder.cpp ../inc/TrackBuilder.h)
target_link_libraries(TrainSimulation ${CURSES_LIBRARIES})
