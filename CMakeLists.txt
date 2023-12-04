CMAKE_MINIMUM_REQUIRED(VERSION 3.0)
project(MelodyMatch)
# Add the googletest subdirectory
ADD_SUBDIRECTORY(googletest)

ADD_EXECUTABLE(userTest
    unitTestSong/userTest.cpp
    # Add the source file(s) containing the User class implementation
    src/user.cpp
)

ADD_EXECUTABLE(loginAuthTest
    unitTestSong/loginAuthTest.cpp
    # Add the source file(s) containing the User class implementation
    src/loginAuth.cpp
    src/user.cpp
)

ADD_EXECUTABLE(parseSongData
    src/song.cpp
    src/songsDataManager.cpp 
    main.cpp
)

ADD_EXECUTABLE(runAllTests
    test/songtest.cpp 
    src/song.cpp
    src/songsDataManager.cpp 
)

# Link the test executables with the gtest library
TARGET_LINK_LIBRARIES(userTest gtest)
TARGET_LINK_LIBRARIES(loginAuthTest gtest)

# Optionally, disable pthreads for gtest (if needed)
TARGET_COMPILE_DEFINITIONS(userTest PRIVATE gtest_disable_pthreads=ON)
TARGET_COMPILE_DEFINITIONS(loginAuthTest PRIVATE gtest_disable_pthreads=ON)
TARGET_LINK_LIBRARIES(runAllTests gtest)
TARGET_COMPILE_DEFINITIONS(runAllTests PRIVATE gtest_disable_pthreads=ON)