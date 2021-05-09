cmake_minimum_required(VERSION 3.10)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

project(LearnOpenGL)

find_package(OpenGL REQUIRED)

find_library( COCOA_LIBRARY Cocoa )
find_library( IOKIT_LIBRARY IOKit )
find_library( COREVIDEO_LIBRARY CoreVideo )


include_directories(
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_SOURCE_DIR}/dependencies/glfw/include
    ${CMAKE_SOURCE_DIR}/dependencies/glad/include
    )

file (GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS
${CMAKE_SOURCE_DIR}/src/*.h
${CMAKE_SOURCE_DIR}/src//*.hpp
${CMAKE_SOURCE_DIR}/src//*.c
${CMAKE_SOURCE_DIR}/src//*.cpp
)

add_executable(${PROJECT_NAME}
    ${CMAKE_SOURCE_DIR}/dependencies/glad/lib/glad.c
    ${SRC_FILES}
    )

target_link_libraries(${PROJECT_NAME} 
    ${CMAKE_SOURCE_DIR}/dependencies/glfw/lib/libglfw3.a
    ${OPENGL_LIBRARY}
    ${COCOA_LIBRARY}
    ${IOKIT_LIBRARY}
    ${COREVIDEO_LIBRARY})