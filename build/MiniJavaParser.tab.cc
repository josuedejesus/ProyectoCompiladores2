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

#line 61 "MiniJavaParser.tab.cc"


// "%code requires" blocks.
#line 11 "MiniJavaParser.y"

    #include <unordered_map>
    #include "MiniJavaAst.hpp"
    class MiniJavaLexer;

    

#line 73 "MiniJavaParser.tab.cc"


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
#line 209 "MiniJavaParser.tab.cc"




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

    static const unsigned char yycheck_[];

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
#line 1988 "MiniJavaParser.tab.cc"








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
#line 2068 "MiniJavaParser.tab.cc"

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
#line 2903 "MiniJavaParser.tab.cc"
    break;

  case 3: // class_body: class_body class_member
#line 119 "MiniJavaParser.y"
                                    {
    yylhs.value.as < Ast::Node * > () = new Ast::NodeList(yystack_[1].value.as < Ast::Node * > (), yystack_[0].value.as < Ast::Node * > ());
}
#line 2911 "MiniJavaParser.tab.cc"
    break;

  case 4: // class_body: class_member
#line 121 "MiniJavaParser.y"
                 {
    yylhs.value.as < Ast::Node * > () = new Ast::NodeList(yystack_[0].value.as < Ast::Node * > (), nullptr);
}
#line 2919 "MiniJavaParser.tab.cc"
    break;

  case 5: // class_body: %empty
#line 123 "MiniJavaParser.y"
              {
    yylhs.value.as < Ast::Node * > () = nullptr;
}
#line 2927 "MiniJavaParser.tab.cc"
    break;

  case 6: // class_member: method_declaration
#line 127 "MiniJavaParser.y"
                                 {
    yylhs.value.as < Ast::Node * > () = yystack_[0].value.as < Ast::Node * > ();
}
#line 2935 "MiniJavaParser.tab.cc"
    break;

  case 7: // class_member: array_decl
#line 129 "MiniJavaParser.y"
               {
    if (auto arrayDecl = dynamic_cast<Ast::ArrayDeclaration*>(yystack_[0].value.as < Ast::Node * > ())) {
        arrayDecl->is_global = true;
    }
    yylhs.value.as < Ast::Node * > () = yystack_[0].value.as < Ast::Node * > ();
}
#line 2946 "MiniJavaParser.tab.cc"
    break;

  case 8: // class_member: variable_decl
#line 134 "MiniJavaParser.y"
                  {
    yylhs.value.as < Ast::Node * > () = yystack_[0].value.as < Ast::Node * > ();
}
#line 2954 "MiniJavaParser.tab.cc"
    break;

  case 9: // method_declaration: method_return_type "identifier" "(" opt_parameter_list ")" "{" block "}"
#line 142 "MiniJavaParser.y"
                                                                                                                     {
    yylhs.value.as < Ast::Node * > () = new Ast::MethodDeclaration(yystack_[7].value.as < Ast::Node * > (), yystack_[6].value.as < std::string > (), yystack_[4].value.as < Ast::Node * > (), yystack_[1].value.as < Ast::Node * > ());
}
#line 2962 "MiniJavaParser.tab.cc"
    break;

  case 10: // method_declaration: method_return_type "identifier" "(" ")" "{" block "}"
#line 144 "MiniJavaParser.y"
                                                                                  {
    yylhs.value.as < Ast::Node * > () = new Ast::MethodDeclaration(yystack_[6].value.as < Ast::Node * > (), yystack_[5].value.as < std::string > (), nullptr, yystack_[1].value.as < Ast::Node * > ());
}
#line 2970 "MiniJavaParser.tab.cc"
    break;

  case 11: // variable_decl: type variable_list ";"
#line 148 "MiniJavaParser.y"
                                            {
    yylhs.value.as < Ast::Node * > () = new Ast::VariableDeclaration(yystack_[1].value.as < Ast::Node * > ());
}
#line 2978 "MiniJavaParser.tab.cc"
    break;

  case 12: // variable_list: "identifier"
