cmake_minimum_required(VERSION 3.24)

# Set the output directory for built objects.
# This makes sure that the dynamic library goes into the build directory
# automatically.
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")

# Prevent installing to system directories. 
set(CMAKE_INSTALL_PREFIX "${CMAKE_BINARY_DIR}" CACHE INTERNAL "")

project(RoundHell)

set(EXECUTABLE_NAME ${PROJECT_NAME})

add_executable(${EXECUTABLE_NAME})

# Set C++ version.
target_compile_features(${EXECUTABLE_NAME} PUBLIC cxx_std_23)

add_subdirectory(vendor)
add_subdirectory(src)
