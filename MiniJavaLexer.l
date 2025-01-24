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
        case Token::HEX: return "HEX";
        case Token::OCT: return "OCT";
        case Token::DEC: return "DEC";
        case Token::BIN: return "BIN";
        case Token::EOF: return "EOF";

        case Token::KW_CLASS: return "CLASS";
        case Token::KW_INT: return "INT";

        case Token::ERROR: return "ERROR";
        default: return "UNKNOWN";
    }
}
%}

%%
[ \t\r\n]+               { }
#.*                      { }
0[xX][0-9a-fA-F]+        { return Token::HEX; }
0[0-7]+                  { return Token::OCT; }
[1-9][0-9]*              { return Token::DEC; }
0[bB][0-1]+              { return Token::BIN; }
<<EOF>>                  { return Token::EOF; }
.                        { return Token::ERROR; }
%%