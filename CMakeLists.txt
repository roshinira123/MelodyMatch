CMAKE_MINIMUM_REQUIRED(VERSION 3.0)
project(SongData)

ADD_SUBDIRECTORY(googletest)

ADD_EXECUTABLE(runFilter
    src/songsDataFilter.cpp
    src/songsDataManager.cpp 
    src/song.cpp
    mainFilter.cpp
)

ADD_EXECUTABLE(MelodyMatch
    src/songsDataFilter.cpp
    src/songsDataManager.cpp 
    src/song.cpp
    src/mainMenu.cpp
)


ADD_EXECUTABLE(parseSongData
    src/song.cpp
    src/songsDataManager.cpp 
    songDatamain.cpp
)

ADD_EXECUTABLE(runAllTests
    test/test.cpp 
    src/song.cpp
    src/songsDataManager.cpp 
)

TARGET_LINK_LIBRARIES(runAllTests gtest)
TARGET_COMPILE_DEFINITIONS(runAllTests PRIVATE
gtest_disable_pthreads=ON)