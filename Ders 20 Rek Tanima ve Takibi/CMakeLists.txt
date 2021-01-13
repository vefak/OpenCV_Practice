cmake_minimum_required(VERSION 3.4)
project( blur )
find_package( OpenCV REQUIRED )
add_executable( blur source.cpp )
target_link_libraries( blur ${OpenCV_LIBS} )

