/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "./syntax.y"


#include "stdio.h"
#include "syntax.tab.h"
#include "lex.yy.c"
#include "tree.h"
#include "semantic.h"

// extern struct ASTNode;
Node *root; //the root of the AST
int err_cnt = 0;

int yyerror(char*msg){
    printf("Error type B at Line %d: %s near %s.\n",yylineno,msg,yytext);
}
// int yyerror(char*msg){
//     printf("syntax error\n");
// }



#line 93 "./syntax.tab.c"

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

#include "syntax.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_INT = 3,                        /* INT  */
  YYSYMBOL_FLOAT = 4,                      /* FLOAT  */
  YYSYMBOL_ID = 5,                         /* ID  */
  YYSYMBOL_SEMI = 6,                       /* SEMI  */
  YYSYMBOL_COMMA = 7,                      /* COMMA  */
  YYSYMBOL_ASSIGNOP = 8,                   /* ASSIGNOP  */
  YYSYMBOL_RELOP = 9,                      /* RELOP  */
  YYSYMBOL_PLUS = 10,                      /* PLUS  */
  YYSYMBOL_MINUS = 11,                     /* MINUS  */
  YYSYMBOL_STAR = 12,                      /* STAR  */
  YYSYMBOL_DIV = 13,                       /* DIV  */
  YYSYMBOL_AND = 14,                       /* AND  */
  YYSYMBOL_OR = 15,                        /* OR  */
  YYSYMBOL_DOT = 16,                       /* DOT  */
  YYSYMBOL_NOT = 17,                       /* NOT  */
  YYSYMBOL_TYPE = 18,                      /* TYPE  */
  YYSYMBOL_LP = 19,                        /* LP  */
  YYSYMBOL_RP = 20,                        /* RP  */
  YYSYMBOL_LB = 21,                        /* LB  */
  YYSYMBOL_RB = 22,                        /* RB  */
  YYSYMBOL_LC = 23,                        /* LC  */
  YYSYMBOL_RC = 24,                        /* RC  */
  YYSYMBOL_STRUCT = 25,                    /* STRUCT  */
  YYSYMBOL_RETURN = 26,                    /* RETURN  */
  YYSYMBOL_IF = 27,                        /* IF  */
  YYSYMBOL_ELSE = 28,                      /* ELSE  */
  YYSYMBOL_WHILE = 29,                     /* WHILE  */
  YYSYMBOL_LOWER_THAN_ELSE = 30,           /* LOWER_THAN_ELSE  */
  YYSYMBOL_YYACCEPT = 31,                  /* $accept  */
  YYSYMBOL_Program = 32,                   /* Program  */
  YYSYMBOL_ExtDefList = 33,                /* ExtDefList  */
  YYSYMBOL_ExtDef = 34,                    /* ExtDef  */
  YYSYMBOL_ExtDecList = 35,                /* ExtDecList  */
  YYSYMBOL_Specifier = 36,                 /* Specifier  */
  YYSYMBOL_StructSpecifier = 37,           /* StructSpecifier  */
  YYSYMBOL_OptTag = 38,                    /* OptTag  */
  YYSYMBOL_Tag = 39,                       /* Tag  */
  YYSYMBOL_VarDec = 40,                    /* VarDec  */
  YYSYMBOL_FunDec = 41,                    /* FunDec  */
  YYSYMBOL_VarList = 42,                   /* VarList  */
  YYSYMBOL_ParamDec = 43,                  /* ParamDec  */
  YYSYMBOL_CompSt = 44,                    /* CompSt  */
  YYSYMBOL_StmtList = 45,                  /* StmtList  */
  YYSYMBOL_Stmt = 46,                      /* Stmt  */
  YYSYMBOL_DefList = 47,                   /* DefList  */
  YYSYMBOL_Def = 48,                       /* Def  */
  YYSYMBOL_DecList = 49,                   /* DecList  */
  YYSYMBOL_Dec = 50,                       /* Dec  */
  YYSYMBOL_Exp = 51,                       /* Exp  */
  YYSYMBOL_Args = 52                       /* Args  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
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


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  16
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   435

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  31
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  93
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  165

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   285


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
      25,    26,    27,    28,    29,    30
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    75,    75,    81,    86,    90,    94,    98,   103,   106,
     109,   112,   115,   118,   122,   126,   131,   137,   141,   146,
     150,   155,   160,   164,   171,   175,   180,   184,   188,   193,
     196,   200,   204,   209,   215,   220,   224,   229,   233,   237,
     241,   245,   249,   253,   258,   261,   264,   267,   270,   273,
     276,   281,   286,   290,   295,   298,   302,   306,   311,   315,
     321,   325,   329,   333,   337,   341,   345,   349,   353,   358,
     362,   366,   370,   374,   378,   382,   386,   390,   395,   398,
     401,   404,   407,   410,   413,   416,   419,   422,   425,   428,
     431,   434,   438,   442
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "INT", "FLOAT", "ID",
  "SEMI", "COMMA", "ASSIGNOP", "RELOP", "PLUS", "MINUS", "STAR", "DIV",
  "AND", "OR", "DOT", "NOT", "TYPE", "LP", "RP", "LB", "RB", "LC", "RC",
  "STRUCT", "RETURN", "IF", "ELSE", "WHILE", "LOWER_THAN_ELSE", "$accept",
  "Program", "ExtDefList", "ExtDef", "ExtDecList", "Specifier",
  "StructSpecifier", "OptTag", "Tag", "VarDec", "FunDec", "VarList",
  "ParamDec", "CompSt", "StmtList", "Stmt", "DefList", "Def", "DecList",
  "Dec", "Exp", "Args", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-109)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-38)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       5,    48,  -109,    17,    28,  -109,    56,    19,  -109,  -109,
    -109,  -109,    44,    36,    52,  -109,  -109,  -109,    90,    86,
    -109,    79,   143,     9,     9,  -109,    -4,  -109,    -4,    75,
    -109,    93,   125,    66,    83,    -4,  -109,  -109,    96,   107,
      -4,   125,   126,   138,   137,  -109,   142,  -109,  -109,  -109,
     141,   146,  -109,    60,   159,    94,   102,   164,  -109,  -109,
     158,  -109,    -4,  -109,  -109,  -109,  -109,     7,  -109,  -109,
     165,   155,   172,   177,   194,    51,    59,  -109,   161,    60,
     111,  -109,   291,  -109,  -109,   125,  -109,  -109,   150,  -109,
     414,  -109,   113,   167,   333,   186,   127,   173,   291,   166,
     291,  -109,  -109,   187,  -109,   199,   216,   221,   238,   243,
     260,   265,   282,   201,   287,   375,  -109,     6,  -109,   304,
     188,  -109,  -109,  -109,  -109,  -109,    87,   347,  -109,  -109,
     361,  -109,  -109,   375,  -109,   408,  -109,   414,  -109,   414,
    -109,   113,  -109,   113,  -109,   401,  -109,   388,  -109,   185,
     318,  -109,  -109,   291,  -109,  -109,    87,    87,  -109,  -109,
    -109,   181,  -109,    87,  -109
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,    17,    22,     0,     2,     0,     0,    18,     8,
      11,    12,     0,    23,     0,    20,     1,     3,     0,    24,
       6,     0,     0,     0,     0,    10,    52,     9,     0,     0,
       5,     0,     0,     0,     0,    52,     7,    13,     0,     0,
      52,     0,     0,    32,     0,    28,     0,    16,    24,    15,
       0,     0,    35,     0,     0,    58,     0,    56,    19,    51,
      33,    30,     0,    29,    27,    26,    25,     0,    76,    77,
      75,     0,     0,     0,     0,     0,     0,    39,     0,     0,
       0,    54,     0,    55,    53,     0,    31,    44,     0,    87,
      69,    88,    70,     0,     0,     0,     0,     0,     0,     0,
       0,    34,    36,     0,    38,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    59,    57,     0,    72,    93,
       0,    86,    68,    47,    46,    40,     0,     0,    49,    50,
       0,    45,    78,    60,    81,    63,    82,    64,    83,    65,
      84,    66,    85,    67,    79,    61,    80,    62,    74,     0,
       0,    90,    89,     0,    71,    48,     0,     0,    91,    73,
      92,    41,    43,     0,    42
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -109,  -109,     2,  -109,   180,    18,  -109,  -109,  -109,   -34,
    -109,   -20,  -109,    -8,   135,  -108,   112,  -109,   130,  -109,
     -71,    70
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     4,     5,     6,    21,     7,     8,    14,    15,    22,
      23,    42,    43,    77,    78,    79,    39,    40,    56,    57,
      80,   120
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      90,    92,    94,    96,    55,    -4,     1,    60,    17,    46,
      34,   115,   151,    87,     2,    36,    37,   119,   155,    12,
      18,     3,    13,     2,    19,    20,   152,   127,    16,   130,
       3,    52,    35,    47,   133,   135,   137,   139,   141,   143,
     145,   147,    86,   150,    38,    24,    41,    41,   161,   162,
      25,    55,    97,    38,     9,   164,    -4,     1,    38,   -21,
      99,    67,    -4,    68,    69,    70,     2,    50,    10,    51,
      98,    71,    11,     3,     2,    26,    44,    72,   100,    73,
      41,     3,   119,    35,   -37,    30,    74,    75,    67,    76,
      68,    69,    70,     2,     1,    45,    27,    54,    71,    -4,
       3,    48,    82,    83,    72,    29,    73,    52,    84,    28,
      35,     2,   103,    74,    75,    33,    76,   104,     3,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   124,   113,
      48,    58,   114,   125,   114,   105,   106,   107,   108,   109,
     110,   111,   112,   113,    31,    62,    61,    53,   114,   -14,
      32,   117,    59,    68,    69,    70,    89,    63,    68,    69,
      70,    71,    64,    65,    33,    81,    71,    72,    66,    73,
     118,    85,    72,    91,    73,    68,    69,    70,    93,    33,
      68,    69,    70,    71,    88,   101,   128,   121,    71,    72,
     129,    73,   123,   131,    72,    95,    73,    68,    69,    70,
     132,   126,    68,    69,    70,    71,   148,   158,   154,   163,
      71,    72,    49,    73,   102,   116,    72,   134,    73,    68,
      69,    70,   136,   160,    68,    69,    70,    71,     0,     0,
       0,     0,    71,    72,     0,    73,     0,     0,    72,   138,
      73,    68,    69,    70,   140,     0,    68,    69,    70,    71,
       0,     0,     0,     0,    71,    72,     0,    73,     0,     0,
      72,   142,    73,    68,    69,    70,   144,     0,    68,    69,
      70,    71,     0,     0,     0,     0,    71,    72,     0,    73,
       0,     0,    72,   146,    73,    68,    69,    70,   149,     0,
      68,    69,    70,    71,    68,    69,    70,     0,    71,    72,
       0,    73,    71,     0,    72,     0,    73,     0,    72,     0,
      73,   153,   105,   106,   107,   108,   109,   110,   111,   112,
     113,     0,     0,     0,     0,   114,   105,   106,   107,   108,
     109,   110,   111,   112,   113,     0,     0,     0,     0,   114,
     159,   105,   106,   107,   108,   109,   110,   111,   112,   113,
       0,     0,     0,   122,   114,   105,   106,   107,   108,   109,
     110,   111,   112,   113,     0,     0,     0,   156,   114,   105,
     106,   107,   108,   109,   110,   111,   112,   113,     0,     0,
       0,   157,   114,   105,   106,   107,   108,   109,   110,   111,
     112,   113,     0,     0,     0,     0,   114,   106,   107,   108,
     109,   110,   111,     0,   113,     0,     0,     0,     0,   114,
     106,   107,   108,   109,   110,     0,     0,   113,   107,   108,
     109,   110,   114,     0,   113,     0,   109,   110,     0,   114,
     113,     0,     0,     0,     0,   114
};

static const yytype_int16 yycheck[] =
{
      71,    72,    73,    74,    38,     0,     1,    41,     6,    29,
       1,    82,     6,     6,    18,    23,    24,    88,   126,     1,
       1,    25,     5,    18,     5,     6,    20,    98,     0,   100,
      25,    24,    23,    31,   105,   106,   107,   108,   109,   110,
     111,   112,    62,   114,    26,     1,    28,    29,   156,   157,
       6,    85,     1,    35,     6,   163,     0,     1,    40,    23,
       1,     1,     6,     3,     4,     5,    18,     1,    20,     3,
      19,    11,    24,    25,    18,    23,     1,    17,    19,    19,
      62,    25,   153,    23,    24,     6,    26,    27,     1,    29,
       3,     4,     5,    18,     1,    20,     6,     1,    11,     6,
      25,     5,     8,     1,    17,    19,    19,    24,     6,    19,
      23,    18,     1,    26,    27,    21,    29,     6,    25,     8,
       9,    10,    11,    12,    13,    14,    15,    16,     1,    16,
       5,    24,    21,     6,    21,     8,     9,    10,    11,    12,
      13,    14,    15,    16,     1,     7,    20,    35,    21,     6,
       7,     1,    40,     3,     4,     5,     1,    20,     3,     4,
       5,    11,    20,    22,    21,     6,    11,    17,    22,    19,
      20,     7,    17,     1,    19,     3,     4,     5,     1,    21,
       3,     4,     5,    11,    19,    24,    20,    20,    11,    17,
      24,    19,     6,     6,    17,     1,    19,     3,     4,     5,
       1,    28,     3,     4,     5,    11,     5,    22,    20,    28,
      11,    17,    32,    19,    79,    85,    17,     1,    19,     3,
       4,     5,     1,   153,     3,     4,     5,    11,    -1,    -1,
      -1,    -1,    11,    17,    -1,    19,    -1,    -1,    17,     1,
      19,     3,     4,     5,     1,    -1,     3,     4,     5,    11,
      -1,    -1,    -1,    -1,    11,    17,    -1,    19,    -1,    -1,
      17,     1,    19,     3,     4,     5,     1,    -1,     3,     4,
       5,    11,    -1,    -1,    -1,    -1,    11,    17,    -1,    19,
      -1,    -1,    17,     1,    19,     3,     4,     5,     1,    -1,
       3,     4,     5,    11,     3,     4,     5,    -1,    11,    17,
      -1,    19,    11,    -1,    17,    -1,    19,    -1,    17,    -1,
      19,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    -1,    -1,    -1,    -1,    21,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    -1,    -1,    -1,    -1,    21,
      22,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      -1,    -1,    -1,    20,    21,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    -1,    -1,    -1,    20,    21,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    -1,    -1,
      -1,    20,    21,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    -1,    -1,    -1,    -1,    21,     9,    10,    11,
      12,    13,    14,    -1,    16,    -1,    -1,    -1,    -1,    21,
       9,    10,    11,    12,    13,    -1,    -1,    16,    10,    11,
      12,    13,    21,    -1,    16,    -1,    12,    13,    -1,    21,
      16,    -1,    -1,    -1,    -1,    21
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,    18,    25,    32,    33,    34,    36,    37,     6,
      20,    24,    36,     5,    38,    39,     0,    33,     1,     5,
       6,    35,    40,    41,     1,     6,    23,     6,    19,    19,
       6,     1,     7,    21,     1,    23,    44,    44,    36,    47,
      48,    36,    42,    43,     1,    20,    42,    33,     5,    35,
       1,     3,    24,    47,     1,    40,    49,    50,    24,    47,
      40,    20,     7,    20,    20,    22,    22,     1,     3,     4,
       5,    11,    17,    19,    26,    27,    29,    44,    45,    46,
      51,     6,     8,     1,     6,     7,    42,     6,    19,     1,
      51,     1,    51,     1,    51,     1,    51,     1,    19,     1,
      19,    24,    45,     1,     6,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    21,    51,    49,     1,    20,    51,
      52,    20,    20,     6,     1,     6,    28,    51,    20,    24,
      51,     6,     1,    51,     1,    51,     1,    51,     1,    51,
       1,    51,     1,    51,     1,    51,     1,    51,     5,     1,
      51,     6,    20,     7,    20,    46,    20,    20,    22,    22,
      52,    46,    46,    28,    46
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    31,    32,    33,    33,    34,    34,    34,    34,    34,
      34,    34,    34,    34,    35,    35,    35,    36,    36,    37,
      37,    38,    38,    39,    40,    40,    40,    41,    41,    41,
      41,    42,    42,    43,    44,    44,    45,    45,    46,    46,
      46,    46,    46,    46,    46,    46,    46,    46,    46,    46,
      46,    47,    47,    48,    48,    48,    49,    49,    50,    50,
      51,    51,    51,    51,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    51,    51,    51,    51,    51,    51,
      51,    51,    52,    52
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     0,     3,     2,     3,     2,     3,
       3,     2,     2,     4,     1,     3,     3,     1,     1,     5,
       2,     1,     0,     1,     1,     4,     4,     4,     3,     4,
       4,     3,     1,     2,     4,     2,     2,     0,     2,     1,
       3,     5,     7,     5,     2,     3,     3,     3,     4,     3,
       3,     2,     0,     3,     3,     3,     1,     3,     1,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       2,     4,     3,     4,     3,     1,     1,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     2,     4,
       4,     4,     3,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YYLOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YYLOCATION_PRINT

#  if defined YY_LOCATION_PRINT

   /* Temporary convenience wrapper in case some people defined the
      undocumented and private YY_LOCATION_PRINT macros.  */
