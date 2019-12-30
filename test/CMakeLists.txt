cmake_minimum_required(VERSION 2.8)

option(CPU_VER "build for CPU" ON)

include_directories(
        ${PROJECT_SOURCE_DIR}/include
        ${PROJECT_SOURCE_DIR}/test
)
# test case的所有cpp文件
set(SOURCE_FILES
        src/gtest_main.cc
        src/test_api.cpp
        src/gtest_helper.cpp
        src/problems/test_3.cpp
        )
# 添加依赖
## base deps
if (${PLATFORM_WIN})
    set(BASE_LIBRARIES gtest.lib hobotlog.lib)
else ()
    set(BASE_DEPS -ldl -lm -lpthread -lrt)
    set(BASE_LIBRARIES ${BASE_LIBRARIES} libgtest.a libhobotlog.a)
    set(BASE_LIBRARIES ${BASE_LIBRARIES} ${BASE_DEPS})
endif ()

## opencv lib & deps
set(OpenCVLib opencv_world)
set(OpenCVDeps libprotobuf libjpeg-turbo libwebp libpng libtiff
        libjasper zlib tegra_hal quirc -ldl -lm -lpthread -lrt)

# mxnet lib & deps
if (${CPU_VER})
    set(MXNET_LIB ${MXNET_LIB} mxnet_mkl.so mklml_intel.so libiomp5.so)
else ()  # mxnet
    set(MXNET_LIB ${MXNET_LIB} mxnet_shared tensorrt_predict nvinfer nvinfer_plugin)
    link_directories(/usr/local/cuda-8.0/lib64/)
    set(MXNET_LIB ${MXNET_LIB} cudnn7 cuda cudart cublas curand culibos cufft nvrtc cusolver)
endif ()

#set(BASE_LIBRARIES ${BASE_LIBRARIES} ${OpenCVLib} ${OpenCVDeps})
#set(BASE_LIBRARIES ${BASE_LIBRARIES} ${MXNET_LIB})

# hobot_util.cmake已经设置了在build/bin中生成可执行文件，默认应该在test目录里生成
add_executable(unit_test ${SOURCE_FILES})
target_link_libraries(unit_test ${CMAKE_PROJECT_NAME} ${BASE_LIBRARIES})