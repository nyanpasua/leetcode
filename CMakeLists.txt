cmake_minimum_required(VERSION 2.8)
include(cmake/hobot_util.cmake)

# 项目名称
project(leetcode)
set(CMAKE_CXX_STANDARD 11)
option(RELEASE_LIB "build version of release" OFF)

if (${PLATFORM_MAC})
    add_definitions(-DHR_POSIX)
    add_definitions(-DHR_MAC)
elseif (${PLATFORM_LINUX})
    add_definitions(-DHR_POSIX)
    add_definitions(-DHR_LINUX)
elseif (${PLATFORM_ANDROID})
    set(ENABLE_NEON "true")
    add_definitions(-DENABLE_OMP)
    add_definitions(-DHR_POSIX)
    add_definitions(-DHR_ANDROID)
elseif (${PLATFORM_WIN})
    set(CMAKE_CXX_FLAGS_RELEASE "/MD")
    set(CMAKE_CXX_FLAGS_DEBUG "/MDd")
    add_definitions(-DHR_WIN)
    add_definitions(-D_MBCS)
    add_definitions(-DHOBOT_EXPORTS)
else ()
    message(FATAL_ERROR "invoke cmake with -DPLATFORM_MAC=TRUE|-DPLATFORM_LINUX=TRUE|-DPLATFORM_ANDROID=TRUE|-DPLATFORM_WIN=TRUE")
    return()
endif ()
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
file(GLOB PROJECT_INC
        "include/*.h"
        "include/*.hpp"
        "include/leetcode/*.h"
        "include/leetcode/utils/*.h"
        "include/leetcode/data_structure/*.h"
        )

# 源文件路径信息
file(GLOB PROJECT_SRC
        "src/leetcode/*.cpp"
        "src/utils/*.cpp"
        "src/problems/*.cpp"
        "src/ds/sort/*.cpp"
        )

set(SOURCE_FILES
        ${PROJECT_SRC}
        ${PROJECT_INC}
        )

add_library(${CMAKE_PROJECT_NAME} SHARED ${SOURCE_FILES})

add_subdirectory(test)

set(OUTPUT_ROOT ${PROJECT_SOURCE_DIR}/output)
set(MY_OUTPUT_ROOT ${OUTPUT_ROOT}/${CMAKE_PROJECT_NAME})
install(DIRECTORY
        ${PROJECT_SOURCE_DIR}/build/lib/
        DESTINATION ${MY_OUTPUT_ROOT}/lib/)
install(DIRECTORY
        ${PROJECT_SOURCE_DIR}/include/${CMAKE_PROJECT_NAME}/
        DESTINATION ${MY_OUTPUT_ROOT}/include/${CMAKE_PROJECT_NAME})