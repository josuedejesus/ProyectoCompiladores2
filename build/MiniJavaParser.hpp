// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton interface for Bison LALR(1) parsers in C++

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


/**
 ** \file /home/josuedejesus/ProyectoCompiladores2/build/MiniJavaParser.hpp
 ** Define the  Expr ::parser class.
 */

// C++ LALR(1) parser skeleton written by Akim Demaille.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.

#ifndef YY_YY_HOME_JOSUEDEJESUS_PROYECTOCOMPILADORES2_BUILD_MINIJAVAPARSER_HPP_INCLUDED
# define YY_YY_HOME_JOSUEDEJESUS_PROYECTOCOMPILADORES2_BUILD_MINIJAVAPARSER_HPP_INCLUDED
// "%code requires" blocks.
#line 11 "MiniJavaParser.y"

    #include <unordered_map>
    #include "MiniJavaAst.hpp"
    class MiniJavaLexer;

    

#line 57 "/home/josuedejesus/ProyectoCompiladores2/build/MiniJavaParser.hpp"


# include <cstdlib> // std::abort
# include <iostream>
# include <stdexcept>
# include <string>
# include <vector>

#if defined __cplusplus
# define YY_CPLUSPLUS __cplusplus
#else
# define YY_CPLUSPLUS 199711L
#endif

// Support move semantics when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_MOVE           std::move
# define YY_MOVE_OR_COPY   move
# define YY_MOVE_REF(Type) Type&&
# define YY_RVREF(Type)    Type&&
# define YY_COPY(Type)     Type
#else
# define YY_MOVE
# define YY_MOVE_OR_COPY   copy
# define YY_MOVE_REF(Type) Type&
# define YY_RVREF(Type)    const Type&
# define YY_COPY(Type)     const Type&
#endif

// Support noexcept when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_NOEXCEPT noexcept
# define YY_NOTHROW
#else
# define YY_NOEXCEPT
# define YY_NOTHROW throw ()
#endif

// Support constexpr when possible.
#if 201703 <= YY_CPLUSPLUS
# define YY_CONSTEXPR constexpr
#else
# define YY_CONSTEXPR
#endif



#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

#line 9 "MiniJavaParser.y"
namespace  Expr  {
#line 193 "/home/josuedejesus/ProyectoCompiladores2/build/MiniJavaParser.hpp"




  /// A Bison parser.
  class  Parser
  {
  public:
#ifdef YYSTYPE
# ifdef __GNUC__
#  pragma GCC message "bison: do not #define YYSTYPE in C++, use %define api.value.type"
# endif
    typedef YYSTYPE value_type;
#else
  /// A buffer to store and retrieve objects.
  ///
  /// Sort of a variant, but does not keep track of the nature
  /// of the stored data, since that knowledge is available
  /// via the current parser state.
  class value_type
  {
  public:
    /// Type of *this.
    typedef value_type self_type;

    /// Empty construction.
    value_type () YY_NOEXCEPT
      : yyraw_ ()
    {}

    /// Construct and fill.
    template <typename T>
    value_type (YY_RVREF (T) t)
    {
      new (yyas_<T> ()) T (YY_MOVE (t));
    }

#if 201103L <= YY_CPLUSPLUS
    /// Non copyable.
    value_type (const self_type&) = delete;
    /// Non copyable.
    self_type& operator= (const self_type&) = delete;
#endif

    /// Destruction, allowed only if empty.
    ~value_type () YY_NOEXCEPT
    {}

# if 201103L <= YY_CPLUSPLUS
    /// Instantiate a \a T in here from \a t.
    template <typename T, typename... U>
    T&
    emplace (U&&... u)
    {
      return *new (yyas_<T> ()) T (std::forward <U>(u)...);
    }
# else
    /// Instantiate an empty \a T in here.
    template <typename T>
    T&
    emplace ()
    {
      return *new (yyas_<T> ()) T ();
    }

    /// Instantiate a \a T in here from \a t.
    template <typename T>
    T&
    emplace (const T& t)
    {
      return *new (yyas_<T> ()) T (t);
    }
# endif

    /// Instantiate an empty \a T in here.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build ()
    {
      return emplace<T> ();
    }

    /// Instantiate a \a T in here from \a t.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build (const T& t)
    {
      return emplace<T> (t);
    }

    /// Accessor to a built \a T.
    template <typename T>
    T&
    as () YY_NOEXCEPT
    {
      return *yyas_<T> ();
    }

    /// Const accessor to a built \a T (for %printer).
    template <typename T>
    const T&
    as () const YY_NOEXCEPT
    {
      return *yyas_<T> ();
    }

    /// Swap the content with \a that, of same type.
    ///
    /// Both variants must be built beforehand, because swapping the actual
    /// data requires reading it (with as()), and this is not possible on
    /// unconstructed variants: it would require some dynamic testing, which
    /// should not be the variant's responsibility.
    /// Swapping between built and (possibly) non-built is done with
    /// self_type::move ().
    template <typename T>
    void
    swap (self_type& that) YY_NOEXCEPT
    {
      std::swap (as<T> (), that.as<T> ());
    }

