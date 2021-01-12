cmake_minimum_required(VERSION 3.4)
project( captureVideo )
find_package( OpenCV REQUIRED )
add_executable( captureVideo source.cpp )
target_link_libraries( captureVideo ${OpenCV_LIBS} )

