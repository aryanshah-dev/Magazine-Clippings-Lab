
cmake_minimum_required(VERSION 3.20)
project(MagazineClippings)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v3.8.1
)

FetchContent_MakeAvailable(Catch2)

add_executable(MagazineTests
        tests.cpp
        magazine.cpp
)

target_link_libraries(MagazineTests PRIVATE Catch2::Catch2WithMain)

add_executable(MagazineBenchmark
        benchmark.cpp
        magazine.cpp
)

target_link_libraries(MagazineBenchmark PRIVATE Catch2::Catch2WithMain)

add_executable(ShakespeareStressTest
        stress_test.cpp
        magazine.cpp
)
