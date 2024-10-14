add_library(Note Note.cpp Folder.cpp)

# Abilita Google Test se non è già stato fatto in tst
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/release-1.11.0.tar.gz
)
FetchContent_MakeAvailable(googletest)

# Collega Google Test alle librerie se necessario
target_link_libraries(Note pthread)