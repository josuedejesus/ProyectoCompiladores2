/* MiniJavaAst.cpp.  Generated automatically by treecc */
#line 31 "/home/josuedejesus/ProyectoCompiladores2/MiniJavaAst.tc"

#include <string>
#include <sstream> 
#include "MiniJavaAst.hpp"

std::string newVariable() {
    static int index = 0;

    return "%t" + std::to_string(index++);
}

std::string newLabel() {
    static int index = 0;

    return "lb" + std::to_string(index++);
}

std::string newTag() {
    static int index = 0;

    return "@.tx" + std::to_string(index++);
}

std::string current_function_type;
Ast::Node* current_method;
bool has_return = false;

#line 31 "MiniJavaAst.cpp"

#include <cstddef>

namespace Ast
{

#define YYNODESTATE_TRACK_LINES 1
#define YYNODESTATE_USE_ALLOCATOR 1
#line 1 "cpp_skel.cc"
/*
 * treecc node allocation routines for C++.
 *
 * Copyright (C) 2001  Southern Storm Software, Pty Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * As a special exception, when this file is copied by treecc into
 * a treecc output file, you may use that output file without restriction.
 */

#ifndef YYNODESTATE_BLKSIZ
#define	YYNODESTATE_BLKSIZ	2048
#endif

/*
 * Types used by the allocation routines.
 */
struct YYNODESTATE_block
{
	char data__[YYNODESTATE_BLKSIZ];
	struct YYNODESTATE_block *next__;

};
struct YYNODESTATE_push
{
	struct YYNODESTATE_push *next__;
	struct YYNODESTATE_block *saved_block__;
	int saved_used__;
};

/*
 * Initialize the singleton instance.
 */
#ifndef YYNODESTATE_REENTRANT
YYNODESTATE *YYNODESTATE::state__ = 0;
#endif

/*
 * Some macro magic to determine the default alignment
 * on this machine.  This will compile down to a constant.
 */
#define	YYNODESTATE_ALIGN_CHECK_TYPE(type,name)	\
	struct _YYNODESTATE_align_##name { \
		char pad; \
		type field; \
	}
