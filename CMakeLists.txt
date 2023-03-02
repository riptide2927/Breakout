cmake_minimum_required(VERSION 3.21.0)

project(Breakout)

set(source_dir "${PROJECT_SOURCE_DIR}/src")

set(CMAKE_CONFIGURATION_TYPES "Release" CACHE STRING "" FORCE)
set(CMAKE_CONFIGURATION_TYPES "Debug" CACHE STRING "" FORCE)

file(GLOB_RECURSE sources "${source_dir}/*.cpp")

add_executable(${PROJECT_NAME} ${sources})

if (CMAKE_BUILD_TYPE STREQUAL Debug)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -g")
    target_compile_definitions(${PROJECT_NAME} PUBLIC DEBUG)
elseif(CMAKE_BUILD_TYPE STREQUAL Release)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -o3")
    target_compile_definitions(${PROJECT_NAME} PUBLIC NDEBUG)
else()
    message(FATAL "set build type")
endif()

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_20)