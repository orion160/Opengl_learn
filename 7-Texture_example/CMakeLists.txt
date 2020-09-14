# CMakeList.txt : CMake project for 7-Texture_example, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.16)

# Set c++ standard and ensure compiler compability
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


# Configuring Project structure
set(SRC_DIR "src/")
set(INCLUDE_DIR "include/")

set(SRC "${SRC_DIR}shader_class.cpp" "${SRC_DIR}main.cpp")
set(HEADERS "${INCLUDE_DIR}shader_class.h" "${INCLUDE_DIR}stb_image")

# libraries to find
find_package(glad CONFIG REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
     

# Add source to this project's executable.
add_executable (texture_example "${SRC}" "${HEADERS}")

target_include_directories(texture_example PRIVATE ${INCLUDE_DIR})

target_link_libraries(texture_example PRIVATE glad::glad)
target_link_libraries(texture_example PRIVATE glfw)

# TODO: Add tests and install targets if needed.
