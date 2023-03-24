cmake_minimum_required(VERSION 3.21.0)

project(Breakout)

set(source_dir "${PROJECT_SOURCE_DIR}/src")

set(CMAKE_CONFIGURATION_TYPES "Release" CACHE STRING "" FORCE)
set(CMAKE_CONFIGURATION_TYPES "Debug" CACHE STRING "" FORCE)

file(GLOB_RECURSE sources "${source_dir}/*.cpp")

add_executable(${PROJECT_NAME} ${sources})

if (CMAKE_BUILD_TYPE STREQUAL Debug)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -g")
    target_compile_definitions(${PROJECT_NAME} PUBLIC DEBUG GLEW_STATIC)
elseif(CMAKE_BUILD_TYPE STREQUAL Release)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -o3")
    target_compile_definitions(${PROJECT_NAME} PUBLIC NDEBUG GLEW_STATIC)
else()
    message(FATAL "set build type")
endif()

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_20)

add_subdirectory(vendor/glfw)

target_include_directories(${PROJECT_NAME} PUBLIC src vendor/glew/include vendor/glfw/include vendor/glm/glm vendor/stb/include)

target_link_directories(${PROJECT_NAME} PRIVATE build/vendor/glfw/src vendor/glew/lib)

target_link_libraries(${PROJECT_NAME} PUBLIC glfw3 opengl32 glew32s)