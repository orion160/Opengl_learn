# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.16)

project ("Opengl_learn")

# Include sub-projects.
add_subdirectory ("1-Legacy_Opengl_hello_triangle")
add_subdirectory ("2-Modern_Opengl_hello_triangle")