#   define YYLOCATION_PRINT(File, Loc)  YY_LOCATION_PRINT(File, *(Loc))

#  elif defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
}

#   define YYLOCATION_PRINT  yy_location_print_

    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT(File, Loc)  YYLOCATION_PRINT(File, &(Loc))

#  else

#   define YYLOCATION_PRINT(File, Loc) ((void) 0)
    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT  YYLOCATION_PRINT

#  endif
# endif /* !defined YYLOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yylocationp);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YYLOCATION_PRINT (yyo, yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]));
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls = yylsa;
    YYLTYPE *yylsp = yyls;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  yylsp[0] = yylloc;
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      yyerror_range[1] = yylloc;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* Program: ExtDefList  */
#line 75 "./syntax.y"
                    {
    (yyval.node) = bison_create_node(PROGRAM,"Program");
    root = (yyval.node);
    addchild((yyval.node),1,(yyvsp[0].node));
    }
#line 1412 "./syntax.tab.c"
    break;

  case 3: /* ExtDefList: ExtDef ExtDefList  */
#line 81 "./syntax.y"
                              {
    (yyval.node) = bison_create_node(EXTDEFLIST,"Extdeflist");
    addchild((yyval.node),2,(yyvsp[-1].node),(yyvsp[0].node));
    }
