cmake_minimum_required(VERSION 3.20)
project(Paradigmas C CXX)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# 1. Encontra todos os arquivos .c na pasta atual
file(GLOB C_FILES *.c)
foreach(file ${C_FILES})
    get_filename_component(target_name ${file} NAME_WE)
    add_executable(${target_name} ${file})
endforeach()

# 2. Encontra todos os arquivos .cpp na pasta atual
file(GLOB CPP_FILES *.cpp)
foreach(file ${CPP_FILES})
    get_filename_component(target_name ${file} NAME_WE)
    add_executable(${target_name} ${file})
endforeach()