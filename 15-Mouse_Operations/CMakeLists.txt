cmake_minimum_required(VERSION 3.4)
project( mouse )
find_package( OpenCV REQUIRED )
add_executable( mouse source.cpp )
target_link_libraries( mouse ${OpenCV_LIBS} )