#line 152 "MiniJavaParser.y"
                          {
    yylhs.value.as < Ast::Node * > () = new Ast::VariableList(false, yystack_[0].value.as < std::string > (), nullptr);
}
#line 2986 "MiniJavaParser.tab.cc"
    break;

  case 13: // variable_list: "identifier" "," variable_list
#line 154 "MiniJavaParser.y"
                                   {
    yylhs.value.as < Ast::Node * > () = new Ast::VariableList(false, yystack_[2].value.as < std::string > (), yystack_[0].value.as < Ast::Node * > ());
}
#line 2994 "MiniJavaParser.tab.cc"
    break;

  case 14: // array_decl: "int" "[" "number" "]" "identifier" ";"
#line 158 "MiniJavaParser.y"
                                                                             {
    yylhs.value.as < Ast::Node * > () = new Ast::ArrayDeclaration(false, yystack_[1].value.as < std::string > (), yystack_[3].value.as < int > ());
}
#line 3002 "MiniJavaParser.tab.cc"
    break;

  case 15: // array_variable: "identifier" "[" expr "]"
#line 162 "MiniJavaParser.y"
                                                           {
    yylhs.value.as < Ast::Expr * > () = new Ast::ArrayVariable(yystack_[3].value.as < std::string > (), yystack_[1].value.as < Ast::Expr * > ());
}
#line 3010 "MiniJavaParser.tab.cc"
    break;

  case 16: // method_return_type: "void"
#line 166 "MiniJavaParser.y"
                            {
    yylhs.value.as < Ast::Node * > () = new Ast::Type("void");
}
#line 3018 "MiniJavaParser.tab.cc"
    break;

  case 17: // method_return_type: "int"
#line 168 "MiniJavaParser.y"
           {
    yylhs.value.as < Ast::Node * > () = new Ast::Type("int");
}
#line 3026 "MiniJavaParser.tab.cc"
    break;

  case 19: // opt_parameter_list: parameter
#line 174 "MiniJavaParser.y"
                              {
    yylhs.value.as < Ast::Node * > () = new Ast::ParameterList(yystack_[0].value.as < Ast::Node * > (), nullptr);
}
#line 3034 "MiniJavaParser.tab.cc"
    break;

  case 20: // opt_parameter_list: opt_parameter_list "," parameter
#line 176 "MiniJavaParser.y"
                                       {
    yylhs.value.as < Ast::Node * > () = new Ast::ParameterList(yystack_[2].value.as < Ast::Node * > (), yystack_[0].value.as < Ast::Node * > ());
}
#line 3042 "MiniJavaParser.tab.cc"
    break;

  case 21: // parameter: "int" "identifier"
#line 180 "MiniJavaParser.y"
                             {
    yylhs.value.as < Ast::Node * > () = new Ast::Parameter(false, yystack_[0].value.as < std::string > ());
}
#line 3050 "MiniJavaParser.tab.cc"
    break;

  case 22: // parameter: "ref" "int" "identifier"
#line 182 "MiniJavaParser.y"
                             {
    yylhs.value.as < Ast::Node * > () = new Ast::Parameter(true, yystack_[0].value.as < std::string > ());
}
#line 3058 "MiniJavaParser.tab.cc"
    break;

  case 23: // parameter: "int" "[" expr "]" "identifier"
#line 184 "MiniJavaParser.y"
                                                      {
    yylhs.value.as < Ast::Node * > () = new Ast::ArrayParameter(false, yystack_[2].value.as < Ast::Expr * > (), yystack_[0].value.as < std::string > ());
}
#line 3066 "MiniJavaParser.tab.cc"
    break;

  case 24: // argument_list: argument
#line 188 "MiniJavaParser.y"
                        {
    yylhs.value.as < Ast::Node * > () = new Ast::ArgumentList(yystack_[0].value.as < Ast::Node * > (), nullptr);
}
#line 3074 "MiniJavaParser.tab.cc"
    break;

  case 25: // argument_list: argument_list "," argument
