include(GoogleTest)
include(FetchContent)

cmake_minimum_required(VERSION 3.11)
project(BraviaCtrl VERSION 0.0.1 
  DESCRIPTION "Command line IP-based Bravia TV Remote"
    LANGUAGES CXX)
add_compile_options(-Wall -Wextra -W -Wshadow -Wformat -fexceptions)
set(CMAKE_CXX_FLAGS_DEBUG "-g -pipe")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -pipe")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE_DIRECTORY "src")
set(INCLUDE_DIRECTORY "include")
set(TEST_DIRECTORY "tests")

include_directories(
  ${SOURCE_DIRECTORY}
  ${INCLUDE_DIRECTORY}
  ${TEST_DIRECTORY}
  )

file(GLOB SOURCES "${SOURCE_DIRECTORY}/*.cpp")

### Unit Testing ###
enable_testing()

macro(add_unit_test TARGET_TEST)
    add_test(${TARGET_TEST} ${CMAKE_CURRENT_BINARY_DIR}/${TARGET_TEST})
    set(UNIT_TEST_TARGETS ${UNIT_TEST_TARGETS} ${TARGET_TEST})
    add_executable(
      ${TARGET_TEST}
      ${TEST_DIRECTORY}/${TARGET_TEST}.cpp
      )
    target_link_libraries(${TARGET_TEST} GTest::gtest_main)
endmacro(add_unit_test)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1
  )
FetchContent_MakeAvailable(googletest)
include_directories(${googletest_SOURCE_DIR}/googletest/include/gtest)

add_unit_test(braviaCommands_test)
gtest_discover_tests(braviaCommands_test)

# TODO Need to run tests on build and fail if tests do not pass
# reference this: https://stackoverflow.com/questions/15115075/how-to-run-ctest-after-building-my-project-with-cmake

add_executable(
  ${CMAKE_PROJECT_NAME}
  ${SOURCES}
)

target_link_libraries(
  ${CMAKE_PROJECT_NAME}
)

