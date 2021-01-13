cmake_minimum_required(VERSION 3.4)
project( smooth )
find_package( OpenCV REQUIRED )
add_executable( smooth source.cpp )
target_link_libraries( smooth ${OpenCV_LIBS} )

