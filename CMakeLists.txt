cmake_minimum_required(VERSION 3.10)

set(CMAKE_BUILD_TYPE Debug)
set(PROJECT_ROOT ${CMAKE_SOURCE_DIR})

configure_file (
  ${CMAKE_SOURCE_DIR}/src/config.h.in
  config.h
  )

project(LearnOpenGL)

find_package(OpenGL REQUIRED)

IF(MSVC)
  set(GLFW_LIBRARY  ${CMAKE_SOURCE_DIR}/dependencies/glfw/lib/glfw3.lib)
ELSE()
  set(GLFW_LIBRARY  ${CMAKE_SOURCE_DIR}/dependencies/glfw/lib/libglfw3.a)
ENDIF()


include_directories(
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_SOURCE_DIR}/dependencies/glfw/include
    ${CMAKE_SOURCE_DIR}/dependencies/glad/include
    ${CMAKE_SOURCE_DIR}/dependencies/stb_image
    ${PROJECT_BINARY_DIR}
    )

file (GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS
    ${CMAKE_SOURCE_DIR}/src/*.h
    ${CMAKE_SOURCE_DIR}/src/*.hpp
    ${CMAKE_SOURCE_DIR}/src/*.c
    ${CMAKE_SOURCE_DIR}/src/*.cpp
)

add_executable(${PROJECT_NAME}
    ${CMAKE_SOURCE_DIR}/dependencies/glad/lib/glad.c
    ${CMAKE_SOURCE_DIR}/dependencies/stb_image/stb_image.cpp
    ${SRC_FILES}
    )

    
if (APPLE)
    find_library( COCOA_LIBRARY Cocoa )
    find_library( IOKIT_LIBRARY IOKit )
    find_library( COREVIDEO_LIBRARY CoreVideo )
    target_link_libraries(${PROJECT_NAME}
        ${OPENGL_LIBRARY}
        ${GLFW_LIBRARY}
        ${COCOA_LIBRARY}
        ${IOKIT_LIBRARY}
        ${COREVIDEO_LIBRARY})

ELSEIF(MSVC)
    target_link_libraries(${PROJECT_NAME}
        ${OPENGL_LIBRARY}
        ${GLFW_LIBRARY}
        )
ENDIF()