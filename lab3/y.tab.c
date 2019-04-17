/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "lab3.y" /* yacc.c:339  */

#include	<stdio.h>
#include	<stdlib.h>
#include 	<string.h>
#define RELOP_1		1
#define RELOP_2		2
#define RELOP_3		3
#define RELOP_4		4
#define RELOP_5		5
#define RELOP_6		6
#define ADOP_1		7
#define ADOP_2		8
#define MULTOP_1 	9
#define MULTOP_2	10
#define MULTOP_3	11
int tab = 0;
char strAux[100];
void tabular();
int yylex();
void yyerror(const char *s);
static int input();
int FromIfStat=0;

#line 90 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    CALL = 258,
    CHAR = 259,
    DO = 260,
    ELSE = 261,
    FALSE = 262,
    FLOAT = 263,
    FOR = 264,
    FUNCTIONS = 265,
    GLOBAL = 266,
    IF = 267,
    INT = 268,
    LOCAL = 269,
    LOGIC = 270,
    MAIN = 271,
    PROGRAM = 272,
    READ = 273,
    RETURN = 274,
    STATEMENTS = 275,
    TRUE = 276,
    VOID = 277,
    WHILE = 278,
    WRITE = 279,
    ID = 280,
    INTCT = 281,
    CHARCT = 282,
    FLOATCT = 283,
    STRING = 284,
    OP = 285,
    OR = 286,
    AND = 287,
    NOT = 288,
    NEG = 289,
    RELOP = 290,
    ADOP = 291,
    MULTOP = 292,
    ASSIGN = 293,
    OPPAR = 294,
    CLPAR = 295,
    OPBRAK = 296,
    CLBRAK = 297,
    OPBRACE = 298,
    CLBRACE = 299,
    SCOLON = 300,
    COMMA = 301,
    COLON = 302,
    INVAL = 303,
    COMMENT = 304
  };
#endif
/* Tokens.  */
#define CALL 258
#define CHAR 259
#define DO 260
#define ELSE 261
#define FALSE 262
#define FLOAT 263
#define FOR 264
#define FUNCTIONS 265
#define GLOBAL 266
#define IF 267
#define INT 268
#define LOCAL 269
#define LOGIC 270
#define MAIN 271
#define PROGRAM 272
#define READ 273
#define RETURN 274
#define STATEMENTS 275
#define TRUE 276
#define VOID 277
#define WHILE 278
#define WRITE 279
#define ID 280
#define INTCT 281
#define CHARCT 282
#define FLOATCT 283
#define STRING 284
#define OP 285
#define OR 286
#define AND 287
#define NOT 288
#define NEG 289
#define RELOP 290
#define ADOP 291
#define MULTOP 292
#define ASSIGN 293
#define OPPAR 294
#define CLPAR 295
#define OPBRAK 296
#define CLBRAK 297
#define OPBRACE 298
#define CLBRACE 299
#define SCOLON 300
#define COMMA 301
#define COLON 302
#define INVAL 303
#define COMMENT 304

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 24 "lab3.y" /* yacc.c:355  */

	char string[100];
  char carac;
	int atr;
	int valor;
	float valreal;

#line 233 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);



/* Copy the second part of user declarations.  */

