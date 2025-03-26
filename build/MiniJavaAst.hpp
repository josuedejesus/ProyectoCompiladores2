/* MiniJavaAst.hpp.  Generated automatically by treecc */
#ifndef __yy_MiniJavaAst_hpp
#define __yy_MiniJavaAst_hpp
#line 4 "/home/josuedejesus/ProyectoCompiladores2/MiniJavaAst.tc"

    #include <string>
    #include <ostream>
    #include <unordered_map> 
    #include "MiniJavaAst.hpp"

    struct CodegenResult {
        std::string code;
        std::string place;
    };

    namespace Ast{
        class Node;
    };

    enum class RetType {
        VOID,
        INT
    };

    using string_t = std::string;
    using symbol_table_t = std::unordered_map<std::string, std::string>;
    using type_table_t = std::unordered_map<std::string, std::string>;
    using literal_table_t = std::unordered_map<std::string, std::string>;
    using function_table_t = std::unordered_map<std::string, Ast::Node*>;
#line 31 "MiniJavaAst.hpp"

#include <new>

namespace Ast
{

const int Node_kind = 1;
const int NodeList_kind = 2;
const int ParameterList_kind = 3;
const int VariableList_kind = 6;
const int Program_kind = 7;
const int Type_kind = 8;
const int MethodDeclaration_kind = 9;
const int Parameter_kind = 10;
const int ArrayParameter_kind = 11;
const int Block_kind = 12;
const int VariableDeclaration_kind = 13;
const int ArrayDeclaration_kind = 14;
const int Assignment_kind = 15;
const int ArrayAssignment_kind = 16;
const int MethodCall_kind = 17;
const int IfStmt_kind = 18;
const int WhileStmt_kind = 19;
const int PrintStmt_kind = 20;
const int PrintStmtLit_kind = 21;
const int ReturnStmt_kind = 22;
const int StringLiteral_kind = 23;
const int Expr_kind = 4;
const int BooleanExpr_kind = 36;
const int ArgumentList_kind = 5;
const int Number_kind = 24;
const int Identifier_kind = 25;
const int ArrayVariable_kind = 26;
const int FunctionCall_kind = 27;
const int Argument_kind = 28;
const int ArrayArgument_kind = 29;
const int BinaryExpr_kind = 30;
const int AddExpr_kind = 31;
const int SubExpr_kind = 32;
const int MulExpr_kind = 33;
const int DivExpr_kind = 34;
const int ModExpr_kind = 35;
const int BinaryBooleanExpr_kind = 37;
const int RelationalExpr_kind = 40;
const int AndExpr_kind = 38;
const int OrExpr_kind = 39;
const int BinaryRelationalExpr_kind = 41;
const int GreaterExpr_kind = 42;
const int GreaterEqualExpr_kind = 43;
const int LessExpr_kind = 44;
const int LessEqualExpr_kind = 45;
const int EqualExpr_kind = 46;
const int NotEqualExpr_kind = 47;

class Node;
class NodeList;
class ParameterList;
class VariableList;
class Program;
class Type;
class MethodDeclaration;
class Parameter;
class ArrayParameter;
class Block;
class VariableDeclaration;
class ArrayDeclaration;
class Assignment;
class ArrayAssignment;
class MethodCall;
class IfStmt;
class WhileStmt;
class PrintStmt;
class PrintStmtLit;
class ReturnStmt;
class StringLiteral;
class Expr;
class BooleanExpr;
class ArgumentList;
class Number;
class Identifier;
class ArrayVariable;
class FunctionCall;
class Argument;
class ArrayArgument;
class BinaryExpr;
class AddExpr;
class SubExpr;
class MulExpr;
class DivExpr;
class ModExpr;
class BinaryBooleanExpr;
class RelationalExpr;
class AndExpr;
class OrExpr;
class BinaryRelationalExpr;
class GreaterExpr;
class GreaterEqualExpr;
class LessExpr;
class LessEqualExpr;
class EqualExpr;
class NotEqualExpr;

class YYNODESTATE
{
public:

	YYNODESTATE();
	virtual ~YYNODESTATE();

#line 1 "cpp_skel.h"
private:

	struct YYNODESTATE_block *blocks__;
	struct YYNODESTATE_push *push_stack__;
	int used__;
#line 147 "MiniJavaAst.hpp"
private:

	static YYNODESTATE *state__;

public:

	static YYNODESTATE *getState()
		{
			if(state__) return state__;
			state__ = new YYNODESTATE();
			return state__;
		}

public:

	void *alloc(size_t);
	void dealloc(void *, size_t);
	int push();
	void pop();
	void clear();
	virtual void failed();
	virtual const char *currFilename() const;
	virtual long currLinenum() const;

};

class Node
{
protected:

	int kind__;
	const char *filename__;
	long linenum__;

public:

