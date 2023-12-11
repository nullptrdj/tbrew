cmake_minimum_required(VERSION 3.27)
project(tbrew C)

set(CMAKE_C_STANDARD 23)

include_directories(include)

add_executable(tbrew
    src/main.c
    src/main.c
    src/vec.c
    src/client.c
    include/client.h
    include/constants.h
    include/language.h
    include/parcel.h
    include/vec.h
)