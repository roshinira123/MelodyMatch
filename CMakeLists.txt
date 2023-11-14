CMAKE_MINIMUM_REQUIRED(VERSION 3.0)

# Add the googletest subdirectory
ADD_SUBDIRECTORY(googletest)

# Define your test executable
ADD_EXECUTABLE(songTest
    unitTestSong/songTest.cpp
)

# Link the test executable with the gtest library
TARGET_LINK_LIBRARIES(songTest gtest)

# Optionally, disable pthreads for gtest (if needed)
TARGET_COMPILE_DEFINITIONS(songTest PRIVATE gtest_disable_pthreads=ON)
