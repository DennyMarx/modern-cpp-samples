cmake_minimum_required(VERSION 3.12)

project(ThreadsFuturePromise VERSION 1.0 LANGUAGES CXX)

# compile with debug symbols only if build type is Debug
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g")

add_library(libThreadsFuturePromise STATIC
  source/main.cpp
)

target_compile_features(libThreadsFuturePromise PUBLIC cxx_std_14)

target_include_directories(fusion
  PUBLIC
    $<BUILD_INTERFACE:>${CMAKE_CURRENT_SOURCE_DIR}/source
    #$<BUILD_INTERFACE:>${CMAKE_CURRENT_SOURCE_DIR}/extern
)

# Testing
enable_testing()

include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.8.1
)

FetchContent_GetProperties(googletest)
if(NOT googletest_POPULATED)
  FetchContent_Populate(googletest)
  add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})
endif()

add_executable(testThreadFuturePromise
  test/testThreadFuturePromise.cpp
)

target_link_libraries(testThreadFuturePromise PRIVATE gtest gmock gtest_main libThreadsFuturePromise)
target_compile_features(testThreadFuturePromise PRIVATE cxx_std_14)
# target_include_directories(FusionTest PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../extern)

add_test(testsThreadFuturePromise testThreadFuturePromise)
