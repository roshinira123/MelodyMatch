CMAKE_MINIMUM_REQUIRED(VERSION 3.0)

# Add the googletest subdirectory
ADD_SUBDIRECTORY(googletest)

# Define your test executables with unique names
ADD_EXECUTABLE(songTest
    unitTestSong/songTest.cpp
)

ADD_EXECUTABLE(userTest
    unitTestSong/userTest.cpp
    # Add the source file(s) containing the User class implementation
    src/user.cpp
)

# Link the test executables with the gtest library
TARGET_LINK_LIBRARIES(songTest gtest)
TARGET_LINK_LIBRARIES(userTest gtest)

# Optionally, disable pthreads for gtest (if needed)
TARGET_COMPILE_DEFINITIONS(songTest PRIVATE gtest_disable_pthreads=ON)
TARGET_COMPILE_DEFINITIONS(userTest PRIVATE gtest_disable_pthreads=ON)
