# CMakeList.txt : CMake project for 8-Transformations, include source and define
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
set(HEADERS "${INCLUDE_DIR}shader_class.h")

# libraries to find
find_package(glad CONFIG REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)
    

     

# Add source to this project's executable.
add_executable (transformations "${SRC}" "${HEADERS}")

find_path(STB_INCLUDE_DIRS "stb.h")
target_include_directories(transformations PRIVATE ${STB_INCLUDE_DIRS})

target_include_directories(transformations PRIVATE ${INCLUDE_DIR})

target_link_libraries(transformations PRIVATE glad::glad)
target_link_libraries(transformations PRIVATE glfw)
target_link_libraries(transformations PRIVATE glm)

# TODO: Add tests and install targets if needed.
