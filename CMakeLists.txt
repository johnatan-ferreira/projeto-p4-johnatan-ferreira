cmake_minimum_required(VERSION 3.16)
project(projeto_p4_johnatan_ferreira C CXX)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Procura arquivos .cpp e .c ignorando a pasta cmake-build-debug
file(GLOB_RECURSE ARQUIVOS_CPP RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
        "imperativo/*.cpp"
        "poo/*.cpp"
        "funcional/*.cpp"
        "logico/*.cpp"
        "*.cpp"
)

file(GLOB_RECURSE ARQUIVOS_C RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
        "imperativo/*.c"
        "poo/*.c"
        "funcional/*.c"
        "logico/*.c"
        "*.c"
)

set(TODOS_OS_ARQUIVOS ${ARQUIVOS_CPP} ${ARQUIVOS_C})

foreach(ARQUIVO ${TODOS_OS_ARQUIVOS})
    # Ignora qualquer arquivo que esteja dentro de pastas de build
    if(NOT ARQUIVO MATCHES "^cmake-build-debug/" AND NOT ARQUIVO MATCHES "^build/")

        # Cria um nome limpo para o target (ex: imperativo_main, poo_poo)
        get_filename_component(DIR_PAI ${ARQUIVO} DIRECTORY)
        get_filename_component(NOME_SEM_EXT ${ARQUIVO} NAME_WE)

        if(DIR_PAI)
            string(REPLACE "/" "_" NOME_TARGET "${DIR_PAI}_${NOME_SEM_EXT}")
        else()
            set(NOME_TARGET "${NOME_SEM_EXT}")
        endif()

        # Adiciona o executavel individual
        add_executable(${NOME_TARGET} ${ARQUIVO})
        message(STATUS "Executavel individual criado: ${NOME_TARGET} -> ${ARQUIVO}")

    endif()
endforeach()