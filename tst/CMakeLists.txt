enable_testing()

# Fetch Google Test
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/release-1.11.0.tar.gz
)
FetchContent_MakeAvailable(googletest)

# Aggiungi i file di test
add_executable(runUnitTests NoteTest.cpp FolderTest.cpp)

# Collega Google Test e la libreria Note
target_link_libraries(runUnitTests gtest gtest_main pthread Note)