cmake_minimum_required(VERSION 4.0)
project(M_Top)

set(CMAKE_CXX_STANDARD 20)

add_executable(M_Top src/main.cpp
        include/system/Process.h
        include/system/ProcessTable.h
        src/system/ProcessTable.cpp
        include/ui/TerminalUI.h
        src/ui/TerminalUI.cpp
)

target_include_directories(M_Top
        PRIVATE
        ${PROJECT_SOURCE_DIR}/include
)