	int getKind() const { return kind__; }
	const char *getFilename() const { return filename__; }
	long getLinenum() const { return linenum__; }
	void setFilename(const char *filename) { filename__ = filename; }
	void setLinenum(long linenum) { linenum__ = linenum; }

	void *operator new(size_t);
	void operator delete(void *, size_t);

protected:

	Node();

public:

	virtual string_t toString() = 0;

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~Node();

};

class NodeList : public Node
{
public:

	NodeList(Node * first_node, Node * next_node);

public:

	Node * first_node;
	Node * next_node;

	virtual string_t toString();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~NodeList();

};

class ParameterList : public Node
{
public:

	ParameterList(Node * first_node, Node * next_node);

public:

	Node * first_node;
	Node * next_node;

	virtual string_t toString();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~ParameterList();

};

class VariableList : public Node
{
public:

	VariableList(bool is_global, string_t identifier, Node * next_node);

public:

	bool is_global;
	string_t identifier;
	Node * next_node;

	virtual string_t toString();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~VariableList();

};

class Program : public Node
{
public:

	Program(string_t class_name, Node * class_body);

public:

	string_t class_name;
	Node * class_body;

	virtual string_t toString();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~Program();

};

class Type : public Node
{
public:

	Type(string_t name);

public:

	string_t name;

	virtual string_t toString();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~Type();

};

class MethodDeclaration : public Node
{
public:

	MethodDeclaration(Node * type, string_t name, Node * parameter_list, Node * block);

public:

	Node * type;
	string_t name;
	Node * parameter_list;
	Node * block;

	virtual string_t toString();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~MethodDeclaration();

};

class Parameter : public Node
{
public:

	Parameter(bool is_ref, string_t identifier);

public:

	bool is_ref;
	string_t identifier;

	virtual string_t toString();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~Parameter();

};

class ArrayParameter : public Node
{
public:

	ArrayParameter(bool is_ref, int index, string_t identifier);

public:

	bool is_ref;
	int index;
	string_t identifier;

	virtual string_t toString();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~ArrayParameter();

};

class Block : public Node
{
public:

	Block(Node * statement_list);

public:

	Node * statement_list;

	virtual string_t toString();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~Block();

};

class VariableDeclaration : public Node
{
public:

	VariableDeclaration(Node * identifier_list);

public:

	Node * identifier_list;

	virtual string_t toString();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~VariableDeclaration();

};

class ArrayDeclaration : public Node
{
public:

	ArrayDeclaration(bool is_global, string_t identifier, int size);

public:

	bool is_global;
	string_t identifier;
	int size;

	virtual string_t toString();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~ArrayDeclaration();

};

class Assignment : public Node
{
public:

	Assignment(string_t identifier, Expr * expr);

public:

	string_t identifier;
	Expr * expr;

	virtual string_t toString();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~Assignment();

};

class ArrayAssignment : public Node
{
public:

	ArrayAssignment(string_t array_identifier, Node * index_expr, Expr * expr);

public:

	string_t array_identifier;
	Node * index_expr;
	Expr * expr;

	virtual string_t toString();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~ArrayAssignment();

};

class MethodCall : public Node
{
public:

	MethodCall(string_t identifier, Node * argument_list);

public:

	string_t identifier;
	Node * argument_list;

	virtual string_t toString();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~MethodCall();

};

class IfStmt : public Node
{
public:

	IfStmt(BooleanExpr * expr, Node * if_stmts, Node * else_stmts);

public:

	BooleanExpr * expr;
	Node * if_stmts;
	Node * else_stmts;

	virtual string_t toString();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~IfStmt();

};

class WhileStmt : public Node
{
public:

	WhileStmt(BooleanExpr * expr, Node * stmts);

public:

	BooleanExpr * expr;
	Node * stmts;

	virtual string_t toString();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~WhileStmt();

};

class PrintStmt : public Node
{
public:

	PrintStmt(Node * expr);

public:

	Node * expr;

	virtual string_t toString();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~PrintStmt();

};

class PrintStmtLit : public Node
{
public:

	PrintStmtLit(string_t literal);

public:

	string_t literal;

	virtual string_t toString();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~PrintStmtLit();

};

class ReturnStmt : public Node
{
public:

	ReturnStmt(Node * expr);

public:

	Node * expr;

	virtual string_t toString();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~ReturnStmt();

};

class StringLiteral : public Node
{
public:

	StringLiteral(string_t value);

public:

	string_t value;

	virtual string_t toString();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~StringLiteral();

};

class Expr : public Node
{
protected:

	Expr();

public:

	virtual string_t toString() = 0;

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~Expr();

};

class BooleanExpr : public Node
{
protected:

	BooleanExpr();

public:

	virtual string_t toString() = 0;

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~BooleanExpr();

};

class ArgumentList : public Expr
{
public:

	ArgumentList(Node * first_node, Node * next_node);

public:

