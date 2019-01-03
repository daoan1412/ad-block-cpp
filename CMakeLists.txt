cmake_minimum_required(VERSION 3.13)
project(ad_enhance)

set(CMAKE_CXX_STANDARD 11)

file(GLOB SOURCE2  "./bloom-filter-cpp/*.cpp" "./bloom-filter-cpp/*.h")
file(GLOB SOURCE3  "./hashset-cpp/*.cc" "./hashset-cpp/*.h")
file(GLOB SOURCES "./*.cc" "./*.h" )


add_executable(ad_enhance ${SOURCES} ${SOURCE2} ${SOURCE3})