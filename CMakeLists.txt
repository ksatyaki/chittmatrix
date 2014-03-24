
cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(ChittMatrix)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "lib/")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "lib/")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "bin/")

add_library(chittmatrix SHARED
src/Matrix.cpp
)

add_library(chittvector SHARED
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