cmake_minimum_required(VERSION 3.27)
project(tbrew C)

set(CMAKE_C_STANDARD 23)
set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS "-g")
set(CMAKE_CXX_FLAGS "-O3")

include_directories(include)

add_executable(tbrew
    src/tbrew.c
    src/tbrew.c
    src/vec.c
    src/client.c
    include/client.h
    include/constants.h
    include/language.h
    include/parcel.h
    include/vec.h
    include/tbrew.h
    include/messages.h
)