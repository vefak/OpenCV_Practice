cmake_minimum_required(VERSION 3.4)
project( videoBright )
find_package( OpenCV REQUIRED )
add_executable( videoBright source.cpp )
target_link_libraries( videoBright ${OpenCV_LIBS} )