#line 190 "MiniJavaParser.y"
                                 {
    yylhs.value.as < Ast::Node * > () = new Ast::ArgumentList(yystack_[2].value.as < Ast::Node * > (), yystack_[0].value.as < Ast::Node * > ());
}
#line 3082 "MiniJavaParser.tab.cc"
    break;

  case 26: // argument: expr
#line 194 "MiniJavaParser.y"
               {
    yylhs.value.as < Ast::Node * > () = new Ast::Argument(false, "", yystack_[0].value.as < Ast::Expr * > ());
}
#line 3090 "MiniJavaParser.tab.cc"
    break;

  case 27: // argument: "ref" "identifier"
#line 196 "MiniJavaParser.y"
                      {
    yylhs.value.as < Ast::Node * > () = new Ast::Argument(true, yystack_[0].value.as < std::string > (), nullptr);
}
#line 3098 "MiniJavaParser.tab.cc"
    break;

  case 28: // block: statement_list
#line 201 "MiniJavaParser.y"
                      { 
    yylhs.value.as < Ast::Node * > () = yystack_[0].value.as < Ast::Node * > (); 
}
#line 3106 "MiniJavaParser.tab.cc"
    break;

  case 29: // block: %empty
#line 203 "MiniJavaParser.y"
              {
    yylhs.value.as < Ast::Node * > () = nullptr; 
}
#line 3114 "MiniJavaParser.tab.cc"
    break;

  case 30: // statement_list: statement
#line 207 "MiniJavaParser.y"
                          {
    yylhs.value.as < Ast::Node * > () = new Ast::NodeList(yystack_[0].value.as < Ast::Node * > (), nullptr);
}
#line 3122 "MiniJavaParser.tab.cc"
    break;

  case 31: // statement_list: statement_list statement
#line 209 "MiniJavaParser.y"
                             {
    yylhs.value.as < Ast::Node * > () = new Ast::NodeList(yystack_[1].value.as < Ast::Node * > (), yystack_[0].value.as < Ast::Node * > ());
}
#line 3130 "MiniJavaParser.tab.cc"
    break;

  case 32: // statement: declaration
#line 213 "MiniJavaParser.y"
                       {
    yylhs.value.as < Ast::Node * > () = yystack_[0].value.as < Ast::Node * > ();
}
#line 3138 "MiniJavaParser.tab.cc"
    break;

  case 33: // statement: method_call
#line 215 "MiniJavaParser.y"
                {
    yylhs.value.as < Ast::Node * > () = yystack_[0].value.as < Ast::Node * > ();
}
#line 3146 "MiniJavaParser.tab.cc"
    break;

  case 34: // statement: assign_stmt
#line 217 "MiniJavaParser.y"
                {
    yylhs.value.as < Ast::Node * > () = yystack_[0].value.as < Ast::Node * > ();
}
#line 3154 "MiniJavaParser.tab.cc"
    break;

  case 35: // statement: if_stmt
#line 219 "MiniJavaParser.y"
            {
    yylhs.value.as < Ast::Node * > () = yystack_[0].value.as < Ast::Node * > ();
}
#line 3162 "MiniJavaParser.tab.cc"
    break;

  case 36: // statement: while_stmt
#line 221 "MiniJavaParser.y"
               {
    yylhs.value.as < Ast::Node * > () = yystack_[0].value.as < Ast::Node * > ();
}
#line 3170 "MiniJavaParser.tab.cc"
    break;

  case 37: // statement: print_stmt
#line 223 "MiniJavaParser.y"
               {
    yylhs.value.as < Ast::Node * > () = yystack_[0].value.as < Ast::Node * > ();
}
#line 3178 "MiniJavaParser.tab.cc"
    break;

  case 38: // statement: return_stmt
#line 225 "MiniJavaParser.y"
                {
    yylhs.value.as < Ast::Node * > () = yystack_[0].value.as < Ast::Node * > ();
}
#line 3186 "MiniJavaParser.tab.cc"
    break;

  case 39: // declaration: array_decl