    /// Move the content of \a that to this.
    ///
    /// Destroys \a that.
    template <typename T>
    void
    move (self_type& that)
    {
# if 201103L <= YY_CPLUSPLUS
      emplace<T> (std::move (that.as<T> ()));
# else
      emplace<T> ();
      swap<T> (that);
# endif
      that.destroy<T> ();
    }

# if 201103L <= YY_CPLUSPLUS
    /// Move the content of \a that to this.
    template <typename T>
    void
    move (self_type&& that)
    {
      emplace<T> (std::move (that.as<T> ()));
      that.destroy<T> ();
    }
#endif

    /// Copy the content of \a that to this.
    template <typename T>
    void
    copy (const self_type& that)
    {
      emplace<T> (that.as<T> ());
    }

    /// Destroy the stored \a T.
    template <typename T>
    void
    destroy ()
    {
      as<T> ().~T ();
    }

  private:
#if YY_CPLUSPLUS < 201103L
    /// Non copyable.
    value_type (const self_type&);
    /// Non copyable.
    self_type& operator= (const self_type&);
#endif

    /// Accessor to raw memory as \a T.
    template <typename T>
    T*
    yyas_ () YY_NOEXCEPT
    {
      void *yyp = yyraw_;
      return static_cast<T*> (yyp);
     }

    /// Const accessor to raw memory as \a T.
    template <typename T>
    const T*
    yyas_ () const YY_NOEXCEPT
    {
      const void *yyp = yyraw_;
      return static_cast<const T*> (yyp);
     }

    /// An auxiliary type to compute the largest semantic type.
    union union_type
    {
      // boolean_expr
      // boolean_term
      // boolean_factor
      char dummy1[sizeof (Ast::BooleanExpr *)];

      // array_variable
      // expr
      // term
      // factor
      char dummy2[sizeof (Ast::Expr *)];

      // class_body
      // class_member
      // method_declaration
      // variable_decl
      // variable_list
      // array_decl
      // method_return_type
      // type
      // opt_parameter_list
      // parameter
      // argument_list
      // argument
      // block
      // statement_list
      // statement
      // declaration
      // assign_stmt
      // method_call
      // if_stmt
      // while_stmt
      // print_stmt
      // return_stmt
      char dummy3[sizeof (Ast::Node *)];

      // relational_expr
      char dummy4[sizeof (Ast::RelationalExpr *)];

      // "number"
      char dummy5[sizeof (int)];

      // "identifier"
      // "string literal"
      char dummy6[sizeof (std::string)];
    };

    /// The size of the largest semantic type.
    enum { size = sizeof (union_type) };

    /// A buffer to store semantic values.
    union
    {
      /// Strongest alignment constraints.
      long double yyalign_me_;
      /// A buffer large enough to store any of the semantic values.
      char yyraw_[size];
    };
  };

#endif
    /// Backward compatibility (Bison 3.8).
    typedef value_type semantic_type;


    /// Syntax errors thrown from user actions.
    struct syntax_error : std::runtime_error
    {
      syntax_error (const std::string& m)
        : std::runtime_error (m)
      {}

      syntax_error (const syntax_error& s)
        : std::runtime_error (s.what ())
      {}

      ~syntax_error () YY_NOEXCEPT YY_NOTHROW;
    };

    /// Token kinds.
    struct token
    {
      enum token_kind_type
      {
        YYEMPTY = -2,
    YYEOF = 0,                     // "end of file"
    YYerror = 256,                 // error
    YYUNDEF = 257,                 // "invalid token"
    OP_ADD = 258,                  // "+"
    OP_SUB = 259,                  // "-"
    OP_MUL = 260,                  // "*"
    OP_DIV = 261,                  // "/"
    OP_MOD = 262,                  // "%"
    OP_ASSIGN = 263,               // "="
    OP_BOOL_AND = 264,             // "&&"
    OP_BOOL_OR = 265,              // "||"
    OP_BOOL_NOT = 266,             // "!"
    OP_EQUAL = 267,                // "=="
    OP_NOT_EQUAL = 268,            // "!="
    OP_GREATER_THAN = 269,         // ">"
    OP_GREATER_EQUAL = 270,        // ">="
    OP_LESS_THAN = 271,            // "<"
    OP_LESS_EQUAL = 272,           // "<="
    KW_CLASS = 273,                // "class"
    KW_INT = 274,                  // "int"
    KW_VOID = 275,                 // "void"
    KW_REF = 276,                  // "ref"
    KW_IF = 277,                   // "if"
    KW_ELSE = 278,                 // "else"
    KW_WHILE = 279,                // "while"
    KW_RETURN = 280,               // "return"
    KW_PRINT = 281,                // "print"
    KW_READ = 282,                 // "read"
    OPEN_PAR = 283,                // "("
    CLOSE_PAR = 284,               // ")"
    OPEN_BRACKET = 285,            // "["
    CLOSE_BRACKET = 286,           // "]"
    OPEN_CURLY = 287,              // "{"
    CLOSE_CURLY = 288,             // "}"
    SEMICOLON = 289,               // ";"
    COMMA = 290,                   // ","
    INT_CONST = 291,               // "number"
    IDENTIFIER = 292,              // "identifier"
    STRING_LITERAL = 293,          // "string literal"
    Error = 294,                   // "unknown token"
    EndOfFile = 295                // "EOF"
      };
      /// Backward compatibility alias (Bison 3.6).
      typedef token_kind_type yytokentype;
    };

