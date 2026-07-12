cmake_minimum_required(VERSION 4.2)
project(CPPLearn)

set(CMAKE_CXX_STANDARD 20)

# 自动发现 src/ 下所有 .cpp 文件，每个文件构建为独立的可执行文件
# CONFIGURE_DEPENDS: 新增/删除文件时 CLion 自动重新运行 CMake
file(GLOB LESSON_SOURCES CONFIGURE_DEPENDS "src/*.cpp")

foreach(SOURCE_FILE ${LESSON_SOURCES})
    get_filename_component(LESSON_NAME ${SOURCE_FILE} NAME_WE)
    add_executable(${LESSON_NAME} ${SOURCE_FILE})
    message(STATUS "Lesson target: ${LESSON_NAME}  <-  ${SOURCE_FILE}")
endforeach()