#line 230 "MiniJavaParser.y"
             { yylhs.value.as < Ast::Node * > () = yystack_[0].value.as < Ast::Node * > (); }
#line 3192 "MiniJavaParser.tab.cc"
    break;

  case 40: // declaration: variable_decl
#line 230 "MiniJavaParser.y"
                          { yylhs.value.as < Ast::Node * > () = yystack_[0].value.as < Ast::Node * > (); }
#line 3198 "MiniJavaParser.tab.cc"
    break;

  case 41: // assign_stmt: "identifier" "=" expr ";"
#line 232 "MiniJavaParser.y"
                                                 {
    yylhs.value.as < Ast::Node * > () = new Ast::Assignment(yystack_[3].value.as < std::string > (), yystack_[1].value.as < Ast::Expr * > ());
}
#line 3206 "MiniJavaParser.tab.cc"
    break;

  case 42: // assign_stmt: "identifier" "[" expr "]" "=" expr ";"
#line 234 "MiniJavaParser.y"
                                                                        {
    yylhs.value.as < Ast::Node * > () = new Ast::ArrayAssignment(yystack_[6].value.as < std::string > (), yystack_[4].value.as < Ast::Expr * > (), yystack_[1].value.as < Ast::Expr * > ());
}
#line 3214 "MiniJavaParser.tab.cc"
    break;

  case 43: // method_call: "identifier" "(" argument_list ")" ";"
#line 240 "MiniJavaParser.y"
                                                                   {
    yylhs.value.as < Ast::Node * > () = new Ast::MethodCall(yystack_[4].value.as < std::string > (), yystack_[2].value.as < Ast::Node * > ());
}
#line 3222 "MiniJavaParser.tab.cc"
    break;

  case 44: // method_call: "identifier" "(" ")" ";"
#line 242 "MiniJavaParser.y"
                                            {
    yylhs.value.as < Ast::Node * > () = new Ast::MethodCall(yystack_[3].value.as < std::string > (), nullptr);
}
#line 3230 "MiniJavaParser.tab.cc"
    break;

  case 45: // if_stmt: "if" "(" boolean_expr ")" "{" block "}"
#line 246 "MiniJavaParser.y"
                                                                            {
    yylhs.value.as < Ast::Node * > () = new Ast::IfStmt(yystack_[4].value.as < Ast::BooleanExpr * > (), yystack_[1].value.as < Ast::Node * > (), nullptr);
}
#line 3238 "MiniJavaParser.tab.cc"
    break;

  case 46: // if_stmt: "if" "(" boolean_expr ")" "{" block "}" "else" "{" statement "}"
#line 248 "MiniJavaParser.y"
                                                                                                                {
    yylhs.value.as < Ast::Node * > () = new Ast::IfStmt(yystack_[8].value.as < Ast::BooleanExpr * > (), yystack_[5].value.as < Ast::Node * > (), yystack_[1].value.as < Ast::Node * > ());
}
#line 3246 "MiniJavaParser.tab.cc"
    break;

  case 47: // while_stmt: "while" "(" boolean_expr ")" "{" block "}"
#line 252 "MiniJavaParser.y"
                                                                                  {
    yylhs.value.as < Ast::Node * > () = new Ast::WhileStmt(yystack_[4].value.as < Ast::BooleanExpr * > (), yystack_[1].value.as < Ast::Node * > ());
}
#line 3254 "MiniJavaParser.tab.cc"
    break;

  case 48: // print_stmt: "print" "(" "string literal" ")" ";"
#line 256 "MiniJavaParser.y"
                                                                 {
    yylhs.value.as < Ast::Node * > () = new Ast::PrintStmtLit(yystack_[2].value.as < std::string > ());
}
#line 3262 "MiniJavaParser.tab.cc"
    break;

  case 49: // print_stmt: "print" "(" expr ")" ";"
#line 258 "MiniJavaParser.y"
                                               {
    yylhs.value.as < Ast::Node * > () = new Ast::PrintStmt(yystack_[2].value.as < Ast::Expr * > ());
}
#line 3270 "MiniJavaParser.tab.cc"
    break;

  case 50: // return_stmt: "return" expr ";"
