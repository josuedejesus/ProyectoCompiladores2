%require "3.0"
%language "c++"
%parse-param {MiniJavaLexer& lexer}
%parse-param {std::unordered_map<std::string, int>& vars}

%define parse.error verbose
%define api.value.type variant
%define api.parser.class { Parser}
%define api.namespace { Expr }

%code requires {
    #include <unordered_map>
    class MiniJavaLexer;
}

%{
    #include <iostream>
    #include <stdexcept>
    #include "MiniJavaLexer.hpp"
    #include "error.h"

    #define yylex(arg) lexer.nextToken(arg)

    namespace Expr {
        void Parser::error (const std::string& msg) {
            throw std::runtime_error(msg);
        }
        
    }
%}




%token OP_ADD "+"
%token OP_SUB "-"
%token OP_MUL "*"
%token OP_DIV "/"
%token OP_MOD "%"
%token OP_ASSIGN "="

%token OP_BOOL_AND "&&"
%token OP_BOOL_OR "||"
%token OP_BOOL_NOT "!"
%token OP_EQUAL "=="
%token OP_NOT_EQUAL "!="
%token OP_GREATER_THAN ">"
%token OP_GREATER_EQUAL ">="
%token OP_LESS_THAN "<"
%token OP_LESS_EQUAL "<="

%token KW_CLASS "CLASS"
%token KW_INT "INT"
%token KW_VOID "VOID"
%token KW_REF "ref"

%token KW_IF "if"
%token KW_ELSE "else"
%token KW_WHILE "while"
%token KW_RETURN "return"
%token KW_PRINT "print"
%token KW_READ "read"

%token STRING_LITERAL "string literal"

%token EndOfFile "EOF"



%token OPEN_PAR CLOSE_PAR OPEN_BRACKET CLOSE_BRACKET OPEN_CURLY CLOSE_CURLY SEMICOLON COMMA
%token<int> INT_CONST "number"
%token<std::string> IDENTIFIER "identifier"
%token Error "unknown token"

%type <int> expr term factor

%%

program: KW_CLASS class_name OPEN_CURLY method_declaration_list CLOSE_CURLY;

class_name: IDENTIFIER;

method_declaration_list: method_declaration | method_declaration_list method_declaration;

method_declaration: KW_VOID IDENTIFIER OPEN_PAR opt_parameter_list CLOSE_PAR;

opt_parameter_list: parameter;

parameter: ;

input: statement_list opt_semicolon;

opt_semicolon: SEMICOLON statement | %empty;

statement_list: statement_list SEMICOLON statement | statement;

statement: expr { std::cout << $1 << '\n'; };

expr: 
    expr "+" term { $$ = $1 + $3; }
    | expr "-" term { $$ = $1 - $3; }
    | term { $$ = $1; }
    ;

term: 
    term OP_MUL factor { $$ = $1 * $3; }
    | term OP_DIV factor {
        if ($3 == 0) {
            error("Division by zero");
        } else {
            $$ = $1 / $3;
        }
    }
    | term OP_MOD factor {
        if ($3 == 0) {
            error("Division by zero");
        } else {
            $$ = $1 % $3;
        }
    }
    | factor { $$ = $1; }
    ;

factor: INT_CONST { $$ = $1; } | OPEN_PAR expr CLOSE_PAR { $$ = $2; } | IDENTIFIER {
    auto it = vars.find($1);
    if (it == vars.end()) {
        error("Unknown variable: " + $1);
    } else {
        $$ = it->second;
    }
}
%%