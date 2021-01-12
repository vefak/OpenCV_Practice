cmake_minimum_required(VERSION 3.4)
project( contrast )
find_package( OpenCV REQUIRED )
add_executable( contrast source.cpp )
target_link_libraries( contrast ${OpenCV_LIBS} )