#line 1421 "./syntax.tab.c"
    break;

  case 4: /* ExtDefList: %empty  */
#line 86 "./syntax.y"
    {
        (yyval.node)=NULL;
    }
#line 1429 "./syntax.tab.c"
    break;

  case 5: /* ExtDef: Specifier ExtDecList SEMI  */
#line 90 "./syntax.y"
                                 {
    (yyval.node) = bison_create_node(EXTDEF,"Extdef");
    addchild((yyval.node),3,(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));
    }
#line 1438 "./syntax.tab.c"
    break;

  case 6: /* ExtDef: Specifier SEMI  */
#line 94 "./syntax.y"
                    {
        (yyval.node) = bison_create_node(EXTDEF,"Extdef");
        addchild((yyval.node),2,(yyvsp[-1].node),(yyvsp[0].node));
    }
#line 1447 "./syntax.tab.c"
    break;

  case 7: /* ExtDef: Specifier FunDec CompSt  */
#line 98 "./syntax.y"
                             {
        (yyval.node) = bison_create_node(EXTDEF,"Extdef");
        addchild((yyval.node),3,(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));
    }
#line 1456 "./syntax.tab.c"
    break;

  case 8: /* ExtDef: error SEMI  */
#line 103 "./syntax.y"
               {
        err_cnt++;
    }