    /// Token kind, as returned by yylex.
    typedef token::token_kind_type token_kind_type;

    /// Backward compatibility alias (Bison 3.6).
    typedef token_kind_type token_type;

    /// Symbol kinds.
    struct symbol_kind
    {
      enum symbol_kind_type
      {
        YYNTOKENS = 41, ///< Number of tokens.
        S_YYEMPTY = -2,
        S_YYEOF = 0,                             // "end of file"
        S_YYerror = 1,                           // error
        S_YYUNDEF = 2,                           // "invalid token"
        S_OP_ADD = 3,                            // "+"
        S_OP_SUB = 4,                            // "-"
        S_OP_MUL = 5,                            // "*"
        S_OP_DIV = 6,                            // "/"
        S_OP_MOD = 7,                            // "%"
        S_OP_ASSIGN = 8,                         // "="
        S_OP_BOOL_AND = 9,                       // "&&"
        S_OP_BOOL_OR = 10,                       // "||"
        S_OP_BOOL_NOT = 11,                      // "!"
        S_OP_EQUAL = 12,                         // "=="
        S_OP_NOT_EQUAL = 13,                     // "!="
        S_OP_GREATER_THAN = 14,                  // ">"
        S_OP_GREATER_EQUAL = 15,                 // ">="
        S_OP_LESS_THAN = 16,                     // "<"
        S_OP_LESS_EQUAL = 17,                    // "<="
        S_KW_CLASS = 18,                         // "class"
        S_KW_INT = 19,                           // "int"
        S_KW_VOID = 20,                          // "void"
        S_KW_REF = 21,                           // "ref"
        S_KW_IF = 22,                            // "if"
        S_KW_ELSE = 23,                          // "else"
        S_KW_WHILE = 24,                         // "while"
        S_KW_RETURN = 25,                        // "return"
        S_KW_PRINT = 26,                         // "print"
        S_KW_READ = 27,                          // "read"
        S_OPEN_PAR = 28,                         // "("
        S_CLOSE_PAR = 29,                        // ")"
        S_OPEN_BRACKET = 30,                     // "["
        S_CLOSE_BRACKET = 31,                    // "]"
        S_OPEN_CURLY = 32,                       // "{"
        S_CLOSE_CURLY = 33,                      // "}"
        S_SEMICOLON = 34,                        // ";"
        S_COMMA = 35,                            // ","
        S_INT_CONST = 36,                        // "number"
        S_IDENTIFIER = 37,                       // "identifier"
        S_STRING_LITERAL = 38,                   // "string literal"
        S_Error = 39,                            // "unknown token"
        S_EndOfFile = 40,                        // "EOF"
        S_YYACCEPT = 41,                         // $accept
        S_program = 42,                          // program
        S_class_body = 43,                       // class_body
        S_class_member = 44,                     // class_member
        S_method_declaration = 45,               // method_declaration
        S_variable_decl = 46,                    // variable_decl
        S_variable_list = 47,                    // variable_list
        S_array_decl = 48,                       // array_decl
        S_array_variable = 49,                   // array_variable
        S_method_return_type = 50,               // method_return_type
        S_type = 51,                             // type
        S_opt_parameter_list = 52,               // opt_parameter_list
        S_parameter = 53,                        // parameter
        S_argument_list = 54,                    // argument_list
        S_argument = 55,                         // argument
        S_block = 56,                            // block
        S_statement_list = 57,                   // statement_list
        S_statement = 58,                        // statement
        S_declaration = 59,                      // declaration
        S_assign_stmt = 60,                      // assign_stmt
        S_method_call = 61,                      // method_call
        S_if_stmt = 62,                          // if_stmt
        S_while_stmt = 63,                       // while_stmt
        S_print_stmt = 64,                       // print_stmt
        S_return_stmt = 65,                      // return_stmt
        S_boolean_expr = 66,                     // boolean_expr
        S_boolean_term = 67,                     // boolean_term
        S_boolean_factor = 68,                   // boolean_factor
        S_relational_expr = 69,                  // relational_expr
        S_expr = 70,                             // expr
        S_term = 71,                             // term
        S_factor = 72                            // factor
      };
    };

    /// (Internal) symbol kind.
    typedef symbol_kind::symbol_kind_type symbol_kind_type;

    /// The number of tokens.
    static const symbol_kind_type YYNTOKENS = symbol_kind::YYNTOKENS;

    /// A complete symbol.
    ///
    /// Expects its Base type to provide access to the symbol kind
    /// via kind ().
    ///
    /// Provide access to semantic value.
    template <typename Base>
    struct basic_symbol : Base
    {
      /// Alias to Base.
      typedef Base super_type;

