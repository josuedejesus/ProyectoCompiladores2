cmake_minimum_required(VERSION 3.10)
project(MiniJavaEval)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})

find_package(TreeCC REQUIRED)

if (TREECC_FOUND)
    message(STATUS "TreeCC found: ${TREECC_EXECUTABLE}")
    message(STATUS "TreeCC version: ${TREECC_VERSION}")
else()
    message(FATAL_ERROR "TreeCC not found. Please install TreeCC or try again.")
endif()


find_package(Reflex REQUIRED)
find_package(BISON REQUIRED)

add_custom_command(
    OUTPUT MiniJavaLexer.cpp MiniJavaLexer.hpp
    COMMAND Reflex::Reflex -o MiniJavaLexer.cpp --header-file=MiniJavaLexer.hpp ${CMAKE_SOURCE_DIR}/MiniJavaLexer.l
    DEPENDS ${CMAKE_SOURCE_DIR}/MiniJavaLexer.l
    COMMENT "Generating lexer source file with Reflex"
)

add_custom_command(
    OUTPUT MiniJavaAst.cpp MiniJavaAst.hpp
    COMMAND ${TREECC_EXECUTABLE} -o MiniJavaAst.cpp -h MiniJavaAst.hpp ${CMAKE_SOURCE_DIR}/MiniJavaAst.tc
    DEPENDS ${CMAKE_SOURCE_DIR}/MiniJavaAst.tc
    COMMENT "Generating expression ASR source file with TreeCC"
)

BISON_TARGET(MiniJavaParser MiniJavaParser.y ${CMAKE_BINARY_DIR}/MiniJavaParser.cpp
    DEFINES_FILE ${CMAKE_BINARY_DIR}/MiniJavaParser.hpp
)

add_executable(${PROJECT_NAME} MiniJavaAst.cpp MiniJavaLexer.cpp MiniJavaLexer.hpp MiniJavaParser.cpp MiniJavaParser.hpp Main.cpp)

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_BINARY_DIR})
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR})

target_link_libraries(${PROJECT_NAME} PRIVATE Reflex::ReflexLibStatic)