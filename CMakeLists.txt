CMAKE_MINIMUM_REQUIRED(VERSION 3.0)
project(TestSong)

ADD_SUBDIRECTORY(test/googletest)

ADD_EXECUTABLE(runAllTests
    test/testSong.cpp
    src/song.cpp
)

TARGET_LINK_LIBRARIES(runAllTests gtest)
TARGET_COMPILE_DEFINITIONS(runAllTests PRIVATE
gtest_disable_pthreads=ON)