#line 262 "MiniJavaParser.y"
                                      {
    yylhs.value.as < Ast::Node * > () = new Ast::ReturnStmt(yystack_[1].value.as < Ast::Expr * > ());
}
#line 3278 "MiniJavaParser.tab.cc"
    break;

  case 51: // boolean_expr: boolean_expr "||" boolean_term
#line 268 "MiniJavaParser.y"
                                                   {  
    yylhs.value.as < Ast::BooleanExpr * > () = new Ast::OrExpr(yystack_[2].value.as < Ast::BooleanExpr * > (), yystack_[0].value.as < Ast::BooleanExpr * > ()); 
}
#line 3286 "MiniJavaParser.tab.cc"
    break;

  case 52: // boolean_expr: boolean_term
#line 270 "MiniJavaParser.y"
                 {
    yylhs.value.as < Ast::BooleanExpr * > () = yystack_[0].value.as < Ast::BooleanExpr * > ();  
}
#line 3294 "MiniJavaParser.tab.cc"
    break;

  case 53: // boolean_term: boolean_term "&&" boolean_factor
#line 274 "MiniJavaParser.y"
                                                      {  
    yylhs.value.as < Ast::BooleanExpr * > () = new Ast::AndExpr(yystack_[2].value.as < Ast::BooleanExpr * > (), yystack_[0].value.as < Ast::BooleanExpr * > ()); 
}
#line 3302 "MiniJavaParser.tab.cc"
    break;

  case 54: // boolean_term: boolean_factor
#line 276 "MiniJavaParser.y"
                   {
    yylhs.value.as < Ast::BooleanExpr * > () = yystack_[0].value.as < Ast::BooleanExpr * > ();
}
#line 3310 "MiniJavaParser.tab.cc"
    break;

  case 55: // boolean_factor: relational_expr
#line 280 "MiniJavaParser.y"
                                {  
    yylhs.value.as < Ast::BooleanExpr * > () = yystack_[0].value.as < Ast::RelationalExpr * > ();  
}
#line 3318 "MiniJavaParser.tab.cc"
    break;

  case 56: // relational_expr: expr ">" expr
#line 284 "MiniJavaParser.y"
                                           {
        yylhs.value.as < Ast::RelationalExpr * > () = new Ast::GreaterExpr(yystack_[2].value.as < Ast::Expr * > (), yystack_[0].value.as < Ast::Expr * > ());
    }
#line 3326 "MiniJavaParser.tab.cc"
    break;

  case 57: // relational_expr: expr ">=" expr
#line 286 "MiniJavaParser.y"
                                   {
        yylhs.value.as < Ast::RelationalExpr * > () = new Ast::GreaterEqualExpr(yystack_[2].value.as < Ast::Expr * > (), yystack_[0].value.as < Ast::Expr * > ());
    }
#line 3334 "MiniJavaParser.tab.cc"
    break;

  case 58: // relational_expr: expr "<" expr
#line 288 "MiniJavaParser.y"
                               {
        yylhs.value.as < Ast::RelationalExpr * > () = new Ast::LessExpr(yystack_[2].value.as < Ast::Expr * > (), yystack_[0].value.as < Ast::Expr * > ());
    }
#line 3342 "MiniJavaParser.tab.cc"
    break;

  case 59: // relational_expr: expr "<=" expr
#line 290 "MiniJavaParser.y"
                                {
        yylhs.value.as < Ast::RelationalExpr * > () = new Ast::LessEqualExpr(yystack_[2].value.as < Ast::Expr * > (), yystack_[0].value.as < Ast::Expr * > ());
    }
#line 3350 "MiniJavaParser.tab.cc"
    break;

  case 60: // relational_expr: expr "!=" expr
#line 292 "MiniJavaParser.y"
                               {
        yylhs.value.as < Ast::RelationalExpr * > () = new Ast::NotEqualExpr(yystack_[2].value.as < Ast::Expr * > (), yystack_[0].value.as < Ast::Expr * > ());
    }
