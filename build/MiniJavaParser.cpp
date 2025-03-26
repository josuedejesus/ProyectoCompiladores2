// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.



// First part of user prologue.
#line 19 "MiniJavaParser.y"

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

#line 61 "/home/josuedejesus/ProyectoCompiladores2/build/MiniJavaParser.cpp"


#include "MiniJavaParser.hpp"




#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif



// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 9 "MiniJavaParser.y"
namespace  Expr  {
#line 140 "/home/josuedejesus/ProyectoCompiladores2/build/MiniJavaParser.cpp"

  /// Build a parser object.
   Parser:: Parser (MiniJavaLexer& lexer_yyarg, Ast::Node*& root_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      lexer (lexer_yyarg),
      root (root_yyarg)
  {}

   Parser::~ Parser ()
  {}

   Parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------.
  | symbol.  |
  `---------*/

  // basic_symbol.
  template <typename Base>
   Parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
  {
    switch (this->kind ())
    {
      case symbol_kind::S_boolean_expr: // boolean_expr
      case symbol_kind::S_boolean_term: // boolean_term
      case symbol_kind::S_boolean_factor: // boolean_factor
        value.copy< Ast::BooleanExpr * > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_array_variable: // array_variable
      case symbol_kind::S_expr: // expr
      case symbol_kind::S_term: // term
      case symbol_kind::S_factor: // factor
        value.copy< Ast::Expr * > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_class_body: // class_body
      case symbol_kind::S_class_member: // class_member
      case symbol_kind::S_method_declaration: // method_declaration
      case symbol_kind::S_variable_decl: // variable_decl
      case symbol_kind::S_variable_list: // variable_list
      case symbol_kind::S_array_decl: // array_decl
      case symbol_kind::S_method_return_type: // method_return_type
      case symbol_kind::S_type: // type
      case symbol_kind::S_opt_parameter_list: // opt_parameter_list
      case symbol_kind::S_parameter: // parameter
      case symbol_kind::S_argument_list: // argument_list
      case symbol_kind::S_argument: // argument
      case symbol_kind::S_block: // block
      case symbol_kind::S_statement_list: // statement_list
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_declaration: // declaration
      case symbol_kind::S_assign_stmt: // assign_stmt
      case symbol_kind::S_method_call: // method_call
      case symbol_kind::S_if_stmt: // if_stmt
      case symbol_kind::S_while_stmt: // while_stmt
      case symbol_kind::S_print_stmt: // print_stmt
      case symbol_kind::S_return_stmt: // return_stmt
        value.copy< Ast::Node * > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_relational_expr: // relational_expr
        value.copy< Ast::RelationalExpr * > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INT_CONST: // "number"
        value.copy< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_IDENTIFIER: // "identifier"
      case symbol_kind::S_STRING_LITERAL: // "string literal"
        value.copy< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

  }




  template <typename Base>
   Parser::symbol_kind_type
   Parser::basic_symbol<Base>::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }


  template <typename Base>
  bool
   Parser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return this->kind () == symbol_kind::S_YYEMPTY;
  }

  template <typename Base>
  void
   Parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->kind ())
    {
      case symbol_kind::S_boolean_expr: // boolean_expr
      case symbol_kind::S_boolean_term: // boolean_term
      case symbol_kind::S_boolean_factor: // boolean_factor
        value.move< Ast::BooleanExpr * > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_array_variable: // array_variable
      case symbol_kind::S_expr: // expr
      case symbol_kind::S_term: // term
      case symbol_kind::S_factor: // factor
        value.move< Ast::Expr * > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_class_body: // class_body
      case symbol_kind::S_class_member: // class_member
      case symbol_kind::S_method_declaration: // method_declaration
      case symbol_kind::S_variable_decl: // variable_decl
      case symbol_kind::S_variable_list: // variable_list
      case symbol_kind::S_array_decl: // array_decl
      case symbol_kind::S_method_return_type: // method_return_type
      case symbol_kind::S_type: // type
      case symbol_kind::S_opt_parameter_list: // opt_parameter_list
      case symbol_kind::S_parameter: // parameter
      case symbol_kind::S_argument_list: // argument_list
      case symbol_kind::S_argument: // argument
      case symbol_kind::S_block: // block
      case symbol_kind::S_statement_list: // statement_list
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_declaration: // declaration
      case symbol_kind::S_assign_stmt: // assign_stmt
      case symbol_kind::S_method_call: // method_call
      case symbol_kind::S_if_stmt: // if_stmt
      case symbol_kind::S_while_stmt: // while_stmt
      case symbol_kind::S_print_stmt: // print_stmt
      case symbol_kind::S_return_stmt: // return_stmt
        value.move< Ast::Node * > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_relational_expr: // relational_expr
        value.move< Ast::RelationalExpr * > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_INT_CONST: // "number"
        value.move< int > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_IDENTIFIER: // "identifier"
      case symbol_kind::S_STRING_LITERAL: // "string literal"
        value.move< std::string > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

  }

  // by_kind.
   Parser::by_kind::by_kind () YY_NOEXCEPT
    : kind_ (symbol_kind::S_YYEMPTY)
  {}

#if 201103L <= YY_CPLUSPLUS
   Parser::by_kind::by_kind (by_kind&& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {
    that.clear ();
  }
#endif

   Parser::by_kind::by_kind (const by_kind& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {}

   Parser::by_kind::by_kind (token_kind_type t) YY_NOEXCEPT
    : kind_ (yytranslate_ (t))
  {}



  void
   Parser::by_kind::clear () YY_NOEXCEPT
  {
    kind_ = symbol_kind::S_YYEMPTY;
  }

  void
   Parser::by_kind::move (by_kind& that)
  {
    kind_ = that.kind_;
    that.clear ();
  }

   Parser::symbol_kind_type
   Parser::by_kind::kind () const YY_NOEXCEPT
  {
    return kind_;
  }


   Parser::symbol_kind_type
   Parser::by_kind::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }



  // by_state.
   Parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

   Parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
   Parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
   Parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

   Parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

   Parser::symbol_kind_type
   Parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

   Parser::stack_symbol_type::stack_symbol_type ()
  {}

   Parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_boolean_expr: // boolean_expr
      case symbol_kind::S_boolean_term: // boolean_term
      case symbol_kind::S_boolean_factor: // boolean_factor
        value.YY_MOVE_OR_COPY< Ast::BooleanExpr * > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_array_variable: // array_variable
      case symbol_kind::S_expr: // expr
      case symbol_kind::S_term: // term
      case symbol_kind::S_factor: // factor
        value.YY_MOVE_OR_COPY< Ast::Expr * > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_class_body: // class_body
      case symbol_kind::S_class_member: // class_member
      case symbol_kind::S_method_declaration: // method_declaration
      case symbol_kind::S_variable_decl: // variable_decl
      case symbol_kind::S_variable_list: // variable_list
      case symbol_kind::S_array_decl: // array_decl
      case symbol_kind::S_method_return_type: // method_return_type
      case symbol_kind::S_type: // type
      case symbol_kind::S_opt_parameter_list: // opt_parameter_list
      case symbol_kind::S_parameter: // parameter
      case symbol_kind::S_argument_list: // argument_list
      case symbol_kind::S_argument: // argument
      case symbol_kind::S_block: // block
      case symbol_kind::S_statement_list: // statement_list
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_declaration: // declaration
      case symbol_kind::S_assign_stmt: // assign_stmt
      case symbol_kind::S_method_call: // method_call
      case symbol_kind::S_if_stmt: // if_stmt
      case symbol_kind::S_while_stmt: // while_stmt
      case symbol_kind::S_print_stmt: // print_stmt
      case symbol_kind::S_return_stmt: // return_stmt
        value.YY_MOVE_OR_COPY< Ast::Node * > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_relational_expr: // relational_expr
        value.YY_MOVE_OR_COPY< Ast::RelationalExpr * > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INT_CONST: // "number"
        value.YY_MOVE_OR_COPY< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_IDENTIFIER: // "identifier"
      case symbol_kind::S_STRING_LITERAL: // "string literal"
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

   Parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s)
  {
    switch (that.kind ())
    {
      case symbol_kind::S_boolean_expr: // boolean_expr
      case symbol_kind::S_boolean_term: // boolean_term
      case symbol_kind::S_boolean_factor: // boolean_factor
        value.move< Ast::BooleanExpr * > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_array_variable: // array_variable
      case symbol_kind::S_expr: // expr
      case symbol_kind::S_term: // term
      case symbol_kind::S_factor: // factor
        value.move< Ast::Expr * > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_class_body: // class_body
      case symbol_kind::S_class_member: // class_member
      case symbol_kind::S_method_declaration: // method_declaration
      case symbol_kind::S_variable_decl: // variable_decl
      case symbol_kind::S_variable_list: // variable_list
      case symbol_kind::S_array_decl: // array_decl
      case symbol_kind::S_method_return_type: // method_return_type
      case symbol_kind::S_type: // type
      case symbol_kind::S_opt_parameter_list: // opt_parameter_list
      case symbol_kind::S_parameter: // parameter
      case symbol_kind::S_argument_list: // argument_list
      case symbol_kind::S_argument: // argument
      case symbol_kind::S_block: // block
      case symbol_kind::S_statement_list: // statement_list
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_declaration: // declaration
      case symbol_kind::S_assign_stmt: // assign_stmt
      case symbol_kind::S_method_call: // method_call
      case symbol_kind::S_if_stmt: // if_stmt
      case symbol_kind::S_while_stmt: // while_stmt
      case symbol_kind::S_print_stmt: // print_stmt
      case symbol_kind::S_return_stmt: // return_stmt
        value.move< Ast::Node * > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_relational_expr: // relational_expr
        value.move< Ast::RelationalExpr * > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INT_CONST: // "number"
        value.move< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_IDENTIFIER: // "identifier"
      case symbol_kind::S_STRING_LITERAL: // "string literal"
        value.move< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
   Parser::stack_symbol_type&
   Parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_boolean_expr: // boolean_expr
      case symbol_kind::S_boolean_term: // boolean_term
      case symbol_kind::S_boolean_factor: // boolean_factor
        value.copy< Ast::BooleanExpr * > (that.value);
        break;

      case symbol_kind::S_array_variable: // array_variable
      case symbol_kind::S_expr: // expr
      case symbol_kind::S_term: // term
      case symbol_kind::S_factor: // factor
        value.copy< Ast::Expr * > (that.value);
        break;

      case symbol_kind::S_class_body: // class_body
      case symbol_kind::S_class_member: // class_member
      case symbol_kind::S_method_declaration: // method_declaration
      case symbol_kind::S_variable_decl: // variable_decl
      case symbol_kind::S_variable_list: // variable_list
      case symbol_kind::S_array_decl: // array_decl
      case symbol_kind::S_method_return_type: // method_return_type
      case symbol_kind::S_type: // type
      case symbol_kind::S_opt_parameter_list: // opt_parameter_list
      case symbol_kind::S_parameter: // parameter
      case symbol_kind::S_argument_list: // argument_list
      case symbol_kind::S_argument: // argument
      case symbol_kind::S_block: // block
      case symbol_kind::S_statement_list: // statement_list
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_declaration: // declaration
      case symbol_kind::S_assign_stmt: // assign_stmt
      case symbol_kind::S_method_call: // method_call
      case symbol_kind::S_if_stmt: // if_stmt
      case symbol_kind::S_while_stmt: // while_stmt
      case symbol_kind::S_print_stmt: // print_stmt
      case symbol_kind::S_return_stmt: // return_stmt
        value.copy< Ast::Node * > (that.value);
        break;

      case symbol_kind::S_relational_expr: // relational_expr
        value.copy< Ast::RelationalExpr * > (that.value);
        break;

      case symbol_kind::S_INT_CONST: // "number"
        value.copy< int > (that.value);
        break;

      case symbol_kind::S_IDENTIFIER: // "identifier"
      case symbol_kind::S_STRING_LITERAL: // "string literal"
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }

    return *this;
  }

   Parser::stack_symbol_type&
   Parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_boolean_expr: // boolean_expr
      case symbol_kind::S_boolean_term: // boolean_term
      case symbol_kind::S_boolean_factor: // boolean_factor
        value.move< Ast::BooleanExpr * > (that.value);
        break;

      case symbol_kind::S_array_variable: // array_variable
      case symbol_kind::S_expr: // expr
      case symbol_kind::S_term: // term
      case symbol_kind::S_factor: // factor
        value.move< Ast::Expr * > (that.value);
        break;

      case symbol_kind::S_class_body: // class_body
      case symbol_kind::S_class_member: // class_member
      case symbol_kind::S_method_declaration: // method_declaration
      case symbol_kind::S_variable_decl: // variable_decl
      case symbol_kind::S_variable_list: // variable_list
      case symbol_kind::S_array_decl: // array_decl
      case symbol_kind::S_method_return_type: // method_return_type
      case symbol_kind::S_type: // type
      case symbol_kind::S_opt_parameter_list: // opt_parameter_list
      case symbol_kind::S_parameter: // parameter
      case symbol_kind::S_argument_list: // argument_list
      case symbol_kind::S_argument: // argument
      case symbol_kind::S_block: // block
      case symbol_kind::S_statement_list: // statement_list
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_declaration: // declaration
      case symbol_kind::S_assign_stmt: // assign_stmt
      case symbol_kind::S_method_call: // method_call
      case symbol_kind::S_if_stmt: // if_stmt
      case symbol_kind::S_while_stmt: // while_stmt
      case symbol_kind::S_print_stmt: // print_stmt
      case symbol_kind::S_return_stmt: // return_stmt
        value.move< Ast::Node * > (that.value);
        break;

      case symbol_kind::S_relational_expr: // relational_expr
        value.move< Ast::RelationalExpr * > (that.value);
        break;

      case symbol_kind::S_INT_CONST: // "number"
        value.move< int > (that.value);
        break;

      case symbol_kind::S_IDENTIFIER: // "identifier"
      case symbol_kind::S_STRING_LITERAL: // "string literal"
        value.move< std::string > (that.value);
        break;

      default:
        break;
    }

    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
   Parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
   Parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " (";
        YY_USE (yykind);
        yyo << ')';
      }
  }
#endif

  void
   Parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
   Parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
   Parser::yypop_ (int n) YY_NOEXCEPT
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
   Parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
   Parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


   Parser::debug_level_type
   Parser::debug_level () const
  {
    return yydebug_;
  }

  void
   Parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

   Parser::state_type
   Parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
   Parser::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
   Parser::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yytable_ninf_;
  }

  int
   Parser::operator() ()
  {
    return parse ();
  }

  int
   Parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            yyla.kind_ = yytranslate_ (yylex (&yyla.value));
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case symbol_kind::S_boolean_expr: // boolean_expr
      case symbol_kind::S_boolean_term: // boolean_term
      case symbol_kind::S_boolean_factor: // boolean_factor
        yylhs.value.emplace< Ast::BooleanExpr * > ();
        break;

      case symbol_kind::S_array_variable: // array_variable
      case symbol_kind::S_expr: // expr
      case symbol_kind::S_term: // term
      case symbol_kind::S_factor: // factor
        yylhs.value.emplace< Ast::Expr * > ();
        break;

      case symbol_kind::S_class_body: // class_body
      case symbol_kind::S_class_member: // class_member
      case symbol_kind::S_method_declaration: // method_declaration
      case symbol_kind::S_variable_decl: // variable_decl
      case symbol_kind::S_variable_list: // variable_list
      case symbol_kind::S_array_decl: // array_decl
      case symbol_kind::S_method_return_type: // method_return_type
      case symbol_kind::S_type: // type
      case symbol_kind::S_opt_parameter_list: // opt_parameter_list
      case symbol_kind::S_parameter: // parameter
      case symbol_kind::S_argument_list: // argument_list
      case symbol_kind::S_argument: // argument
      case symbol_kind::S_block: // block
      case symbol_kind::S_statement_list: // statement_list
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_declaration: // declaration
      case symbol_kind::S_assign_stmt: // assign_stmt
      case symbol_kind::S_method_call: // method_call
      case symbol_kind::S_if_stmt: // if_stmt
      case symbol_kind::S_while_stmt: // while_stmt
      case symbol_kind::S_print_stmt: // print_stmt
      case symbol_kind::S_return_stmt: // return_stmt
        yylhs.value.emplace< Ast::Node * > ();
        break;

      case symbol_kind::S_relational_expr: // relational_expr
        yylhs.value.emplace< Ast::RelationalExpr * > ();
        break;

      case symbol_kind::S_INT_CONST: // "number"
        yylhs.value.emplace< int > ();
        break;

      case symbol_kind::S_IDENTIFIER: // "identifier"
      case symbol_kind::S_STRING_LITERAL: // "string literal"
        yylhs.value.emplace< std::string > ();
        break;

      default:
        break;
    }



      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2: // program: "class" "identifier" "{" class_body "}" "EOF"
#line 115 "MiniJavaParser.y"
                                                                         {
    root = new Ast::Program(yystack_[4].value.as < std::string > (), yystack_[2].value.as < Ast::Node * > ());
}
#line 975 "/home/josuedejesus/ProyectoCompiladores2/build/MiniJavaParser.cpp"
    break;

  case 3: // class_body: class_body class_member
#line 119 "MiniJavaParser.y"
                                    {
    yylhs.value.as < Ast::Node * > () = new Ast::NodeList(yystack_[1].value.as < Ast::Node * > (), yystack_[0].value.as < Ast::Node * > ());
}
#line 983 "/home/josuedejesus/ProyectoCompiladores2/build/MiniJavaParser.cpp"
    break;

  case 4: // class_body: class_member
#line 121 "MiniJavaParser.y"
                 {
    yylhs.value.as < Ast::Node * > () = new Ast::NodeList(yystack_[0].value.as < Ast::Node * > (), nullptr);
}
#line 991 "/home/josuedejesus/ProyectoCompiladores2/build/MiniJavaParser.cpp"
    break;

  case 5: // class_body: %empty
#line 123 "MiniJavaParser.y"
              {
    yylhs.value.as < Ast::Node * > () = nullptr;
}
#line 999 "/home/josuedejesus/ProyectoCompiladores2/build/MiniJavaParser.cpp"
    break;

  case 6: // class_member: method_declaration
#line 127 "MiniJavaParser.y"
                                 {
    yylhs.value.as < Ast::Node * > () = yystack_[0].value.as < Ast::Node * > ();
}
#line 1007 "/home/josuedejesus/ProyectoCompiladores2/build/MiniJavaParser.cpp"
    break;

  case 7: // class_member: array_decl
#line 129 "MiniJavaParser.y"
               {
    if (auto arrayDecl = dynamic_cast<Ast::ArrayDeclaration*>(yystack_[0].value.as < Ast::Node * > ())) {
        arrayDecl->is_global = true;
    }
    yylhs.value.as < Ast::Node * > () = yystack_[0].value.as < Ast::Node * > ();
}
#line 1018 "/home/josuedejesus/ProyectoCompiladores2/build/MiniJavaParser.cpp"
    break;

  case 8: // class_member: variable_decl
#line 134 "MiniJavaParser.y"
                  {
    yylhs.value.as < Ast::Node * > () = yystack_[0].value.as < Ast::Node * > ();
}
#line 1026 "/home/josuedejesus/ProyectoCompiladores2/build/MiniJavaParser.cpp"
    break;

  case 9: // method_declaration: method_return_type "identifier" "(" opt_parameter_list ")" "{" block "}"
#line 142 "MiniJavaParser.y"
                                                                                                                     {
    yylhs.value.as < Ast::Node * > () = new Ast::MethodDeclaration(yystack_[7].value.as < Ast::Node * > (), yystack_[6].value.as < std::string > (), yystack_[4].value.as < Ast::Node * > (), yystack_[1].value.as < Ast::Node * > ());
}
#line 1034 "/home/josuedejesus/ProyectoCompiladores2/build/MiniJavaParser.cpp"
    break;

  case 10: // method_declaration: method_return_type "identifier" "(" ")" "{" block "}"
#line 144 "MiniJavaParser.y"
                                                                                  {
    yylhs.value.as < Ast::Node * > () = new Ast::MethodDeclaration(yystack_[6].value.as < Ast::Node * > (), yystack_[5].value.as < std::string > (), nullptr, yystack_[1].value.as < Ast::Node * > ());
}
#line 1042 "/home/josuedejesus/ProyectoCompiladores2/build/MiniJavaParser.cpp"
    break;

  case 11: // variable_decl: type variable_list ";"
#line 148 "MiniJavaParser.y"
                                            {
    yylhs.value.as < Ast::Node * > () = new Ast::VariableDeclaration(yystack_[1].value.as < Ast::Node * > ());
}
#line 1050 "/home/josuedejesus/ProyectoCompiladores2/build/MiniJavaParser.cpp"
    break;

  case 12: // variable_list: "identifier"
#line 152 "MiniJavaParser.y"
                          {
    yylhs.value.as < Ast::Node * > () = new Ast::VariableList(false, yystack_[0].value.as < std::string > (), nullptr);
}
#line 1058 "/home/josuedejesus/ProyectoCompiladores2/build/MiniJavaParser.cpp"
    break;

  case 13: // variable_list: "identifier" "," variable_list
#line 154 "MiniJavaParser.y"
                                   {
    yylhs.value.as < Ast::Node * > () = new Ast::VariableList(false, yystack_[2].value.as < std::string > (), yystack_[0].value.as < Ast::Node * > ());
}
#line 1066 "/home/josuedejesus/ProyectoCompiladores2/build/MiniJavaParser.cpp"
    break;

  case 14: // array_decl: "int" "[" "number" "]" "identifier" ";"
#line 158 "MiniJavaParser.y"
                                                                             {
    yylhs.value.as < Ast::Node * > () = new Ast::ArrayDeclaration(false, yystack_[1].value.as < std::string > (), yystack_[3].value.as < int > ());
}
#line 1074 "/home/josuedejesus/ProyectoCompiladores2/build/MiniJavaParser.cpp"
    break;

  case 15: // array_variable: "identifier" "[" expr "]"
#line 162 "MiniJavaParser.y"
                                                           {
    yylhs.value.as < Ast::Expr * > () = new Ast::ArrayVariable(yystack_[3].value.as < std::string > (), yystack_[1].value.as < Ast::Expr * > ());
}
#line 1082 "/home/josuedejesus/ProyectoCompiladores2/build/MiniJavaParser.cpp"
    break;

  case 16: // method_return_type: "void"
#line 166 "MiniJavaParser.y"
                            {
    yylhs.value.as < Ast::Node * > () = new Ast::Type("void");
}
#line 1090 "/home/josuedejesus/ProyectoCompiladores2/build/MiniJavaParser.cpp"
    break;

  case 17: // method_return_type: "int"
#line 168 "MiniJavaParser.y"
           {
    yylhs.value.as < Ast::Node * > () = new Ast::Type("int");
}
#line 1098 "/home/josuedejesus/ProyectoCompiladores2/build/MiniJavaParser.cpp"
    break;

  case 19: // opt_parameter_list: parameter
#line 174 "MiniJavaParser.y"
                              {
    yylhs.value.as < Ast::Node * > () = new Ast::ParameterList(yystack_[0].value.as < Ast::Node * > (), nullptr);
}
#line 1106 "/home/josuedejesus/ProyectoCompiladores2/build/MiniJavaParser.cpp"
    break;

  case 20: // opt_parameter_list: parameter "," opt_parameter_list
#line 176 "MiniJavaParser.y"
                                       {
    yylhs.value.as < Ast::Node * > () = new Ast::ParameterList(yystack_[2].value.as < Ast::Node * > (), yystack_[0].value.as < Ast::Node * > ());
}
#line 1114 "/home/josuedejesus/ProyectoCompiladores2/build/MiniJavaParser.cpp"
    break;

  case 21: // parameter: "int" "identifier"
#line 180 "MiniJavaParser.y"
                             {
    yylhs.value.as < Ast::Node * > () = new Ast::Parameter(false, yystack_[0].value.as < std::string > ());
}
#line 1122 "/home/josuedejesus/ProyectoCompiladores2/build/MiniJavaParser.cpp"
    break;

  case 22: // parameter: "ref" "int" "identifier"
#line 182 "MiniJavaParser.y"
                             {
    yylhs.value.as < Ast::Node * > () = new Ast::Parameter(true, yystack_[0].value.as < std::string > ());
}
#line 1130 "/home/josuedejesus/ProyectoCompiladores2/build/MiniJavaParser.cpp"
    break;

  case 23: // parameter: "int" "[" "number" "]" "identifier"
#line 184 "MiniJavaParser.y"
                                                           {
    yylhs.value.as < Ast::Node * > () = new Ast::ArrayParameter(false, yystack_[2].value.as < int > (), yystack_[0].value.as < std::string > ());
}
#line 1138 "/home/josuedejesus/ProyectoCompiladores2/build/MiniJavaParser.cpp"
    break;

  case 24: // argument_list: argument
#line 188 "MiniJavaParser.y"
                        {
    yylhs.value.as < Ast::Node * > () = new Ast::ArgumentList(yystack_[0].value.as < Ast::Node * > (), nullptr);
}
#line 1146 "/home/josuedejesus/ProyectoCompiladores2/build/MiniJavaParser.cpp"
    break;

  case 25: // argument_list: argument "," argument_list
#line 190 "MiniJavaParser.y"
                                 {
    yylhs.value.as < Ast::Node * > () = new Ast::ArgumentList(yystack_[2].value.as < Ast::Node * > (), yystack_[0].value.as < Ast::Node * > ());
}
#line 1154 "/home/josuedejesus/ProyectoCompiladores2/build/MiniJavaParser.cpp"
    break;

  case 26: // argument: expr
#line 194 "MiniJavaParser.y"
               {
    yylhs.value.as < Ast::Node * > () = new Ast::Argument(false, "", yystack_[0].value.as < Ast::Expr * > ());
}
#line 1162 "/home/josuedejesus/ProyectoCompiladores2/build/MiniJavaParser.cpp"
    break;

  case 27: // argument: "ref" "identifier"
#line 196 "MiniJavaParser.y"
                      {
    yylhs.value.as < Ast::Node * > () = new Ast::Argument(true, yystack_[0].value.as < std::string > (), nullptr);
}
#line 1170 "/home/josuedejesus/ProyectoCompiladores2/build/MiniJavaParser.cpp"
    break;

  case 28: // block: statement_list
#line 201 "MiniJavaParser.y"
                      { 
    yylhs.value.as < Ast::Node * > () = yystack_[0].value.as < Ast::Node * > (); 
}
#line 1178 "/home/josuedejesus/ProyectoCompiladores2/build/MiniJavaParser.cpp"
    break;

  case 29: // block: %empty
#line 203 "MiniJavaParser.y"
              {
    yylhs.value.as < Ast::Node * > () = nullptr; 
}
#line 1186 "/home/josuedejesus/ProyectoCompiladores2/build/MiniJavaParser.cpp"
    break;

  case 30: // statement_list: statement
#line 207 "MiniJavaParser.y"
                          {
    yylhs.value.as < Ast::Node * > () = new Ast::NodeList(yystack_[0].value.as < Ast::Node * > (), nullptr);
}
#line 1194 "/home/josuedejesus/ProyectoCompiladores2/build/MiniJavaParser.cpp"
    break;

  case 31: // statement_list: statement_list statement
#line 209 "MiniJavaParser.y"
                             {
    yylhs.value.as < Ast::Node * > () = new Ast::NodeList(yystack_[1].value.as < Ast::Node * > (), yystack_[0].value.as < Ast::Node * > ());
}
#line 1202 "/home/josuedejesus/ProyectoCompiladores2/build/MiniJavaParser.cpp"
    break;

  case 32: // statement: declaration
#line 213 "MiniJavaParser.y"
                       {
    yylhs.value.as < Ast::Node * > () = yystack_[0].value.as < Ast::Node * > ();
}
#line 1210 "/home/josuedejesus/ProyectoCompiladores2/build/MiniJavaParser.cpp"
    break;

  case 33: // statement: method_call
#line 215 "MiniJavaParser.y"
                {
    yylhs.value.as < Ast::Node * > () = yystack_[0].value.as < Ast::Node * > ();
}
#line 1218 "/home/josuedejesus/ProyectoCompiladores2/build/MiniJavaParser.cpp"
    break;

  case 34: // statement: assign_stmt
#line 217 "MiniJavaParser.y"
                {
    yylhs.value.as < Ast::Node * > () = yystack_[0].value.as < Ast::Node * > ();
}
#line 1226 "/home/josuedejesus/ProyectoCompiladores2/build/MiniJavaParser.cpp"
    break;

  case 35: // statement: if_stmt
#line 219 "MiniJavaParser.y"
            {
    yylhs.value.as < Ast::Node * > () = yystack_[0].value.as < Ast::Node * > ();
}
#line 1234 "/home/josuedejesus/ProyectoCompiladores2/build/MiniJavaParser.cpp"
    break;

  case 36: // statement: while_stmt
#line 221 "MiniJavaParser.y"
               {
    yylhs.value.as < Ast::Node * > () = yystack_[0].value.as < Ast::Node * > ();
}
#line 1242 "/home/josuedejesus/ProyectoCompiladores2/build/MiniJavaParser.cpp"
    break;

  case 37: // statement: print_stmt
#line 223 "MiniJavaParser.y"
               {
    yylhs.value.as < Ast::Node * > () = yystack_[0].value.as < Ast::Node * > ();
}
#line 1250 "/home/josuedejesus/ProyectoCompiladores2/build/MiniJavaParser.cpp"
    break;

  case 38: // statement: return_stmt
#line 225 "MiniJavaParser.y"
                {
    yylhs.value.as < Ast::Node * > () = yystack_[0].value.as < Ast::Node * > ();
}
#line 1258 "/home/josuedejesus/ProyectoCompiladores2/build/MiniJavaParser.cpp"
    break;

  case 39: // declaration: array_decl
#line 230 "MiniJavaParser.y"
             { yylhs.value.as < Ast::Node * > () = yystack_[0].value.as < Ast::Node * > (); }
#line 1264 "/home/josuedejesus/ProyectoCompiladores2/build/MiniJavaParser.cpp"
    break;

  case 40: // declaration: variable_decl
#line 230 "MiniJavaParser.y"
                          { yylhs.value.as < Ast::Node * > () = yystack_[0].value.as < Ast::Node * > (); }
#line 1270 "/home/josuedejesus/ProyectoCompiladores2/build/MiniJavaParser.cpp"
    break;

  case 41: // assign_stmt: "identifier" "=" expr ";"
#line 232 "MiniJavaParser.y"
                                                 {
    yylhs.value.as < Ast::Node * > () = new Ast::Assignment(yystack_[3].value.as < std::string > (), yystack_[1].value.as < Ast::Expr * > ());
}
#line 1278 "/home/josuedejesus/ProyectoCompiladores2/build/MiniJavaParser.cpp"
    break;

  case 42: // assign_stmt: "identifier" "[" expr "]" "=" expr ";"
#line 234 "MiniJavaParser.y"
                                                                        {
    yylhs.value.as < Ast::Node * > () = new Ast::ArrayAssignment(yystack_[6].value.as < std::string > (), yystack_[4].value.as < Ast::Expr * > (), yystack_[1].value.as < Ast::Expr * > ());
}
#line 1286 "/home/josuedejesus/ProyectoCompiladores2/build/MiniJavaParser.cpp"
    break;

  case 43: // method_call: "identifier" "(" argument_list ")" ";"
#line 240 "MiniJavaParser.y"
                                                                   {
    yylhs.value.as < Ast::Node * > () = new Ast::MethodCall(yystack_[4].value.as < std::string > (), yystack_[2].value.as < Ast::Node * > ());
}
#line 1294 "/home/josuedejesus/ProyectoCompiladores2/build/MiniJavaParser.cpp"
    break;

  case 44: // method_call: "identifier" "(" ")" ";"
#line 242 "MiniJavaParser.y"
                                            {
    yylhs.value.as < Ast::Node * > () = new Ast::MethodCall(yystack_[3].value.as < std::string > (), nullptr);
}
#line 1302 "/home/josuedejesus/ProyectoCompiladores2/build/MiniJavaParser.cpp"
    break;

  case 45: // if_stmt: "if" "(" boolean_expr ")" "{" block "}"
#line 246 "MiniJavaParser.y"
                                                                            {
    yylhs.value.as < Ast::Node * > () = new Ast::IfStmt(yystack_[4].value.as < Ast::BooleanExpr * > (), yystack_[1].value.as < Ast::Node * > (), nullptr);
}
#line 1310 "/home/josuedejesus/ProyectoCompiladores2/build/MiniJavaParser.cpp"
    break;

  case 46: // if_stmt: "if" "(" boolean_expr ")" "{" block "}" "else" "{" statement "}"
#line 248 "MiniJavaParser.y"
                                                                                                                {
    yylhs.value.as < Ast::Node * > () = new Ast::IfStmt(yystack_[8].value.as < Ast::BooleanExpr * > (), yystack_[5].value.as < Ast::Node * > (), yystack_[1].value.as < Ast::Node * > ());
}
#line 1318 "/home/josuedejesus/ProyectoCompiladores2/build/MiniJavaParser.cpp"
    break;

  case 47: // while_stmt: "while" "(" boolean_expr ")" "{" block "}"
#line 252 "MiniJavaParser.y"
                                                                                  {
    yylhs.value.as < Ast::Node * > () = new Ast::WhileStmt(yystack_[4].value.as < Ast::BooleanExpr * > (), yystack_[1].value.as < Ast::Node * > ());
}
#line 1326 "/home/josuedejesus/ProyectoCompiladores2/build/MiniJavaParser.cpp"
    break;

  case 48: // print_stmt: "print" "(" "string literal" ")" ";"
#line 256 "MiniJavaParser.y"
                                                                 {
    yylhs.value.as < Ast::Node * > () = new Ast::PrintStmtLit(yystack_[2].value.as < std::string > ());
}
#line 1334 "/home/josuedejesus/ProyectoCompiladores2/build/MiniJavaParser.cpp"
    break;

  case 49: // print_stmt: "print" "(" expr ")" ";"
#line 258 "MiniJavaParser.y"
                                               {
    yylhs.value.as < Ast::Node * > () = new Ast::PrintStmt(yystack_[2].value.as < Ast::Expr * > ());
}
#line 1342 "/home/josuedejesus/ProyectoCompiladores2/build/MiniJavaParser.cpp"
    break;

  case 50: // return_stmt: "return" expr ";"
#line 262 "MiniJavaParser.y"
                                      {
    yylhs.value.as < Ast::Node * > () = new Ast::ReturnStmt(yystack_[1].value.as < Ast::Expr * > ());
}
#line 1350 "/home/josuedejesus/ProyectoCompiladores2/build/MiniJavaParser.cpp"
    break;

  case 51: // boolean_expr: boolean_expr "||" boolean_term
#line 268 "MiniJavaParser.y"
                                                   {  
    yylhs.value.as < Ast::BooleanExpr * > () = new Ast::OrExpr(yystack_[2].value.as < Ast::BooleanExpr * > (), yystack_[0].value.as < Ast::BooleanExpr * > ()); 
}
#line 1358 "/home/josuedejesus/ProyectoCompiladores2/build/MiniJavaParser.cpp"
    break;

  case 52: // boolean_expr: boolean_term
#line 270 "MiniJavaParser.y"
                 {
    yylhs.value.as < Ast::BooleanExpr * > () = yystack_[0].value.as < Ast::BooleanExpr * > ();  
}
#line 1366 "/home/josuedejesus/ProyectoCompiladores2/build/MiniJavaParser.cpp"
    break;

  case 53: // boolean_term: boolean_term "&&" boolean_factor
#line 274 "MiniJavaParser.y"
                                                      {  
    yylhs.value.as < Ast::BooleanExpr * > () = new Ast::AndExpr(yystack_[2].value.as < Ast::BooleanExpr * > (), yystack_[0].value.as < Ast::BooleanExpr * > ()); 
}
#line 1374 "/home/josuedejesus/ProyectoCompiladores2/build/MiniJavaParser.cpp"
    break;

  case 54: // boolean_term: boolean_factor
#line 276 "MiniJavaParser.y"
                   {
    yylhs.value.as < Ast::BooleanExpr * > () = yystack_[0].value.as < Ast::BooleanExpr * > ();
}
#line 1382 "/home/josuedejesus/ProyectoCompiladores2/build/MiniJavaParser.cpp"
    break;

  case 55: // boolean_factor: relational_expr
#line 280 "MiniJavaParser.y"
                                {  
    yylhs.value.as < Ast::BooleanExpr * > () = yystack_[0].value.as < Ast::RelationalExpr * > ();  
}
#line 1390 "/home/josuedejesus/ProyectoCompiladores2/build/MiniJavaParser.cpp"
    break;

  case 56: // relational_expr: expr ">" expr
#line 284 "MiniJavaParser.y"
                                           {
        yylhs.value.as < Ast::RelationalExpr * > () = new Ast::GreaterExpr(yystack_[2].value.as < Ast::Expr * > (), yystack_[0].value.as < Ast::Expr * > ());
    }
#line 1398 "/home/josuedejesus/ProyectoCompiladores2/build/MiniJavaParser.cpp"
    break;

  case 57: // relational_expr: expr ">=" expr
#line 286 "MiniJavaParser.y"
                                   {
        yylhs.value.as < Ast::RelationalExpr * > () = new Ast::GreaterEqualExpr(yystack_[2].value.as < Ast::Expr * > (), yystack_[0].value.as < Ast::Expr * > ());
    }
#line 1406 "/home/josuedejesus/ProyectoCompiladores2/build/MiniJavaParser.cpp"
    break;

  case 58: // relational_expr: expr "<" expr
#line 288 "MiniJavaParser.y"
                               {
        yylhs.value.as < Ast::RelationalExpr * > () = new Ast::LessExpr(yystack_[2].value.as < Ast::Expr * > (), yystack_[0].value.as < Ast::Expr * > ());
    }
#line 1414 "/home/josuedejesus/ProyectoCompiladores2/build/MiniJavaParser.cpp"
    break;

  case 59: // relational_expr: expr "<=" expr
#line 290 "MiniJavaParser.y"
                                {
        yylhs.value.as < Ast::RelationalExpr * > () = new Ast::LessEqualExpr(yystack_[2].value.as < Ast::Expr * > (), yystack_[0].value.as < Ast::Expr * > ());
    }
#line 1422 "/home/josuedejesus/ProyectoCompiladores2/build/MiniJavaParser.cpp"
    break;

  case 60: // relational_expr: expr "!=" expr
#line 292 "MiniJavaParser.y"
                               {
        yylhs.value.as < Ast::RelationalExpr * > () = new Ast::NotEqualExpr(yystack_[2].value.as < Ast::Expr * > (), yystack_[0].value.as < Ast::Expr * > ());
    }
#line 1430 "/home/josuedejesus/ProyectoCompiladores2/build/MiniJavaParser.cpp"
    break;

  case 61: // relational_expr: expr "==" expr
#line 294 "MiniJavaParser.y"
                           {
        yylhs.value.as < Ast::RelationalExpr * > () = new Ast::EqualExpr(yystack_[2].value.as < Ast::Expr * > (), yystack_[0].value.as < Ast::Expr * > ());
    }
#line 1438 "/home/josuedejesus/ProyectoCompiladores2/build/MiniJavaParser.cpp"
    break;

  case 62: // expr: expr "+" term
#line 299 "MiniJavaParser.y"
                  { 
        yylhs.value.as < Ast::Expr * > () = new Ast::AddExpr(yystack_[2].value.as < Ast::Expr * > (), yystack_[0].value.as < Ast::Expr * > ()); 
    }
#line 1446 "/home/josuedejesus/ProyectoCompiladores2/build/MiniJavaParser.cpp"
    break;

  case 63: // expr: expr "-" term
#line 301 "MiniJavaParser.y"
                      { 
        yylhs.value.as < Ast::Expr * > () = new Ast::SubExpr(yystack_[2].value.as < Ast::Expr * > (), yystack_[0].value.as < Ast::Expr * > ()); 
    }
#line 1454 "/home/josuedejesus/ProyectoCompiladores2/build/MiniJavaParser.cpp"
    break;

  case 64: // expr: term
#line 303 "MiniJavaParser.y"
            { yylhs.value.as < Ast::Expr * > () = yystack_[0].value.as < Ast::Expr * > (); }
#line 1460 "/home/josuedejesus/ProyectoCompiladores2/build/MiniJavaParser.cpp"
    break;

  case 65: // term: term "*" factor
#line 306 "MiniJavaParser.y"
                       { 
        yylhs.value.as < Ast::Expr * > () = new Ast::MulExpr(yystack_[2].value.as < Ast::Expr * > (), yystack_[0].value.as < Ast::Expr * > ());
    }
#line 1468 "/home/josuedejesus/ProyectoCompiladores2/build/MiniJavaParser.cpp"
    break;

  case 66: // term: term "/" factor
#line 308 "MiniJavaParser.y"
                           {
        yylhs.value.as < Ast::Expr * > () = new Ast::DivExpr(yystack_[2].value.as < Ast::Expr * > (), yystack_[0].value.as < Ast::Expr * > ());
    }
#line 1476 "/home/josuedejesus/ProyectoCompiladores2/build/MiniJavaParser.cpp"
    break;

  case 67: // term: term "%" factor
#line 310 "MiniJavaParser.y"
                           {
        yylhs.value.as < Ast::Expr * > () = new Ast::ModExpr(yystack_[2].value.as < Ast::Expr * > (), yystack_[0].value.as < Ast::Expr * > ());
    }
#line 1484 "/home/josuedejesus/ProyectoCompiladores2/build/MiniJavaParser.cpp"
    break;

  case 68: // term: factor
#line 312 "MiniJavaParser.y"
               { 
        yylhs.value.as < Ast::Expr * > () = yystack_[0].value.as < Ast::Expr * > ();
    }
#line 1492 "/home/josuedejesus/ProyectoCompiladores2/build/MiniJavaParser.cpp"
    break;

  case 69: // factor: "number"
#line 316 "MiniJavaParser.y"
                  { 
    yylhs.value.as < Ast::Expr * > () = new Ast::Number(yystack_[0].value.as < int > ());
}
#line 1500 "/home/josuedejesus/ProyectoCompiladores2/build/MiniJavaParser.cpp"
    break;

  case 70: // factor: "(" expr ")"
#line 318 "MiniJavaParser.y"
                            { 
    yylhs.value.as < Ast::Expr * > () = yystack_[1].value.as < Ast::Expr * > ();
}
#line 1508 "/home/josuedejesus/ProyectoCompiladores2/build/MiniJavaParser.cpp"
    break;

  case 71: // factor: "identifier"
#line 320 "MiniJavaParser.y"
               {
    yylhs.value.as < Ast::Expr * > () = new Ast::Identifier(yystack_[0].value.as < std::string > ());
}
#line 1516 "/home/josuedejesus/ProyectoCompiladores2/build/MiniJavaParser.cpp"
    break;

  case 72: // factor: array_variable
#line 322 "MiniJavaParser.y"
                   {
    yylhs.value.as < Ast::Expr * > () = yystack_[0].value.as < Ast::Expr * > ();
}
#line 1524 "/home/josuedejesus/ProyectoCompiladores2/build/MiniJavaParser.cpp"
    break;

  case 73: // factor: "identifier" "(" argument_list ")"
#line 324 "MiniJavaParser.y"
                                                {
    yylhs.value.as < Ast::Expr * > () = new Ast::FunctionCall(yystack_[3].value.as < std::string > (), yystack_[1].value.as < Ast::Node * > ());
}
#line 1532 "/home/josuedejesus/ProyectoCompiladores2/build/MiniJavaParser.cpp"
    break;

  case 74: // factor: "identifier" "(" ")"
#line 326 "MiniJavaParser.y"
                                  {
    yylhs.value.as < Ast::Expr * > () = new Ast::FunctionCall(yystack_[2].value.as < std::string > (), nullptr);
}
#line 1540 "/home/josuedejesus/ProyectoCompiladores2/build/MiniJavaParser.cpp"
    break;


#line 1544 "/home/josuedejesus/ProyectoCompiladores2/build/MiniJavaParser.cpp"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        context yyctx (*this, yyla);
        std::string msg = yysyntax_error_ (yyctx);
        error (YY_MOVE (msg));
      }


    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;


      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
   Parser::error (const syntax_error& yyexc)
  {
    error (yyexc.what ());
  }

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
   Parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr;
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              else
                goto append;

            append:
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }

  std::string
   Parser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytnamerr_ (yytname_[yysymbol]);
  }



  //  Parser::context.
   Parser::context::context (const  Parser& yyparser, const symbol_type& yyla)
    : yyparser_ (yyparser)
    , yyla_ (yyla)
  {}

  int
   Parser::context::expected_tokens (symbol_kind_type yyarg[], int yyargn) const
  {
    // Actual number of expected tokens
    int yycount = 0;

    const int yyn = yypact_[+yyparser_.yystack_[0].state];
    if (!yy_pact_value_is_default_ (yyn))
      {
        /* Start YYX at -YYN if negative to avoid negative indexes in
           YYCHECK.  In other words, skip the first -YYN actions for
           this state because they are default actions.  */
        const int yyxbegin = yyn < 0 ? -yyn : 0;
        // Stay within bounds of both yycheck and yytname.
        const int yychecklim = yylast_ - yyn + 1;
        const int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
        for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
          if (yycheck_[yyx + yyn] == yyx && yyx != symbol_kind::S_YYerror
              && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
            {
              if (!yyarg)
                ++yycount;
              else if (yycount == yyargn)
                return 0;
              else
                yyarg[yycount++] = YY_CAST (symbol_kind_type, yyx);
            }
      }

    if (yyarg && yycount == 0 && 0 < yyargn)
      yyarg[0] = symbol_kind::S_YYEMPTY;
    return yycount;
  }






  int
   Parser::yy_syntax_error_arguments_ (const context& yyctx,
                                                 symbol_kind_type yyarg[], int yyargn) const
  {
    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state merging
         (from LALR or IELR) and default reductions corrupt the expected
         token list.  However, the list is correct for canonical LR with
         one exception: it will still contain any token that will not be
         accepted due to an error action in a later state.
    */

    if (!yyctx.lookahead ().empty ())
      {
        if (yyarg)
          yyarg[0] = yyctx.token ();
        int yyn = yyctx.expected_tokens (yyarg ? yyarg + 1 : yyarg, yyargn - 1);
        return yyn + 1;
      }
    return 0;
  }

  // Generate an error message.
  std::string
   Parser::yysyntax_error_ (const context& yyctx) const
  {
    // Its maximum.
    enum { YYARGS_MAX = 5 };
    // Arguments of yyformat.
    symbol_kind_type yyarg[YYARGS_MAX];
    int yycount = yy_syntax_error_arguments_ (yyctx, yyarg, YYARGS_MAX);

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    std::ptrdiff_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += symbol_name (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char  Parser::yypact_ninf_ = -86;

  const signed char  Parser::yytable_ninf_ = -1;

  const short
   Parser::yypact_[] =
  {
       0,    -4,    48,    39,   -86,    41,    62,   -86,    58,   -86,
     -86,   -86,   -86,    63,    66,    76,    77,   -86,    95,    89,
      91,    96,   -86,    80,    66,   -86,    92,    19,   107,    98,
      99,   100,   -86,   102,   103,   -86,    94,    33,   105,    97,
     -86,   109,   -86,    62,   104,   106,    74,   110,     6,   -86,
     -86,   108,    33,   -86,   -86,   -86,   -86,   -86,   -86,   -86,
     -86,    33,   -86,   111,    74,    74,    74,   -86,    -6,   -86,
       1,   101,   -86,   -11,    74,    51,    74,   -86,   -86,   112,
     -86,    13,   124,   -86,   -86,    81,    22,    12,    53,    74,
      74,    74,   -86,    74,    74,    74,   113,    16,     3,   114,
     115,   117,   118,   116,     7,   -86,    74,   120,    74,    74,
      74,    74,    74,    74,    74,   122,   -86,   -86,   121,     9,
     101,   101,   -86,   -86,   -86,   123,   125,   -86,   -86,   -86,
     126,    26,   135,   124,    33,   -86,   116,   116,   116,   116,
     116,   116,    33,   -86,   -86,   -86,   -86,   -86,   -86,    74,
     128,   129,     5,   132,   -86,   -86,   131,    33,   133,   -86
  };

  const signed char
   Parser::yydefact_[] =
  {
       0,     0,     0,     0,     1,     5,    17,    16,     0,     4,
       6,     8,     7,     0,     0,     0,     0,     3,     0,    12,
       0,     0,     2,     0,     0,    11,     0,     0,     0,     0,
       0,    19,    13,     0,     0,    21,     0,    29,     0,     0,
      14,     0,    22,    18,     0,     0,     0,     0,     0,    40,
      39,     0,    28,    30,    32,    34,    33,    35,    36,    37,
      38,    29,    20,     0,     0,     0,     0,    69,    71,    72,
       0,    64,    68,     0,     0,     0,     0,    10,    31,     0,
      23,     0,    52,    54,    55,     0,     0,     0,     0,     0,
       0,     0,    50,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    24,    26,     0,     9,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    70,    74,     0,     0,
      62,    63,    65,    66,    67,     0,     0,    41,    27,    44,
       0,     0,     0,    51,    29,    53,    61,    60,    56,    57,
      58,    59,    29,    73,    15,    48,    49,    43,    25,     0,
       0,     0,     0,    45,    47,    42,     0,     0,     0,    46
  };

  const short
   Parser::yypgoto_[] =
  {
     -86,   -86,   -86,   136,   -86,    45,   134,    68,   -86,   -86,
     -86,   130,   -86,   -85,   -86,   -59,   -86,   -52,   -86,   -86,
     -86,   -86,   -86,   -86,   -86,    82,    50,    56,   -86,   -45,
      31,    20
  };

  const signed char
   Parser::yydefgoto_[] =
  {
       0,     2,     8,     9,    10,    49,    20,    50,    69,    13,
      14,    30,    31,   101,   102,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    81,    82,    83,    84,    85,
      71,    72
  };

  const unsigned char
   Parser::yytable_[] =
  {
      78,    70,    79,   118,    90,    91,    90,    91,    90,    91,
      90,    91,    90,    91,    74,    90,    91,    66,     1,    90,
      91,    87,    88,   106,    89,    67,    68,    96,    97,    98,
     103,   104,   106,     3,    75,    92,    76,   127,   132,   155,
     144,   116,   107,   103,   119,   126,   148,    99,     4,    34,
      11,   115,    43,    11,    66,    44,    35,    45,    46,    47,
       6,     7,    67,    68,   136,   137,   138,   139,   140,   141,
      48,     5,    99,    12,    99,   150,    12,     6,     7,    66,
     100,    66,   117,   151,    90,    91,   103,    67,    68,    67,
      68,    16,    15,   109,   110,   111,   112,   113,   114,    27,
      18,    28,    66,    19,   152,   158,    93,    94,    95,    29,
      67,    68,    21,   122,   123,   124,    27,    22,    28,    90,
      91,   120,   121,    23,    24,    25,    36,    26,    38,    33,
      37,    42,    64,   108,    65,    39,    40,    61,    73,    41,
      63,    77,   125,   149,    17,   105,   130,    86,    80,   129,
     143,   128,   134,   131,   142,   156,   133,   145,    32,   146,
     147,   153,   154,   157,   135,     0,   159,     0,     0,    62
  };

  const short
   Parser::yycheck_[] =
  {
      52,    46,    61,    88,     3,     4,     3,     4,     3,     4,
       3,     4,     3,     4,     8,     3,     4,    28,    18,     3,
       4,    66,    28,    10,    30,    36,    37,    38,    73,    74,
      75,    76,    10,    37,    28,    34,    30,    34,    31,    34,
      31,    29,    29,    88,    89,    29,   131,    21,     0,    30,
       5,    29,    19,     8,    28,    22,    37,    24,    25,    26,
      19,    20,    36,    37,   109,   110,   111,   112,   113,   114,
      37,    32,    21,     5,    21,   134,     8,    19,    20,    28,
      29,    28,    29,   142,     3,     4,   131,    36,    37,    36,
      37,    33,    30,    12,    13,    14,    15,    16,    17,    19,
      37,    21,    28,    37,   149,   157,     5,     6,     7,    29,
      36,    37,    36,    93,    94,    95,    19,    40,    21,     3,
       4,    90,    91,    28,    35,    34,    19,    31,    29,    37,
      32,    37,    28,     9,    28,    35,    34,    32,    28,    36,
      31,    33,    29,     8,     8,    33,    29,    65,    37,    34,
      29,    37,    32,    35,    32,    23,   106,    34,    24,    34,
      34,    33,    33,    32,   108,    -1,    33,    -1,    -1,    39
  };

  const signed char
   Parser::yystos_[] =
  {
       0,    18,    42,    37,     0,    32,    19,    20,    43,    44,
      45,    46,    48,    50,    51,    30,    33,    44,    37,    37,
      47,    36,    40,    28,    35,    34,    31,    19,    21,    29,
      52,    53,    47,    37,    30,    37,    19,    32,    29,    35,
      34,    36,    37,    19,    22,    24,    25,    26,    37,    46,
      48,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    32,    52,    31,    28,    28,    28,    36,    37,    49,
      70,    71,    72,    28,     8,    28,    30,    33,    58,    56,
      37,    66,    67,    68,    69,    70,    66,    70,    28,    30,
       3,     4,    34,     5,     6,     7,    38,    70,    70,    21,
      29,    54,    55,    70,    70,    33,    10,    29,     9,    12,
      13,    14,    15,    16,    17,    29,    29,    29,    54,    70,
      71,    71,    72,    72,    72,    29,    29,    34,    37,    34,
      29,    35,    31,    67,    32,    68,    70,    70,    70,    70,
      70,    70,    32,    29,    31,    34,    34,    34,    54,     8,
      56,    56,    70,    33,    33,    34,    23,    32,    58,    33
  };

  const signed char
   Parser::yyr1_[] =
  {
       0,    41,    42,    43,    43,    43,    44,    44,    44,    45,
      45,    46,    47,    47,    48,    49,    50,    50,    51,    52,
      52,    53,    53,    53,    54,    54,    55,    55,    56,    56,
      57,    57,    58,    58,    58,    58,    58,    58,    58,    59,
      59,    60,    60,    61,    61,    62,    62,    63,    64,    64,
      65,    66,    66,    67,    67,    68,    69,    69,    69,    69,
      69,    69,    70,    70,    70,    71,    71,    71,    71,    72,
      72,    72,    72,    72,    72
  };

  const signed char
   Parser::yyr2_[] =
  {
       0,     2,     6,     2,     1,     0,     1,     1,     1,     8,
       7,     3,     1,     3,     6,     4,     1,     1,     1,     1,
       3,     2,     3,     5,     1,     3,     1,     2,     1,     0,
       1,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     7,     5,     4,     7,    11,     7,     5,     5,
       3,     3,     1,     3,     1,     1,     3,     3,     3,     3,
       3,     3,     3,     3,     1,     3,     3,     3,     1,     1,
       3,     1,     1,     4,     3
  };


#if YYDEBUG || 1
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const  Parser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "\"+\"", "\"-\"",
  "\"*\"", "\"/\"", "\"%\"", "\"=\"", "\"&&\"", "\"||\"", "\"!\"",
  "\"==\"", "\"!=\"", "\">\"", "\">=\"", "\"<\"", "\"<=\"", "\"class\"",
  "\"int\"", "\"void\"", "\"ref\"", "\"if\"", "\"else\"", "\"while\"",
  "\"return\"", "\"print\"", "\"read\"", "\"(\"", "\")\"", "\"[\"",
  "\"]\"", "\"{\"", "\"}\"", "\";\"", "\",\"", "\"number\"",
  "\"identifier\"", "\"string literal\"", "\"unknown token\"", "\"EOF\"",
  "$accept", "program", "class_body", "class_member", "method_declaration",
  "variable_decl", "variable_list", "array_decl", "array_variable",
  "method_return_type", "type", "opt_parameter_list", "parameter",
  "argument_list", "argument", "block", "statement_list", "statement",
  "declaration", "assign_stmt", "method_call", "if_stmt", "while_stmt",
  "print_stmt", "return_stmt", "boolean_expr", "boolean_term",
  "boolean_factor", "relational_expr", "expr", "term", "factor", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
   Parser::yyrline_[] =
  {
       0,   115,   115,   119,   121,   123,   127,   129,   134,   142,
     144,   148,   152,   154,   158,   162,   166,   168,   172,   174,
     176,   180,   182,   184,   188,   190,   194,   196,   201,   203,
     207,   209,   213,   215,   217,   219,   221,   223,   225,   230,
     230,   232,   234,   240,   242,   246,   248,   252,   256,   258,
     262,   268,   270,   274,   276,   280,   284,   286,   288,   290,
     292,   294,   299,   301,   303,   306,   308,   310,   312,   316,
     318,   320,   322,   324,   326
  };

  void
   Parser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
   Parser::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

   Parser::symbol_kind_type
   Parser::yytranslate_ (int t) YY_NOEXCEPT
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const signed char
    translate_table[] =
    {
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40
    };
    // Last valid token kind.
    const int code_max = 295;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return static_cast <symbol_kind_type> (translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

#line 9 "MiniJavaParser.y"
} //  Expr 
#line 2166 "/home/josuedejesus/ProyectoCompiladores2/build/MiniJavaParser.cpp"

#line 329 "MiniJavaParser.y"
