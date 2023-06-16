cmake_minimum_required(VERSION 3.5)

project(TicTacToe VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets LinguistTools)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets LinguistTools)

enable_testing()

option(BUILD_TESTS "Включить сборку тестов" ON)

set(PROJECT_SOURCES
        mainwindow.cpp
        mainwindow.h
        dialog.ui
        dialog.h
        dialog.cpp
        mainwindow.ui
)


if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(TicTacToe
        MANUAL_FINALIZATION
        main.cpp ${PROJECT_SOURCES}
    )

else()
    if(ANDROID)
        add_library(TicTacToe SHARED
            main.cpp ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(TicTacToe
            main.cpp ${PROJECT_SOURCES}
        )
    endif()

endif()

target_link_libraries(TicTacToe PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(TicTacToe PROPERTIES
    # MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS TicTacToe
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(TicTacToe)
endif()

if (BUILD_TESTS)
    add_subdirectory(doctest)
    include_directories("${CMAKE_SOURCE_DIR}")
    add_executable(tests test.cpp ${PROJECT_SOURCES})
    target_link_libraries(tests PRIVATE doctest::doctest Qt${QT_VERSION_MAJOR}::Widgets)
endif (BUILD_TESTS)
