cmake_minimum_required(VERSION 3.4)
project( rot )
find_package( OpenCV REQUIRED )
add_executable( rot source.cpp )
target_link_libraries( rot ${OpenCV_LIBS} )

