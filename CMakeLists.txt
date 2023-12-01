CMAKE_MINIMUM_REQUIRED(VERSION 3.0)
project(SongData)

ADD_SUBDIRECTORY(googletest)

ADD_EXECUTABLE(parseSongData
    src/song.cpp
    src/SongsDataManager.cpp 
    main.cpp
)

ADD_EXECUTABLE(runAllTests
    test/test.cpp 
    src/song.cpp
    src/SongsDataManager.cpp 
)

TARGET_LINK_LIBRARIES(runAllTests gtest)
TARGET_COMPILE_DEFINITIONS(runAllTests PRIVATE
gtest_disable_pthreads=ON)