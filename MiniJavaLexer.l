%option lexer = "MiniJavaLexer"
%option lex = "nextToken"
%option token-type = "Token"

%{
 #include <iostream>
 #include "MiniJavaLexer.hpp"   
%}

%top{
#include "Tokens.hpp"
%}

%class{
public:
    static const char *tokenToString(Token token) {
        switch(token) {
            case Token::KW_CLASS: return "CLASS";
            case Token::KW_INT: return "INT";
            case Token::KW_VOID: return "VOID";
            case Token::KW_REF: return "REF";
            case Token::KW_IF: return "IF";
            case Token::KW_ELSE: return "ELSE";
            case Token::KW_WHILE: return "WHILE";
            case Token::KW_RETURN: return "RETURN";
            case Token::KW_READ: return "READ";
            case Token::KW_PRINT: return "PRINT";
            case Token::DEC: return "DEC";
            case Token::OP_BOOL_AND: return "OP_BOOL_AND";
            case Token::OP_BOOL_OR: return "OP_BOOL_OR";
            case Token::OP_BOOL_NOT: return "OP_BOOL_NOT";
            case Token::OP_GREATER_THAN: return "OP_GREATER_THAN";
            case Token::OP_LESS_THAN: return "OP_LESS_THAN";
            case Token::OP_LESS_EQUAL: return "OP_LESS_EQUAL";
            case Token::OP_EQUAL: return "OP_EQUAL";
            case Token::OP_NOT_EQUAL: return "OP_NOT_EQUAL";
            case Token::OP_ASSIGN: return "OP_ASSIGN";
            case Token::OP_DIV: return "OP_DIV";
            case Token::OP_MUL: return "OP_MUL";
            case Token::OP_MOD: return "OP_MOD";
            case Token::OP_GREATER_EQUAL: return "OP_GREATER_EQUAL";
            case Token::STRING_LITERAL: return "STRING_LITERAL";
            case Token::IDENTIFIER: return "IDENTIFIER";
            case Token::OP_ADD: return "OP_ADD";
            case Token::OP_SUB: return "OP_SUB";
            case Token::SEMICOLON: return "SEMICOLON";
            case Token::OPEN_CURLY: return "OPEN_CURLY";
            case Token::CLOSE_CURLY: return "CLOSE_CURLY";
            case Token::OPEN_BRACKET: return "OPEN_BRACKET";
            case Token::CLOSE_BRACKET: return "CLOSE_BRACKET";
            case Token::OPEN_PAR: return "OPEN_PAR";
            case Token::CLOSE_PAR: return "CLOSE_PAR";
            case Token::COMMA: return "COMMA";
            case Token::EndOfFile: return "EndOfFile";
            case Token::Error: return "Error: Unknown token";
            default: return "UNKNOWN";
        }
    }

    int num_lines = 0;
    int num_chars = 0;
%}

%%
\n { num_lines++; num_chars++; }


/* Symbols */
";" { return Token::SEMICOLON; }
"{" { return Token::OPEN_CURLY; }
"}" { return Token::CLOSE_CURLY; }
"[" { return Token::OPEN_BRACKET; }
"]" { return Token::CLOSE_BRACKET; }
"(" { return Token::OPEN_PAR; }
")" { return Token::CLOSE_PAR; }
"," { return Token::COMMA; }

/* Operators */
"&&" { return Token::OP_BOOL_AND; }
"||" { return Token::OP_BOOL_OR; }
"!" { return Token::OP_BOOL_NOT; }
">" { return Token::OP_GREATER_THAN; }
"<" { return Token::OP_LESS_THAN; }
">=" { return Token::OP_GREATER_EQUAL; }
"<=" { return Token::OP_LESS_EQUAL; }
"==" { return Token::OP_EQUAL; }
"!=" { return Token::OP_NOT_EQUAL; }
"=" { return Token::OP_ASSIGN; }
"+" { return Token::OP_ADD; }
"-" { return Token::OP_SUB; }
"*" { return Token::OP_MUL; }
"/" { return Token::OP_DIV; }
"%" { return Token::OP_MOD; }

/* Keywords */
"class" { return Token::KW_CLASS; }
"int" { return Token::KW_INT; }
"void" { return Token::KW_VOID; }
"ref" { return Token::KW_REF; }
"if" { return Token::KW_IF; }
"else" { return Token::KW_ELSE; }
"while" { return Token::KW_WHILE; }
"return" { return Token::KW_RETURN; }
"read" { return Token::KW_READ; }
"print" { return Token::KW_PRINT; }



0|[1-9][0-9]* { return Token::DEC; }
\"([^\\\"]|\\.)*\"   { return Token::STRING_LITERAL; }
[a-zA-Z_][a-zA-Z0-9_]* { return Token::IDENTIFIER; }
[ \t\r\n]+ { /* Ignorar espacios en blanco */ }
#.* { /* Ignorar comentarios */ }
<<EOF>> { return Token::EndOfFile; }
. { return Token::Error; }

%%