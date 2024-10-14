cmake_minimum_required(VERSION 3.28)
project(ProgettoLabDiProgrammazione)

set(CMAKE_CXX_STANDARD 17)

add_executable(ProgettoLabDiProgrammazione main.cpp
        src/Note.cpp
        src/Note.h
        src/Folder.cpp
        src/Folder.h
        src/Folder.h
        tst/NoteTest.cpp
        tst/FolderTest.cpp)

add_subdirectory(src)
add_subdirectory(tst)
