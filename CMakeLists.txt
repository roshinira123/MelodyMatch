CMAKE_MINIMUM_REQUIRED(VERSION 3.0)
set(CMAKE_BUILD_TYPE Debug)
project(MelodyMatch)

ADD_SUBDIRECTORY(googletest)

ADD_EXECUTABLE(userTest
    unitTestSong/userTest.cpp
    src/user.cpp
)

ADD_EXECUTABLE(loginAuthTest
    unitTestSong/loginAuthTest.cpp
    src/loginAuth.cpp
    src/user.cpp
)

ADD_EXECUTABLE(mainLoginTest
    unitTestSong/mainLogin.cpp
    src/loginAuth.cpp
    src/user.cpp
)

TARGET_LINK_LIBRARIES(userTest gtest)
TARGET_LINK_LIBRARIES(loginAuthTest gtest)
TARGET_LINK_LIBRARIES(mainLoginTest gtest) # Note: 'mainTest' should be 'mainLoginTest'

TARGET_COMPILE_DEFINITIONS(userTest PRIVATE gtest_disable_pthreads=ON)
TARGET_COMPILE_DEFINITIONS(loginAuthTest PRIVATE gtest_disable_pthreads=ON)

# New Targets from the second CMakeLists.txt

project(SongData)
set(CMAKE_BUILD_TYPE Debug)

ADD_EXECUTABLE(MelodyMatch
    src/songsDataFilter.cpp
    src/songsDataManager.cpp 
    src/loginAuth.cpp
    src/user.cpp
    src/song.cpp
    src/main.cpp
    src/mainMenu.cpp
)

ADD_EXECUTABLE(runAllTests
    test/test.cpp 
    src/song.cpp
    src/songsDataManager.cpp
    src/songsDataFilter.cpp
)

TARGET_LINK_LIBRARIES(MelodyMatch gtest)
TARGET_LINK_LIBRARIES(runAllTests gtest)
TARGET_COMPILE_DEFINITIONS(runAllTests PRIVATE gtest_disable_pthreads=ON)