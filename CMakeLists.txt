cmake_minimum_required(VERSION 3.26)
project(SHTTP VERSION 0.1.0 LANGUAGES CXX)

set(SHTTP_BUILD_STATIC ON)
Include(FetchContent)

FetchContent_Declare(
        sockpp
        GIT_REPOSITORY  https://github.com/fpagliughi/sockpp
        GIT_TAG         v0.8.1
)

FetchContent_Declare(
        toml11
        GIT_REPOSITORY  https://github.com/ToruNiina/toml11
        GIT_TAG         v3.7.1
)

set(SOCKPP_BUILD_SHARED ON CACHE BOOL "" FORCE)
set(SOCKPP_BUILD_STATIC ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(sockpp)
FetchContent_MakeAvailable(toml11)

add_subdirectory(src)