	Node * first_node;
	Node * next_node;

	virtual string_t toString();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~ArgumentList();

};

class Number : public Expr
{
public:

	Number(int value);

public:

	int value;

	virtual string_t toString();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~Number();

};

class Identifier : public Expr
{
public:

	Identifier(string_t name);

public:

	string_t name;

	virtual string_t toString();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~Identifier();

};

class ArrayVariable : public Expr
{
public:

	ArrayVariable(string_t identifier, Expr * expr);

public:

	string_t identifier;
	Expr * expr;

	virtual string_t toString();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~ArrayVariable();

};

class FunctionCall : public Expr
{
public:

	FunctionCall(string_t identifier, Node * argument_list);

public:

	string_t identifier;
	Node * argument_list;

	virtual string_t toString();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~FunctionCall();

};

class Argument : public Expr
{
public:

	Argument(bool is_ref, string_t identifier, Expr * expr);

public:

	bool is_ref;
	string_t identifier;
	Expr * expr;

	virtual string_t toString();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~Argument();

};

class ArrayArgument : public Expr
{
public:

	ArrayArgument(bool is_ref, Expr * expr, string_t identifier);

public:

	bool is_ref;
	Expr * expr;
	string_t identifier;

	virtual string_t toString();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~ArrayArgument();

};

class BinaryExpr : public Expr
{
protected:

	BinaryExpr(Expr * left, Expr * right);

public:

	Expr * left;
	Expr * right;

	virtual string_t toString() = 0;

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~BinaryExpr();

};

class AddExpr : public BinaryExpr
{
public:

	AddExpr(Expr * left, Expr * right);

public:

	virtual string_t toString();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~AddExpr();

};

class SubExpr : public BinaryExpr
{
public:

	SubExpr(Expr * left, Expr * right);

public:

	virtual string_t toString();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~SubExpr();

};

class MulExpr : public BinaryExpr
{
public:

	MulExpr(Expr * left, Expr * right);

public:

	virtual string_t toString();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~MulExpr();

};

class DivExpr : public BinaryExpr
{
public:

	DivExpr(Expr * left, Expr * right);

public:

	virtual string_t toString();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~DivExpr();

};

class ModExpr : public BinaryExpr
{
public:

	ModExpr(Expr * left, Expr * right);

public:

	virtual string_t toString();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~ModExpr();

};

class BinaryBooleanExpr : public BooleanExpr
{
protected:

	BinaryBooleanExpr(BooleanExpr * left, BooleanExpr * right);

public:

	BooleanExpr * left;
	BooleanExpr * right;

	virtual string_t toString() = 0;

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~BinaryBooleanExpr();

};

class RelationalExpr : public BooleanExpr
{
protected:

	RelationalExpr();

public:

	virtual string_t toString() = 0;

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~RelationalExpr();

};

class AndExpr : public BinaryBooleanExpr
{
public:

	AndExpr(BooleanExpr * left, BooleanExpr * right);

public:

	virtual string_t toString();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~AndExpr();

};

class OrExpr : public BinaryBooleanExpr
{
public:

	OrExpr(BooleanExpr * left, BooleanExpr * right);

public:

	virtual string_t toString();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~OrExpr();

};

class BinaryRelationalExpr : public RelationalExpr
{
protected:

	BinaryRelationalExpr(Expr * left, Expr * right);

public:

	Expr * left;
	Expr * right;

	virtual string_t toString() = 0;

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~BinaryRelationalExpr();

};

class GreaterExpr : public BinaryRelationalExpr
{
public:

	GreaterExpr(Expr * left, Expr * right);

public:

	virtual string_t toString();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~GreaterExpr();

};

class GreaterEqualExpr : public BinaryRelationalExpr
{
public:

	GreaterEqualExpr(Expr * left, Expr * right);

public:

	virtual string_t toString();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~GreaterEqualExpr();

};

class LessExpr : public BinaryRelationalExpr
{
public:

	LessExpr(Expr * left, Expr * right);

public:

	virtual string_t toString();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~LessExpr();

};

class LessEqualExpr : public BinaryRelationalExpr
{
public:

	LessEqualExpr(Expr * left, Expr * right);

public:

	virtual string_t toString();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~LessEqualExpr();

};

class EqualExpr : public BinaryRelationalExpr
{
public:

	EqualExpr(Expr * left, Expr * right);

public:

	virtual string_t toString();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~EqualExpr();

};

class NotEqualExpr : public BinaryRelationalExpr
{
public:

	NotEqualExpr(Expr * left, Expr * right);

public:

	virtual string_t toString();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~NotEqualExpr();

};


CodegenResult exprCompile(Node * root, type_table_t & types, literal_table_t & literals, function_table_t & functions, symbol_table_t & vars);
void getFunction(Node * root, function_table_t & functions);

}
#endif
