CMAKE_MINIMUM_REQUIRED(VERSION 3.0)
<<<<<<< HEAD
project(SongData)

ADD_SUBDIRECTORY(googletest)

ADD_EXECUTABLE(parseSongData
    src/song.cpp
    src/songsDataManager.cpp 
    main.cpp
)

ADD_EXECUTABLE(runAllTests
    test/test.cpp 
    src/song.cpp
    src/songsDataManager.cpp 
=======
project(TestSong)

ADD_SUBDIRECTORY(test/googletest)

ADD_EXECUTABLE(runAllTests
    test/testSong.cpp
    src/song.cpp
>>>>>>> 2d624f9fa5c3e1bc62bc5ebfdcf7516092c0a61d
)

TARGET_LINK_LIBRARIES(runAllTests gtest)
TARGET_COMPILE_DEFINITIONS(runAllTests PRIVATE
gtest_disable_pthreads=ON)