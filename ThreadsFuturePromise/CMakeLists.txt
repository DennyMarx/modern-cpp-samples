cmake_minimum_required(VERSION 3.12)

project(ThreadsFuturePromisePrj VERSION 1.0 LANGUAGES CXX)

set(PRJ_ROOT_DIR .)

# set outour directories
set(PRJ_OUTPUT_DIR ${PRJ_ROOT_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PRJ_OUTPUT_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PRJ_OUTPUT_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PRJ_OUTPUT_DIR})

# setup main lib name
set(PRJ_MAIN_LIB ThreadsFuturePromise)

# setup source paths
set(PRJ_SRC_FOLDER source)

set(PRJ_SRC_PATH ${PRJ_ROOT_DIR}/${PRJ_SRC_FOLDER})


#collect sources
set(PRJ_SOURCES
  ${PRJ_SRC_PATH}/ISensor.h
  ${PRJ_SRC_PATH}/Sensor.cpp
  ${PRJ_SRC_PATH}/Sensor.h
  ${PRJ_SRC_PATH}/SensorData.h
  ${PRJ_SRC_PATH}/SensorData.cpp
)


# compile with debug symbols
set(CMAKE_CXX_FLAGS "-g")

add_library(${PRJ_MAIN_LIB} STATIC
  ${PRJ_SOURCES}
)


target_compile_features(${PRJ_MAIN_LIB} PUBLIC cxx_std_14)

target_include_directories(${PRJ_MAIN_LIB}
  PUBLIC
    $<BUILD_INTERFACE:>${CMAKE_CURRENT_SOURCE_DIR}/source
) 


# Testing
enable_testing()

include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.10.0
)

FetchContent_GetProperties(googletest)
if(NOT googletest_POPULATED)
  FetchContent_Populate(googletest)
  add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})
endif()

# console test app
add_executable(ConsoleApp
  test/testThreadFuturePromise.cpp
)

target_link_libraries(ConsoleApp PRIVATE gtest gmock gtest_main ${PRJ_MAIN_LIB})
target_compile_features(ConsoleApp PRIVATE cxx_std_14)


# GTest app
add_executable(GTestApp
  test/UnitTestsMain.cpp
)

target_link_libraries(GTestApp PRIVATE gtest gmock gtest_main ${PRJ_MAIN_LIB})
target_compile_features(GTestApp PRIVATE cxx_std_14)

add_test(testActivateSensor GTestApp)