#line 1464 "./syntax.tab.c"
    break;

  case 9: /* ExtDef: Specifier error SEMI  */
#line 106 "./syntax.y"
                         {
        err_cnt++;
    }
#line 1472 "./syntax.tab.c"
    break;

  case 10: /* ExtDef: error Specifier SEMI  */
#line 109 "./syntax.y"
                          {
        err_cnt++;
    }
#line 1480 "./syntax.tab.c"
    break;

  case 11: /* ExtDef: error RP  */
#line 112 "./syntax.y"
              {
        err_cnt++;
    }
#line 1488 "./syntax.tab.c"
    break;

  case 12: /* ExtDef: error RC  */
#line 115 "./syntax.y"
              {
        err_cnt++;
    }
#line 1496 "./syntax.tab.c"
    break;

  case 13: /* ExtDef: error Specifier error CompSt  */
#line 118 "./syntax.y"
                                  {
        err_cnt++;
    }
#line 1504 "./syntax.tab.c"
    break;

  case 14: /* ExtDecList: VarDec  */
#line 122 "./syntax.y"
                  {
    (yyval.node) = bison_create_node(EXTDECLIST,"Extdeclist");
    addchild((yyval.node),1,(yyvsp[0].node));
    }
#line 1513 "./syntax.tab.c"
    break;

  case 15: /* ExtDecList: VarDec COMMA ExtDecList  */
