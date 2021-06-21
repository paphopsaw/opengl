cmake_minimum_required(VERSION 3.10)

set(CMAKE_BUILD_TYPE Release)
set(PROJECT_ROOT ${CMAKE_SOURCE_DIR})

configure_file (
  ${CMAKE_SOURCE_DIR}/src/config.h.in
  config.h
  )

project(LearnOpenGL)

find_package(OpenGL REQUIRED)



IF(MSVC)
  set(GLFW_LIBRARY  ${CMAKE_SOURCE_DIR}/dependencies/glfw/lib/glfw3.lib)
ELSEIF(APPLE)
  set(GLFW_LIBRARY  ${CMAKE_SOURCE_DIR}/dependencies/glfw/lib/libglfw3_mac.a)
ELSEIF(UNIX)
  set(GLFW_LIBRARY  ${CMAKE_SOURCE_DIR}/dependencies/glfw/lib/libglfw3_linux.a)
ENDIF()

# Assimp


set(ZLIB_LIBRARIES zlibstatic)
set(ENABLE_BOOST_WORKAROUND ON)
set(BUILD_SHARED_LIBS OFF)
set(BUILD_ASSIMP_TOOLS  ON)
add_subdirectory(dependencies/assimp-5.0.1)

include_directories(
    ${CMAKE_SOURCE_DIR}/src/commons
    ${CMAKE_SOURCE_DIR}/dependencies/glfw/include
    ${CMAKE_SOURCE_DIR}/dependencies/glad/include
    ${CMAKE_SOURCE_DIR}/dependencies/stb_image/include
    ${CMAKE_SOURCE_DIR}/dependencies/glm/include
    ${CMAKE_SOURCE_DIR}/dependencies/assimp-5.0.1/include
    ${PROJECT_BINARY_DIR}
    )

file (GLOB_RECURSE COMMONS CONFIGURE_DEPENDS
    ${CMAKE_SOURCE_DIR}/src/commons/*.h
    ${CMAKE_SOURCE_DIR}/src/commons/*.cpp
)
    
IF (APPLE)
    find_library( COCOA_LIBRARY Cocoa )
    find_library( IOKIT_LIBRARY IOKit )
    find_library( COREVIDEO_LIBRARY CoreVideo )
    link_libraries(
        ${OPENGL_LIBRARY}
        ${GLFW_LIBRARY}
        ${COCOA_LIBRARY}
        ${IOKIT_LIBRARY}
        ${COREVIDEO_LIBRARY})

ELSEIF(UNIX)
    link_libraries(
        ${OPENGL_LIBRARY}
        ${GLFW_LIBRARY}
        -lrt -lm -ldl -lX11 -lpthread -lxcb -lXau -lXdmcp
        )

ELSEIF(MSVC)
    link_libraries(
        ${OPENGL_LIBRARY}
        ${GLFW_LIBRARY}
        ${ZLIB_LIBRARIES}
        assimp
        )
ENDIF()


add_executable(GettingStarted
    ${CMAKE_SOURCE_DIR}/src/GettingStarted.cpp
    ${CMAKE_SOURCE_DIR}/dependencies/glad/lib/glad.c
    ${CMAKE_SOURCE_DIR}/dependencies/stb_image/lib/stb_image.cpp
    ${COMMONS}
    )

add_executable(Lighting
    ${CMAKE_SOURCE_DIR}/src/Lighting.cpp
    ${CMAKE_SOURCE_DIR}/dependencies/glad/lib/glad.c
    ${CMAKE_SOURCE_DIR}/dependencies/stb_image/lib/stb_image.cpp
    ${COMMONS}
    )

add_executable(ModelLoading
    ${CMAKE_SOURCE_DIR}/src/ModelLoading.cpp
    ${CMAKE_SOURCE_DIR}/dependencies/glad/lib/glad.c
    ${CMAKE_SOURCE_DIR}/dependencies/stb_image/lib/stb_image.cpp
    ${COMMONS}
    )