#line 3358 "MiniJavaParser.tab.cc"
    break;

  case 61: // relational_expr: expr "==" expr
#line 294 "MiniJavaParser.y"
                           {
        yylhs.value.as < Ast::RelationalExpr * > () = new Ast::EqualExpr(yystack_[2].value.as < Ast::Expr * > (), yystack_[0].value.as < Ast::Expr * > ());
    }
#line 3366 "MiniJavaParser.tab.cc"
    break;

  case 62: // expr: expr "+" term
#line 299 "MiniJavaParser.y"
                  { 
        yylhs.value.as < Ast::Expr * > () = new Ast::AddExpr(yystack_[2].value.as < Ast::Expr * > (), yystack_[0].value.as < Ast::Expr * > ()); 
    }
#line 3374 "MiniJavaParser.tab.cc"
    break;

  case 63: // expr: expr "-" term
#line 301 "MiniJavaParser.y"
                      { 
        yylhs.value.as < Ast::Expr * > () = new Ast::SubExpr(yystack_[2].value.as < Ast::Expr * > (), yystack_[0].value.as < Ast::Expr * > ()); 
    }
#line 3382 "MiniJavaParser.tab.cc"
    break;

  case 64: // expr: term
#line 303 "MiniJavaParser.y"
            { yylhs.value.as < Ast::Expr * > () = yystack_[0].value.as < Ast::Expr * > (); }
#line 3388 "MiniJavaParser.tab.cc"
    break;

  case 65: // term: term "*" factor
#line 306 "MiniJavaParser.y"
                       { 
        yylhs.value.as < Ast::Expr * > () = new Ast::MulExpr(yystack_[2].value.as < Ast::Expr * > (), yystack_[0].value.as < Ast::Expr * > ());
    }
#line 3396 "MiniJavaParser.tab.cc"
    break;

  case 66: // term: term "/" factor
#line 308 "MiniJavaParser.y"
                           {
        yylhs.value.as < Ast::Expr * > () = new Ast::DivExpr(yystack_[2].value.as < Ast::Expr * > (), yystack_[0].value.as < Ast::Expr * > ());
    }
#line 3404 "MiniJavaParser.tab.cc"
    break;

  case 67: // term: term "%" factor
#line 310 "MiniJavaParser.y"
                           {
        yylhs.value.as < Ast::Expr * > () = new Ast::ModExpr(yystack_[2].value.as < Ast::Expr * > (), yystack_[0].value.as < Ast::Expr * > ());
    }
#line 3412 "MiniJavaParser.tab.cc"
    break;

  case 68: // term: factor
#line 312 "MiniJavaParser.y"
               { 
        yylhs.value.as < Ast::Expr * > () = yystack_[0].value.as < Ast::Expr * > ();
    }
#line 3420 "MiniJavaParser.tab.cc"
    break;

  case 69: // factor: "number"
#line 316 "MiniJavaParser.y"
                  { 
    yylhs.value.as < Ast::Expr * > () = new Ast::Number(yystack_[0].value.as < int > ());
}
#line 3428 "MiniJavaParser.tab.cc"
    break;

  case 70: // factor: "(" expr ")"
#line 318 "MiniJavaParser.y"
                            { 
    yylhs.value.as < Ast::Expr * > () = yystack_[1].value.as < Ast::Expr * > ();
}
#line 3436 "MiniJavaParser.tab.cc"
    break;

  case 71: // factor: "identifier"
#line 320 "MiniJavaParser.y"
               {
    yylhs.value.as < Ast::Expr * > () = new Ast::Identifier(yystack_[0].value.as < std::string > ());
}
#line 3444 "MiniJavaParser.tab.cc"
    break;

  case 72: // factor: array_variable
#line 322 "MiniJavaParser.y"
                   {
    yylhs.value.as < Ast::Expr * > () = yystack_[0].value.as < Ast::Expr * > ();
}
#line 3452 "MiniJavaParser.tab.cc"
    break;

  case 73: // factor: "identifier" "(" argument_list ")"
