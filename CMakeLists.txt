cmake_minimum_required(VERSION 3.10)
project(UT_SDL2)

set(CMAKE_CXX_STANDARD 17)


#if(${CMAKE_BINARY_DIR} STRNOTEQUAL ${CMAKE_SOURCE_DIR})
#CLION执行文件输出位置
#-----------------------------------------------------------------------------
# Redirect output files

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin CACHE INTERNAL "" FORCE)
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib CACHE INTERNAL "" FORCE)
#set(TESTS_OUTPUT_DIR ${EXECUTABLE_OUTPUT_PATH}/tests CACHE INTERNAL "" FORCE)
#endif()
set(UT_INCLUDE_DIRS
        "include"
        "include/SDL2"
        "./"
        "include/glad"
        )

include_directories(${UT_INCLUDE_DIRS})

set(UT_LIBRARIES_DIRS
        "lib")
link_directories(${UT_LIBRARIES_DIRS})

#add_definitions(-D_GLIBCXX_USE_CXX17_ABI=0)


add_subdirectory("UtCore")
add_subdirectory("UtEngine")
add_subdirectory("UtGui")
add_subdirectory("UtMath")

add_executable(UT_SDL2 main.cpp)


target_link_libraries(UT_SDL2
        SDL2
        UtCore
        UtEngine
        UtGui
        assimp
        )
add_executable(testmath testmath.cpp)
target_link_libraries(testmath
        SDL2
        dl)