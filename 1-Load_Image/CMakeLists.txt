cmake_minimum_required(VERSION 3.4)
project( loadImage )
find_package( OpenCV REQUIRED )
add_executable( loadImage source.cpp )
target_link_libraries( loadImage ${OpenCV_LIBS} )

