cmake_minimum_required(VERSION 3.9)
set(PROJECT_NAME GridCellFramework)
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 17)

set(SFML_ROOT "C:/mingw64/SFML242/")
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})

set(SOURCE_FILES
        src/Application.cpp
        include/Application.h
        src/Grid.cpp
        include/Grid.h
        src/Cell.cpp
        include/Cell.h
        src/main.cpp src/Config.cpp include/Config.h)


find_package(SFML 2 COMPONENTS system window graphics audio)
include_directories(${SFML_INCLUDE_DIR})

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})