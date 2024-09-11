cmake_minimum_required(VERSION 3.10)
project(vulkar)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

# Include the directory where VulkanApp.h is located
include_directories(${CMAKE_SOURCE_DIR}/include)

# Include GLFW headers from vcpkg (for static build)
include_directories(C:/src/vcpkg/installed/x64-mingw-static/include)

# Set CMAKE_PREFIX_PATH to include vcpkg installation path for static libraries
set(CMAKE_PREFIX_PATH "${CMAKE_PREFIX_PATH};C:/src/vcpkg/installed/x64-mingw-static")

# Find Vulkan
find_package(Vulkan REQUIRED)

# Gather all the .cpp files in the src directory
file(GLOB SOURCES "src/*.cpp")

# Add the executable
add_executable(vulkar ${SOURCES})

# Explicitly link the static GLFW library
target_link_libraries(vulkar Vulkan::Vulkan C:/src/vcpkg/installed/x64-mingw-static/lib/libglfw3.a)
