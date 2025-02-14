%require "3.0"
%language "c++"
%parse-param {MiniJavaLexer& lexer}
%parse-param {Ast::Node*& root}

%define parse.error verbose
%define api.value.type variant
%define api.parser.class { Parser}
%define api.namespace { Expr }

%code requires {
    #include <unordered_map>
    #include <MiniJavaAst.hpp>
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

%type <Ast::Node *> expr term factor

%%

program: KW_CLASS class_name OPEN_CURLY method_list CLOSE_CURLY {
    root = new Ast::Program($2, $4);
};

class_name: IDENTIFIER {
    $$ = std::string($1);
};

method_list: method_declaration {
    $$ = new Ast::NodeList($1, NULL);
} | method_list method_declaration {
    $$ = new Ast::NodeList($1, $2);
};

method_declaration: KW_VOID IDENTIFIER OPEN_PAR opt_parameter_list CLOSE_PAR block {
    $$ = new Ast::MethodDeclaration($2, $4, $6);
};

opt_parameter_list: parameter {
    $$ = new Ast::NodeList($1, nullptr);
} | opt_parameter_list COMMA parameter {
    $$ = new Ast::NodeList($1, $2);
};

block: statement {
    $$ = new Ast::Block($1);
};

//statement_list: statement_list SEMICOLON statement { $$ = new Ast:LineSeq($1, $3); } | statement { $$ = new Ast::LineSeq($1, nullptr); };

statement_list: statement_list SEMICOLON statement { 
    $$ = new Ast:NodeList($1, $3); 
} | statement {
    $$ = new Ast::NodeList($1, nullptr); 
};


statement: block | { $$ = $1; };



parameter: ;

input: statement_list opt_semicolon;

opt_semicolon: SEMICOLON statement | %empty;



expr: 
    expr "+" term { $$ = $1 + $3; }
    | expr "-" term { $$ = $1 - $3; }
    | term { $$ = $1; }
    ;

term: 
    term OP_MUL factor { $$ = new Ast::MulExpr($1, $3); }
    | term OP_DIV factor {
        $$ = new Ast::DivExpr($1, $3);
    }
    | term OP_MOD factor {
        $$ = new Ast::ModExpr($1, $3);
    }
    | factor { $$ = $1; }
    ;

factor: INT_CONST { $$ = new Ast::INT_CONST($1); }
 | OPEN_PAR expr CLOSE_PAR { $$ = $2; } 
 | IDENTIFIER {
    $$ = new Ast::Identifier($1);
}
%%