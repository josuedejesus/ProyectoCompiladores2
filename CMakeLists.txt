cmake_minimum_required(VERSION 3.10)
project(MiniJavaLexer)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Reflex REQUIRED)

add_custom_command(
    OUTPUT MiniJavaLexer.cpp MiniJavaLexer.hpp
    COMMAND Reflex::Reflex -o MiniJavaLexer.cpp --header-file=MiniJavaLexer.hpp ${CMAKE_SOURCE_DIR}/MiniJavaLexer.l
    DEPENDS ${CMAKE_SOURCE_DIR}/MiniJavaLexer.l
    COMMENT "Generating lexer source file with Reflex"
)

add_executable(${PROJECT_NAME} MiniJavaLexer.cpp MiniJavaLexer.hpp Main.cpp)

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_BINARY_DIR})
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR})

target_link_libraries(${PROJECT_NAME} PRIVATE Reflex::ReflexLibStatic)