cmake_minimum_required(VERSION 3.4)
project( bright )
find_package( OpenCV REQUIRED )
add_executable( bright source.cpp )
target_link_libraries( bright ${OpenCV_LIBS} )

