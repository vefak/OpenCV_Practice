cmake_minimum_required(VERSION 3.4)
project( histogram )
find_package( OpenCV REQUIRED )
add_executable( histogram source.cpp )
target_link_libraries( histogram ${OpenCV_LIBS} )

