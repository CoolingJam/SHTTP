project(SHTTP)

set(CMAKE_CXX_STANDARD 23)
option(CROSSCHAT_BUILD_STATIC "Build SHTTP as static executable" OFF)

add_executable(shttp main.cpp server.cpp)

if (SHTTP_BUILD_STATIC)
    message("Linking statically. To link dynamically, in the root CMakeLists.txt set SHTTP_BUILD_STATIC to OFF")
    target_link_libraries(shttp PRIVATE sockpp-static)  # Link to sockpp_static
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static")
else()
    message("Linking dynamically. To link statically, in the root CMakeLists.txt set SHTTP_BUILD_STATIC to ON")
    target_link_libraries(shttp PRIVATE sockpp)  # Link to sockpp_static
endif()

target_include_directories(shttp PRIVATE ${sockpp_SOURCE_DIR}/include ${toml11_SOURCE_DIR} ./)