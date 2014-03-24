
cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(ChittMatrix)

add_library(chittmatrix
src/Matrix.cpp
)

add_library(chittvector
src/vector.cpp
)

add_executable(test_chitt_matrix
src/test_ChittMatrix.cpp
)

target_link_libraries(chittvector
chittmatrix
)

target_link_libraries(test_chitt_matrix
chittvector
)