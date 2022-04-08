
cmake_minimum_required(VERSION 3.10)

set(PROJECT_NAME "simple_http_server")

set(CMAKE_CXX_STANDARD 17)

project(${PROJECT_NAME})

add_executable(${PROJECT_NAME} src/main.cpp)

target_include_directories(${PROJECT_NAME} PRIVATE include)

target_sources(${PROJECT_NAME} PRIVATE
    src/main.cpp
    src/Application.cpp
    src/Listener.cpp
    src/Poller.cpp
    src/Service.cpp
    src/IOEpoll.cpp
    src/EpollWorker.cpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE "-pthread")