%option lexer = "MiniJavaLexer"
%option lex = "nextToken"
%option params = "Expr::Parser::value_type *yylval"


%{
 #include <iostream>
 #include "MiniJavaLexer.hpp"   
 #include "MiniJavaParser.hpp"
%}

%top{
    #include "MiniJavaParser.hpp"
%}

%class{
using Token = Expr::Parser::token;
%}

%x COMMENT 

DIGIT [0-9]


%%
//\n { num_lines++; num_chars++; }

"//".* { /* ignore line comments */ }

"/*"   start(COMMENT);  
<COMMENT>[^*]+         { /* ignores anything but * */ }
<COMMENT>"*"+[^*/]*    { /* ignores * */ }
<COMMENT>"*"+"/"       start(INITIAL);  // block comment end
<COMMENT><<EOF>>       { std::cerr << "Error: EOF en comentario de bloque\n"; return Token::Error; }


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




{DIGIT}+ {
    yylval->emplace<int>(std::stol(text(), nullptr, 10));
    return Token::INT_CONST;
}

\"([^\\\"]|\\.)*\"   { return Token::STRING_LITERAL; }

[_a-z_A-Z][_a-z_A-Z_0-9]* { 
    yylval->emplace<std::string>(text());
    return Token::IDENTIFIER; 
}
[ \t\r\n]+ { /* Ignorar espacios en blanco */ }
<<EOF>> { return Token::EndOfFile; }
. { return Token::Error; }

%%