#line 126 "./syntax.y"
                             {
        (yyval.node) = bison_create_node(EXTDECLIST,"Extdeclist");
        addchild((yyval.node),3,(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));
    }
#line 1522 "./syntax.tab.c"
    break;

  case 16: /* ExtDecList: VarDec error ExtDefList  */
#line 131 "./syntax.y"
                            {
        err_cnt++;
    }
#line 1530 "./syntax.tab.c"
    break;

  case 17: /* Specifier: TYPE  */
#line 137 "./syntax.y"
               {
    (yyval.node) = bison_create_node(SPECIFIER,"Specifier");
    addchild((yyval.node),1,(yyvsp[0].node));
    }
#line 1539 "./syntax.tab.c"
    break;

  case 18: /* Specifier: StructSpecifier  */
#line 141 "./syntax.y"
                     {
        (yyval.node) = bison_create_node(SPECIFIER,"Specifier");
        addchild((yyval.node),1,(yyvsp[0].node));
    }
#line 1548 "./syntax.tab.c"
    break;

  case 19: /* StructSpecifier: STRUCT OptTag LC DefList RC  */
#line 146 "./syntax.y"
                                            {
    (yyval.node) = bison_create_node(STRUCTSPECIFIER,"StructSpecifier");
    addchild((yyval.node),5,(yyvsp[-4].node),(yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));
    }
#line 1557 "./syntax.tab.c"
    break;

  case 20: /* StructSpecifier: STRUCT Tag  */
#line 150 "./syntax.y"
                {
        (yyval.node) = bison_create_node(STRUCTSPECIFIER,"StructSpecifier");
        addchild((yyval.node),2,(yyvsp[-1].node),(yyvsp[0].node));
    }
#line 1566 "./syntax.tab.c"
    break;

  case 21: /* OptTag: ID  */
#line 155 "./syntax.y"
          {
        (yyval.node) = bison_create_node(OPTTAG,"OptTag");
        addchild((yyval.node),1,(yyvsp[0].node));
    }
#line 1575 "./syntax.tab.c"
    break;

  case 22: /* OptTag: %empty  */
#line 160 "./syntax.y"
    {
        (yyval.node)=NULL;
    }
#line 1583 "./syntax.tab.c"
    break;

  case 23: /* Tag: ID  */
#line 164 "./syntax.y"
       {
        (yyval.node) = bison_create_node(TAG,"Tag");
        addchild((yyval.node),1,(yyvsp[0].node));
    }
#line 1592 "./syntax.tab.c"
    break;

  case 24: /* VarDec: ID  */
#line 171 "./syntax.y"
          {
    (yyval.node) = bison_create_node(VARDEC,"VarDec");
    addchild((yyval.node),1,(yyvsp[0].node));
    }
#line 1601 "./syntax.tab.c"
    break;

  case 25: /* VarDec: VarDec LB INT RB  */
#line 175 "./syntax.y"
                      {
        (yyval.node) = bison_create_node(VARDEC,"VarDec");
        addchild((yyval.node),4,(yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));
    }
#line 1610 "./syntax.tab.c"
    break;

  case 26: /* VarDec: VarDec LB error RB  */
#line 180 "./syntax.y"
                       {
        err_cnt++;
    }
#line 1618 "./syntax.tab.c"
    break;

  case 27: /* FunDec: ID LP VarList RP  */
#line 184 "./syntax.y"
                       {
    (yyval.node) = bison_create_node(FUNDEC,"FunDec");
    addchild((yyval.node),4,(yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));
    }
#line 1627 "./syntax.tab.c"
    break;

  case 28: /* FunDec: ID LP RP  */
#line 188 "./syntax.y"
              {
        (yyval.node) = bison_create_node(FUNDEC,"FunDec");
        addchild((yyval.node),3,(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));
    }
#line 1636 "./syntax.tab.c"
    break;

  case 29: /* FunDec: ID LP error RP  */
#line 193 "./syntax.y"
                   {
        err_cnt++;
    }
#line 1644 "./syntax.tab.c"
    break;

  case 30: /* FunDec: error LP VarList RP  */
#line 196 "./syntax.y"
                        {
        err_cnt++;
    }
#line 1652 "./syntax.tab.c"
    break;

  case 31: /* VarList: ParamDec COMMA VarList  */
#line 200 "./syntax.y"
                               {
    (yyval.node) = bison_create_node(VARLIST,"Varlist");
    addchild((yyval.node),3,(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));
    }
#line 1661 "./syntax.tab.c"
    break;

  case 32: /* VarList: ParamDec  */
#line 204 "./syntax.y"
              {
        (yyval.node) = bison_create_node(VARLIST,"Varlist");
        addchild((yyval.node),1,(yyvsp[0].node));
    }
