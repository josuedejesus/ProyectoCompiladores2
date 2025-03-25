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
    #include "MiniJavaAst.hpp"
    class MiniJavaLexer;

    
}

%{
    #include <iostream>
    #include <stdexcept>
    #include "MiniJavaLexer.hpp"
    #include "MiniJavaAst.hpp" 
    #include "error.h"

    #define yylex(arg) lexer.nextToken(arg)

    extern int num_lines, num_chars; 

    namespace Expr {
        void Parser::error (const std::string& msg) {
            std::cerr << "line " << num_lines << std::endl;
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

%token KW_CLASS "class"
%token KW_INT "int"
%token KW_VOID "void"
%token KW_REF "ref"

%token KW_IF "if"
%token KW_ELSE "else"
%token KW_WHILE "while"
%token KW_RETURN "return"
%token KW_PRINT "print"
%token KW_READ "read"

%token OPEN_PAR "("
%token CLOSE_PAR ")"
%token OPEN_BRACKET "["
%token CLOSE_BRACKET "]"
%token OPEN_CURLY "{"
%token CLOSE_CURLY "}" 
%token SEMICOLON ";" 
%token COMMA ","
%token<int> INT_CONST "number"
%token<std::string> IDENTIFIER "identifier"
%token<std::string> STRING_LITERAL "string literal"
%token Error "unknown token"

%token EndOfFile "EOF"

%type <Ast::Expr *> expr term factor array_variable
%type <Ast::Node *> identifier
%type <Ast::Node *> class_body
%type <Ast::Node *> class_member
%type <Ast::Node *> method_declaration
%type <Ast::Node *> type
%type <Ast::Node *> method_return_type
%type <Ast::Node *> opt_parameter_list
%type <Ast::Node *> parameter
%type <Ast::Node *> argument_list
%type <Ast::Node *> argument
%type <Ast::Node *> statement
%type <Ast::Node *> block
%type <Ast::Node *> statement_list
%type <Ast::Node *> declaration
%type <Ast::Node *> variable_decl
%type <Ast::Node *> variable_list
%type <Ast::Node *> array_decl 
%type <Ast::Node *> assign_stmt 
%type <Ast::Node *> method_call 
%type <Ast::Node *> if_stmt 
%type <Ast::Node *> while_stmt 
%type <Ast::Node *> print_stmt
%type <Ast::Node *> return_stmt
%type <Ast::RelationalExpr *> relational_expr
%type <Ast::BooleanExpr *> boolean_expr boolean_term boolean_factor
 
%%

program: KW_CLASS IDENTIFIER OPEN_CURLY class_body CLOSE_CURLY EndOfFile {
    root = new Ast::Program($2, $4);
};

class_body: class_body class_member {
    $$ = new Ast::NodeList($1, $2);
} | class_member {
    $$ = new Ast::NodeList($1, nullptr);
} | /*vacio*/ {
    $$ = nullptr;
};

class_member: method_declaration {
    $$ = $1;
} | array_decl {
    if (auto arrayDecl = dynamic_cast<Ast::ArrayDeclaration*>($1)) {
        arrayDecl->is_global = true;
    }
    $$ = $1;
} | variable_decl {
    $$ = $1;
}

identifier: IDENTIFIER {
    $$ = new Ast::Identifier($1);
}

method_declaration: method_return_type IDENTIFIER OPEN_PAR opt_parameter_list CLOSE_PAR OPEN_CURLY block CLOSE_CURLY {
    $$ = new Ast::MethodDeclaration($1, $2, $4, $7);
} | method_return_type IDENTIFIER OPEN_PAR CLOSE_PAR OPEN_CURLY block CLOSE_CURLY {
    $$ = new Ast::MethodDeclaration($1, $2, nullptr, $6);
};

variable_decl: type variable_list SEMICOLON {
    $$ = new Ast::VariableDeclaration($2);
};

variable_list: IDENTIFIER {
    $$ = new Ast::VariableList(false, $1, nullptr);
} | IDENTIFIER COMMA variable_list {
    $$ = new Ast::VariableList(false, $1, $3);
};

array_decl: KW_INT OPEN_BRACKET INT_CONST CLOSE_BRACKET IDENTIFIER SEMICOLON {
    $$ = new Ast::ArrayDeclaration(false, $5, $3);
};

array_variable: IDENTIFIER OPEN_BRACKET expr CLOSE_BRACKET {
    $$ = new Ast::ArrayVariable($1, $3);
}

method_return_type: KW_VOID {
    $$ = new Ast::Type("void");
} | KW_INT {
    $$ = new Ast::Type("int");
};

type: KW_INT;

opt_parameter_list: parameter {
    $$ = new Ast::ParameterList($1, nullptr);
} | parameter COMMA opt_parameter_list {
    $$ = new Ast::ParameterList($1, $3);
};

parameter: KW_INT IDENTIFIER {
    $$ = new Ast::Parameter(false, $2);
} | KW_REF KW_INT IDENTIFIER {
    $$ = new Ast::Parameter(true, $3);
} | KW_INT OPEN_BRACKET INT_CONST CLOSE_BRACKET IDENTIFIER {
    $$ = new Ast::ArrayParameter(false, $3, $5);
};

argument_list: argument {
    $$ = new Ast::ArgumentList($1, nullptr);
} | argument COMMA argument_list {
    $$ = new Ast::ArgumentList($1, $3);
} ;

argument: expr {
    $$ = new Ast::Argument(false, "", $1);
} | KW_REF IDENTIFIER {
    $$ = new Ast::Argument(true, $2, nullptr);
};


block: statement_list { 
    $$ = $1; 
} | /*vacio*/ {
    $$ = nullptr; 
};

statement_list: statement {
    $$ = new Ast::NodeList($1, nullptr);
} | statement_list statement {
    $$ = new Ast::NodeList($1, $2);
};

statement: declaration {
    $$ = $1;
} | method_call {
    $$ = $1;
} | assign_stmt {
    $$ = $1;
} | if_stmt {
    $$ = $1;
} | while_stmt {
    $$ = $1;
} | print_stmt {
    $$ = $1;
} | return_stmt {
    $$ = $1;
};


declaration: array_decl | variable_decl;

assign_stmt: IDENTIFIER OP_ASSIGN expr SEMICOLON {
    $$ = new Ast::Assignment($1, $3);
} | IDENTIFIER OPEN_BRACKET expr CLOSE_BRACKET OP_ASSIGN expr SEMICOLON {
    $$ = new Ast::ArrayAssignment($1, $3, $6);
}



method_call: IDENTIFIER OPEN_PAR argument_list CLOSE_PAR SEMICOLON {
    $$ = new Ast::MethodCall($1, $3);
} | IDENTIFIER OPEN_PAR CLOSE_PAR SEMICOLON {
    $$ = new Ast::MethodCall($1, nullptr);
};

if_stmt: KW_IF OPEN_PAR boolean_expr CLOSE_PAR OPEN_CURLY block CLOSE_CURLY {
    $$ = new Ast::IfStmt($3, $6, nullptr);
} | KW_IF OPEN_PAR boolean_expr CLOSE_PAR OPEN_CURLY block CLOSE_CURLY KW_ELSE OPEN_CURLY statement CLOSE_CURLY {
    $$ = new Ast::IfStmt($3, $6, $10);
}

while_stmt: KW_WHILE OPEN_PAR boolean_expr CLOSE_PAR OPEN_CURLY block CLOSE_CURLY {
    $$ = new Ast::WhileStmt($3, $6);
}

print_stmt: KW_PRINT OPEN_PAR STRING_LITERAL CLOSE_PAR SEMICOLON {
    $$ = new Ast::PrintStmtLit($3);
} | KW_PRINT OPEN_PAR expr CLOSE_PAR SEMICOLON {
    $$ = new Ast::PrintStmt($3);
};

return_stmt: KW_RETURN expr SEMICOLON {
    $$ = new Ast::ReturnStmt($2);
}



boolean_expr: boolean_expr OP_BOOL_OR boolean_term {  
    $$ = new Ast::OrExpr($1, $3); 
} | boolean_term {
    $$ = $1;  
};

boolean_term: boolean_term OP_BOOL_AND boolean_factor {  
    $$ = new Ast::AndExpr($1, $3); 
} | boolean_factor {
    $$ = $1;
};

boolean_factor: relational_expr {  
    $$ = $1;  
};

relational_expr: expr OP_GREATER_THAN expr {
        $$ = new Ast::GreaterExpr($1, $3);
    } | expr OP_GREATER_EQUAL expr {
        $$ = new Ast::GreaterEqualExpr($1, $3);
    } | expr OP_LESS_THAN expr {
        $$ = new Ast::LessExpr($1, $3);
    } | expr OP_LESS_EQUAL expr {
        $$ = new Ast::LessEqualExpr($1, $3);
    } | expr OP_NOT_EQUAL expr {
        $$ = new Ast::NotEqualExpr($1, $3);
    } | expr OP_EQUAL expr {
        $$ = new Ast::EqualExpr($1, $3);
    }

expr: 
    expr "+" term { 
        $$ = new Ast::AddExpr($1, $3); 
    } | expr "-" term { 
        $$ = new Ast::SubExpr($1, $3); 
    } |term { $$ = $1; };

term: 
    term OP_MUL factor { 
        $$ = new Ast::MulExpr($1, $3);
    } | term OP_DIV factor {
        $$ = new Ast::DivExpr($1, $3);
    } | term OP_MOD factor {
        $$ = new Ast::ModExpr($1, $3);
    } | factor { 
        $$ = $1;
    };

factor: INT_CONST { 
    $$ = new Ast::Number($1);
} | OPEN_PAR expr CLOSE_PAR { 
    $$ = $2;
} | IDENTIFIER {
    $$ = new Ast::Identifier($1);
} | array_variable {
    $$ = $1;
} | IDENTIFIER OPEN_PAR argument_list CLOSE_PAR {
    $$ = new Ast::FunctionCall($1, $3);
} | IDENTIFIER OPEN_PAR CLOSE_PAR {
    $$ = new Ast::FunctionCall($1, nullptr);
}
%%