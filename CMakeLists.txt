cmake_minimum_required(VERSION 3.26)
project(SIECI_ZPO)

set(CMAKE_CXX_STANDARD 17)
include_directories(include)
set(SOURCE_FILES
        src/package.cpp)
add_executable(SIECI_ZPO ${SOURCE_FILES}  main.cpp)

set(SOURCES_FILES_TESTS
    test/test_package.cpp)
set(EXEC_TEST SIECI_ZPO_test)
add_executable(${EXEC_TEST} ${SOURCE_FILES} ${SOURCES_FILES_TESTS} test/main_gtest.cpp)

set(GTEST_ROOT ./googletest-master)
target_include_directories(${EXEC_TEST} PUBLIC
        ${GTEST_ROOT}/googlemock/include
        ${GTEST_ROOT}/googletest/include)
add_subdirectory(${GTEST_ROOT} googletest-master)

target_link_libraries(${EXEC_TEST} gmock)