#line 250 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   205

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  50
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  125
/* YYNRULES -- Number of rules.  */
#define YYNRULES  173
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  262

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   304

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    85,    85,    85,    85,    85,    86,    86,    86,    86,
      87,    87,    88,    89,    89,    89,    89,    89,    90,    90,
      90,    91,    91,    92,    92,    92,    93,    93,    93,    94,
      94,    94,    95,    95,    96,    96,    97,    97,    97,    97,
      98,    98,    99,    99,    99,   100,   101,   101,   101,   101,
     102,   102,   102,   103,   103,   104,   104,   104,   104,   104,
     104,   104,   104,   105,   105,   105,   105,   105,   105,   105,
     105,   106,   106,   106,   106,   106,   107,   107,   107,   107,
     108,   108,   108,   108,   108,   108,   109,   109,   109,   110,
     110,   110,   110,   111,   111,   111,   112,   112,   112,   112,
     113,   113,   114,   112,   115,   115,   115,   115,   116,   116,
     116,   116,   117,   117,   117,   117,   118,   118,   118,   119,
     119,   120,   120,   121,   121,   121,   122,   122,   123,   123,
     123,   123,   124,   124,   125,   125,   125,   126,   126,   126,
     127,   127,   127,   128,   128,   128,   129,   129,   129,   151,
     151,   151,   152,   152,   152,   165,   165,   165,   165,   166,
     166,   166,   166,   167,   167,   167,   168,   168,   169,   169,
     169,   170,   170,   170
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CALL", "CHAR", "DO", "ELSE", "FALSE",
  "FLOAT", "FOR", "FUNCTIONS", "GLOBAL", "IF", "INT", "LOCAL", "LOGIC",
  "MAIN", "PROGRAM", "READ", "RETURN", "STATEMENTS", "TRUE", "VOID",
  "WHILE", "WRITE", "ID", "INTCT", "CHARCT", "FLOATCT", "STRING", "OP",
  "OR", "AND", "NOT", "NEG", "RELOP", "ADOP", "MULTOP", "ASSIGN", "OPPAR",
  "CLPAR", "OPBRAK", "CLBRAK", "OPBRACE", "CLBRACE", "SCOLON", "COMMA",
  "COLON", "INVAL", "COMMENT", "$accept", "Prog", "$@1", "$@2", "$@3",
  "GlobDecls", "$@4", "$@5", "DeclList", "Declaration", "Type", "ElemList",
  "$@6", "Elem", "$@7", "Dims", "$@8", "DimList", "$@9", "Functions",
  "$@10", "$@11", "FuncList", "Function", "$@12", "Header", "$@13", "$@14",
  "Params", "ParamList", "$@15", "Parameter", "LocDecls", "$@16", "$@17",
  "Stats", "$@18", "$@19", "StatList", "Statement", "$@20", "$@21", "$@22",
  "$@23", "$@24", "$@25", "$@26", "$@27", "$@28", "$@29", "CompStat",
  "$@30", "$@31", "$@32", "IfStat", "$@33", "$@34", "$@35", "$@36", "$@37",
  "ElseStat", "$@38", "WhileStat", "$@39", "$@40", "$@41", "DoStat",
  "$@42", "$@43", "ForStat", "$@44", "$@45", "$@46", "$@47", "$@48",
  "$@49", "$@50", "ReadStat", "$@51", "$@52", "$@53", "ReadList", "$@54",
  "$@55", "WriteStat", "$@56", "$@57", "$@58", "WriteList", "$@59",
  "WriteElem", "CallStat", "$@60", "FuncCall", "$@61", "$@62", "Arguments",
  "ReturnStat", "$@63", "$@64", "AssignStat", "$@65", "ExprList", "$@66",
  "Expression", "$@67", "AuxExpr1", "$@68", "AuxExpr2", "$@69", "AuxExpr3",
  "$@70", "AuxExpr4", "$@71", "Term", "$@72", "Factor", "$@73", "$@74",
  "Variable", "$@75", "Subscripts", "$@76", "SubscrList", "$@77", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304
};
# endif

#define YYPACT_NINF -160

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-160)))