      /// Default constructor.
      basic_symbol () YY_NOEXCEPT
        : value ()
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      basic_symbol (basic_symbol&& that)
        : Base (std::move (that))
        , value ()
      {
        switch (this->kind ())
    {
      case symbol_kind::S_boolean_expr: // boolean_expr
      case symbol_kind::S_boolean_term: // boolean_term
      case symbol_kind::S_boolean_factor: // boolean_factor
        value.move< Ast::BooleanExpr * > (std::move (that.value));
        break;

      case symbol_kind::S_array_variable: // array_variable
      case symbol_kind::S_expr: // expr
      case symbol_kind::S_term: // term
      case symbol_kind::S_factor: // factor
        value.move< Ast::Expr * > (std::move (that.value));
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
        value.move< Ast::Node * > (std::move (that.value));
        break;

      case symbol_kind::S_relational_expr: // relational_expr
        value.move< Ast::RelationalExpr * > (std::move (that.value));
        break;

      case symbol_kind::S_INT_CONST: // "number"
        value.move< int > (std::move (that.value));
        break;

      case symbol_kind::S_IDENTIFIER: // "identifier"
      case symbol_kind::S_STRING_LITERAL: // "string literal"
        value.move< std::string > (std::move (that.value));
        break;

      default:
        break;
    }

      }
#endif

      /// Copy constructor.
      basic_symbol (const basic_symbol& that);

      /// Constructors for typed symbols.
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t)
        : Base (t)
      {}
#else
      basic_symbol (typename Base::kind_type t)
        : Base (t)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, Ast::BooleanExpr *&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const Ast::BooleanExpr *& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, Ast::Expr *&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const Ast::Expr *& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, Ast::Node *&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const Ast::Node *& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, Ast::RelationalExpr *&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const Ast::RelationalExpr *& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, int&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const int& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::string&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::string& v)
        : Base (t)
        , value (v)
      {}
#endif

      /// Destroy the symbol.
      ~basic_symbol ()
      {
        clear ();
      }



      /// Destroy contents, and record that is empty.
      void clear () YY_NOEXCEPT
      {
        // User destructor.
        symbol_kind_type yykind = this->kind ();
        basic_symbol<Base>& yysym = *this;
        (void) yysym;
        switch (yykind)
        {
       default:
          break;
        }

        // Value type destructor.
switch (yykind)
    {
      case symbol_kind::S_boolean_expr: // boolean_expr
      case symbol_kind::S_boolean_term: // boolean_term
      case symbol_kind::S_boolean_factor: // boolean_factor
        value.template destroy< Ast::BooleanExpr * > ();
        break;

      case symbol_kind::S_array_variable: // array_variable
      case symbol_kind::S_expr: // expr
      case symbol_kind::S_term: // term
      case symbol_kind::S_factor: // factor
        value.template destroy< Ast::Expr * > ();
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
        value.template destroy< Ast::Node * > ();
        break;

      case symbol_kind::S_relational_expr: // relational_expr
        value.template destroy< Ast::RelationalExpr * > ();
        break;

      case symbol_kind::S_INT_CONST: // "number"
        value.template destroy< int > ();
        break;

      case symbol_kind::S_IDENTIFIER: // "identifier"
      case symbol_kind::S_STRING_LITERAL: // "string literal"
        value.template destroy< std::string > ();
        break;

      default:
        break;
    }

        Base::clear ();
      }

      /// The user-facing name of this symbol.
      std::string name () const YY_NOEXCEPT
      {
        return  Parser::symbol_name (this->kind ());
      }

      /// Backward compatibility (Bison 3.6).
      symbol_kind_type type_get () const YY_NOEXCEPT;

      /// Whether empty.
      bool empty () const YY_NOEXCEPT;

      /// Destructive move, \a s is emptied into this.
      void move (basic_symbol& s);

      /// The semantic value.
      value_type value;

    private:
#if YY_CPLUSPLUS < 201103L
      /// Assignment operator.
      basic_symbol& operator= (const basic_symbol& that);
#endif
    };

    /// Type access provider for token (enum) based symbols.
    struct by_kind
    {
      /// The symbol kind as needed by the constructor.
      typedef token_kind_type kind_type;

      /// Default constructor.
      by_kind () YY_NOEXCEPT;

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      by_kind (by_kind&& that) YY_NOEXCEPT;
#endif

      /// Copy constructor.
      by_kind (const by_kind& that) YY_NOEXCEPT;

      /// Constructor from (external) token numbers.
      by_kind (kind_type t) YY_NOEXCEPT;



      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol kind from \a that.
      void move (by_kind& that);

      /// The (internal) type number (corresponding to \a type).
      /// \a empty when empty.
      symbol_kind_type kind () const YY_NOEXCEPT;

      /// Backward compatibility (Bison 3.6).
      symbol_kind_type type_get () const YY_NOEXCEPT;

      /// The symbol kind.
      /// \a S_YYEMPTY when empty.
      symbol_kind_type kind_;
    };

    /// Backward compatibility for a private implementation detail (Bison 3.6).
    typedef by_kind by_type;

    /// "External" symbols: returned by the scanner.
    struct symbol_type : basic_symbol<by_kind>
    {
      /// Superclass.
      typedef basic_symbol<by_kind> super_type;

      /// Empty symbol.
      symbol_type () YY_NOEXCEPT {}

      /// Constructor for valueless symbols, and symbols from each type.
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok)
        : super_type (token_kind_type (tok))
