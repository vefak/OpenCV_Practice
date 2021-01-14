cmake_minimum_required(VERSION 3.4)
project( color )
find_package( OpenCV REQUIRED )
add_executable( color source.cpp )
target_link_libraries( color ${OpenCV_LIBS} )

