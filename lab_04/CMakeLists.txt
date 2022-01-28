cmake_minimum_required(VERSION 3.16.3)
project(lab_04)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(QT_VERSION 5)
set(REQUIRED_LIBS Core Gui Widgets)
set(REQUIRED_LIBS_QUALIFIED Qt5::Core Qt5::Gui Qt5::Widgets)

add_executable(${PROJECT_NAME}
        src/main.cpp
        src/mainwindow.cpp
        inc/mainwindow.h
        inc/define.h
        inc/button.h
        src/button.cpp
        inc/lift.h
        inc/lift_control.h
        src/lift_control.cpp
        inc/door.h
        src/door.cpp
        inc/lift_cabin.h
        src/lift_cabin.cpp src/lift.cpp)

find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)
target_link_libraries(${PROJECT_NAME} ${REQUIRED_LIBS_QUALIFIED} config++)
