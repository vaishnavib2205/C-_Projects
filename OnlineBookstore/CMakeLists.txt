cmake_minimum_required(VERSION 3.10)
project(OnlineBookstore)

set(CMAKE_CXX_STANDARD 17)

add_executable(OnlineBookstore
    main.cpp
    database.cpp
    user.cpp
    book.cpp
    order.cpp
)

target_include_directories(OnlineBookstore PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