#line 1670 "./syntax.tab.c"
    break;

  case 33: /* ParamDec: Specifier VarDec  */
#line 209 "./syntax.y"
                          {
    (yyval.node) = bison_create_node(PARAMDEC,"ParamDec");
    addchild((yyval.node),2,(yyvsp[-1].node),(yyvsp[0].node));
    }
#line 1679 "./syntax.tab.c"
    break;

  case 34: /* CompSt: LC DefList StmtList RC  */
#line 215 "./syntax.y"
                              {
    (yyval.node) = bison_create_node(COMPST,"CompSt");
    addchild((yyval.node),4,(yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));
    }
#line 1688 "./syntax.tab.c"
    break;

  case 35: /* CompSt: error RC  */
#line 220 "./syntax.y"
              {
        err_cnt++;
    }
#line 1696 "./syntax.tab.c"
    break;

  case 36: /* StmtList: Stmt StmtList  */
#line 224 "./syntax.y"
                       {
    (yyval.node) = bison_create_node(STMTLIST,"StmtList");
    addchild((yyval.node),2,(yyvsp[-1].node),(yyvsp[0].node));
    }
#line 1705 "./syntax.tab.c"
    break;

  case 37: /* StmtList: %empty  */
#line 229 "./syntax.y"
    {
        (yyval.node)=NULL;
    }
#line 1713 "./syntax.tab.c"
    break;

  case 38: /* Stmt: Exp SEMI  */
#line 233 "./syntax.y"
              {
    (yyval.node) = bison_create_node(STMT,"Stmt");
    addchild((yyval.node),2,(yyvsp[-1].node),(yyvsp[0].node));
    }
#line 1722 "./syntax.tab.c"
    break;

  case 39: /* Stmt: CompSt  */
#line 237 "./syntax.y"
            {
        (yyval.node) = bison_create_node(STMT,"Stmt");
        addchild((yyval.node),1,(yyvsp[0].node));
    }
#line 1731 "./syntax.tab.c"
    break;

  case 40: /* Stmt: RETURN Exp SEMI  */
#line 241 "./syntax.y"
                     {
        (yyval.node) = bison_create_node(STMT,"Stmt");
        addchild((yyval.node),3,(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));
    }
#line 1740 "./syntax.tab.c"
    break;

  case 41: /* Stmt: IF LP Exp RP Stmt  */
#line 245 "./syntax.y"
                       {
        (yyval.node) = bison_create_node(STMT,"Stmt");
        addchild((yyval.node),5,(yyvsp[-4].node),(yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));
    }
#line 1749 "./syntax.tab.c"
    break;

  case 42: /* Stmt: IF LP Exp RP Stmt ELSE Stmt  */
#line 249 "./syntax.y"
                                 {
        (yyval.node) = bison_create_node(STMT,"Stmt");
        addchild((yyval.node),7,(yyvsp[-6].node),(yyvsp[-5].node),(yyvsp[-4].node),(yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));
    }
#line 1758 "./syntax.tab.c"
    break;

  case 43: /* Stmt: WHILE LP Exp RP Stmt  */
#line 253 "./syntax.y"
                          {
        (yyval.node) = bison_create_node(STMT,"Stmt");
        addchild((yyval.node),5,(yyvsp[-4].node),(yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));
    }
#line 1767 "./syntax.tab.c"
    break;

  case 44: /* Stmt: error SEMI  */
#line 258 "./syntax.y"
                 {
        err_cnt++;
    }
#line 1775 "./syntax.tab.c"
    break;

  case 45: /* Stmt: Exp error SEMI  */
#line 261 "./syntax.y"
                    {
        err_cnt++;
    }
#line 1783 "./syntax.tab.c"
    break;

  case 46: /* Stmt: RETURN Exp error  */
#line 264 "./syntax.y"
                     {
        err_cnt++;
    }
#line 1791 "./syntax.tab.c"
    break;

  case 47: /* Stmt: RETURN error SEMI  */
#line 267 "./syntax.y"
                      {
        err_cnt++;
    }
#line 1799 "./syntax.tab.c"
    break;

  case 48: /* Stmt: IF error ELSE Stmt  */
#line 270 "./syntax.y"
                        {
        err_cnt++;
    }
#line 1807 "./syntax.tab.c"
    break;

  case 49: /* Stmt: WHILE error RP  */
#line 273 "./syntax.y"
                    {
        err_cnt++;
    }
#line 1815 "./syntax.tab.c"
    break;

  case 50: /* Stmt: WHILE error RC  */
#line 276 "./syntax.y"
                    {
        err_cnt++;
    }
#line 1823 "./syntax.tab.c"
    break;

  case 51: /* DefList: Def DefList  */
#line 281 "./syntax.y"
                    {
    (yyval.node) = bison_create_node(DEFLIST,"DefList");
    addchild((yyval.node),2,(yyvsp[-1].node),(yyvsp[0].node));
    }
#line 1832 "./syntax.tab.c"
    break;

  case 52: /* DefList: %empty  */
#line 286 "./syntax.y"
    {
        (yyval.node)=NULL;
    }
#line 1840 "./syntax.tab.c"
    break;

  case 53: /* Def: Specifier DecList SEMI  */
