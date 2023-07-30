cmake_minimum_required(VERSION 3.26)
project(SHTTP VERSION 0.1.0 LANGUAGES CXX)

set(SHTTP_BUILD_STATIC ON)
Include(FetchContent)

FetchContent_Declare(
        sockpp
        GIT_REPOSITORY https://github.com/fpagliughi/sockpp
        GIT_TAG        v0.8.1
)

set(SOCKPP_BUILD_SHARED ON CACHE BOOL "" FORCE)
set(SOCKPP_BUILD_STATIC ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(sockpp)

add_subdirectory(src)