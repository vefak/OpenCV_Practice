cmake_minimum_required(VERSION 3.4)
project( streamVideo )
find_package( OpenCV REQUIRED )
add_executable( streamVideo source.cpp )
target_link_libraries( streamVideo ${OpenCV_LIBS} )

