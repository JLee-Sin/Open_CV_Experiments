cmake_minimum_required(VERSION 3.21)
project(Open_CV_Experiments)

set(CMAKE_CXX_STANDARD 11)


find_package( OpenCV REQUIRED PATHS "C:/OpenCV")
set(OpenCV_FOUND 1)
include_directories(${OpenCV_INCLUDE_DIRS})
add_executable(Open_CV_Experiments Main.cpp Recognition.h)
target_link_libraries(Open_CV_Experiments ${OpenCV_LIBS} )
MESSAGE("OpenCV_LIBS: " ${OpenCV_LIBS} )
MESSAGE(STATUS "LINK LIBRARIES ${OpenCV_LIBS}")
