cmake_minimum_required(VERSION 3.13)
project(ad_enhance)

set(CMAKE_CXX_STANDARD 11)

file(GLOB bloom  "./bloom-filter-cpp/*.cpp")
file(GLOB hashset  "./hashset-cpp/*.cc")
file(GLOB root "./*.cc" )


add_executable(ad_enhance ${bloom} ${hashset} ${root})