#define YYTABLE_NINF -129

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -3,  -160,    16,    21,  -160,  -160,    34,  -160,    67,  -160,
      52,    35,  -160,    41,  -160,    44,  -160,    79,  -160,  -160,
    -160,  -160,  -160,  -160,    79,  -160,    54,    37,  -160,  -160,
     -19,  -160,  -160,    56,    37,  -160,    59,    62,  -160,  -160,
    -160,  -160,  -160,  -160,  -160,    54,    58,    93,    82,  -160,
    -160,  -160,    89,  -160,    -2,    79,    63,  -160,    68,  -160,
    -160,    86,    73,    69,  -160,  -160,    70,  -160,    88,  -160,
    -160,  -160,    79,  -160,  -160,    79,    79,  -160,  -160,     6,
    -160,  -160,    75,   104,    96,   118,   116,   109,   105,   103,
     128,   114,  -160,  -160,  -160,  -160,  -160,  -160,    81,  -160,
    -160,  -160,  -160,  -160,  -160,  -160,  -160,  -160,    98,  -160,
    -160,    92,  -160,  -160,   119,   120,   132,   121,   122,   125,
     102,  -160,   141,   124,   123,  -160,  -160,  -160,   129,  -160,
    -160,  -160,  -160,  -160,   123,  -160,   130,  -160,  -160,  -160,
     131,  -160,  -160,  -160,  -160,  -160,  -160,  -160,   -26,   144,
    -160,  -160,    32,   140,  -160,  -160,    51,   123,   123,  -160,
     103,   103,   113,   146,   -25,   139,  -160,   146,   146,   123,
    -160,  -160,  -160,  -160,  -160,  -160,   135,    -8,     2,   123,
     143,   142,  -160,  -160,   -12,  -160,   152,   148,    19,  -160,
    -160,  -160,  -160,     8,   123,   123,   146,   146,   146,  -160,
    -160,  -160,    33,  -160,  -160,   145,  -160,  -160,  -160,  -160,
     123,  -160,   144,  -160,   148,   140,  -160,  -160,    81,  -160,
     123,   147,  -160,   149,   113,   146,   150,   151,   152,    81,
    -160,   153,   -24,  -160,   103,  -160,  -160,   148,  -160,  -160,
    -160,  -160,  -160,  -160,   123,   180,   123,   152,  -160,  -160,
     -23,    81,  -160,  -160,   103,   155,  -160,   123,    49,  -160,
      81,  -160
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     2,     0,     0,     1,     3,     0,     4,     6,     7,
       0,     0,    29,     0,     8,     0,     5,     0,    30,    15,
      14,    13,    16,    17,     9,    10,     0,     0,    11,    21,
       0,    18,    36,     0,    31,    32,     0,    23,    12,    19,
      37,    33,    34,    24,    22,     0,     0,    46,     0,    20,
      38,    47,     0,    26,     0,    40,     0,    50,     0,    25,
      27,     0,     0,    41,    42,    48,     0,    35,     0,    45,
      39,    43,     0,    51,    28,     0,    49,    53,    44,    52,
      75,    54,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    76,    56,    80,    58,    89,    60,    55,    62,
      96,    64,   104,    66,   112,    68,   166,    70,     0,   121,
      72,   130,    74,    77,     0,     0,     0,     0,     0,     0,
     168,   132,     0,     0,     0,    53,    81,    90,     0,    97,
     105,   113,   169,   167,     0,   123,     0,   129,   160,   159,
     166,   156,   158,   157,   144,   161,   163,   165,     0,   137,
     140,   143,   146,   149,   152,   155,    55,     0,     0,    93,
       0,     0,     0,     0,     0,     0,   122,     0,     0,     0,
     138,   131,   141,   147,   150,   153,     0,     0,     0,     0,
       0,   109,   108,   119,     0,   116,   120,   171,     0,   133,
     124,   145,   162,     0,     0,     0,     0,     0,     0,    79,
      82,    91,     0,    98,   106,     0,   114,   117,   170,   172,
     126,   164,   139,   142,   148,   151,   154,    83,    55,    94,
       0,     0,   110,     0,     0,     0,     0,   127,   134,    55,
      92,     0,     0,   107,     0,   115,   118,   173,   125,   135,
      84,    95,    99,   111,     0,    86,     0,   136,    87,    85,
       0,    55,   100,    88,     0,     0,   101,     0,     0,   102,
      55,   103
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -160,  -160,  -160,  -160,  -160,  -160,  -160,  -160,   115,   -21,
     -17,  -160,  -160,   154,  -160,  -160,  -160,  -160,  -160,  -160,
    -160,  -160,  -160,   161,  -160,  -160,  -160,  -160,  -160,  -160,
    -160,   126,  -160,  -160,  -160,  -160,  -160,  -160,    64,   -97,
    -160,  -160,  -160,  -160,  -160,  -160,  -160,  -160,  -160,  -160,
    -160,  -160,  -160,  -160,  -160,  -160,  -160,  -160,  -160,  -160,
    -160,  -160,  -160,  -160,  -160,  -160,  -160,  -160,  -160,  -160,
    -160,  -160,  -160,  -160,  -160,  -160,  -160,  -160,  -160,  -160,
    -160,  -160,  -160,  -160,  -160,  -160,  -160,  -160,  -160,  -160,
     -36,  -160,  -160,    74,  -160,  -160,  -160,  -160,  -160,  -160,
    -160,  -160,  -160,  -160,  -122,  -160,     9,  -160,     5,  -160,
      38,  -160,  -159,  -160,     7,  -160,  -155,  -160,  -160,   -89,
    -160,  -160,  -160,  -160,  -160
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     6,     8,    10,    11,    17,    24,    25,
      26,    30,    45,    31,    37,    44,    48,    54,    68,    13,
      15,    27,    34,    35,    47,    36,    46,    55,    62,    63,
      75,    64,    52,    56,    72,    58,    66,    77,    79,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      93,   113,   125,   176,    95,   114,   157,   217,   229,   245,
     249,   251,    97,   115,   158,   218,    99,   179,   231,   101,
     117,   160,   220,   246,   254,   257,   260,   103,   118,   161,
     221,   181,   205,   234,   105,   119,   162,   223,   184,   224,
     185,   110,   122,   147,   165,   210,   226,   112,   123,   124,
     107,   134,   227,   244,   186,   194,   149,   195,   150,   167,
     151,   196,   152,   197,   153,   198,   154,   168,   169,   155,
     120,   133,   163,   188,   225
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     108,   116,   148,    28,   187,   170,   170,   170,   170,   -71,
      33,   -61,   164,   192,     1,   -63,     4,    33,   -57,   171,
     189,   242,   252,   170,   -65,   -73,    38,    39,   206,   -59,
     -67,   -69,   200,   170,   207,   177,   178,   214,    61,   170,
      59,    19,   201,   216,    60,    20,     5,   193,   211,   -55,
      21,    80,    22,    32,   -71,    28,   -61,   202,    61,    23,
     -63,   208,    12,   -57,   170,   209,   237,   173,   174,   -65,
     -73,   180,   182,   219,   -59,   -67,   -69,     7,     9,    29,
     170,    40,    14,    19,   -71,    16,   -61,    20,   228,   259,
     -63,    18,    21,   -57,    22,   -78,    80,    50,   232,   -65,
     -73,    23,    42,    43,   -59,   -67,   -69,    51,    53,    57,
      65,    69,    67,    70,    74,    71,    94,    73,    92,    96,
     138,   230,   247,    98,   250,   100,    80,   102,   106,   104,
     138,   109,   240,   111,   139,   258,   121,  -128,   140,   141,
     142,   143,   183,   132,   139,   243,   144,   145,   140,   141,
     142,   143,   146,   138,   253,   128,   144,   145,   126,   127,
     129,   130,   146,   261,   131,   255,   135,   139,   159,   137,
    -123,   140,   141,   142,   143,   166,   172,   175,   190,   199,
     145,   203,   204,   170,   174,   146,   248,    76,   236,   156,
     238,   222,   233,   256,   235,    41,   136,   239,   241,    49,
     213,    78,     0,   212,   215,   191
};

