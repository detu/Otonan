cmake_minimum_required(VERSION 3.21)
project(Otonan)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_MODULE_PATH
        ${PROJECT_SOURCE_DIR}/cmake
        ${CMAKE_MODULE_PATH})

find_package(wt REQUIRED Wt HTTP)
include_directories(${Boost_INCLUDE_DIR} ${Wt_INCLUDE_DIR})
link_directories(${Boost_LIBRARY} ${Wt_LIBRARY})
add_executable(Otonan main.cpp)
target_link_libraries(Otonan ${Boost_LIBRARY} Wt::Wt Wt::HTTP)
#target_compile_features(Otonan private cxx_std_20)
