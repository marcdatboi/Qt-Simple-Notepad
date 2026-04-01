



cmake_minimum_required(VERSION 3.16)
project(simplenotepad)

set(CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_PREFIX_PATH "C:/Qt/6.10.2/mingw_64/bin")

set(SOURCES
        src/main.cpp
        src/MainWindow.cpp
        src/NoteTextEditor.cpp
        src/FormatChecker.cpp
        src/ToolBarWidget.cpp

)
set(HEADERS
        include/MainWindow.hpp
        include/NoteTextEditor.hpp
        include/FormatChecker.hpp
        include/ToolBarWidget.hpp

)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)
add_executable(simplenotepad
        ${SOURCES}
        ${HEADERS}
)

target_include_directories(simplenotepad PRIVATE include)
target_link_libraries(simplenotepad PRIVATE
        Qt6::Core
        Qt6::Gui
        Qt6::Widgets
)