static const yytype_int16 yycheck[] =
{
      89,    98,   124,    24,   163,    31,    31,    31,    31,     3,
      27,     5,   134,   168,    17,     9,     0,    34,    12,    45,
      45,    45,    45,    31,    18,    19,    45,    46,    40,    23,
      24,    25,    40,    31,    46,   157,   158,   196,    55,    31,
      42,     4,    40,   198,    46,     8,    25,   169,    40,    43,
      13,    45,    15,    16,     3,    76,     5,   179,    75,    22,
       9,    42,    10,    12,    31,    46,   225,    35,    36,    18,
      19,   160,   161,    40,    23,    24,    25,    43,    11,    25,
      31,    25,    47,     4,     3,    44,     5,     8,   210,    40,
       9,    47,    13,    12,    15,    44,    45,    39,   220,    18,
      19,    22,    43,    41,    23,    24,    25,    14,    26,    20,
      47,    25,    44,    40,    26,    46,    12,    47,    43,    23,
       7,   218,   244,     5,   246,     9,    45,    18,    25,    24,
       7,     3,   229,    19,    21,   257,    38,    45,    25,    26,
      27,    28,    29,    41,    21,   234,    33,    34,    25,    26,
      27,    28,    39,     7,   251,    23,    33,    34,    39,    39,
      39,    39,    39,   260,    39,   254,    25,    21,    39,    45,
      39,    25,    26,    27,    28,    45,    32,    37,    39,    44,
      34,    38,    40,    31,    36,    39,     6,    72,   224,   125,
      40,    46,    45,    38,    45,    34,   122,    46,    45,    45,
     195,    75,    -1,   194,   197,   167
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    17,    51,    52,     0,    25,    53,    43,    54,    11,
      55,    56,    10,    69,    47,    70,    44,    57,    47,     4,
       8,    13,    15,    22,    58,    59,    60,    71,    59,    25,
      61,    63,    16,    60,    72,    73,    75,    64,    45,    46,
      25,    73,    43,    41,    65,    62,    76,    74,    66,    63,
      39,    14,    82,    26,    67,    77,    83,    20,    85,    42,
      46,    60,    78,    79,    81,    47,    86,    44,    68,    25,
      40,    46,    84,    47,    26,    80,    58,    87,    81,    88,
      45,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,    43,   100,    12,   104,    23,   112,     5,   116,
       9,   119,    18,   127,    24,   134,    25,   150,   169,     3,
     141,    19,   147,   101,   105,   113,    89,   120,   128,   135,
     170,    38,   142,   148,   149,   102,    39,    39,    23,    39,
      39,    39,    41,   171,   151,    25,   143,    45,     7,    21,
      25,    26,    27,    28,    33,    34,    39,   143,   154,   156,
     158,   160,   162,   164,   166,   169,    88,   106,   114,    39,
     121,   129,   136,   172,   154,   144,    45,   159,   167,   168,
      31,    45,    32,    35,    36,    37,   103,   154,   154,   117,
     169,   131,   169,    29,   138,   140,   154,   162,   173,    45,
      39,   160,   166,   154,   155,   157,   161,   163,   165,    44,
      40,    40,   154,    38,    40,   132,    40,    46,    42,    46,
     145,    40,   156,   158,   162,   164,   166,   107,   115,    40,
     122,   130,    46,   137,   139,   174,   146,   152,   154,   108,
      89,   118,   154,    45,   133,    45,   140,   162,    40,    46,
      89,    45,    45,   169,   153,   109,   123,   154,     6,   110,
     154,   111,    45,    89,   124,   169,    38,   125,   154,    40,
     126,    89
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    50,    52,    53,    54,    51,    55,    56,    57,    55,
      58,    58,    59,    60,    60,    60,    60,    60,    61,    62,
      61,    64,    63,    65,    66,    65,    67,    68,    67,    70,
      71,    69,    72,    72,    74,    73,    75,    76,    77,    75,
      78,    78,    79,    80,    79,    81,    82,    83,    84,    82,
      86,    87,    85,    88,    88,    90,    89,    91,    89,    92,
      89,    93,    89,    94,    89,    95,    89,    96,    89,    97,
      89,    98,    89,    99,    89,    89,   101,   102,   103,   100,
     105,   106,   107,   108,   109,   104,   110,   111,   110,   113,
     114,   115,   112,   117,   118,   116,   120,   121,   122,   123,
     124,   125,   126,   119,   128,   129,   130,   127,   131,   132,
     133,   131,   135,   136,   137,   134,   138,   139,   138,   140,
     140,   142,   141,   144,   145,   143,   146,   146,   148,   147,
     149,   147,   151,   150,   152,   153,   152,   154,   155,   154,
     156,   157,   156,   158,   159,   158,   160,   161,   160,   162,
     163,   162,   164,   165,   164,   166,   166,   166,   166,   166,
     166,   167,   166,   168,   166,   166,   170,   169,   171,   172,
     171,   173,   174,   173
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     0,     0,     9,     0,     0,     0,     5,
       1,     2,     3,     1,     1,     1,     1,     1,     1,     0,
       4,     0,     3,     0,     0,     4,     1,     0,     4,     0,
       0,     5,     1,     2,     0,     6,     1,     0,     0,     7,
       0,     1,     1,     0,     4,     2,     0,     0,     0,     5,
       0,     0,     5,     0,     2,     0,     2,     0,     2,     0,
       2,     0,     2,     0,     2,     0,     2,     0,     2,     0,
       2,     0,     2,     0,     2,     1,     0,     0,     0,     6,
       0,     0,     0,     0,     0,    11,     0,     0,     3,     0,
       0,     0,     8,     0,     0,     9,     0,     0,     0,     0,
       0,     0,     0,    20,     0,     0,     0,     8,     1,     0,
       0,     5,     0,     0,     0,     8,     1,     0,     4,     1,
       1,     0,     4,     0,     0,     6,     0,     1,     0,     3,
       0,     4,     0,     5,     1,     0,     4,     1,     0,     4,
       1,     0,     4,     1,     0,     3,     1,     0,     4,     1,
       0,     4,     1,     0,     4,     1,     1,     1,     1,     1,
       1,     0,     3,     0,     4,     1,     0,     3,     0,     0,
       4,     1,     0,     4
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 85 "lab3.y" /* yacc.c:1646  */
    {printf("program ");}
#line 1538 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 85 "lab3.y" /* yacc.c:1646  */
    {printf("%s",yylval.string);}
#line 1544 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 85 "lab3.y" /* yacc.c:1646  */
    {printf("\{\n");}
#line 1550 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 85 "lab3.y" /* yacc.c:1646  */
    {printf("\}\n");}
#line 1556 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 86 "lab3.y" /* yacc.c:1646  */
    {printf("global");}
#line 1562 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 86 "lab3.y" /* yacc.c:1646  */
    {printf(":\n");tab++;}
#line 1568 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 86 "lab3.y" /* yacc.c:1646  */
    {tab--;}
#line 1574 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 88 "lab3.y" /* yacc.c:1646  */
    {printf(";\n");}
#line 1580 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 89 "lab3.y" /* yacc.c:1646  */
    {tabular();printf("int ");}
#line 1586 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 89 "lab3.y" /* yacc.c:1646  */
    {tabular();printf("float ");}
#line 1592 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 89 "lab3.y" /* yacc.c:1646  */
    {tabular();printf("char ");}
#line 1598 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 89 "lab3.y" /* yacc.c:1646  */
    {tabular();printf("logic ");}
#line 1604 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 89 "lab3.y" /* yacc.c:1646  */
    {tabular();printf("void ");}
#line 1610 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 90 "lab3.y" /* yacc.c:1646  */
    {printf(", ");}
#line 1616 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 91 "lab3.y" /* yacc.c:1646  */
    {printf("%s",yylval.string);}
#line 1622 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 92 "lab3.y" /* yacc.c:1646  */
    {printf("[");}
#line 1628 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 92 "lab3.y" /* yacc.c:1646  */
    {printf("]");}
#line 1634 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 93 "lab3.y" /* yacc.c:1646  */
    {printf("%d",yylval.valor);}
#line 1640 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 93 "lab3.y" /* yacc.c:1646  */
    {printf(", ");}
#line 1646 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 93 "lab3.y" /* yacc.c:1646  */
    {printf("%d",yylval.valor);}
#line 1652 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 94 "lab3.y" /* yacc.c:1646  */
    {printf("functions");}
#line 1658 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 94 "lab3.y" /* yacc.c:1646  */
    {printf(":\n");}
#line 1664 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 96 "lab3.y" /* yacc.c:1646  */
    {printf("\{\n");}
#line 1670 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 96 "lab3.y" /* yacc.c:1646  */
    {printf("\}\n");}
#line 1676 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 97 "lab3.y" /* yacc.c:1646  */
    {printf("main");}
#line 1682 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 97 "lab3.y" /* yacc.c:1646  */
    {printf("%s",yylval.string);}
#line 1688 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 97 "lab3.y" /* yacc.c:1646  */
    {printf("\(");}
#line 1694 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 97 "lab3.y" /* yacc.c:1646  */
    {printf("\)");}
#line 1700 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 99 "lab3.y" /* yacc.c:1646  */
    {printf(", ");}
#line 1706 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 100 "lab3.y" /* yacc.c:1646  */
    {printf("%s",yylval.string);}
#line 1712 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 101 "lab3.y" /* yacc.c:1646  */
    {printf("local ");tab++;}
#line 1718 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 101 "lab3.y" /* yacc.c:1646  */
    {printf(":\n");}
#line 1724 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 101 "lab3.y" /* yacc.c:1646  */
    {tab--;}
#line 1730 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 102 "lab3.y" /* yacc.c:1646  */
    {printf("statements");}
#line 1736 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 102 "lab3.y" /* yacc.c:1646  */
    {printf(":\n");tab++;}
#line 1742 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 102 "lab3.y" /* yacc.c:1646  */
    {tab--;}
#line 1748 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 104 "lab3.y" /* yacc.c:1646  */
    {FromIfStat=0;}
#line 1754 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 104 "lab3.y" /* yacc.c:1646  */
    {tabular();}
#line 1760 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 104 "lab3.y" /* yacc.c:1646  */
    {tabular();}
#line 1766 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 104 "lab3.y" /* yacc.c:1646  */
    {tabular();}
#line 1772 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 105 "lab3.y" /* yacc.c:1646  */
    {tabular();}
#line 1778 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 105 "lab3.y" /* yacc.c:1646  */
    {tabular();}
#line 1784 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 105 "lab3.y" /* yacc.c:1646  */
    {tabular();}
#line 1790 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 105 "lab3.y" /* yacc.c:1646  */
    {tabular();if(FromIfStat){printf("\n");tab++;tabular();tab--;}}
#line 1796 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 106 "lab3.y" /* yacc.c:1646  */
    {tabular();}
#line 1802 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 106 "lab3.y" /* yacc.c:1646  */
    {tabular();}
#line 1808 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 106 "lab3.y" /* yacc.c:1646  */
    {printf(";\n");}
#line 1814 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 107 "lab3.y" /* yacc.c:1646  */
    {printf("\{\n");}
#line 1820 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 107 "lab3.y" /* yacc.c:1646  */
    {tab++;}
#line 1826 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 107 "lab3.y" /* yacc.c:1646  */
    {tab--;}
#line 1832 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 107 "lab3.y" /* yacc.c:1646  */
    {tabular();printf("\}\n");}
#line 1838 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 108 "lab3.y" /* yacc.c:1646  */
    {printf("if");}
#line 1844 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 108 "lab3.y" /* yacc.c:1646  */
    {printf("\(");}
#line 1850 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 108 "lab3.y" /* yacc.c:1646  */
    {printf("\)");}
#line 1856 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 108 "lab3.y" /* yacc.c:1646  */
    {FromIfStat=1;}
#line 1862 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 108 "lab3.y" /* yacc.c:1646  */
    {FromIfStat=0;}
#line 1868 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 109 "lab3.y" /* yacc.c:1646  */
    {tab++;}
#line 1874 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 109 "lab3.y" /* yacc.c:1646  */
    {tab--;}
#line 1880 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 110 "lab3.y" /* yacc.c:1646  */
    {printf("while");}
#line 1886 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 110 "lab3.y" /* yacc.c:1646  */
    {printf("\(");}
#line 1892 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 110 "lab3.y" /* yacc.c:1646  */
    {printf("\)");}
#line 1898 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 111 "lab3.y" /* yacc.c:1646  */
    {printf("\(");}
#line 1904 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 111 "lab3.y" /* yacc.c:1646  */
    {printf("\)");}
#line 1910 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 111 "lab3.y" /* yacc.c:1646  */
    {printf(";\n");}
#line 1916 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 112 "lab3.y" /* yacc.c:1646  */
    {printf("for");}
#line 1922 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 112 "lab3.y" /* yacc.c:1646  */
    {printf("\(");}
#line 1928 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 112 "lab3.y" /* yacc.c:1646  */
    {printf("<-");}
#line 1934 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 112 "lab3.y" /* yacc.c:1646  */
    {printf(";");}
#line 1940 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 113 "lab3.y" /* yacc.c:1646  */
    {printf(";");}
#line 1946 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 113 "lab3.y" /* yacc.c:1646  */
    {printf("<-");}
#line 1952 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 114 "lab3.y" /* yacc.c:1646  */
    {printf("\)");}
#line 1958 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 115 "lab3.y" /* yacc.c:1646  */
    {printf("read");}
#line 1964 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 115 "lab3.y" /* yacc.c:1646  */
    {printf("\(");}
#line 1970 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 115 "lab3.y" /* yacc.c:1646  */
    {printf("\)");}
#line 1976 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 115 "lab3.y" /* yacc.c:1646  */
    {printf(";\n");}
#line 1982 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 116 "lab3.y" /* yacc.c:1646  */
    {printf("read");}
#line 1988 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 116 "lab3.y" /* yacc.c:1646  */
    {printf(", ");}
#line 1994 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 117 "lab3.y" /* yacc.c:1646  */
    {printf("write");}
#line 2000 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 117 "lab3.y" /* yacc.c:1646  */
    {printf("\(");}
#line 2006 "y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 117 "lab3.y" /* yacc.c:1646  */
    {printf("\)");}
#line 2012 "y.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 117 "lab3.y" /* yacc.c:1646  */
    {printf(";\n");}
#line 2018 "y.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 118 "lab3.y" /* yacc.c:1646  */
    {printf(", ");}
#line 2024 "y.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 119 "lab3.y" /* yacc.c:1646  */
    {printf("%s",yylval.string);}
#line 2030 "y.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 120 "lab3.y" /* yacc.c:1646  */
    {printf("call ");}
#line 2036 "y.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 120 "lab3.y" /* yacc.c:1646  */
    {printf(";\n");}
#line 2042 "y.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 121 "lab3.y" /* yacc.c:1646  */
    {printf("%s",yylval.string);}
#line 2048 "y.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 121 "lab3.y" /* yacc.c:1646  */
    {printf("\(");}
#line 2054 "y.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 121 "lab3.y" /* yacc.c:1646  */
    {printf("\)");}
#line 2060 "y.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 123 "lab3.y" /* yacc.c:1646  */
    {printf("return");}
#line 2066 "y.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 123 "lab3.y" /* yacc.c:1646  */
    {printf(";\n");}
#line 2072 "y.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 123 "lab3.y" /* yacc.c:1646  */
    {printf("return");}
#line 2078 "y.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 123 "lab3.y" /* yacc.c:1646  */
    {printf(";\n");}
#line 2084 "y.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 124 "lab3.y" /* yacc.c:1646  */
    {printf("<-");}
#line 2090 "y.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 124 "lab3.y" /* yacc.c:1646  */
    {printf(";\n");}
#line 2096 "y.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 125 "lab3.y" /* yacc.c:1646  */
    {printf(", ");}
#line 2102 "y.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 126 "lab3.y" /* yacc.c:1646  */
    {printf(" | ");}
#line 2108 "y.tab.c" /* yacc.c:1646  */
    break;

  case 141:
#line 127 "lab3.y" /* yacc.c:1646  */
    {printf(" & ");}
#line 2114 "y.tab.c" /* yacc.c:1646  */
    break;

  case 144:
#line 128 "lab3.y" /* yacc.c:1646  */
    {printf("!");}
#line 2120 "y.tab.c" /* yacc.c:1646  */
    break;

  case 147:
#line 129 "lab3.y" /* yacc.c:1646  */
    {
    switch((yyvsp[0].atr)){
      case RELOP_1:
        printf("<");
        break;
      case RELOP_2:
        printf("<=");
        break;
      case RELOP_3:
        printf(">");
        break;
      case RELOP_4:
        printf(">=");
        break;
      case RELOP_5:
        printf("=");
        break;
      case RELOP_6:
        printf("!=");
        break;
    };
}
#line 2147 "y.tab.c" /* yacc.c:1646  */
    break;

  case 150:
#line 151 "lab3.y" /* yacc.c:1646  */
    {if((yyvsp[0].atr) == ADOP_1) printf("+"); else printf("-"); }
#line 2153 "y.tab.c" /* yacc.c:1646  */
    break;

  case 153:
#line 152 "lab3.y" /* yacc.c:1646  */
    {
    switch((yyvsp[0].atr)){
      case MULTOP_1:
        printf("*");
        break;
      case MULTOP_2:
        printf("/");
        break;
      case MULTOP_3:
        printf("%%");
        break;
    };
}
#line 2171 "y.tab.c" /* yacc.c:1646  */
    break;

  case 156:
#line 165 "lab3.y" /* yacc.c:1646  */
    {printf("%d",yylval.valor);}
#line 2177 "y.tab.c" /* yacc.c:1646  */
    break;

  case 157:
#line 165 "lab3.y" /* yacc.c:1646  */
    {printf("%f",yylval.valreal);}
#line 2183 "y.tab.c" /* yacc.c:1646  */
    break;

  case 158:
#line 165 "lab3.y" /* yacc.c:1646  */
    {printf("%s",yylval.string);}
#line 2189 "y.tab.c" /* yacc.c:1646  */
    break;

  case 159:
#line 166 "lab3.y" /* yacc.c:1646  */
    {printf("true");}
#line 2195 "y.tab.c" /* yacc.c:1646  */
    break;

  case 160:
#line 166 "lab3.y" /* yacc.c:1646  */
    {printf("false");}
#line 2201 "y.tab.c" /* yacc.c:1646  */
    break;

  case 161:
#line 166 "lab3.y" /* yacc.c:1646  */
    {printf("~");}
#line 2207 "y.tab.c" /* yacc.c:1646  */
    break;

  case 163:
#line 167 "lab3.y" /* yacc.c:1646  */
    {printf("\(");}
#line 2213 "y.tab.c" /* yacc.c:1646  */
    break;

  case 164:
#line 167 "lab3.y" /* yacc.c:1646  */
    {printf("\)");}
#line 2219 "y.tab.c" /* yacc.c:1646  */
    break;

  case 166:
#line 168 "lab3.y" /* yacc.c:1646  */
    {printf("%s",(yyvsp[0].string));}
#line 2225 "y.tab.c" /* yacc.c:1646  */
    break;

  case 169:
#line 169 "lab3.y" /* yacc.c:1646  */
    {printf("[");}
#line 2231 "y.tab.c" /* yacc.c:1646  */
    break;

  case 170:
#line 169 "lab3.y" /* yacc.c:1646  */
    {printf("]");}
#line 2237 "y.tab.c" /* yacc.c:1646  */
    break;

  case 172:
#line 170 "lab3.y" /* yacc.c:1646  */
    {printf(", ");}
#line 2243 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2247 "y.tab.c" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



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
                      yytoken, &yylval);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
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

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 171 "lab3.y" /* yacc.c:1906  */

#include "lex.yy.c"
void tabular () {
	int i;
	for (i = 1; i <= tab; i++)
   		printf ("\t");
}
