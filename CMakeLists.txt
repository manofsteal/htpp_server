
cmake_minimum_required(VERSION 3.10)

set(PROJECT_NAME "http_server")

set(CMAKE_CXX_STANDARD 17)

project(${PROJECT_NAME})

find_package(Threads REQUIRED)

include(cmake/sanitizer.cmake)

add_executable(${PROJECT_NAME} src/main.cpp)

target_include_directories(${PROJECT_NAME} PRIVATE include)

target_sources(${PROJECT_NAME} PRIVATE
    src/main.cpp
    src/Application.cpp
    src/IOEpoll.cpp
    src/EpollWorker.cpp
    src/IOSocketCli.cpp
    src/IOSocketSrv.cpp
    src/EpollPool.cpp
    src/HttpService.cpp
    src/HttpMessage.cpp
    src/Executor.cpp
    src/ExecutorPool.cpp
    src/Signals.cpp

)

target_compile_options(${PROJECT_NAME} PRIVATE "-fno-exceptions")
target_compile_options(${PROJECT_NAME} PRVIATE "-rdynamic")
target_link_libraries(${PROJECT_NAME} PRIVATE Threads::Threads)