#else
      symbol_type (int tok)
        : super_type (token_kind_type (tok))
#endif
      {}
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, int v)
        : super_type (token_kind_type (tok), std::move (v))
#else
      symbol_type (int tok, const int& v)
        : super_type (token_kind_type (tok), v)
#endif
      {}
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, std::string v)
        : super_type (token_kind_type (tok), std::move (v))
#else
      symbol_type (int tok, const std::string& v)
        : super_type (token_kind_type (tok), v)
#endif
      {}
    };

    /// Build a parser object.
     Parser (MiniJavaLexer& lexer_yyarg, Ast::Node*& root_yyarg);
    virtual ~ Parser ();

#if 201103L <= YY_CPLUSPLUS
    /// Non copyable.
     Parser (const  Parser&) = delete;
    /// Non copyable.
     Parser& operator= (const  Parser&) = delete;
#endif

    /// Parse.  An alias for parse ().
    /// \returns  0 iff parsing succeeded.
    int operator() ();

    /// Parse.
    /// \returns  0 iff parsing succeeded.
    virtual int parse ();

#if YYDEBUG
    /// The current debugging stream.
    std::ostream& debug_stream () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging stream.
    void set_debug_stream (std::ostream &);

    /// Type for debugging levels.
    typedef int debug_level_type;
    /// The current debugging level.
    debug_level_type debug_level () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging level.
    void set_debug_level (debug_level_type l);
#endif

    /// Report a syntax error.
    /// \param msg    a description of the syntax error.
    virtual void error (const std::string& msg);

    /// Report a syntax error.
    void error (const syntax_error& err);

    /// The user-facing name of the symbol whose (internal) number is
    /// YYSYMBOL.  No bounds checking.
    static std::string symbol_name (symbol_kind_type yysymbol);

    // Implementation of make_symbol for each token kind.
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YYEOF ()
      {
        return symbol_type (token::YYEOF);
      }