#line 324 "MiniJavaParser.y"
                                                {
    yylhs.value.as < Ast::Expr * > () = new Ast::FunctionCall(yystack_[3].value.as < std::string > (), yystack_[1].value.as < Ast::Node * > ());
}
#line 3460 "MiniJavaParser.tab.cc"
    break;

  case 74: // factor: "identifier" "(" ")"
#line 326 "MiniJavaParser.y"
                                  {
    yylhs.value.as < Ast::Expr * > () = new Ast::FunctionCall(yystack_[2].value.as < std::string > (), nullptr);
}
#line 3468 "MiniJavaParser.tab.cc"
    break;


#line 3472 "MiniJavaParser.tab.cc"

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


  const signed char  Parser::yypact_ninf_ = -66;

  const signed char  Parser::yytable_ninf_ = -1;

  const short
   Parser::yypact_[] =
  {
       4,     1,    62,    43,   -66,     8,    75,   -66,    83,   -66,
     -66,   -66,   -66,    71,    88,    84,    91,   -66,    86,    97,
      99,   103,   -66,    36,    88,   -66,    98,    74,   117,   105,
     -12,   -66,   -66,   104,    73,   -66,   102,    34,   108,    25,
     -66,    73,   -66,    96,   -66,     2,   112,   -66,   -66,    75,
     113,   114,    73,   115,    24,   -66,   -66,   111,    34,   -66,
     -66,   -66,   -66,   -66,   -66,   -66,   -66,    34,   -66,    16,
      40,    73,    73,    73,   109,    73,    73,    73,    73,    73,
       0,    -7,    73,    45,    73,   -66,   -66,   116,   -66,   110,
     -66,    77,   -66,   124,     9,   112,   112,   -66,   -66,   -66,
     -66,     6,   136,   -66,   -66,    82,    14,   -66,   119,    22,
       5,   118,    78,    11,   -66,   -66,   -66,    42,   -66,    73,
     121,    73,    73,    73,    73,    73,    73,    73,   122,   123,
     125,   -66,   -66,   126,   142,   -66,   136,    34,   -66,   124,
     124,   124,   124,   124,   124,    34,   -66,   -66,   -66,    73,
     128,   129,     7,   132,   -66,   -66,   131,    34,   133,   -66
  };

  const signed char
   Parser::yydefact_[] =
  {
       0,     0,     0,     0,     1,     5,    17,    16,     0,     4,
       6,     8,     7,     0,     0,     0,     0,     3,     0,    12,
       0,     0,     2,     0,     0,    11,     0,     0,     0,     0,
       0,    19,    13,     0,     0,    21,     0,    29,     0,     0,
      14,     0,    69,    71,    72,     0,    64,    68,    22,    18,
       0,     0,     0,     0,     0,    40,    39,     0,    28,    30,
      32,    34,    33,    35,    36,    37,    38,    29,    20,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    10,    31,     0,    70,     0,
      74,     0,    24,    26,     0,    62,    63,    23,    65,    66,
      67,     0,    52,    54,    55,     0,     0,    50,     0,     0,
       0,     0,     0,     0,     9,    27,    73,     0,    15,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    41,    44,     0,     0,    25,    51,    29,    53,    61,
      60,    56,    57,    58,    59,    29,    48,    49,    43,     0,
       0,     0,     0,    45,    47,    42,     0,     0,     0,    46
  };

  const short
   Parser::yypgoto_[] =
  {
     -66,   -66,   -66,   143,   -66,    59,   134,    79,   -66,   -66,
     -66,   -66,   130,    81,    39,   -65,   -66,   -57,   -66,   -66,
     -66,   -66,   -66,   -66,   -66,    89,    48,    44,   -66,   -34,
      57,    46
  };

  const signed char
   Parser::yydefgoto_[] =
  {
       0,     2,     8,     9,    10,    55,    20,    56,    44,    13,
      14,    30,    31,    91,    92,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,   101,   102,   103,   104,   105,
      46,    47
  };

  const unsigned char
   Parser::yytable_[] =
  {
      45,    86,    87,    72,    73,    72,    73,    69,    72,    73,
      72,    73,    72,    73,    72,    73,   119,    38,    80,    72,
      73,    41,     1,    39,   119,    72,    73,     6,     7,    42,
      43,   108,    82,    74,   107,   120,    93,    94,     3,   131,
     118,   155,   134,   128,    27,    88,    28,   109,   110,    93,
     113,   130,    83,    49,    84,    27,    50,    28,    51,    52,
      53,    89,     4,    89,    11,    29,    89,    11,    41,    90,
      41,    54,   150,    41,   111,     5,    42,    43,    42,    43,
     151,    42,    43,    93,    12,    72,    73,    12,   139,   140,
     141,   142,   143,   144,   122,   123,   124,   125,   126,   127,
     158,    41,     6,     7,    34,    15,   116,   133,    18,    42,
      43,    35,   117,   117,    23,   152,    16,    75,    76,    77,
      21,    98,    99,   100,    70,    19,    71,    72,    73,    95,
      96,    22,    24,    25,    26,    33,    36,    37,    40,    48,
      67,    78,    79,    81,    85,   121,    97,   115,   129,   114,
     149,    17,   132,   137,   145,   156,   135,   146,    32,   147,
     148,   153,   154,   157,   112,   138,   159,   136,   106,    68
  };

  const unsigned char
   Parser::yycheck_[] =
  {
      34,    58,    67,     3,     4,     3,     4,    41,     3,     4,
       3,     4,     3,     4,     3,     4,    10,    29,    52,     3,
       4,    28,    18,    35,    10,     3,     4,    19,    20,    36,
      37,    38,     8,    31,    34,    29,    70,    71,    37,    34,
      31,    34,    31,    29,    19,    29,    21,    81,    82,    83,
      84,    29,    28,    19,    30,    19,    22,    21,    24,    25,
      26,    21,     0,    21,     5,    29,    21,     8,    28,    29,
      28,    37,   137,    28,    29,    32,    36,    37,    36,    37,
     145,    36,    37,   117,     5,     3,     4,     8,   122,   123,
     124,   125,   126,   127,    12,    13,    14,    15,    16,    17,
     157,    28,    19,    20,    30,    30,    29,    29,    37,    36,
      37,    37,    35,    35,    28,   149,    33,     5,     6,     7,
      36,    75,    76,    77,    28,    37,    30,     3,     4,    72,
      73,    40,    35,    34,    31,    37,    19,    32,    34,    37,
      32,    28,    28,    28,    33,     9,    37,    37,    29,    33,
       8,     8,    34,    32,    32,    23,   117,    34,    24,    34,
      34,    33,    33,    32,    83,   121,    33,   119,    79,    39
  };

  const signed char
   Parser::yystos_[] =
  {
       0,    18,    42,    37,     0,    32,    19,    20,    43,    44,
      45,    46,    48,    50,    51,    30,    33,    44,    37,    37,
      47,    36,    40,    28,    35,    34,    31,    19,    21,    29,
      52,    53,    47,    37,    30,    37,    19,    32,    29,    35,
      34,    28,    36,    37,    49,    70,    71,    72,    37,    19,
      22,    24,    25,    26,    37,    46,    48,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    32,    53,    70,
      28,    30,     3,     4,    31,     5,     6,     7,    28,    28,
      70,    28,     8,    28,    30,    33,    58,    56,    29,    21,
      29,    54,    55,    70,    70,    71,    71,    37,    72,    72,
      72,    66,    67,    68,    69,    70,    66,    34,    38,    70,
      70,    29,    54,    70,    33,    37,    29,    35,    31,    10,
      29,     9,    12,    13,    14,    15,    16,    17,    29,    29,
      29,    34,    34,    29,    31,    55,    67,    32,    68,    70,
      70,    70,    70,    70,    70,    32,    34,    34,    34,     8,
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
#line 4094 "MiniJavaParser.tab.cc"

#line 329 "MiniJavaParser.y"