#define	YYNODESTATE_ALIGN_FOR_TYPE(type)	\
	offsetof(_YYNODESTATE_align_##type, field)
#define	YYNODESTATE_ALIGN_MAX(a,b)	\
	((a) > (b) ? (a) : (b))
#define	YYNODESTATE_ALIGN_MAX3(a,b,c) \
	(YYNODESTATE_ALIGN_MAX((a), YYNODESTATE_ALIGN_MAX((b), (c))))
YYNODESTATE_ALIGN_CHECK_TYPE(int, int);
YYNODESTATE_ALIGN_CHECK_TYPE(long, long);
#if defined(WIN32) && !defined(__CYGWIN__)
YYNODESTATE_ALIGN_CHECK_TYPE(__int64, long_long);
#else
YYNODESTATE_ALIGN_CHECK_TYPE(long long, long_long);
#endif
YYNODESTATE_ALIGN_CHECK_TYPE(void *, void_p);
YYNODESTATE_ALIGN_CHECK_TYPE(float, float);
YYNODESTATE_ALIGN_CHECK_TYPE(double, double);
#define	YYNODESTATE_ALIGNMENT	\
	YYNODESTATE_ALIGN_MAX( \
			YYNODESTATE_ALIGN_MAX3	\
			(YYNODESTATE_ALIGN_FOR_TYPE(int), \
		     YYNODESTATE_ALIGN_FOR_TYPE(long), \
			 YYNODESTATE_ALIGN_FOR_TYPE(long_long)), \
  	     YYNODESTATE_ALIGN_MAX3 \
		 	(YYNODESTATE_ALIGN_FOR_TYPE(void_p), \
			 YYNODESTATE_ALIGN_FOR_TYPE(float), \
			 YYNODESTATE_ALIGN_FOR_TYPE(double)))

/*
 * Constructor for YYNODESTATE.
 */
YYNODESTATE::YYNODESTATE()
{
	/* Initialize the allocation state */
	blocks__ = 0;
	push_stack__ = 0;
	used__ = 0;

#ifndef YYNODESTATE_REENTRANT
	/* Register this object as the singleton instance */
	if(!state__)
	{
		state__ = this;
	}
#endif
}

/*
 * Destructor for YYNODESTATE.
 */
YYNODESTATE::~YYNODESTATE()
{
	/* Free all node memory */
	clear();

#ifndef YYNODESTATE_REENTRANT
	/* We are no longer the singleton instance */
	if(state__ == this)
	{
		state__ = 0;
	}
#endif
}

#ifdef YYNODESTATE_USE_ALLOCATOR

/*
 * Allocate a block of memory.
 */
void *YYNODESTATE::alloc(size_t size__)
{
	struct YYNODESTATE_block *block__;
	void *result__;

	/* Round the size to the next alignment boundary */
	size__ = (size__ + YYNODESTATE_ALIGNMENT - 1) &
				~(YYNODESTATE_ALIGNMENT - 1);

	/* Do we need to allocate a new block? */
	block__ = blocks__;
	if(!block__ || (used__ + size__) > YYNODESTATE_BLKSIZ)
	{
		if(size__ > YYNODESTATE_BLKSIZ)
		{
			/* The allocation is too big for the node pool */
			return (void *)0;
		}
		block__ = new YYNODESTATE_block;
		if(!block__)
		{
			/* The system is out of memory.  The programmer can
			   inherit the "failed" method to report the
			   out of memory state and/or abort the program */
			failed();
			return (void *)0;
		}
		block__->next__ = blocks__;
		blocks__ = block__;
		used__ = 0;
	}

	/* Allocate the memory and return it */
	result__ = (void *)(block__->data__ + used__);
	used__ += size__;
	return result__;
}

/*
 * Deallocate a block of memory.
 */
void YYNODESTATE::dealloc(void *ptr__, size_t size__)
{
	/* Nothing to do for this type of node allocator */
}

/*
 * Push the node allocation state.
 */
int YYNODESTATE::push()
{
	struct YYNODESTATE_block *saved_block__;
	int saved_used__;
	struct YYNODESTATE_push *push_item__;

	/* Save the current state of the node allocation pool */
	saved_block__ = blocks__;
	saved_used__ = used__;

	/* Allocate space for a push item */
	push_item__ = (struct YYNODESTATE_push *)
			alloc(sizeof(struct YYNODESTATE_push));
	if(!push_item__)
	{
		return 0;
	}

	/* Copy the saved information to the push item */
	push_item__->saved_block__ = saved_block__;
	push_item__->saved_used__ = saved_used__;

	/* Add the push item to the push stack */
	push_item__->next__ = push_stack__;
	push_stack__ = push_item__;
	return 1;
}

/*
 * Pop the node allocation state.
 */
void YYNODESTATE::pop()
{
	struct YYNODESTATE_push *push_item__;
	struct YYNODESTATE_block *saved_block__;
	struct YYNODESTATE_block *temp_block__;

	/* Pop the top of the push stack */
	push_item__ = push_stack__;
	if(push_item__ == 0)
	{
		saved_block__ = 0;
		used__ = 0;
	}
	else
	{
		saved_block__ = push_item__->saved_block__;
		used__ = push_item__->saved_used__;
		push_stack__ = push_item__->next__;
	}

	/* Free unnecessary blocks */
	while(blocks__ != saved_block__)
	{
		temp_block__ = blocks__;
		blocks__ = temp_block__->next__;
		delete temp_block__;
	}
}

/*
 * Clear the node allocation pool completely.
 */
void YYNODESTATE::clear()
{
	struct YYNODESTATE_block *temp_block__;
	while(blocks__ != 0)
	{
		temp_block__ = blocks__;
		blocks__ = temp_block__->next__;
		delete temp_block__;
	}
	push_stack__ = 0;
	used__ = 0;
}

#endif /* YYNODESTATE_USE_ALLOCATOR */

/*
 * Default implementation of functions which may be overridden.
 */
void YYNODESTATE::failed()
{
}

#ifdef YYNODESTATE_TRACK_LINES

const char *YYNODESTATE::currFilename() const
{
	return (const char *)0;
}

long YYNODESTATE::currLinenum() const
{
	return 0;
}

#endif
#line 315 "MiniJavaAst.cpp"
void *Node::operator new(size_t size__)
{
	return YYNODESTATE::getState()->alloc(size__);
}

void Node::operator delete(void *ptr__, size_t size__)
{
	YYNODESTATE::getState()->dealloc(ptr__, size__);
}

Node::Node()
{
	this->kind__ = Node_kind;
	this->filename__ = YYNODESTATE::getState()->currFilename();
	this->linenum__ = YYNODESTATE::getState()->currLinenum();
}

Node::~Node()
{
	// not used
}

int Node::isA(int kind) const
{
	if(kind == Node_kind)
		return 1;
	else
		return 0;
}

const char *Node::getKindName() const
{
	return "Node";
}

NodeList::NodeList(Node * first_node, Node * next_node)
	: Node()
{
	this->kind__ = NodeList_kind;
	this->first_node = first_node;
	this->next_node = next_node;
}

NodeList::~NodeList()
{
	// not used
}

string_t NodeList::toString()
{
	NodeList *node = this;
#line 277 "/home/josuedejesus/ProyectoCompiladores2/MiniJavaAst.tc"
	{
	    std::ostringstream os;
	
	    os << "NodeList(" << node->first_node->toString();
	
	    if (node->next_node) {
	        os << ", " << node->next_node->toString();
	    }
	    
	    os << ")";
	
	    return os.str();
	}
#line 381 "MiniJavaAst.cpp"
}

int NodeList::isA(int kind) const
{
	if(kind == NodeList_kind)
		return 1;
	else
		return Node::isA(kind);
}

const char *NodeList::getKindName() const
{
	return "NodeList";
}

ParameterList::ParameterList(Node * first_node, Node * next_node)
	: Node()
{
	this->kind__ = ParameterList_kind;
	this->first_node = first_node;
	this->next_node = next_node;
}

ParameterList::~ParameterList()
{
	// not used
}

string_t ParameterList::toString()
{
	ParameterList *node = this;
#line 291 "/home/josuedejesus/ProyectoCompiladores2/MiniJavaAst.tc"
	{
	    std::ostringstream os;
	
	    os << "ParameterList(" << node->first_node->toString();
	
	    if (node->next_node) {
	        os << ", " << node->next_node->toString();
	    }
	    
	    os << ")";
	
	    return os.str();
	}
#line 427 "MiniJavaAst.cpp"
}

int ParameterList::isA(int kind) const
{
	if(kind == ParameterList_kind)
		return 1;
	else
		return Node::isA(kind);
}

const char *ParameterList::getKindName() const
{
	return "ParameterList";
}

VariableList::VariableList(bool is_global, string_t identifier, Node * next_node)
	: Node()
{
	this->kind__ = VariableList_kind;
	this->is_global = is_global;
	this->identifier = identifier;
	this->next_node = next_node;
}

VariableList::~VariableList()
{
	// not used
}

string_t VariableList::toString()
{
	VariableList *node = this;
#line 319 "/home/josuedejesus/ProyectoCompiladores2/MiniJavaAst.tc"
	{
	    std::ostringstream os;
	
	    os << "VariableList(" << node->identifier;
	
	    if (node->next_node) {
	        os << ", " << node->next_node;
	    }
	    
	    os << ")";
	
	    return os.str();
	}
#line 474 "MiniJavaAst.cpp"
}

int VariableList::isA(int kind) const
{
	if(kind == VariableList_kind)
		return 1;
	else
		return Node::isA(kind);
}

const char *VariableList::getKindName() const
{
	return "VariableList";
}

Program::Program(string_t class_name, Node * class_body)
	: Node()
{
	this->kind__ = Program_kind;
	this->class_name = class_name;
	this->class_body = class_body;
}

Program::~Program()
{
	// not used
}

string_t Program::toString()
{
	Program *node = this;
#line 269 "/home/josuedejesus/ProyectoCompiladores2/MiniJavaAst.tc"
	{
	    std::ostringstream os;
	
	    os << "Program(" << node->class_body->toString() << ")";
	
	    return os.str();
	}
#line 514 "MiniJavaAst.cpp"
}

int Program::isA(int kind) const
{
	if(kind == Program_kind)
		return 1;
	else
		return Node::isA(kind);
}

const char *Program::getKindName() const
{
	return "Program";
}

Type::Type(string_t name)
	: Node()
{
	this->kind__ = Type_kind;
	this->name = name;
}

Type::~Type()
{
	// not used
}

string_t Type::toString()
{
	Type *node = this;
#line 261 "/home/josuedejesus/ProyectoCompiladores2/MiniJavaAst.tc"
	{
	    std::ostringstream os;
	
	    os << "Type(" << node->name << ")";
	
	    return os.str();
	}
#line 553 "MiniJavaAst.cpp"
}

int Type::isA(int kind) const
{
	if(kind == Type_kind)
		return 1;
	else
		return Node::isA(kind);
}

const char *Type::getKindName() const
{
	return "Type";
}

MethodDeclaration::MethodDeclaration(Node * type, string_t name, Node * parameter_list, Node * block)
	: Node()
{
	this->kind__ = MethodDeclaration_kind;
	this->type = type;
	this->name = name;
	this->parameter_list = parameter_list;
	this->block = block;
}

MethodDeclaration::~MethodDeclaration()
{
	// not used
}

string_t MethodDeclaration::toString()
{
	MethodDeclaration *node = this;
#line 333 "/home/josuedejesus/ProyectoCompiladores2/MiniJavaAst.tc"
	{
	    std::ostringstream os;
	
	    os << "MethodDeclaration(";
	
	    if(node->parameter_list) {
	        os << ", " << node->parameter_list->toString();
	    }
	
	    os << node->block->toString() << ")";
	
	    return os.str();
	}
#line 601 "MiniJavaAst.cpp"
}

int MethodDeclaration::isA(int kind) const
{
	if(kind == MethodDeclaration_kind)
		return 1;
	else
		return Node::isA(kind);
}

const char *MethodDeclaration::getKindName() const
{
	return "MethodDeclaration";
}

Parameter::Parameter(bool is_ref, string_t identifier)
	: Node()
{
	this->kind__ = Parameter_kind;
	this->is_ref = is_ref;
	this->identifier = identifier;
}

Parameter::~Parameter()
{
	// not used
}

string_t Parameter::toString()
{
	Parameter *node = this;
#line 347 "/home/josuedejesus/ProyectoCompiladores2/MiniJavaAst.tc"
	{
	    std::ostringstream os;
	
	    os << "Parameter(" << node->identifier << ")";
	
	    return os.str();
	}
#line 641 "MiniJavaAst.cpp"
}

int Parameter::isA(int kind) const
{
	if(kind == Parameter_kind)
		return 1;
	else
		return Node::isA(kind);
}

const char *Parameter::getKindName() const
{
	return "Parameter";
}

ArrayParameter::ArrayParameter(bool is_ref, int index, string_t identifier)
	: Node()
{
	this->kind__ = ArrayParameter_kind;
	this->is_ref = is_ref;
	this->index = index;
	this->identifier = identifier;
}

ArrayParameter::~ArrayParameter()
{
	// not used
}

string_t ArrayParameter::toString()
{
	ArrayParameter *node = this;
#line 355 "/home/josuedejesus/ProyectoCompiladores2/MiniJavaAst.tc"
	{
	    std::ostringstream os;
	
	    os << "ArrayParameter(" << node->identifier << ")";
	
	    return os.str();
	}
#line 682 "MiniJavaAst.cpp"
}

int ArrayParameter::isA(int kind) const
{
	if(kind == ArrayParameter_kind)
		return 1;
	else
		return Node::isA(kind);
}

const char *ArrayParameter::getKindName() const
{
	return "ArrayParameter";
}

Block::Block(Node * statement_list)
	: Node()
{
	this->kind__ = Block_kind;
	this->statement_list = statement_list;
}

Block::~Block()
{
	// not used
}

string_t Block::toString()
{
	Block *node = this;
#line 386 "/home/josuedejesus/ProyectoCompiladores2/MiniJavaAst.tc"
	{
	    std::ostringstream os;
	
	    os << "Block(" << node->statement_list->toString() << ")";
	
	    return os.str();
	}
#line 721 "MiniJavaAst.cpp"
}

int Block::isA(int kind) const
{
	if(kind == Block_kind)
		return 1;
	else
		return Node::isA(kind);
}

const char *Block::getKindName() const
{
	return "Block";
}

VariableDeclaration::VariableDeclaration(Node * identifier_list)
	: Node()
{
	this->kind__ = VariableDeclaration_kind;
	this->identifier_list = identifier_list;
}

VariableDeclaration::~VariableDeclaration()
{
	// not used
}

string_t VariableDeclaration::toString()
{
	VariableDeclaration *node = this;
#line 394 "/home/josuedejesus/ProyectoCompiladores2/MiniJavaAst.tc"
	{
	    std::ostringstream os;
	
	    os << "VariableDeclaration(" << node->identifier_list->toString() << ")";
	
	
	    return os.str();
	}
#line 761 "MiniJavaAst.cpp"
}

int VariableDeclaration::isA(int kind) const
{
	if(kind == VariableDeclaration_kind)
		return 1;
	else
		return Node::isA(kind);
}

const char *VariableDeclaration::getKindName() const
{
	return "VariableDeclaration";
}

ArrayDeclaration::ArrayDeclaration(bool is_global, string_t identifier, int size)
	: Node()
{
	this->kind__ = ArrayDeclaration_kind;
	this->is_global = is_global;
	this->identifier = identifier;
	this->size = size;
}

ArrayDeclaration::~ArrayDeclaration()
{
	// not used
}

string_t ArrayDeclaration::toString()
{
	ArrayDeclaration *node = this;
#line 403 "/home/josuedejesus/ProyectoCompiladores2/MiniJavaAst.tc"
	{
	    std::ostringstream os;
	
	    os << "ArrayDeclaration(" << node->identifier << ")";
	
	    return os.str();
	}
#line 802 "MiniJavaAst.cpp"
}

int ArrayDeclaration::isA(int kind) const
{
	if(kind == ArrayDeclaration_kind)
		return 1;
	else
		return Node::isA(kind);
}

const char *ArrayDeclaration::getKindName() const
{
	return "ArrayDeclaration";
}

Assignment::Assignment(string_t identifier, Expr * expr)
	: Node()
{
	this->kind__ = Assignment_kind;
	this->identifier = identifier;
	this->expr = expr;
}

Assignment::~Assignment()
{
	// not used
}

string_t Assignment::toString()
{
	Assignment *node = this;
#line 419 "/home/josuedejesus/ProyectoCompiladores2/MiniJavaAst.tc"
	{
	    std::ostringstream os;
	
	    os << "Assignment(" << node->identifier << ", " << node->expr->toString() << ")";
	
	    return os.str();
	}
#line 842 "MiniJavaAst.cpp"
}

int Assignment::isA(int kind) const
{
	if(kind == Assignment_kind)
		return 1;
	else
		return Node::isA(kind);
}

const char *Assignment::getKindName() const
{
	return "Assignment";
}

ArrayAssignment::ArrayAssignment(string_t array_identifier, Node * index_expr, Expr * expr)
	: Node()
{
	this->kind__ = ArrayAssignment_kind;
	this->array_identifier = array_identifier;
	this->index_expr = index_expr;
	this->expr = expr;
}

ArrayAssignment::~ArrayAssignment()
{
	// not used
}

string_t ArrayAssignment::toString()
{
	ArrayAssignment *node = this;
#line 427 "/home/josuedejesus/ProyectoCompiladores2/MiniJavaAst.tc"
	{
	    std::ostringstream os;
	
	    os << "ArrayAssignment(" << node->array_identifier << "[" << node->index_expr->toString() << "]" << ", " << node->expr->toString() << ")";
	
	    return os.str();
	}
#line 883 "MiniJavaAst.cpp"
}

int ArrayAssignment::isA(int kind) const
{
	if(kind == ArrayAssignment_kind)
		return 1;
	else
		return Node::isA(kind);
}

const char *ArrayAssignment::getKindName() const
{
	return "ArrayAssignment";
}

MethodCall::MethodCall(string_t identifier, Node * argument_list)
	: Node()
{
	this->kind__ = MethodCall_kind;
	this->identifier = identifier;
	this->argument_list = argument_list;
}

MethodCall::~MethodCall()
{
	// not used
}

string_t MethodCall::toString()
{
	MethodCall *node = this;
#line 435 "/home/josuedejesus/ProyectoCompiladores2/MiniJavaAst.tc"
	{
	    std::ostringstream os;
	
	    os << "MethodCall(" << node->identifier;
	
	    if(node->argument_list) {
	        os << ", " << node->argument_list->toString();
	
	    }
	
	    os << ")";
	
	    return os.str();
	}
#line 930 "MiniJavaAst.cpp"
}

int MethodCall::isA(int kind) const
{
	if(kind == MethodCall_kind)
		return 1;
	else
		return Node::isA(kind);
}

const char *MethodCall::getKindName() const
{
	return "MethodCall";
}

IfStmt::IfStmt(BooleanExpr * expr, Node * if_stmts, Node * else_stmts)
	: Node()
{
	this->kind__ = IfStmt_kind;
	this->expr = expr;
	this->if_stmts = if_stmts;
	this->else_stmts = else_stmts;
}

IfStmt::~IfStmt()
{
	// not used
}

string_t IfStmt::toString()
{
	IfStmt *node = this;
#line 465 "/home/josuedejesus/ProyectoCompiladores2/MiniJavaAst.tc"
	{
	    std::ostringstream os;
	
	    os << "IfStmt(" << node->expr->toString() << ", " << node->if_stmts->toString();
	
	    if(node->else_stmts) {
	        os << ", " << node->else_stmts->toString();
	    }
	
	    os << ")";
	
	    return os.str();
	}
#line 977 "MiniJavaAst.cpp"
}

int IfStmt::isA(int kind) const
{
	if(kind == IfStmt_kind)
		return 1;
	else
		return Node::isA(kind);
}

const char *IfStmt::getKindName() const
{
	return "IfStmt";
}

WhileStmt::WhileStmt(BooleanExpr * expr, Node * stmts)
	: Node()
{
	this->kind__ = WhileStmt_kind;
	this->expr = expr;
	this->stmts = stmts;
}

WhileStmt::~WhileStmt()
{
	// not used
}

string_t WhileStmt::toString()
{
	WhileStmt *node = this;
#line 479 "/home/josuedejesus/ProyectoCompiladores2/MiniJavaAst.tc"
	{
	    std::ostringstream os;
	
	    os << "WhileStmt(" << node->expr->toString() << ", " << node->stmts->toString() << ")";
	
	    return os.str();
	}
#line 1017 "MiniJavaAst.cpp"
}

int WhileStmt::isA(int kind) const
{
	if(kind == WhileStmt_kind)
		return 1;
	else
		return Node::isA(kind);
}

const char *WhileStmt::getKindName() const
{
	return "WhileStmt";
}

PrintStmt::PrintStmt(Node * expr)
	: Node()
{
	this->kind__ = PrintStmt_kind;
	this->expr = expr;
}

PrintStmt::~PrintStmt()
{
	// not used
}

string_t PrintStmt::toString()
{
	PrintStmt *node = this;
#line 487 "/home/josuedejesus/ProyectoCompiladores2/MiniJavaAst.tc"
	{
	    std::ostringstream os;
	
	    os << "PrintStmt(" << node->expr->toString() << ")";
	
	    return os.str();
	}
#line 1056 "MiniJavaAst.cpp"
}

int PrintStmt::isA(int kind) const
{
	if(kind == PrintStmt_kind)
		return 1;
	else
		return Node::isA(kind);
}

const char *PrintStmt::getKindName() const
{
	return "PrintStmt";
}

PrintStmtLit::PrintStmtLit(string_t literal)
	: Node()
{
	this->kind__ = PrintStmtLit_kind;
	this->literal = literal;
}

PrintStmtLit::~PrintStmtLit()
{
	// not used
}

string_t PrintStmtLit::toString()
{
	PrintStmtLit *node = this;
#line 495 "/home/josuedejesus/ProyectoCompiladores2/MiniJavaAst.tc"
	{
	    std::ostringstream os;
	
	    os << "PrintStmtLit(" << node->literal << ")";
	
	    return os.str();
	}
#line 1095 "MiniJavaAst.cpp"
}

int PrintStmtLit::isA(int kind) const
{
	if(kind == PrintStmtLit_kind)
		return 1;
	else
		return Node::isA(kind);
}

const char *PrintStmtLit::getKindName() const
{
	return "PrintStmtLit";
}

ReturnStmt::ReturnStmt(Node * expr)
	: Node()
{
	this->kind__ = ReturnStmt_kind;
	this->expr = expr;
}

ReturnStmt::~ReturnStmt()
{
	// not used
}

string_t ReturnStmt::toString()
{
	ReturnStmt *node = this;
#line 503 "/home/josuedejesus/ProyectoCompiladores2/MiniJavaAst.tc"
	{
	    std::ostringstream os;
	
	    os << "ReturnStmt(" << node->expr->toString() << ")";
	
	
	    return os.str();
	}
#line 1135 "MiniJavaAst.cpp"
}

int ReturnStmt::isA(int kind) const
{
	if(kind == ReturnStmt_kind)
		return 1;
	else
		return Node::isA(kind);
}

const char *ReturnStmt::getKindName() const
{
	return "ReturnStmt";
}

StringLiteral::StringLiteral(string_t value)
	: Node()
{
	this->kind__ = StringLiteral_kind;
	this->value = value;
}

StringLiteral::~StringLiteral()
{
	// not used
}

string_t StringLiteral::toString()
{
	StringLiteral *node = this;
#line 512 "/home/josuedejesus/ProyectoCompiladores2/MiniJavaAst.tc"
	{
	    std::ostringstream os;
	
	    os << "StringLiteral(" << node->value << ")";
	
	    return os.str();
	}
#line 1174 "MiniJavaAst.cpp"
}

int StringLiteral::isA(int kind) const
{
	if(kind == StringLiteral_kind)
		return 1;
	else
		return Node::isA(kind);
}

const char *StringLiteral::getKindName() const
{
	return "StringLiteral";
}

Expr::Expr()
	: Node()
{
	this->kind__ = Expr_kind;
}

Expr::~Expr()
{
	// not used
}

int Expr::isA(int kind) const
{
	if(kind == Expr_kind)
		return 1;
	else
		return Node::isA(kind);
}

const char *Expr::getKindName() const
{
	return "Expr";
}

BooleanExpr::BooleanExpr()
	: Node()
{
	this->kind__ = BooleanExpr_kind;
}

BooleanExpr::~BooleanExpr()
{
	// not used
}

int BooleanExpr::isA(int kind) const
{
	if(kind == BooleanExpr_kind)
		return 1;
	else
		return Node::isA(kind);
}

const char *BooleanExpr::getKindName() const
{
	return "BooleanExpr";
}

ArgumentList::ArgumentList(Node * first_node, Node * next_node)
	: Expr()
{
	this->kind__ = ArgumentList_kind;
	this->first_node = first_node;
	this->next_node = next_node;
}

ArgumentList::~ArgumentList()
{
	// not used
}

string_t ArgumentList::toString()
{
	ArgumentList *node = this;
#line 305 "/home/josuedejesus/ProyectoCompiladores2/MiniJavaAst.tc"
	{
	    std::ostringstream os;
	
	    os << "ArgumentList(" << node->first_node->toString();
	
	    if (node->next_node) {
	        os << ", " << node->next_node->toString();
	    }
	    
	    os << ")";
	
	    return os.str();
	}
#line 1268 "MiniJavaAst.cpp"
}

int ArgumentList::isA(int kind) const
{
	if(kind == ArgumentList_kind)
		return 1;
	else
		return Expr::isA(kind);
}

const char *ArgumentList::getKindName() const
{
	return "ArgumentList";
}

Number::Number(int value)
	: Expr()
{
	this->kind__ = Number_kind;
	this->value = value;
}

Number::~Number()
{
	// not used
}

string_t Number::toString()
{
	Number *node = this;
#line 627 "/home/josuedejesus/ProyectoCompiladores2/MiniJavaAst.tc"
	{
	    return std::to_string(node->value);
	}
#line 1303 "MiniJavaAst.cpp"
}

int Number::isA(int kind) const
{
	if(kind == Number_kind)
		return 1;
	else
		return Expr::isA(kind);
}

const char *Number::getKindName() const
{
	return "Number";
}

Identifier::Identifier(string_t name)
	: Expr()
{
	this->kind__ = Identifier_kind;
	this->name = name;
}

Identifier::~Identifier()
{
	// not used
}

string_t Identifier::toString()
{
	Identifier *node = this;
#line 631 "/home/josuedejesus/ProyectoCompiladores2/MiniJavaAst.tc"
	{
	    return node->name;
	}
#line 1338 "MiniJavaAst.cpp"
}

int Identifier::isA(int kind) const
{
	if(kind == Identifier_kind)
		return 1;
	else
		return Expr::isA(kind);
}

const char *Identifier::getKindName() const
{
	return "Identifier";
}

ArrayVariable::ArrayVariable(string_t identifier, Expr * expr)
	: Expr()
{
	this->kind__ = ArrayVariable_kind;
	this->identifier = identifier;
	this->expr = expr;
}

ArrayVariable::~ArrayVariable()
{
	// not used
}

string_t ArrayVariable::toString()
{
	ArrayVariable *node = this;
#line 411 "/home/josuedejesus/ProyectoCompiladores2/MiniJavaAst.tc"
	{
	    std::ostringstream os;
	
	    os << "ArrayVariable(" << node->identifier << node->expr->toString() << ")";
	
	    return os.str();
	}
#line 1378 "MiniJavaAst.cpp"
}

int ArrayVariable::isA(int kind) const
{
	if(kind == ArrayVariable_kind)
		return 1;
	else
		return Expr::isA(kind);
}

const char *ArrayVariable::getKindName() const
{
	return "ArrayVariable";
}

FunctionCall::FunctionCall(string_t identifier, Node * argument_list)
	: Expr()
{
	this->kind__ = FunctionCall_kind;
	this->identifier = identifier;
	this->argument_list = argument_list;
}

FunctionCall::~FunctionCall()
{
	// not used
}

string_t FunctionCall::toString()
{
	FunctionCall *node = this;
#line 450 "/home/josuedejesus/ProyectoCompiladores2/MiniJavaAst.tc"
	{
	    std::ostringstream os;
	
	    os << "FunctionCall(" << node->identifier;
	
	    if (node->argument_list) {
	        os << ", " << node->argument_list->toString();
	
	    }
	
	    os << ")";
	
	    return os.str();
	}
#line 1425 "MiniJavaAst.cpp"
}

int FunctionCall::isA(int kind) const
{
	if(kind == FunctionCall_kind)
		return 1;
	else
		return Expr::isA(kind);
}

const char *FunctionCall::getKindName() const
{
	return "FunctionCall";
}

Argument::Argument(bool is_ref, string_t identifier, Expr * expr)
	: Expr()
{
	this->kind__ = Argument_kind;
	this->is_ref = is_ref;
	this->identifier = identifier;
	this->expr = expr;
}

Argument::~Argument()
{
	// not used
}

string_t Argument::toString()
{
	Argument *node = this;
#line 371 "/home/josuedejesus/ProyectoCompiladores2/MiniJavaAst.tc"
	{
	    std::ostringstream os;
	
	    if (node->expr) {
	        os << "Argument(" << node->expr->toString() << ")";
	
	    } else {
	        os << "Argument(" << node->identifier << ")";
	
	    }
	
	
	    return os.str();
	}
#line 1473 "MiniJavaAst.cpp"
}

int Argument::isA(int kind) const
{
	if(kind == Argument_kind)
		return 1;
	else
		return Expr::isA(kind);
}

const char *Argument::getKindName() const
{
	return "Argument";
}

ArrayArgument::ArrayArgument(bool is_ref, Expr * expr, string_t identifier)
	: Expr()
{
	this->kind__ = ArrayArgument_kind;
	this->is_ref = is_ref;
	this->expr = expr;
	this->identifier = identifier;
}

ArrayArgument::~ArrayArgument()
{
	// not used
}

string_t ArrayArgument::toString()
{
	ArrayArgument *node = this;
#line 363 "/home/josuedejesus/ProyectoCompiladores2/MiniJavaAst.tc"
	{
	    std::ostringstream os;
	
	    os << "ArrayArgument(" << node->identifier << ")";
	
	    return os.str();
	}
#line 1514 "MiniJavaAst.cpp"
}

int ArrayArgument::isA(int kind) const
{
	if(kind == ArrayArgument_kind)
		return 1;
	else
		return Expr::isA(kind);
}

const char *ArrayArgument::getKindName() const
{
	return "ArrayArgument";
}

BinaryExpr::BinaryExpr(Expr * left, Expr * right)
	: Expr()
{
	this->kind__ = BinaryExpr_kind;
	this->left = left;
	this->right = right;
}

BinaryExpr::~BinaryExpr()
{
	// not used
}

int BinaryExpr::isA(int kind) const
{
	if(kind == BinaryExpr_kind)
		return 1;
	else
		return Expr::isA(kind);
}

const char *BinaryExpr::getKindName() const
{
	return "BinaryExpr";
}

AddExpr::AddExpr(Expr * left, Expr * right)
	: BinaryExpr(left, right)
{
	this->kind__ = AddExpr_kind;
}

AddExpr::~AddExpr()
{
	// not used
}

string_t AddExpr::toString()
{
	AddExpr *node = this;
#line 520 "/home/josuedejesus/ProyectoCompiladores2/MiniJavaAst.tc"
	{
	    std::ostringstream os;
	
	    os << "AddExpr(" << node->left->toString() << ", " << node->right->toString() << ")";
	
	    return os.str(); 
	}
#line 1578 "MiniJavaAst.cpp"
}

int AddExpr::isA(int kind) const
{
	if(kind == AddExpr_kind)
		return 1;
	else
		return BinaryExpr::isA(kind);
}

const char *AddExpr::getKindName() const
{
	return "AddExpr";
}

SubExpr::SubExpr(Expr * left, Expr * right)
	: BinaryExpr(left, right)
{
	this->kind__ = SubExpr_kind;
}

SubExpr::~SubExpr()
{
	// not used
}

string_t SubExpr::toString()
{
	SubExpr *node = this;
#line 528 "/home/josuedejesus/ProyectoCompiladores2/MiniJavaAst.tc"
	{
	    std::ostringstream os;
	
	    os << "SubExpr(" << node->left->toString() << ", " << node->right->toString() << ")";
	
	    return os.str(); 
	}
#line 1616 "MiniJavaAst.cpp"
}

int SubExpr::isA(int kind) const
{
	if(kind == SubExpr_kind)
		return 1;
	else
		return BinaryExpr::isA(kind);
}

const char *SubExpr::getKindName() const
{
	return "SubExpr";
}

MulExpr::MulExpr(Expr * left, Expr * right)
	: BinaryExpr(left, right)
{
	this->kind__ = MulExpr_kind;
}

MulExpr::~MulExpr()
{
	// not used
}

string_t MulExpr::toString()
{
	MulExpr *node = this;
#line 536 "/home/josuedejesus/ProyectoCompiladores2/MiniJavaAst.tc"
	{
	    std::ostringstream os;
	
	    os << "MulExpr(" << node->left->toString() << ", " << node->right->toString() << ")";
	
	    return os.str(); 
	}
#line 1654 "MiniJavaAst.cpp"
}

int MulExpr::isA(int kind) const
{
	if(kind == MulExpr_kind)
		return 1;
	else
		return BinaryExpr::isA(kind);
}

const char *MulExpr::getKindName() const
{
	return "MulExpr";
}

DivExpr::DivExpr(Expr * left, Expr * right)
	: BinaryExpr(left, right)
{
	this->kind__ = DivExpr_kind;
}

DivExpr::~DivExpr()
{
	// not used
}

string_t DivExpr::toString()
{
	DivExpr *node = this;
#line 544 "/home/josuedejesus/ProyectoCompiladores2/MiniJavaAst.tc"
	{
	    std::ostringstream os;
	
	    os << "DivExpr(" << node->left->toString() << ", " << node->right->toString() << ")";
	
	
	    return os.str(); 
	}
#line 1693 "MiniJavaAst.cpp"
}

int DivExpr::isA(int kind) const
{
	if(kind == DivExpr_kind)
		return 1;
	else
		return BinaryExpr::isA(kind);
}

const char *DivExpr::getKindName() const
{
	return "DivExpr";
}

ModExpr::ModExpr(Expr * left, Expr * right)
	: BinaryExpr(left, right)
{
	this->kind__ = ModExpr_kind;
}

ModExpr::~ModExpr()
{
	// not used
}

string_t ModExpr::toString()
{
	ModExpr *node = this;
#line 553 "/home/josuedejesus/ProyectoCompiladores2/MiniJavaAst.tc"
	{
	    std::ostringstream os;
	
	    os << "ModExpr(" << node->left->toString() << ", " << node->right->toString() << ")";
	
	    return os.str(); 
	}
#line 1731 "MiniJavaAst.cpp"
}

int ModExpr::isA(int kind) const
{
	if(kind == ModExpr_kind)
		return 1;
	else
		return BinaryExpr::isA(kind);
}

const char *ModExpr::getKindName() const
{
	return "ModExpr";
}

BinaryBooleanExpr::BinaryBooleanExpr(BooleanExpr * left, BooleanExpr * right)
	: BooleanExpr()
{
	this->kind__ = BinaryBooleanExpr_kind;
	this->left = left;
	this->right = right;
}

BinaryBooleanExpr::~BinaryBooleanExpr()
{
	// not used
}

int BinaryBooleanExpr::isA(int kind) const
{
	if(kind == BinaryBooleanExpr_kind)
		return 1;
	else
		return BooleanExpr::isA(kind);
}

const char *BinaryBooleanExpr::getKindName() const
{
	return "BinaryBooleanExpr";
}

RelationalExpr::RelationalExpr()
	: BooleanExpr()
{
	this->kind__ = RelationalExpr_kind;
}

RelationalExpr::~RelationalExpr()
{
	// not used
}

int RelationalExpr::isA(int kind) const
{
	if(kind == RelationalExpr_kind)
		return 1;
	else
		return BooleanExpr::isA(kind);
}

const char *RelationalExpr::getKindName() const
{
	return "RelationalExpr";
}

AndExpr::AndExpr(BooleanExpr * left, BooleanExpr * right)
	: BinaryBooleanExpr(left, right)
{
	this->kind__ = AndExpr_kind;
}

AndExpr::~AndExpr()
{
	// not used
}

string_t AndExpr::toString()
{
	AndExpr *node = this;
#line 611 "/home/josuedejesus/ProyectoCompiladores2/MiniJavaAst.tc"
	{
	    std::ostringstream os;
	
	    os << "AndExpr(" << node->left->toString() << ", " << node->right->toString() << ")";
	
	    return os.str(); 
	}
#line 1819 "MiniJavaAst.cpp"
}

int AndExpr::isA(int kind) const
{
	if(kind == AndExpr_kind)
		return 1;
	else
		return BinaryBooleanExpr::isA(kind);
}

const char *AndExpr::getKindName() const
{
	return "AndExpr";
}

OrExpr::OrExpr(BooleanExpr * left, BooleanExpr * right)
	: BinaryBooleanExpr(left, right)
{
	this->kind__ = OrExpr_kind;
}

OrExpr::~OrExpr()
{
	// not used
}

string_t OrExpr::toString()
{
	OrExpr *node = this;
#line 619 "/home/josuedejesus/ProyectoCompiladores2/MiniJavaAst.tc"
	{
	    std::ostringstream os;
	
	    os << "OrExpr(" << node->left->toString() << ", " << node->right->toString() << ")";
	
	    return os.str(); 
	}
#line 1857 "MiniJavaAst.cpp"
}

int OrExpr::isA(int kind) const
{
	if(kind == OrExpr_kind)
		return 1;
	else
		return BinaryBooleanExpr::isA(kind);
}

const char *OrExpr::getKindName() const
{
	return "OrExpr";
}

BinaryRelationalExpr::BinaryRelationalExpr(Expr * left, Expr * right)
	: RelationalExpr()
{
	this->kind__ = BinaryRelationalExpr_kind;
	this->left = left;
	this->right = right;
}

BinaryRelationalExpr::~BinaryRelationalExpr()
{
	// not used
}

int BinaryRelationalExpr::isA(int kind) const
{
	if(kind == BinaryRelationalExpr_kind)
		return 1;
	else
		return RelationalExpr::isA(kind);
}

const char *BinaryRelationalExpr::getKindName() const
{
	return "BinaryRelationalExpr";
}

GreaterExpr::GreaterExpr(Expr * left, Expr * right)
	: BinaryRelationalExpr(left, right)
{
	this->kind__ = GreaterExpr_kind;
}

GreaterExpr::~GreaterExpr()
{
	// not used
}

string_t GreaterExpr::toString()
{
	GreaterExpr *node = this;
#line 561 "/home/josuedejesus/ProyectoCompiladores2/MiniJavaAst.tc"
	{
	    std::ostringstream os;
	
	    os << "GreaterExpr(" << node->left->toString() << ", " << node->right->toString() << ")";
	
	    return os.str(); 
	}
#line 1921 "MiniJavaAst.cpp"
}

int GreaterExpr::isA(int kind) const
{
	if(kind == GreaterExpr_kind)
		return 1;
	else
		return BinaryRelationalExpr::isA(kind);
}

const char *GreaterExpr::getKindName() const
{
	return "GreaterExpr";
}

GreaterEqualExpr::GreaterEqualExpr(Expr * left, Expr * right)
	: BinaryRelationalExpr(left, right)
{
	this->kind__ = GreaterEqualExpr_kind;
}

GreaterEqualExpr::~GreaterEqualExpr()
{
	// not used
}

string_t GreaterEqualExpr::toString()
{
	GreaterEqualExpr *node = this;
#line 569 "/home/josuedejesus/ProyectoCompiladores2/MiniJavaAst.tc"
	{
	    std::ostringstream os;
	
	    os << "GreaterEqualExpr(" << node->left->toString() << ", " << node->right->toString() << ")";
	
	    return os.str(); 
	}
#line 1959 "MiniJavaAst.cpp"
}

int GreaterEqualExpr::isA(int kind) const
{
	if(kind == GreaterEqualExpr_kind)
		return 1;
	else
		return BinaryRelationalExpr::isA(kind);
}

const char *GreaterEqualExpr::getKindName() const
{
	return "GreaterEqualExpr";
}

LessExpr::LessExpr(Expr * left, Expr * right)
	: BinaryRelationalExpr(left, right)
{
	this->kind__ = LessExpr_kind;
}

LessExpr::~LessExpr()
{
	// not used
}

string_t LessExpr::toString()
{
	LessExpr *node = this;
#line 578 "/home/josuedejesus/ProyectoCompiladores2/MiniJavaAst.tc"
	{
	    std::ostringstream os;
	
	    os << "LessExpr(" << node->left->toString() << ", " << node->right->toString() << ")";
	
	    return os.str(); 
	}
#line 1997 "MiniJavaAst.cpp"
}

int LessExpr::isA(int kind) const
{
	if(kind == LessExpr_kind)
		return 1;
	else
		return BinaryRelationalExpr::isA(kind);
}

const char *LessExpr::getKindName() const
{
	return "LessExpr";
}

LessEqualExpr::LessEqualExpr(Expr * left, Expr * right)
	: BinaryRelationalExpr(left, right)
{
	this->kind__ = LessEqualExpr_kind;
}

LessEqualExpr::~LessEqualExpr()
{
	// not used
}

string_t LessEqualExpr::toString()
{
	LessEqualExpr *node = this;
#line 586 "/home/josuedejesus/ProyectoCompiladores2/MiniJavaAst.tc"
	{
	    std::ostringstream os;
	
	    os << "LessEqualExpr(" << node->left->toString() << ", " << node->right->toString() << ")";
	
	
	    return os.str(); 
	}
#line 2036 "MiniJavaAst.cpp"
}

int LessEqualExpr::isA(int kind) const
{
	if(kind == LessEqualExpr_kind)
		return 1;
	else
		return BinaryRelationalExpr::isA(kind);
}

const char *LessEqualExpr::getKindName() const
{
	return "LessEqualExpr";
}

EqualExpr::EqualExpr(Expr * left, Expr * right)
	: BinaryRelationalExpr(left, right)
{
	this->kind__ = EqualExpr_kind;
}

EqualExpr::~EqualExpr()
{
	// not used
}

string_t EqualExpr::toString()
{
	EqualExpr *node = this;
#line 595 "/home/josuedejesus/ProyectoCompiladores2/MiniJavaAst.tc"
	{
	    std::ostringstream os;
	
	    os << "EqualExpr(" << node->left->toString() << ", " << node->right->toString() << ")";
	
	    return os.str(); 
	}
#line 2074 "MiniJavaAst.cpp"
}

int EqualExpr::isA(int kind) const
{
	if(kind == EqualExpr_kind)
		return 1;
	else
		return BinaryRelationalExpr::isA(kind);
}

const char *EqualExpr::getKindName() const
{
	return "EqualExpr";
}

NotEqualExpr::NotEqualExpr(Expr * left, Expr * right)
	: BinaryRelationalExpr(left, right)
{
	this->kind__ = NotEqualExpr_kind;
}

NotEqualExpr::~NotEqualExpr()
{
	// not used
}

string_t NotEqualExpr::toString()
{
	NotEqualExpr *node = this;
#line 603 "/home/josuedejesus/ProyectoCompiladores2/MiniJavaAst.tc"
	{
	    std::ostringstream os;
	
	    os << "NotEqualExpr(" << node->left->toString() << ", " << node->right->toString() << ")";
	
	    return os.str(); 
	}
#line 2112 "MiniJavaAst.cpp"
}

int NotEqualExpr::isA(int kind) const
{
	if(kind == NotEqualExpr_kind)
		return 1;
	else
		return BinaryRelationalExpr::isA(kind);
}

const char *NotEqualExpr::getKindName() const
{
	return "NotEqualExpr";
}

static CodegenResult exprCompile_1__(NodeList *root, type_table_t & types, literal_table_t & literals, function_table_t & functions, symbol_table_t & vars)
#line 666 "/home/josuedejesus/ProyectoCompiladores2/MiniJavaAst.tc"
{
    std::ostringstream os;

    getFunction(root->first_node, functions);


    CodegenResult res;

    CodegenResult r1 = exprCompile(root->first_node, types, literals, functions, vars);

    os << r1.code;
    res.place = r1.place;

    if (root->next_node) {
        getFunction(root->next_node, functions);


        CodegenResult r2 = exprCompile(root->next_node, types, literals, functions, vars);
        os << "\n" << r2.code;
        res.place = r2.place;  
    }

    res.code = os.str();

    return res;
}
#line 2156 "MiniJavaAst.cpp"

static CodegenResult exprCompile_2__(ParameterList *root, type_table_t & types, literal_table_t & literals, function_table_t & functions, symbol_table_t & vars)
#line 693 "/home/josuedejesus/ProyectoCompiladores2/MiniJavaAst.tc"
{
    std::ostringstream os;

    CodegenResult r1 = exprCompile(root->first_node, types, literals, functions, vars);

    os << r1.code;

    if (root->next_node) {

        CodegenResult r2 = exprCompile(root->next_node, types, literals, functions, vars);
        os << ", " << r2.code;  
    }
    return {os.str(), ""};
}
#line 2174 "MiniJavaAst.cpp"

static CodegenResult exprCompile_3__(ArgumentList *root, type_table_t & types, literal_table_t & literals, function_table_t & functions, symbol_table_t & vars)
#line 708 "/home/josuedejesus/ProyectoCompiladores2/MiniJavaAst.tc"
{
    std::ostringstream os;

    CodegenResult res;
    CodegenResult r1 = exprCompile(root->first_node, types, literals, functions, vars);
    
    os << r1.code;
    res.place = r1.place;

    if (root->next_node) {
        CodegenResult r2 = exprCompile(root->next_node, types, literals, functions, vars);
        os << "\n" << r2.code;
        res.place += ", " + r2.place;
    }

    res.code = os.str();

    return res;
}
#line 2197 "MiniJavaAst.cpp"

static CodegenResult exprCompile_4__(Number *root, type_table_t & types, literal_table_t & literals, function_table_t & functions, symbol_table_t & vars)
#line 1578 "/home/josuedejesus/ProyectoCompiladores2/MiniJavaAst.tc"
{
    std::ostringstream os;

    CodegenResult r;

    r.code = "";
    r.place = std::to_string(root->value);

    return r;
}
#line 2211 "MiniJavaAst.cpp"

static CodegenResult exprCompile_5__(Identifier *root, type_table_t & types, literal_table_t & literals, function_table_t & functions, symbol_table_t & vars)
#line 1589 "/home/josuedejesus/ProyectoCompiladores2/MiniJavaAst.tc"
{
    std::ostringstream os;

    CodegenResult r;

    auto it = types.find(root->name);

    if (it != types.end()) {
        if (it->second == "*") {
            r.place = newVariable();
            os << r.place << " = load i32, i32* %" << root->name << ", align 4\n";
        } else if (it->second == "@") {
            r.place = "* @" + root->name;
        } else {
            r.place = "%" + root->name;
        }
    } else {
        r.place = newVariable();
        os << r.place << " = load i32, i32* %" << root->name << ", align 4\n";
    }

    r.code = os.str();

    return r;
}
#line 2240 "MiniJavaAst.cpp"

static CodegenResult exprCompile_6__(ArrayVariable *root, type_table_t & types, literal_table_t & literals, function_table_t & functions, symbol_table_t & vars)
#line 1615 "/home/josuedejesus/ProyectoCompiladores2/MiniJavaAst.tc"
{
    std::ostringstream os;

    CodegenResult i = exprCompile(root->expr, types, literals, functions, vars);

    os << i.code << "\n";

    CodegenResult arr_ptr;
    arr_ptr.place = newVariable();

    auto it = types.find(root->identifier);

    if (it == types.end()) {
    throw std::runtime_error("Error: Unknown identifier '" + root->identifier + "'");
}

    if (it->second == "@") {
        os << arr_ptr.place << " = getelementptr i32, i32* @" << root->identifier << ", i32 " << i.place << "\n";
    } else {
        os << arr_ptr.place << " = getelementptr i32, i32* %" << root->identifier << ", i32 " << i.place << "\n";
    }


    CodegenResult ptr_value;
    ptr_value.place = newVariable();

    os << ptr_value.place << " = load i32, i32* " << arr_ptr.place << ", align 4" << "\n";

    ptr_value.code = os.str();

    return ptr_value;
}
#line 2276 "MiniJavaAst.cpp"

static CodegenResult exprCompile_7__(FunctionCall *root, type_table_t & types, literal_table_t & literals, function_table_t & functions, symbol_table_t & vars)
#line 1071 "/home/josuedejesus/ProyectoCompiladores2/MiniJavaAst.tc"
{
    std::ostringstream os;

    auto method = functions.find(root->identifier);

    if (method == functions.end()) {
        throw std::runtime_error("Error: Method '" + root->identifier + "' was not declared.");
    }

    MethodDeclaration* methNode =  static_cast<MethodDeclaration*>(method->second);
    current_method = methNode->parameter_list;

    ParameterList* params = static_cast<ParameterList*>(methNode->parameter_list);

    int params_count = 0;

    while (params) {
        params_count++;
        params = static_cast<ParameterList*>(params->next_node);
    }

    ArgumentList* args = static_cast<ArgumentList*>(root->argument_list);
    int args_count = 0;
    while (args) {
        args_count++;
        args = static_cast<ArgumentList*>(args->next_node);
    }

    if (params_count != args_count) {
        throw std::runtime_error("Error: Function expected '" + std::to_string(params_count) + "' arguments but received '" + std::to_string(args_count) + "'.");
    }


    CodegenResult r1;

    if (root->argument_list) {
        r1 = exprCompile(root->argument_list, types, literals, functions, vars);

        os << r1.code;
    }

    CodegenResult res;
    res.place = newVariable();

    os << res.place  << " = call i32 @" << root->identifier << "(";

    if (root->argument_list) {
        os << r1.place;
    }

    os << ")\n";

    res.code = os.str();

    return res;
}
#line 2336 "MiniJavaAst.cpp"

static CodegenResult exprCompile_8__(Argument *root, type_table_t & types, literal_table_t & literals, function_table_t & functions, symbol_table_t & vars)
#line 827 "/home/josuedejesus/ProyectoCompiladores2/MiniJavaAst.tc"
{
    std::ostringstream os;

    CodegenResult r1;

    std::string type = "";
    std::string ref = "";

    if (auto* params = dynamic_cast<ParameterList*>(current_method)) {
        Node* firstNode = params->first_node;

        

        if (auto* param = dynamic_cast<Parameter*>(firstNode)) {
            if (param->is_ref) {
                auto* id = dynamic_cast<Identifier*>(root->expr);
                r1.place = "i32* %" + id->name;
            } else if (root->expr) {
                if (root->expr) {
                    r1 = exprCompile(root->expr, types, literals, functions, vars);
                }
                r1.place = "i32" + ref + " " + r1.place;
            } else {
                r1.place = "i32" + ref + " %" + root->identifier;
            }
        } else if (auto* param = dynamic_cast<ArrayParameter*>(firstNode)) {
            if (root->expr) {
                r1 = exprCompile(root->expr, types, literals, functions, vars);
            }
            r1.place = "[" + std::to_string(param->index) + " x i32]* " + r1.place;
        } else {
            throw std::runtime_error("Error: Unknown argument type.");
        }
        current_method = params->next_node;
    }

    os << r1.code;
    
    r1.code = os.str();

    types.emplace(r1.place, ref);

    return r1;
}
#line 2384 "MiniJavaAst.cpp"

static CodegenResult exprCompile_9__(ArrayArgument *root, type_table_t & types, literal_table_t & literals, function_table_t & functions, symbol_table_t & vars)
#line 895 "/home/josuedejesus/ProyectoCompiladores2/MiniJavaAst.tc"
{
    std::ostringstream os;

    std::string ref = "";

    CodegenResult index = exprCompile(root->expr, types, literals, functions, vars);

    os << "[" << index.place << " x i32]*";

    CodegenResult r1;
    r1.place = root->identifier;

    os << " %" << r1.place;

    r1.code = os.str();

    types.emplace(r1.place, ref);

    return r1;
}
#line 2408 "MiniJavaAst.cpp"

static CodegenResult exprCompile_10__(AddExpr *root, type_table_t & types, literal_table_t & literals, function_table_t & functions, symbol_table_t & vars)
#line 1287 "/home/josuedejesus/ProyectoCompiladores2/MiniJavaAst.tc"
{
    std::ostringstream os;

    CodegenResult r1 = exprCompile(root->left, types, literals, functions, vars);
    os << r1.code << "\n";

    CodegenResult r2 = exprCompile(root->right, types, literals, functions, vars);
    os << r2.code << "\n";

    CodegenResult r3;
    r3.place = newVariable();

    os << r3.place << " = add i32 " << r1.place << ", " << r2.place << "\n";

    CodegenResult r4;
    r4.place = r3.place;
    r4.code = os.str();

    return r4; 
}
#line 2432 "MiniJavaAst.cpp"

static CodegenResult exprCompile_11__(SubExpr *root, type_table_t & types, literal_table_t & literals, function_table_t & functions, symbol_table_t & vars)
#line 1308 "/home/josuedejesus/ProyectoCompiladores2/MiniJavaAst.tc"
{
    std::ostringstream os;

    CodegenResult r1 = exprCompile(root->left, types, literals, functions, vars);
    os << r1.code << "\n";

    CodegenResult r2 = exprCompile(root->right, types, literals, functions, vars);
    os << r2.code << "\n";

    CodegenResult r3;
    r3.place = newVariable();

    os << r3.place << " = sub i32 " << r1.place << ", " << r2.place << "\n";

    CodegenResult r4;
    r4.place = r3.place;
    r4.code = os.str();

    return r4; 
}
#line 2456 "MiniJavaAst.cpp"

static CodegenResult exprCompile_12__(MulExpr *root, type_table_t & types, literal_table_t & literals, function_table_t & functions, symbol_table_t & vars)
#line 1329 "/home/josuedejesus/ProyectoCompiladores2/MiniJavaAst.tc"
{
    std::ostringstream os;

    CodegenResult r1 = exprCompile(root->left, types, literals, functions, vars);
    os << r1.code << "\n";

    CodegenResult r2 = exprCompile(root->right, types, literals, functions, vars);
    os << r2.code << "\n";

    CodegenResult r3;
    r3.place = newVariable();

    os << r3.place << " = mul i32 " << r1.place << ", " << r2.place << "\n";

    CodegenResult r4;
    r4.place = r3.place;
    r4.code = os.str();

    return r4; 
}
#line 2480 "MiniJavaAst.cpp"

static CodegenResult exprCompile_13__(DivExpr *root, type_table_t & types, literal_table_t & literals, function_table_t & functions, symbol_table_t & vars)
#line 1350 "/home/josuedejesus/ProyectoCompiladores2/MiniJavaAst.tc"
{
    std::ostringstream os;

    CodegenResult r1 = exprCompile(root->left, types, literals, functions, vars);
    os << r1.code << "\n";

    CodegenResult r2 = exprCompile(root->right, types, literals, functions, vars);
    os << r2.code << "\n";

    CodegenResult r3;
    r3.place = newVariable();

    os << r3.place << " = sdiv i32 " << r1.place << ", " << r2.place << "\n";

    CodegenResult r4;
    r4.place = r3.place;
    r4.code = os.str();

    return r4; 
}
#line 2504 "MiniJavaAst.cpp"

static CodegenResult exprCompile_14__(ModExpr *root, type_table_t & types, literal_table_t & literals, function_table_t & functions, symbol_table_t & vars)
#line 1371 "/home/josuedejesus/ProyectoCompiladores2/MiniJavaAst.tc"
{
    std::ostringstream os;

    CodegenResult r1 = exprCompile(root->left, types, literals, functions, vars);
    os << r1.code << "\n";

    CodegenResult r2 = exprCompile(root->right, types, literals, functions, vars);
    os << r2.code << "\n";

    CodegenResult r3;
    r3.place = newVariable();

    os <<  r3.place << " = srem i32 " << r1.place << ", " << r2.place << "\n";

    CodegenResult r4;
    r4.place = r3.place;
    r4.code = os.str();

    return r4; 
}
#line 2528 "MiniJavaAst.cpp"

static CodegenResult exprCompile_15__(VariableList *root, type_table_t & types, literal_table_t & literals, function_table_t & functions, symbol_table_t & vars)
#line 728 "/home/josuedejesus/ProyectoCompiladores2/MiniJavaAst.tc"
{
    std::ostringstream os;

    auto it = types.find(root->identifier);

    if (it != types.end()) {
        throw std::runtime_error("Variable \"" + root->identifier + "\" already declared.");
    }

    if(root->is_global) {
        os << "@" << root->identifier << " = global i32 0, align 4\n";
        types.emplace(root->identifier, "@");
        vars.emplace(root->identifier, "");
    } else {
        os << "%" << root->identifier << " = alloca i32, align 4\n";
        //types.emplace(root->identifier, "");
        vars.emplace(root->identifier, "");
    }

    if (root->next_node) {
        CodegenResult r2 = exprCompile(root->next_node, types, literals, functions, vars);
        os << r2.code;
    }

    return {os.str(), ""};
}
#line 2558 "MiniJavaAst.cpp"

static CodegenResult exprCompile_16__(Program *root, type_table_t & types, literal_table_t & literals, function_table_t & functions, symbol_table_t & vars)
#line 639 "/home/josuedejesus/ProyectoCompiladores2/MiniJavaAst.tc"
{
    getFunction(root->class_body, functions);

    

    CodegenResult r = exprCompile(root->class_body, types, literals, functions, vars);

    std::ostringstream os;

    os << "declare void @exit(i32)\n";
    os << "declare i32 @printf(i8*, ...)\n";

    os << r.code;

    auto it = functions.find("main");
    if (it == functions.end()) {
        throw std::runtime_error("Error: A 'main' function is required.");
    }

    os << "@.fmt = private constant [4 x i8] c\"%d\\0A\\00\", align 1\n";
    for (const auto& [lit, var] : literals) {
        int size = lit.size() + 2;
        os << var << " = private constant [" << size << " x i8] c\"" + lit + "\\0A\\00\", align 1\n";
    }
    return {os.str(), ""};
}
#line 2588 "MiniJavaAst.cpp"

static CodegenResult exprCompile_17__(Type *root, type_table_t & types, literal_table_t & literals, function_table_t & functions, symbol_table_t & vars)
#line 789 "/home/josuedejesus/ProyectoCompiladores2/MiniJavaAst.tc"
{
    std::ostringstream os;

    if (root->name == "void") {
        os << "void";
    } else if (root->name == "int") {
        os << "i32";
    }

    return {os.str(), ""};
}
#line 2603 "MiniJavaAst.cpp"

static CodegenResult exprCompile_18__(MethodDeclaration *root, type_table_t & types, literal_table_t & literals, function_table_t & functions, symbol_table_t & vars)
#line 755 "/home/josuedejesus/ProyectoCompiladores2/MiniJavaAst.tc"
{
    std::ostringstream os;

    CodegenResult r1 = exprCompile(root->type, types, literals, functions, vars);
    current_function_type = r1.code;

    os << "define " << r1.code << " @" << root->name << "(";

    if (root->parameter_list) {
        CodegenResult r2 = exprCompile(root->parameter_list, types, literals, functions, vars);
        os << r2.code;
    }

    os << ") {\n";

    os << "entry:\n";

    CodegenResult r3 = exprCompile(root->block, types, literals, functions, vars);

    os << r3.code << "\n";

    if (current_function_type.find("void") != std::string::npos) {
        os << "ret void\n"; 
    } else {
        if (!has_return) {
            os << "ret i32 0\n";
        }
    }

    os << "}\n";

    return {os.str(), ""};
}
#line 2640 "MiniJavaAst.cpp"

static CodegenResult exprCompile_19__(Parameter *root, type_table_t & types, literal_table_t & literals, function_table_t & functions, symbol_table_t & vars)
#line 801 "/home/josuedejesus/ProyectoCompiladores2/MiniJavaAst.tc"
{
    std::ostringstream os;

    std::string type = "i32";

    os << "i32";

    if (root->is_ref) {
        os << "*";
        type = "*";
    }

    CodegenResult r1;
    r1.place = root->identifier;

    os << " %" << r1.place;

    r1.code = os.str();

    types.emplace(r1.place, type);
    vars.emplace(r1.place, "");


    return r1;
}
#line 2669 "MiniJavaAst.cpp"

static CodegenResult exprCompile_20__(ArrayParameter *root, type_table_t & types, literal_table_t & literals, function_table_t & functions, symbol_table_t & vars)
#line 872 "/home/josuedejesus/ProyectoCompiladores2/MiniJavaAst.tc"
{
    std::ostringstream os;

    std::string ref = "";

    //CodegenResult index = exprCompile(root->expr, types, literals, functions, vars);

    os << "[" << std::to_string(root->index) << " x i32]*";

    ref = "[" + std::to_string(root->index) + " x i32]* ";

    CodegenResult r1;
    r1.place = root->identifier;

    os << " %" << r1.place;

    r1.code = os.str();

    types.emplace(r1.place, ref);

    return r1;
}
#line 2695 "MiniJavaAst.cpp"

static CodegenResult exprCompile_21__(Block *root, type_table_t & types, literal_table_t & literals, function_table_t & functions, symbol_table_t & vars)
#line 916 "/home/josuedejesus/ProyectoCompiladores2/MiniJavaAst.tc"
{
    std::ostringstream os;

    CodegenResult r1 = exprCompile(root->statement_list, types, literals, functions, vars);

    os << r1.code;

    return {os.str(), ""};
}
#line 2708 "MiniJavaAst.cpp"

static CodegenResult exprCompile_22__(VariableDeclaration *root, type_table_t & types, literal_table_t & literals, function_table_t & functions, symbol_table_t & vars)
#line 926 "/home/josuedejesus/ProyectoCompiladores2/MiniJavaAst.tc"
{
    std::ostringstream os;

    CodegenResult r = exprCompile(root->identifier_list, types, literals, functions, vars);

    os << r.code;

    return {os.str(), ""};
}
#line 2721 "MiniJavaAst.cpp"

static CodegenResult exprCompile_23__(ArrayDeclaration *root, type_table_t & types, literal_table_t & literals, function_table_t & functions, symbol_table_t & vars)
#line 936 "/home/josuedejesus/ProyectoCompiladores2/MiniJavaAst.tc"
{
    std::ostringstream os;

    CodegenResult r;

    r.place = root->identifier;

    if (root->is_global) {
        os << "@" << r.place << " = global [" << root->size << " x i32] zeroinitializer, align 4";
        types.emplace(r.place, "@");
    } else {
        os << "%" << r.place << " = alloca [" << root->size << " x i32], align 4";
        types.emplace(r.place, "[" + std::to_string(root->size) + " x i32]* ");
    }

    return {os.str(), ""};
}
#line 2742 "MiniJavaAst.cpp"

static CodegenResult exprCompile_24__(Assignment *root, type_table_t & types, literal_table_t & literals, function_table_t & functions, symbol_table_t & vars)
#line 956 "/home/josuedejesus/ProyectoCompiladores2/MiniJavaAst.tc"
{
    std::ostringstream os;

    CodegenResult r1 = exprCompile(root->expr, types, literals, functions, vars);

    os << r1.code;

    auto it = types.find(root->identifier);
    auto v = vars.find(root->identifier);

    if (v == vars.end()) {
        throw std::runtime_error("Error: Unknown identifier '" + root->identifier + "'");
    }

    if (it != types.end()) {
        if (it->second == "*") {
            os << "store i32 " << r1.place << ", i32* %" << root->identifier << ", align 4\n";
        } else {
            CodegenResult param;
            param.place = newVariable();
            os << param.place  << " = alloca i32, align 4";
        }
        
    } else {
        os << "store i32 " << r1.place << ", i32* %" << root->identifier << ", align 4";
    }


    return {os.str(), ""};
}
#line 2776 "MiniJavaAst.cpp"

static CodegenResult exprCompile_25__(ArrayAssignment *root, type_table_t & types, literal_table_t & literals, function_table_t & functions, symbol_table_t & vars)
#line 987 "/home/josuedejesus/ProyectoCompiladores2/MiniJavaAst.tc"
{
    std::ostringstream os;

    CodegenResult r1 = exprCompile(root->index_expr, types, literals, functions, vars);

    os << r1.code;

    CodegenResult r2;
    r2.place = newVariable();

    auto it = types.find(root->array_identifier);

    if (it == types.end()) {
        throw std::runtime_error("Error: Unknown identifier '" + root->array_identifier + "'");
    }

    if (it->second == "@") {
        os << r2.place << " = getelementptr i32, i32* @" << root->array_identifier << ", i32 " << r1.place << "\n";
    } else {
        os << r2.place << " = getelementptr i32, i32* %" << root->array_identifier << ", i32 " << r1.place << "\n";
    }

    CodegenResult r3 = exprCompile(root->expr, types, literals, functions, vars);

    os << r3.code;

    os << "store i32 " << r3.place << ", i32* " << r2.place << "\n"; 

    return {os.str(), ""};
}
#line 2810 "MiniJavaAst.cpp"

static CodegenResult exprCompile_26__(MethodCall *root, type_table_t & types, literal_table_t & literals, function_table_t & functions, symbol_table_t & vars)
#line 1018 "/home/josuedejesus/ProyectoCompiladores2/MiniJavaAst.tc"
{
    std::ostringstream os;

    auto method = functions.find(root->identifier);

    if (method == functions.end()) {
        throw std::runtime_error("Error: Method '" + root->identifier + "' was not declared.");
    }

    MethodDeclaration* methNode =  static_cast<MethodDeclaration*>(method->second);
    current_method = methNode->parameter_list;

    ParameterList* params = static_cast<ParameterList*>(methNode->parameter_list);

    int params_count = 0;

    while (params) {
        params_count++;
        params = static_cast<ParameterList*>(params->next_node);
    }

    ArgumentList* args = static_cast<ArgumentList*>(root->argument_list);
    int args_count = 0;
    while (args) {
        args_count++;
        args = static_cast<ArgumentList*>(args->next_node);
    }

    if (params_count != args_count) {
        throw std::runtime_error("Error: Function expected '" + std::to_string(params_count) + "' arguments but received '" + std::to_string(args_count) + "'.");
    }

    
    CodegenResult r1;

    if (root->argument_list) {
        r1 = exprCompile(root->argument_list, types, literals, functions, vars);

        os << r1.code;
    }
    

    os << "call void @" << root->identifier << "(";

    if (root->argument_list) {
        os << r1.place;
    }

    os << ")\n";

    return {os.str(), ""};
}
#line 2866 "MiniJavaAst.cpp"

static CodegenResult exprCompile_27__(IfStmt *root, type_table_t & types, literal_table_t & literals, function_table_t & functions, symbol_table_t & vars)
#line 1128 "/home/josuedejesus/ProyectoCompiladores2/MiniJavaAst.tc"
{
    std::ostringstream os;

    CodegenResult res;

    CodegenResult r1 = exprCompile(root->expr, types, literals, functions, vars);

    os << r1.code << "\n";

    CodegenResult if_stmt;
    if_stmt.place = newLabel();

    CodegenResult endif;
    endif.place = newLabel();

    CodegenResult else_stmt;
    else_stmt.place = newLabel();

    if (root->else_stmts) {
        os << "br i1 " << r1.place << ", label %" << if_stmt.place << ", label %" << else_stmt.place << "\n";

    } else {
        os << "br i1 " << r1.place << ", label %" << if_stmt.place << ", label %" << endif.place << "\n";
    }

    os << if_stmt.place << ":\n";

    CodegenResult r2 = exprCompile(root->if_stmts, types, literals, functions, vars);
    os << r2.code << "\n";
    res.place = r2.place;

    bool if_has_return = r2.code.find("ret i32") != std::string::npos;

    if (!if_has_return) {
        os << "br label %" << endif.place << "\n";
    }


    if(root->else_stmts) {
        os << else_stmt.place << ":\n";

        CodegenResult r3 = exprCompile(root->else_stmts, types, literals, functions, vars);

        os << r3.code << "\n";
        res.place = r3.place;

        os << "br label %" << endif.place << "\n";
    } else {
        os << "br label %" << endif.place << "\n";
    }

    os << endif.place << ":\n";

    has_return = false;

    endif.code = os.str();

    return endif;

}
#line 2930 "MiniJavaAst.cpp"

static CodegenResult exprCompile_28__(WhileStmt *root, type_table_t & types, literal_table_t & literals, function_table_t & functions, symbol_table_t & vars)
#line 1190 "/home/josuedejesus/ProyectoCompiladores2/MiniJavaAst.tc"
{
    std::ostringstream os;

    CodegenResult loop;
    loop.place = newLabel();

    CodegenResult loop_body;
    loop_body.place = newLabel();

    CodegenResult end_loop;
    end_loop.place = newLabel();

    os << "br label %" << loop.place << "\n";
    
    os << loop.place << ":\n";

    CodegenResult r1 = exprCompile(root->expr, types, literals, functions, vars);

    os << r1.code << "\n";
    os << "br i1 " << r1.place << ", label %" << loop_body.place << ", label %" << end_loop.place << "\n";

    os << loop_body.place << ":\n";

    CodegenResult r2 = exprCompile(root->stmts, types, literals, functions, vars);

    os << r2.code << "\n";

    CodegenResult inc;

    os << "br label %" << loop.place << "\n";

    os << end_loop.place << ":\n";

    end_loop.code = os.str();

    return end_loop;
}
#line 2971 "MiniJavaAst.cpp"

static CodegenResult exprCompile_29__(PrintStmt *root, type_table_t & types, literal_table_t & literals, function_table_t & functions, symbol_table_t & vars)
#line 1228 "/home/josuedejesus/ProyectoCompiladores2/MiniJavaAst.tc"
{
    std::ostringstream os;

    CodegenResult r = exprCompile(root->expr, types, literals, functions, vars);

    os << r.code;

    os << "call i32 (i8*, ...) @printf(i8* @.fmt, i32 " << r.place << ")\n";

    return {os.str(), ""};
}
#line 2986 "MiniJavaAst.cpp"

static CodegenResult exprCompile_30__(PrintStmtLit *root, type_table_t & types, literal_table_t & literals, function_table_t & functions, symbol_table_t & vars)
#line 1240 "/home/josuedejesus/ProyectoCompiladores2/MiniJavaAst.tc"
{
    std::ostringstream os;

    std::string text = root->literal;

    if (text.front() == '"' && text.back() == '"') {
        text = text.substr(1, text.length() - 2);
    }

    auto it = literals.find(text);

    if (it != literals.end()){
        os << "call i32 (i8*, ...) @printf(i8* " << it->second << ")";
    } else {
        std::string tag = newTag();
        literals.insert({text, tag});
        os << "call i32 (i8*, ...) @printf(i8* " << tag << ")";
    }

    return { os.str(), "" };
}
#line 3011 "MiniJavaAst.cpp"

static CodegenResult exprCompile_31__(ReturnStmt *root, type_table_t & types, literal_table_t & literals, function_table_t & functions, symbol_table_t & vars)
#line 1262 "/home/josuedejesus/ProyectoCompiladores2/MiniJavaAst.tc"
{
    std::ostringstream os;

    CodegenResult r1 = exprCompile(root->expr, types, literals, functions, vars);

    os << r1.code << "\n";

    os << "ret i32 " << r1.place << "\n";

    has_return = true;

    r1.code = os.str();

    return r1;
}
#line 3030 "MiniJavaAst.cpp"

static CodegenResult exprCompile_32__(StringLiteral *root, type_table_t & types, literal_table_t & literals, function_table_t & functions, symbol_table_t & vars)
#line 1279 "/home/josuedejesus/ProyectoCompiladores2/MiniJavaAst.tc"
{
    std::ostringstream os;

    os << "StringLiteral(" << root->value << ")";

    return {os.str(), ""};
}
#line 3041 "MiniJavaAst.cpp"

static CodegenResult exprCompile_33__(AndExpr *root, type_table_t & types, literal_table_t & literals, function_table_t & functions, symbol_table_t & vars)
#line 1518 "/home/josuedejesus/ProyectoCompiladores2/MiniJavaAst.tc"
{
    std::ostringstream os;

    CodegenResult r1 = exprCompile(root->left, types, literals, functions, vars);
    os << r1.code << "\n";

    CodegenResult r2 = exprCompile(root->right, types, literals, functions, vars);
    os << r2.code << "\n";

    CodegenResult r3;
    CodegenResult r4;

    r3.place = newVariable();
    r4.place = newVariable();


    //os << r3.place << " = icmp ne i32 " << r1.place << ", 0\n";
    //os << r4.place << " = icmp ne i32 " << r2.place << ", 0\n";

    CodegenResult r5;
    r5.place = newVariable();

    os << r5.place << " = and i1 " << r1.place << ", " << r2.place << "\n";

    CodegenResult r6;
    r6.place = r5.place;
    r6.code = os.str();

    return r6; 
}
#line 3075 "MiniJavaAst.cpp"

static CodegenResult exprCompile_34__(OrExpr *root, type_table_t & types, literal_table_t & literals, function_table_t & functions, symbol_table_t & vars)
#line 1549 "/home/josuedejesus/ProyectoCompiladores2/MiniJavaAst.tc"
{
    std::ostringstream os;

    CodegenResult r1 = exprCompile(root->left, types, literals, functions, vars);
    os << r1.code << "\n";
    CodegenResult r2 = exprCompile(root->right, types, literals, functions, vars);
    os << r2.code << "\n";

    CodegenResult r3;
    CodegenResult r4;

    r3.place = newVariable();
    r4.place = newVariable();

    //os << r3.place << " = icmp ne i32 " << r1.place << ", 0\n";
    //os << r4.place << " = icmp ne i32 " << r2.place << ", 0\n";

    CodegenResult r5;
    r5.place = newVariable();

    os << r5.place << " = or i1 " << r1.place << ", " << r2.place << "\n";

    CodegenResult r6;
    r6.place = r5.place;
    r6.code = os.str();

    return r6; 
}
#line 3107 "MiniJavaAst.cpp"

static CodegenResult exprCompile_35__(GreaterExpr *root, type_table_t & types, literal_table_t & literals, function_table_t & functions, symbol_table_t & vars)
#line 1392 "/home/josuedejesus/ProyectoCompiladores2/MiniJavaAst.tc"
{
    std::ostringstream os;

    CodegenResult r1 = exprCompile(root->left, types, literals, functions, vars);
    os << r1.code << "\n";

    CodegenResult r2 = exprCompile(root->right, types, literals, functions, vars);
    os << r2.code << "\n";

    CodegenResult r3;
    r3.place = newVariable();

    os << r3.place << " = icmp sgt i32 " << r1.place << ", " << r2.place << "\n";

    CodegenResult r4;
    r4.place = r3.place;
    r4.code = os.str();

    return r4; 
}
#line 3131 "MiniJavaAst.cpp"

static CodegenResult exprCompile_36__(GreaterEqualExpr *root, type_table_t & types, literal_table_t & literals, function_table_t & functions, symbol_table_t & vars)
#line 1413 "/home/josuedejesus/ProyectoCompiladores2/MiniJavaAst.tc"
{
    std::ostringstream os;

    CodegenResult r1 = exprCompile(root->left, types, literals, functions, vars);
    os << r1.code << "\n";

    CodegenResult r2 = exprCompile(root->right, types, literals, functions, vars);
    os << r2.code << "\n";

    CodegenResult r3;
    r3.place = newVariable();

    os << r3.place << " = icmp sge i32 " << r1.place << ", " << r2.place << "\n";

    CodegenResult r4;
    r4.place = r3.place;
    r4.code = os.str();

    return r4; 
}
#line 3155 "MiniJavaAst.cpp"

static CodegenResult exprCompile_37__(LessExpr *root, type_table_t & types, literal_table_t & literals, function_table_t & functions, symbol_table_t & vars)
#line 1434 "/home/josuedejesus/ProyectoCompiladores2/MiniJavaAst.tc"
{
    std::ostringstream os;

    CodegenResult r1 = exprCompile(root->left, types, literals, functions, vars);
    os << r1.code << "\n";

    CodegenResult r2 = exprCompile(root->right, types, literals, functions, vars);
    os << r2.code << "\n";

    CodegenResult r3;
    r3.place = newVariable();

    os << r3.place << " = icmp slt i32 " << r1.place << ", " << r2.place << "\n";

    CodegenResult r4;
    r4.place = r3.place;
    r4.code = os.str();

    return r4; 
}
#line 3179 "MiniJavaAst.cpp"

static CodegenResult exprCompile_38__(LessEqualExpr *root, type_table_t & types, literal_table_t & literals, function_table_t & functions, symbol_table_t & vars)
#line 1455 "/home/josuedejesus/ProyectoCompiladores2/MiniJavaAst.tc"
{
    std::ostringstream os;

    CodegenResult r1 = exprCompile(root->left, types, literals, functions, vars);
    os << r1.code << "\n";

    CodegenResult r2 = exprCompile(root->right, types, literals, functions, vars);
    os << r2.code << "\n";

    CodegenResult r3;
    r3.place = newVariable();

    os << r3.place << " = icmp sle i32 " << r1.place << ", " << r2.place << "\n";

    CodegenResult r4;
    r4.place = r3.place;
    r4.code = os.str();

    return r4; 
}
#line 3203 "MiniJavaAst.cpp"

static CodegenResult exprCompile_39__(EqualExpr *root, type_table_t & types, literal_table_t & literals, function_table_t & functions, symbol_table_t & vars)
#line 1476 "/home/josuedejesus/ProyectoCompiladores2/MiniJavaAst.tc"
{
    std::ostringstream os;

    CodegenResult r1 = exprCompile(root->left, types, literals, functions, vars);
    os << r1.code << "\n";

    CodegenResult r2 = exprCompile(root->right, types, literals, functions, vars);
    os << r2.code << "\n";

    CodegenResult r3;
    r3.place = newVariable();

    os << r3.place << " = icmp eq i32 " << r1.place << ", " << r2.place << "\n";

    CodegenResult r4;
    r4.place = r3.place;
    r4.code = os.str();

    return r4; 
}
#line 3227 "MiniJavaAst.cpp"

static CodegenResult exprCompile_40__(NotEqualExpr *root, type_table_t & types, literal_table_t & literals, function_table_t & functions, symbol_table_t & vars)
#line 1497 "/home/josuedejesus/ProyectoCompiladores2/MiniJavaAst.tc"
{
    std::ostringstream os;

    CodegenResult r1 = exprCompile(root->left, types, literals, functions, vars);
    os << r1.code << "\n";

    CodegenResult r2 = exprCompile(root->right, types, literals, functions, vars);
    os << r2.code << "\n";

    CodegenResult r3;
    r3.place = newVariable();

    os << r3.place << " = icmp ne i32 " << r1.place << ", " << r2.place << "\n";

    CodegenResult r4;
    r4.place = r3.place;
    r4.code = os.str();

    return r4; 
}
#line 3251 "MiniJavaAst.cpp"

CodegenResult exprCompile(Node * root__, type_table_t & types, literal_table_t & literals, function_table_t & functions, symbol_table_t & vars)
{
	switch(root__->getKind())
	{
		case NodeList_kind:
		{
			return exprCompile_1__((NodeList *)root__, types, literals, functions, vars);
		}
		break;

		case ParameterList_kind:
		{
			return exprCompile_2__((ParameterList *)root__, types, literals, functions, vars);
		}
		break;

		case ArgumentList_kind:
		{
			return exprCompile_3__((ArgumentList *)root__, types, literals, functions, vars);
		}
		break;

		case Number_kind:
		{
			return exprCompile_4__((Number *)root__, types, literals, functions, vars);
		}
		break;

		case Identifier_kind:
		{
			return exprCompile_5__((Identifier *)root__, types, literals, functions, vars);
		}
		break;

		case ArrayVariable_kind:
		{
			return exprCompile_6__((ArrayVariable *)root__, types, literals, functions, vars);
		}
		break;

		case FunctionCall_kind:
		{
			return exprCompile_7__((FunctionCall *)root__, types, literals, functions, vars);
		}
		break;

		case Argument_kind:
		{
			return exprCompile_8__((Argument *)root__, types, literals, functions, vars);
		}
		break;

		case ArrayArgument_kind:
		{
			return exprCompile_9__((ArrayArgument *)root__, types, literals, functions, vars);
		}
		break;

		case AddExpr_kind:
		{
			return exprCompile_10__((AddExpr *)root__, types, literals, functions, vars);
		}
		break;

		case SubExpr_kind:
		{
			return exprCompile_11__((SubExpr *)root__, types, literals, functions, vars);
		}
		break;

		case MulExpr_kind:
		{
			return exprCompile_12__((MulExpr *)root__, types, literals, functions, vars);
		}
		break;

		case DivExpr_kind:
		{
			return exprCompile_13__((DivExpr *)root__, types, literals, functions, vars);
		}
		break;

		case ModExpr_kind:
		{
			return exprCompile_14__((ModExpr *)root__, types, literals, functions, vars);
		}
		break;

		case VariableList_kind:
		{
			return exprCompile_15__((VariableList *)root__, types, literals, functions, vars);
		}
		break;

		case Program_kind:
		{
			return exprCompile_16__((Program *)root__, types, literals, functions, vars);
		}
		break;

		case Type_kind:
		{
			return exprCompile_17__((Type *)root__, types, literals, functions, vars);
		}
		break;

		case MethodDeclaration_kind:
		{
			return exprCompile_18__((MethodDeclaration *)root__, types, literals, functions, vars);
		}
		break;

		case Parameter_kind:
		{
			return exprCompile_19__((Parameter *)root__, types, literals, functions, vars);
		}
		break;

		case ArrayParameter_kind:
		{
			return exprCompile_20__((ArrayParameter *)root__, types, literals, functions, vars);
		}
		break;

		case Block_kind:
		{
			return exprCompile_21__((Block *)root__, types, literals, functions, vars);
		}
		break;

		case VariableDeclaration_kind:
		{
			return exprCompile_22__((VariableDeclaration *)root__, types, literals, functions, vars);
		}
		break;

		case ArrayDeclaration_kind:
		{
			return exprCompile_23__((ArrayDeclaration *)root__, types, literals, functions, vars);
		}
		break;

		case Assignment_kind:
		{
			return exprCompile_24__((Assignment *)root__, types, literals, functions, vars);
		}
		break;

		case ArrayAssignment_kind:
		{
			return exprCompile_25__((ArrayAssignment *)root__, types, literals, functions, vars);
		}
		break;

		case MethodCall_kind:
		{
			return exprCompile_26__((MethodCall *)root__, types, literals, functions, vars);
		}
		break;

		case IfStmt_kind:
		{
			return exprCompile_27__((IfStmt *)root__, types, literals, functions, vars);
		}
		break;

		case WhileStmt_kind:
		{
			return exprCompile_28__((WhileStmt *)root__, types, literals, functions, vars);
		}
		break;

		case PrintStmt_kind:
		{
			return exprCompile_29__((PrintStmt *)root__, types, literals, functions, vars);
		}
		break;

		case PrintStmtLit_kind:
		{
			return exprCompile_30__((PrintStmtLit *)root__, types, literals, functions, vars);
		}
		break;

		case ReturnStmt_kind:
		{
			return exprCompile_31__((ReturnStmt *)root__, types, literals, functions, vars);
		}
		break;

		case StringLiteral_kind:
		{
			return exprCompile_32__((StringLiteral *)root__, types, literals, functions, vars);
		}
		break;

		case AndExpr_kind:
		{
			return exprCompile_33__((AndExpr *)root__, types, literals, functions, vars);
		}
		break;

		case OrExpr_kind:
		{
			return exprCompile_34__((OrExpr *)root__, types, literals, functions, vars);
		}
		break;

		case GreaterExpr_kind:
		{
			return exprCompile_35__((GreaterExpr *)root__, types, literals, functions, vars);
		}
		break;

		case GreaterEqualExpr_kind:
		{
			return exprCompile_36__((GreaterEqualExpr *)root__, types, literals, functions, vars);
		}
		break;

		case LessExpr_kind:
		{
			return exprCompile_37__((LessExpr *)root__, types, literals, functions, vars);
		}
		break;

		case LessEqualExpr_kind:
		{
			return exprCompile_38__((LessEqualExpr *)root__, types, literals, functions, vars);
		}
		break;

		case EqualExpr_kind:
		{
			return exprCompile_39__((EqualExpr *)root__, types, literals, functions, vars);
		}
		break;

		case NotEqualExpr_kind:
		{
			return exprCompile_40__((NotEqualExpr *)root__, types, literals, functions, vars);
		}
		break;

		default: break;
	}
	return (CodegenResult({}));
}

static void getFunction_1__(MethodDeclaration *root, function_table_t & functions)
#line 247 "/home/josuedejesus/ProyectoCompiladores2/MiniJavaAst.tc"
{
    auto it = functions.find(root->name);

    if (it != functions.end()) {
        throw std::runtime_error("Function '" + root->name + "' was already declared.");
    }

    functions.emplace(root->name, root);

    //functions[root->name] = root;

}
#line 3516 "MiniJavaAst.cpp"

static void getFunction_2__(Node *root, function_table_t & functions)
#line 243 "/home/josuedejesus/ProyectoCompiladores2/MiniJavaAst.tc"
{

}
#line 3523 "MiniJavaAst.cpp"

void getFunction(Node * root__, function_table_t & functions)
{
	switch(root__->getKind())
	{
		case MethodDeclaration_kind:
		{
			getFunction_1__((MethodDeclaration *)root__, functions);
		}
		break;

		case Node_kind:
		case NodeList_kind:
		case ParameterList_kind:
		case VariableList_kind:
		case Program_kind:
		case Type_kind:
		case Parameter_kind:
		case ArrayParameter_kind:
		case Block_kind:
		case VariableDeclaration_kind:
		case ArrayDeclaration_kind:
		case Assignment_kind:
		case ArrayAssignment_kind:
		case MethodCall_kind:
		case IfStmt_kind:
		case WhileStmt_kind:
		case PrintStmt_kind:
		case PrintStmtLit_kind:
		case ReturnStmt_kind:
		case StringLiteral_kind:
		case Expr_kind:
		case ArgumentList_kind:
		case Number_kind:
		case Identifier_kind:
		case ArrayVariable_kind:
		case FunctionCall_kind:
		case Argument_kind:
		case ArrayArgument_kind:
		case BinaryExpr_kind:
		case AddExpr_kind:
		case SubExpr_kind:
		case MulExpr_kind:
		case DivExpr_kind:
		case ModExpr_kind:
		case BooleanExpr_kind:
		case BinaryBooleanExpr_kind:
		case AndExpr_kind:
		case OrExpr_kind:
		case RelationalExpr_kind:
		case BinaryRelationalExpr_kind:
		case GreaterExpr_kind:
		case GreaterEqualExpr_kind:
		case LessExpr_kind:
		case LessEqualExpr_kind:
		case EqualExpr_kind:
		case NotEqualExpr_kind:
		{
			getFunction_2__((Node *)root__, functions);
		}
		break;

		default: break;
	}
}

}