#line 290 "./syntax.y"
                           {
    (yyval.node) = bison_create_node(DEF,"Def");
    addchild((yyval.node),3,(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));    
    }
#line 1849 "./syntax.tab.c"
    break;

  case 54: /* Def: Specifier error SEMI  */
#line 295 "./syntax.y"
                          {
        err_cnt++;
    }
#line 1857 "./syntax.tab.c"
    break;

  case 55: /* Def: Specifier DecList error  */
#line 298 "./syntax.y"
                             {
        err_cnt++;
    }
#line 1865 "./syntax.tab.c"
    break;

  case 56: /* DecList: Dec  */
#line 302 "./syntax.y"
            {
    (yyval.node) = bison_create_node(DECLIST,"DecList");
    addchild((yyval.node),1,(yyvsp[0].node));
    }
#line 1874 "./syntax.tab.c"
    break;

  case 57: /* DecList: Dec COMMA DecList  */
#line 306 "./syntax.y"
                       {
        (yyval.node) = bison_create_node(DECLIST,"DecList");
        addchild((yyval.node),3,(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));
    }
#line 1883 "./syntax.tab.c"
    break;

  case 58: /* Dec: VarDec  */
#line 311 "./syntax.y"
          {
    (yyval.node) = bison_create_node(DEC,"Dec");
    addchild((yyval.node),1,(yyvsp[0].node));
    }
#line 1892 "./syntax.tab.c"
    break;

  case 59: /* Dec: VarDec ASSIGNOP Exp  */
#line 315 "./syntax.y"
                         {
        (yyval.node) = bison_create_node(DEC,"Dec");
        addchild((yyval.node),3,(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));
    }
#line 1901 "./syntax.tab.c"
    break;

  case 60: /* Exp: Exp ASSIGNOP Exp  */
#line 321 "./syntax.y"
                     {
    (yyval.node) = bison_create_node(EXP,"Exp");
    addchild((yyval.node),3,(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));
    }
#line 1910 "./syntax.tab.c"
    break;

  case 61: /* Exp: Exp AND Exp  */
#line 325 "./syntax.y"
                 {
        (yyval.node) = bison_create_node(EXP,"Exp");
        addchild((yyval.node),3,(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));
    }
#line 1919 "./syntax.tab.c"
    break;

  case 62: /* Exp: Exp OR Exp  */
#line 329 "./syntax.y"
                {
        (yyval.node) = bison_create_node(EXP,"Exp");
        addchild((yyval.node),3,(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));
    }
#line 1928 "./syntax.tab.c"
    break;

  case 63: /* Exp: Exp RELOP Exp  */
#line 333 "./syntax.y"
                   {
        (yyval.node) = bison_create_node(EXP,"Exp");
        addchild((yyval.node),3,(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));
    }
#line 1937 "./syntax.tab.c"
    break;

  case 64: /* Exp: Exp PLUS Exp  */
#line 337 "./syntax.y"
                  {
        (yyval.node) = bison_create_node(EXP,"Exp");
        addchild((yyval.node),3,(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));
    }
#line 1946 "./syntax.tab.c"
    break;

  case 65: /* Exp: Exp MINUS Exp  */
#line 341 "./syntax.y"
                   {
        (yyval.node) = bison_create_node(EXP,"Exp");
        addchild((yyval.node),3,(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));
    }
#line 1955 "./syntax.tab.c"
    break;

  case 66: /* Exp: Exp STAR Exp  */
#line 345 "./syntax.y"
                  {
        (yyval.node) = bison_create_node(EXP,"Exp");
        addchild((yyval.node),3,(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));
    }
#line 1964 "./syntax.tab.c"
    break;

  case 67: /* Exp: Exp DIV Exp  */
#line 349 "./syntax.y"
                 {
        (yyval.node) = bison_create_node(EXP,"Exp");
        addchild((yyval.node),3,(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));
    }
#line 1973 "./syntax.tab.c"
    break;

  case 68: /* Exp: LP Exp RP  */
#line 353 "./syntax.y"
               {
        (yyval.node) = bison_create_node(EXP,"Exp");
        addchild((yyval.node),3,(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));
    }
#line 1982 "./syntax.tab.c"
    break;

  case 69: /* Exp: MINUS Exp  */
#line 358 "./syntax.y"
               {
        (yyval.node) = bison_create_node(EXP,"Exp");
        addchild((yyval.node),2,(yyvsp[-1].node),(yyvsp[0].node));
    }
#line 1991 "./syntax.tab.c"
    break;

  case 70: /* Exp: NOT Exp  */
#line 362 "./syntax.y"
             {
        (yyval.node) = bison_create_node(EXP,"Exp");
        addchild((yyval.node),2,(yyvsp[-1].node),(yyvsp[0].node));
    }
#line 2000 "./syntax.tab.c"
    break;

  case 71: /* Exp: ID LP Args RP  */
#line 366 "./syntax.y"
                   {
        (yyval.node) = bison_create_node(EXP,"Exp");
        addchild((yyval.node),4,(yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));
    }
#line 2009 "./syntax.tab.c"
    break;

  case 72: /* Exp: ID LP RP  */
#line 370 "./syntax.y"
              {
        (yyval.node) = bison_create_node(EXP,"Exp");
        addchild((yyval.node),3,(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));
    }
