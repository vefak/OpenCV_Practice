cmake_minimum_required(VERSION 3.4)
project( callbacktrach )
find_package( OpenCV REQUIRED )
add_executable( callbacktrach source.cpp )
target_link_libraries( callbacktrach ${OpenCV_LIBS} )

