cmake_minimum_required(VERSION 3.15)
project(NeironTest CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(model
    Model/Model.cpp
    Model/BaseClass/Base.cpp
    Model/Mode/Check.cpp
    Model/Mode/Learn.cpp
    Model/Operation/Randome.cpp
    Model/WorkWithData/File.cpp
)

if(MSVC)
    target_compile_options(model PRIVATE /W4 /utf-8)
else()
    target_compile_options(model PRIVATE -Wall -Wextra -Wpedantic)
endif()
