cmake_minimum_required(VERSION 3.16)
project(Cirrus LANGUAGES CXX)

include(qt.cmake)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR}
    COMPONENTS
        Core
        Gui
        Widgets
)
qt_standard_project_setup()

set(CMAKE_AUTORCC ON)

set(PROJECT_SOURCES
    main.cpp
    Cirrus.ui
    Cirrus.h
    Cirrus.cpp
    paintscene.h
    paintscene.cpp
    actionmanager.h
    drawaction.h
    action.h
)

set(app_icon_resource_windows "${CMAKE_CURRENT_SOURCE_DIR}/src.qrc")

qt_add_executable(Cirrus ${PROJECT_SOURCES} ${app_icon_resource_windows})

set_target_properties(Cirrus
    PROPERTIES
        WIN32_EXECUTABLE TRUE
)

target_link_libraries(Cirrus
    PUBLIC
        Qt::Core
        Qt::Gui
        Qt::Widgets
)
