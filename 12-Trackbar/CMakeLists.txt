cmake_minimum_required(VERSION 3.4)
project( trackbar )
find_package( OpenCV REQUIRED )
add_executable( trackbar source.cpp )
target_link_libraries( trackbar ${OpenCV_LIBS} )

