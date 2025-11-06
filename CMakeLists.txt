cmake_minimum_required(VERSION 3.10)
project(Melodie)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE_FILES src/Melodie.cpp src/main.cpp)

include_directories(include)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
