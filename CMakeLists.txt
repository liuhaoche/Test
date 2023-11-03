cmake_minimum_required(VERSION 3.0.0)
project(MyClinet VERSION 0.1.0)

include(CTest)
enable_testing()

aux_source_directory(. SRC_FILE)

add_executable(MyClinet ${SRC_FILE})

target_link_libraries(${CMAKE_PROJECT_NAME} ws2_32)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
