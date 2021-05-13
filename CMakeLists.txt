cmake_minimum_required(VERSION 3.1)
# 项目名称
project(leetcode)
set(CMAKE_CXX_STANDARD 11)
option(RELEASE_LIB "build version of release" OFF)

# 编译模式
if (${RELEASE_LIB})
    set(CMAKE_BUILD_TYPE Release)
    add_definitions(-DCMAKE_BUILD_TYPE=Release)
else ()
    set(CMAKE_BUILD_TYPE Debug)
    add_definitions(-DCMAKE_BUILD_TYPE=Debug)
endif ()

# 编译参数
if (NOT PLATFORM_WIN)
    if (${CMAKE_BUILD_TYPE} STREQUAL "Release")
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x -fPIC -Ofast")
    else ()
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x -DEBUG -g -O0 -fPIC")
    endif ()
endif ()

# 添加头文件路径
include_directories(
        ${PROJECT_SOURCE_DIR}/include
        ${PROJECT_SOURCE_DIR}/third_party/include
)
link_directories(
        ${PROJECT_SOURCE_DIR}/third_party/lib
)
# 头文件路径信息
file(GLOB_RECURSE PROJECT_INC
        "include/*.h"
        "include/*.hpp"
        )

# 源文件路径信息
file(GLOB_RECURSE PROJECT_SRC
        "src/*.cpp"
        "src/*.cc"
        "src/*.h"
        "src/*.hpp"
        )

set(SOURCE_FILES
        ${PROJECT_SRC}
        ${PROJECT_INC}
        )

add_library(${CMAKE_PROJECT_NAME} SHARED ${SOURCE_FILES})

set(OUTPUT_ROOT ${PROJECT_SOURCE_DIR}/output)
set(MY_OUTPUT_ROOT ${OUTPUT_ROOT}/${CMAKE_PROJECT_NAME})
install(DIRECTORY
        ${PROJECT_SOURCE_DIR}/build/lib/
        DESTINATION ${MY_OUTPUT_ROOT}/lib/)
install(DIRECTORY
        ${PROJECT_SOURCE_DIR}/include/${CMAKE_PROJECT_NAME}/
        DESTINATION ${MY_OUTPUT_ROOT}/include/${CMAKE_PROJECT_NAME})