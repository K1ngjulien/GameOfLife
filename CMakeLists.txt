cmake_minimum_required(VERSION 3.9)
set(PROJECT_NAME GameOfLife) #Project name as a Variable for Changeability
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})

set(SOURCE_FILES
        src/Config.cpp
        include/Config.h
        src/Application.cpp
        include/Application.h
        src/Grid.cpp
        include/Grid.h
        src/Cell.cpp
        include/Cell.h
        src/main.cpp)

find_package(SFML 2 COMPONENTS system window graphics)  #Include SFML
include_directories(${SFML_INCLUDE_DIR})

add_executable(${PROJECT_NAME} ${SOURCE_FILES}) #Add Executable
target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES}) #Link SFML ( SFML Root is in PATH Evionment Variable)