#line 2018 "./syntax.tab.c"
    break;

  case 73: /* Exp: Exp LB Exp RB  */
#line 374 "./syntax.y"
                   {
        (yyval.node) = bison_create_node(EXP,"Exp");
        addchild((yyval.node),4,(yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));
    }
#line 2027 "./syntax.tab.c"
    break;

  case 74: /* Exp: Exp DOT ID  */
#line 378 "./syntax.y"
                {
        (yyval.node) = bison_create_node(EXP,"Exp");
        addchild((yyval.node),3,(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));
    }
#line 2036 "./syntax.tab.c"
    break;

  case 75: /* Exp: ID  */
#line 382 "./syntax.y"
        {
        (yyval.node) = bison_create_node(EXP,"Exp");
        addchild((yyval.node),1,(yyvsp[0].node));
    }
#line 2045 "./syntax.tab.c"
    break;

  case 76: /* Exp: INT  */
#line 386 "./syntax.y"
         {
        (yyval.node) = bison_create_node(EXP,"Exp");
        addchild((yyval.node),1,(yyvsp[0].node));
    }
#line 2054 "./syntax.tab.c"
    break;

  case 77: /* Exp: FLOAT  */
#line 390 "./syntax.y"
           {
        (yyval.node) = bison_create_node(EXP,"Exp");
        addchild((yyval.node),1,(yyvsp[0].node));
    }
#line 2063 "./syntax.tab.c"
    break;

  case 78: /* Exp: Exp ASSIGNOP error  */
#line 395 "./syntax.y"
                        {
        err_cnt++;
    }
#line 2071 "./syntax.tab.c"
    break;

  case 79: /* Exp: Exp AND error  */
#line 398 "./syntax.y"
                   {
        err_cnt++;
    }
#line 2079 "./syntax.tab.c"
    break;

  case 80: /* Exp: Exp OR error  */
#line 401 "./syntax.y"
                  {
        err_cnt++;
    }
#line 2087 "./syntax.tab.c"
    break;

  case 81: /* Exp: Exp RELOP error  */
#line 404 "./syntax.y"
                     {
        err_cnt++;
    }
#line 2095 "./syntax.tab.c"
    break;

  case 82: /* Exp: Exp PLUS error  */
#line 407 "./syntax.y"
                    {
        err_cnt++;
    }
#line 2103 "./syntax.tab.c"
    break;

  case 83: /* Exp: Exp MINUS error  */
#line 410 "./syntax.y"
                     {
        err_cnt++;
    }
#line 2111 "./syntax.tab.c"
    break;

  case 84: /* Exp: Exp STAR error  */
#line 413 "./syntax.y"
                    {
        err_cnt++;
    }
#line 2119 "./syntax.tab.c"
    break;

  case 85: /* Exp: Exp DIV error  */
#line 416 "./syntax.y"
                   {
        err_cnt++;
    }
#line 2127 "./syntax.tab.c"
    break;

  case 86: /* Exp: LP error RP  */
#line 419 "./syntax.y"
                 {
        err_cnt++;
    }
#line 2135 "./syntax.tab.c"
    break;

  case 87: /* Exp: MINUS error  */
#line 422 "./syntax.y"
                 {
        err_cnt++;
    }
#line 2143 "./syntax.tab.c"
    break;

  case 88: /* Exp: NOT error  */
#line 425 "./syntax.y"
               {
        err_cnt++;
    }
#line 2151 "./syntax.tab.c"
    break;

  case 89: /* Exp: ID LP error RP  */
#line 428 "./syntax.y"
                    {
        err_cnt++;
    }
#line 2159 "./syntax.tab.c"
    break;

  case 90: /* Exp: ID LP error SEMI  */
#line 431 "./syntax.y"
                      {
        err_cnt++;
    }
#line 2167 "./syntax.tab.c"
    break;

  case 91: /* Exp: Exp LB error RB  */
#line 434 "./syntax.y"
                     {
        err_cnt++;
    }
#line 2175 "./syntax.tab.c"
    break;

  case 92: /* Args: Exp COMMA Args  */
#line 438 "./syntax.y"
                    {
    (yyval.node) = bison_create_node(ARGS,"Args");
    addchild((yyval.node),3,(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));
    }
#line 2184 "./syntax.tab.c"
    break;

  case 93: /* Args: Exp  */
#line 442 "./syntax.y"
         {
        (yyval.node) = bison_create_node(ARGS,"Args");
        addchild((yyval.node),1,(yyvsp[0].node));
    }
#line 2193 "./syntax.tab.c"
    break;


#line 2197 "./syntax.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  yyerror_range[1] = yylloc;
  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, &yylloc);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 447 "./syntax.y"


int main(int argc, char** argv)
{
    if (argc <= 1) return 1;
    FILE* f = fopen(argv[1], "r");
    if (!f)
    {
    perror(argv[1]);
    return 1;
    }
    yyrestart(f);
    yyparse();
    if(err_cnt == 0){
        // preorder_traversal_AST(root);
        ListNode* headnode = (ListNode*)malloc(sizeof(ListNode));
        headnode -> name = (char*)malloc(sizeof(char));//如果可能触及到的指针，都必须初始化。否则segfault
        ListNode* tailnode = headnode;
        // printf("syntax good\n");
        ASTtraversal(root,headnode,&tailnode);
    }
    return 0;
}