#else
      static
      symbol_type
      make_YYEOF ()
      {
        return symbol_type (token::YYEOF);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YYerror ()
      {
        return symbol_type (token::YYerror);
      }
#else
      static
      symbol_type
      make_YYerror ()
      {
        return symbol_type (token::YYerror);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YYUNDEF ()
      {
        return symbol_type (token::YYUNDEF);
      }
#else
      static
      symbol_type
      make_YYUNDEF ()
      {
        return symbol_type (token::YYUNDEF);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OP_ADD ()
      {
        return symbol_type (token::OP_ADD);
      }
#else
      static
      symbol_type
      make_OP_ADD ()
      {
        return symbol_type (token::OP_ADD);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OP_SUB ()
      {
        return symbol_type (token::OP_SUB);
      }
#else
      static
      symbol_type
      make_OP_SUB ()
      {
        return symbol_type (token::OP_SUB);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OP_MUL ()
      {
        return symbol_type (token::OP_MUL);
      }
#else
      static
      symbol_type
      make_OP_MUL ()
      {
        return symbol_type (token::OP_MUL);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OP_DIV ()
      {
        return symbol_type (token::OP_DIV);
      }
#else
      static
      symbol_type
      make_OP_DIV ()
      {
        return symbol_type (token::OP_DIV);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OP_MOD ()
      {
        return symbol_type (token::OP_MOD);
      }
#else
      static
      symbol_type
      make_OP_MOD ()
      {
        return symbol_type (token::OP_MOD);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OP_ASSIGN ()
      {
        return symbol_type (token::OP_ASSIGN);
      }
#else
      static
      symbol_type
      make_OP_ASSIGN ()
      {
        return symbol_type (token::OP_ASSIGN);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OP_BOOL_AND ()
      {
        return symbol_type (token::OP_BOOL_AND);
      }
#else
      static
      symbol_type
      make_OP_BOOL_AND ()
      {
        return symbol_type (token::OP_BOOL_AND);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OP_BOOL_OR ()
      {
        return symbol_type (token::OP_BOOL_OR);
      }
#else
      static
      symbol_type
      make_OP_BOOL_OR ()
      {
        return symbol_type (token::OP_BOOL_OR);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OP_BOOL_NOT ()
      {
        return symbol_type (token::OP_BOOL_NOT);
      }
#else
      static
      symbol_type
      make_OP_BOOL_NOT ()
      {
        return symbol_type (token::OP_BOOL_NOT);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OP_EQUAL ()
      {
        return symbol_type (token::OP_EQUAL);
      }
#else
      static
      symbol_type
      make_OP_EQUAL ()
      {
        return symbol_type (token::OP_EQUAL);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OP_NOT_EQUAL ()
      {
        return symbol_type (token::OP_NOT_EQUAL);
      }
#else
      static
      symbol_type
      make_OP_NOT_EQUAL ()
      {
        return symbol_type (token::OP_NOT_EQUAL);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OP_GREATER_THAN ()
      {
        return symbol_type (token::OP_GREATER_THAN);
      }
#else
      static
      symbol_type
      make_OP_GREATER_THAN ()
      {
        return symbol_type (token::OP_GREATER_THAN);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OP_GREATER_EQUAL ()
      {
        return symbol_type (token::OP_GREATER_EQUAL);
      }
#else
      static
      symbol_type
      make_OP_GREATER_EQUAL ()
      {
        return symbol_type (token::OP_GREATER_EQUAL);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OP_LESS_THAN ()
      {
        return symbol_type (token::OP_LESS_THAN);
      }
#else
      static
      symbol_type
      make_OP_LESS_THAN ()
      {
        return symbol_type (token::OP_LESS_THAN);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OP_LESS_EQUAL ()
      {
        return symbol_type (token::OP_LESS_EQUAL);
      }
#else
      static
      symbol_type
      make_OP_LESS_EQUAL ()
      {
        return symbol_type (token::OP_LESS_EQUAL);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_KW_CLASS ()
      {
        return symbol_type (token::KW_CLASS);
      }
#else
      static
      symbol_type
      make_KW_CLASS ()
      {
        return symbol_type (token::KW_CLASS);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_KW_INT ()
      {
        return symbol_type (token::KW_INT);
      }
#else
      static
      symbol_type
      make_KW_INT ()
      {
        return symbol_type (token::KW_INT);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_KW_VOID ()
      {
        return symbol_type (token::KW_VOID);
      }
#else
      static
      symbol_type
      make_KW_VOID ()
      {
        return symbol_type (token::KW_VOID);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_KW_REF ()
      {
        return symbol_type (token::KW_REF);
      }
#else
      static
      symbol_type
      make_KW_REF ()
      {
        return symbol_type (token::KW_REF);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_KW_IF ()
      {
        return symbol_type (token::KW_IF);
      }
#else
      static
      symbol_type
      make_KW_IF ()
      {
        return symbol_type (token::KW_IF);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_KW_ELSE ()
      {
        return symbol_type (token::KW_ELSE);
      }
#else
      static
      symbol_type
      make_KW_ELSE ()
      {
        return symbol_type (token::KW_ELSE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_KW_WHILE ()
      {
        return symbol_type (token::KW_WHILE);
      }
#else
      static
      symbol_type
      make_KW_WHILE ()
      {
        return symbol_type (token::KW_WHILE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_KW_RETURN ()
      {
        return symbol_type (token::KW_RETURN);
      }
#else
      static
      symbol_type
      make_KW_RETURN ()
      {
        return symbol_type (token::KW_RETURN);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_KW_PRINT ()
      {
        return symbol_type (token::KW_PRINT);
      }
#else
      static
      symbol_type
      make_KW_PRINT ()
      {
        return symbol_type (token::KW_PRINT);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_KW_READ ()
      {
        return symbol_type (token::KW_READ);
      }
#else
      static
      symbol_type
      make_KW_READ ()
      {
        return symbol_type (token::KW_READ);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OPEN_PAR ()
      {
        return symbol_type (token::OPEN_PAR);
      }
#else
      static
      symbol_type
      make_OPEN_PAR ()
      {
        return symbol_type (token::OPEN_PAR);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CLOSE_PAR ()
      {
        return symbol_type (token::CLOSE_PAR);
      }
#else
      static
      symbol_type
      make_CLOSE_PAR ()
      {
        return symbol_type (token::CLOSE_PAR);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OPEN_BRACKET ()
      {
        return symbol_type (token::OPEN_BRACKET);
      }
#else
      static
      symbol_type
      make_OPEN_BRACKET ()
      {
        return symbol_type (token::OPEN_BRACKET);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CLOSE_BRACKET ()
      {
        return symbol_type (token::CLOSE_BRACKET);
      }
#else
      static
      symbol_type
      make_CLOSE_BRACKET ()
      {
        return symbol_type (token::CLOSE_BRACKET);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OPEN_CURLY ()
      {
        return symbol_type (token::OPEN_CURLY);
      }
#else
      static
      symbol_type
      make_OPEN_CURLY ()
      {
        return symbol_type (token::OPEN_CURLY);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CLOSE_CURLY ()
      {
        return symbol_type (token::CLOSE_CURLY);
      }
#else
      static
      symbol_type
      make_CLOSE_CURLY ()
      {
        return symbol_type (token::CLOSE_CURLY);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SEMICOLON ()
      {
        return symbol_type (token::SEMICOLON);
      }
#else
      static
      symbol_type
      make_SEMICOLON ()
      {
        return symbol_type (token::SEMICOLON);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_COMMA ()
      {
        return symbol_type (token::COMMA);
      }
#else
      static
      symbol_type
      make_COMMA ()
      {
        return symbol_type (token::COMMA);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_INT_CONST (int v)
      {
        return symbol_type (token::INT_CONST, std::move (v));
      }
#else
      static
      symbol_type
      make_INT_CONST (const int& v)
      {
        return symbol_type (token::INT_CONST, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_IDENTIFIER (std::string v)
      {
        return symbol_type (token::IDENTIFIER, std::move (v));
      }
#else
      static
      symbol_type
      make_IDENTIFIER (const std::string& v)
      {
        return symbol_type (token::IDENTIFIER, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_STRING_LITERAL (std::string v)
      {
        return symbol_type (token::STRING_LITERAL, std::move (v));
      }
#else
      static
      symbol_type
      make_STRING_LITERAL (const std::string& v)
      {
        return symbol_type (token::STRING_LITERAL, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_Error ()
      {
        return symbol_type (token::Error);
      }
#else
      static
      symbol_type
      make_Error ()
      {
        return symbol_type (token::Error);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EndOfFile ()
      {
        return symbol_type (token::EndOfFile);
      }
#else
      static
      symbol_type
      make_EndOfFile ()
      {
        return symbol_type (token::EndOfFile);
      }
#endif


    class context
    {
    public:
      context (const  Parser& yyparser, const symbol_type& yyla);
      const symbol_type& lookahead () const YY_NOEXCEPT { return yyla_; }
      symbol_kind_type token () const YY_NOEXCEPT { return yyla_.kind (); }
      /// Put in YYARG at most YYARGN of the expected tokens, and return the
      /// number of tokens stored in YYARG.  If YYARG is null, return the
      /// number of expected tokens (guaranteed to be less than YYNTOKENS).
      int expected_tokens (symbol_kind_type yyarg[], int yyargn) const;

    private:
      const  Parser& yyparser_;
      const symbol_type& yyla_;
    };

  private:
#if YY_CPLUSPLUS < 201103L
    /// Non copyable.
     Parser (const  Parser&);
    /// Non copyable.
     Parser& operator= (const  Parser&);
#endif


    /// Stored state numbers (used for stacks).
    typedef unsigned char state_type;

    /// The arguments of the error message.
    int yy_syntax_error_arguments_ (const context& yyctx,
                                    symbol_kind_type yyarg[], int yyargn) const;

    /// Generate an error message.
    /// \param yyctx     the context in which the error occurred.
    virtual std::string yysyntax_error_ (const context& yyctx) const;
    /// Compute post-reduction state.
    /// \param yystate   the current state
    /// \param yysym     the nonterminal to push on the stack
    static state_type yy_lr_goto_state_ (state_type yystate, int yysym);

    /// Whether the given \c yypact_ value indicates a defaulted state.
    /// \param yyvalue   the value to check
    static bool yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT;

    /// Whether the given \c yytable_ value indicates a syntax error.
    /// \param yyvalue   the value to check
    static bool yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT;

    static const signed char yypact_ninf_;
    static const signed char yytable_ninf_;

    /// Convert a scanner token kind \a t to a symbol kind.
    /// In theory \a t should be a token_kind_type, but character literals
    /// are valid, yet not members of the token_kind_type enum.
    static symbol_kind_type yytranslate_ (int t) YY_NOEXCEPT;

    /// Convert the symbol name \a n to a form suitable for a diagnostic.
    static std::string yytnamerr_ (const char *yystr);

    /// For a symbol, its name in clear.
    static const char* const yytname_[];


    // Tables.
    // YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
    // STATE-NUM.
    static const short yypact_[];

    // YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
    // Performed when YYTABLE does not specify something else to do.  Zero
    // means the default is an error.
    static const signed char yydefact_[];

    // YYPGOTO[NTERM-NUM].
    static const short yypgoto_[];

    // YYDEFGOTO[NTERM-NUM].
    static const signed char yydefgoto_[];

    // YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
    // positive, shift that token.  If negative, reduce the rule whose
    // number is the opposite.  If YYTABLE_NINF, syntax error.
    static const unsigned char yytable_[];

    static const short yycheck_[];

    // YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
    // state STATE-NUM.
    static const signed char yystos_[];

    // YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.
    static const signed char yyr1_[];

    // YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.
    static const signed char yyr2_[];


#if YYDEBUG
    // YYRLINE[YYN] -- Source line where rule number YYN was defined.
    static const short yyrline_[];
    /// Report on the debug stream that the rule \a r is going to be reduced.
    virtual void yy_reduce_print_ (int r) const;
    /// Print the state stack on the debug stream.
    virtual void yy_stack_print_ () const;

    /// Debugging level.
    int yydebug_;
    /// Debug stream.
    std::ostream* yycdebug_;

    /// \brief Display a symbol kind, value and location.
    /// \param yyo    The output stream.
    /// \param yysym  The symbol.
    template <typename Base>
    void yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const;
#endif

    /// \brief Reclaim the memory associated to a symbol.
    /// \param yymsg     Why this token is reclaimed.
    ///                  If null, print nothing.
    /// \param yysym     The symbol.
    template <typename Base>
    void yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const;

  private:
    /// Type access provider for state based symbols.
    struct by_state
    {
      /// Default constructor.
      by_state () YY_NOEXCEPT;

      /// The symbol kind as needed by the constructor.
      typedef state_type kind_type;

      /// Constructor.
      by_state (kind_type s) YY_NOEXCEPT;

      /// Copy constructor.
      by_state (const by_state& that) YY_NOEXCEPT;

      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol kind from \a that.
      void move (by_state& that);

      /// The symbol kind (corresponding to \a state).
      /// \a symbol_kind::S_YYEMPTY when empty.
      symbol_kind_type kind () const YY_NOEXCEPT;

      /// The state number used to denote an empty symbol.
      /// We use the initial state, as it does not have a value.
      enum { empty_state = 0 };

      /// The state.
      /// \a empty when empty.
      state_type state;
    };

    /// "Internal" symbol: element of the stack.
    struct stack_symbol_type : basic_symbol<by_state>
    {
      /// Superclass.
      typedef basic_symbol<by_state> super_type;
      /// Construct an empty symbol.
      stack_symbol_type ();
      /// Move or copy construction.
      stack_symbol_type (YY_RVREF (stack_symbol_type) that);
      /// Steal the contents from \a sym to build this.
      stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) sym);
#if YY_CPLUSPLUS < 201103L
      /// Assignment, needed by push_back by some old implementations.
      /// Moves the contents of that.
      stack_symbol_type& operator= (stack_symbol_type& that);

      /// Assignment, needed by push_back by other implementations.
      /// Needed by some other old implementations.
      stack_symbol_type& operator= (const stack_symbol_type& that);
#endif
    };

    /// A stack with random access from its top.
    template <typename T, typename S = std::vector<T> >
    class stack
    {
    public:
      // Hide our reversed order.
      typedef typename S::iterator iterator;
      typedef typename S::const_iterator const_iterator;
      typedef typename S::size_type size_type;
      typedef typename std::ptrdiff_t index_type;

      stack (size_type n = 200) YY_NOEXCEPT
        : seq_ (n)
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Non copyable.
      stack (const stack&) = delete;
      /// Non copyable.
      stack& operator= (const stack&) = delete;
#endif

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      const T&
      operator[] (index_type i) const
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      T&
      operator[] (index_type i)
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Steal the contents of \a t.
      ///
      /// Close to move-semantics.
      void
      push (YY_MOVE_REF (T) t)
      {
        seq_.push_back (T ());
        operator[] (0).move (t);
      }

      /// Pop elements from the stack.
      void
      pop (std::ptrdiff_t n = 1) YY_NOEXCEPT
      {
        for (; 0 < n; --n)
          seq_.pop_back ();
      }

      /// Pop all elements from the stack.
      void
      clear () YY_NOEXCEPT
      {
        seq_.clear ();
      }

      /// Number of elements on the stack.
      index_type
      size () const YY_NOEXCEPT
      {
        return index_type (seq_.size ());
      }

      /// Iterator on top of the stack (going downwards).
      const_iterator
      begin () const YY_NOEXCEPT
      {
        return seq_.begin ();
      }

      /// Bottom of the stack.
      const_iterator
      end () const YY_NOEXCEPT
      {
        return seq_.end ();
      }

      /// Present a slice of the top of a stack.
      class slice
      {
      public:
        slice (const stack& stack, index_type range) YY_NOEXCEPT
          : stack_ (stack)
          , range_ (range)
        {}

        const T&
        operator[] (index_type i) const
        {
          return stack_[range_ - i];
        }

      private:
        const stack& stack_;
        index_type range_;
      };

    private:
#if YY_CPLUSPLUS < 201103L
      /// Non copyable.
      stack (const stack&);
      /// Non copyable.
      stack& operator= (const stack&);
#endif
      /// The wrapped container.
      S seq_;
    };


    /// Stack type.
    typedef stack<stack_symbol_type> stack_type;

    /// The stack.
    stack_type yystack_;

    /// Push a new state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param sym  the symbol
    /// \warning the contents of \a s.value is stolen.
    void yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym);

    /// Push a new look ahead token on the state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param s    the state
    /// \param sym  the symbol (for its value and location).
    /// \warning the contents of \a sym.value is stolen.
    void yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym);

    /// Pop \a n symbols from the stack.
    void yypop_ (int n = 1) YY_NOEXCEPT;

    /// Constants.
    enum
    {
      yylast_ = 169,     ///< Last index in yytable_.
      yynnts_ = 32,  ///< Number of nonterminal symbols.
      yyfinal_ = 4 ///< Termination state number.
    };


    // User arguments.
    MiniJavaLexer& lexer;
    Ast::Node*& root;

  };


#line 9 "MiniJavaParser.y"
} //  Expr 
#line 1972 "/home/josuedejesus/ProyectoCompiladores2/build/MiniJavaParser.hpp"




#endif // !YY_YY_HOME_JOSUEDEJESUS_PROYECTOCOMPILADORES2_BUILD_MINIJAVAPARSER_HPP_INCLUDED
