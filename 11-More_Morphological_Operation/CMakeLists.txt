cmake_minimum_required(VERSION 3.4)
project( morp )
find_package( OpenCV REQUIRED )
add_executable( morp source.cpp )
target_link_libraries( morp ${OpenCV_LIBS} )

