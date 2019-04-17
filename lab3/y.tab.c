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

#line 89 "y.tab.c" /* yacc.c:339  */

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
#line 23 "lab3.y" /* yacc.c:355  */

	char string[100];
  char carac;
	int atr;
	int valor;
	float valreal;

#line 232 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);



/* Copy the second part of user declarations.  */

#line 249 "y.tab.c" /* yacc.c:358  */

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
#define YYLAST   192

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  50
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  98
/* YYNRULES -- Number of rules.  */
#define YYNRULES  146
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  235

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
       0,    84,    84,    84,    84,    84,    85,    85,    85,    85,
      86,    86,    87,    88,    88,    88,    88,    88,    89,    89,
      89,    90,    90,    91,    91,    91,    92,    92,    92,    93,
      93,    94,    94,    95,    95,    95,    96,    96,    96,    97,
      97,    98,    98,    98,    99,   100,   100,   100,   100,   101,
     101,   101,   102,   102,   103,   103,   103,   103,   104,   104,
     104,   104,   105,   105,   105,   106,   106,   107,   107,   107,
     108,   108,   109,   109,   109,   110,   110,   110,   111,   111,
     112,   113,   111,   114,   114,   114,   114,   115,   115,   115,
     115,   116,   116,   116,   116,   117,   117,   117,   118,   118,
     119,   119,   120,   120,   121,   121,   122,   122,   122,   122,
     123,   123,   124,   124,   124,   125,   125,   125,   126,   126,
     126,   127,   127,   127,   128,   128,   129,   129,   130,   130,
     131,   131,   131,   131,   132,   132,   132,   133,   133,   133,
     134,   135,   135,   135,   136,   136,   136
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
  "$@10", "FuncList", "Function", "$@11", "$@12", "Header", "$@13",
  "Params", "ParamList", "$@14", "Parameter", "LocDecls", "$@15", "$@16",
  "Stats", "$@17", "$@18", "StatList", "Statement", "CompStat", "$@19",
  "IfStat", "$@20", "$@21", "ElseStat", "WhileStat", "$@22", "$@23",
  "DoStat", "$@24", "$@25", "ForStat", "$@26", "$@27", "$@28", "$@29",
  "ReadStat", "$@30", "$@31", "$@32", "ReadList", "$@33", "$@34",
  "WriteStat", "$@35", "$@36", "$@37", "WriteList", "$@38", "WriteElem",
  "CallStat", "$@39", "FuncCall", "$@40", "Arguments", "ReturnStat",
  "$@41", "$@42", "AssignStat", "$@43", "ExprList", "$@44", "Expression",
  "$@45", "AuxExpr1", "$@46", "AuxExpr2", "$@47", "AuxExpr3", "AuxExpr4",
  "Term", "Factor", "$@48", "Variable", "Subscripts", "$@49", "SubscrList",
  "$@50", YY_NULLPTR
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

#define YYPACT_NINF -138

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-138)))

#define YYTABLE_NINF -107

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       0,  -138,    22,     8,  -138,    -2,  -138,  -138,    36,  -138,
      45,    38,    39,    16,  -138,  -138,  -138,    62,    30,  -138,
    -138,  -138,  -138,  -138,    62,  -138,    66,  -138,    77,    30,
    -138,    61,  -138,  -138,    70,  -138,    73,  -138,  -138,    86,
    -138,  -138,  -138,  -138,  -138,  -138,    66,    62,   104,   102,
    -138,   106,    92,    87,  -138,  -138,   114,  -138,    12,  -138,
    -138,  -138,    89,  -138,    95,  -138,  -138,    62,  -138,   101,
    -138,   116,  -138,    62,  -138,  -138,    62,  -138,    64,  -138,
      64,   110,   112,  -138,    98,   113,  -138,   115,  -138,  -138,
    -138,  -138,  -138,  -138,  -138,  -138,  -138,  -138,  -138,  -138,
    -138,   121,   132,   137,  -138,  -138,   122,   117,    96,  -138,
     124,  -138,  -138,  -138,  -138,   125,   120,   127,   142,    96,
    -138,  -138,  -138,  -138,    53,  -138,  -138,  -138,  -138,   119,
    -138,  -138,   -24,   136,  -138,  -138,    60,   133,  -138,  -138,
      96,  -138,   119,     6,    96,  -138,  -138,  -138,   131,    -8,
     142,   119,  -138,    96,  -138,  -138,  -138,   119,   119,   119,
      13,    72,   135,    32,  -138,   -19,    96,    96,    96,  -138,
     134,  -138,  -138,    28,    96,    96,   135,   133,  -138,  -138,
    -138,   -30,  -138,   141,  -138,  -138,  -138,   138,   129,   141,
      40,   -18,    64,  -138,   130,  -138,   136,  -138,    64,  -138,
    -138,   119,  -138,  -138,  -138,  -138,   167,   139,  -138,  -138,
     140,    72,   135,    96,   143,    96,    64,  -138,  -138,   142,
    -138,  -138,   141,  -138,    -3,  -138,  -138,  -138,   142,   144,
      96,    50,  -138,    64,  -138
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     2,     0,     0,     1,     0,     3,     4,     6,     7,
       0,     0,     0,     0,     8,    29,     5,     0,     0,    15,
      14,    13,    16,    17,     9,    10,     0,    36,     0,    30,
      31,     0,    11,    21,     0,    18,     0,    32,    33,    23,
      12,    19,    37,    34,    24,    22,     0,    39,    45,     0,
      20,     0,     0,    40,    41,    46,     0,    26,     0,    44,
      38,    42,     0,    49,     0,    25,    27,     0,    47,     0,
      35,     0,    43,     0,    50,    28,    48,    52,    51,   100,
       0,     0,     0,    83,   108,     0,    91,   141,    65,    64,
      53,    54,    55,    56,    57,    58,    59,    60,    62,    63,
      61,     0,     0,     0,    78,    67,     0,     0,     0,    72,
       0,   142,   140,    52,   110,     0,     0,     0,     0,     0,
      84,   107,   135,   134,   141,   131,   133,   132,   122,     0,
     137,   139,     0,   115,   118,   121,   124,   126,   128,   130,
       0,    92,     0,     0,     0,   102,   101,    75,     0,     0,
       0,     0,   136,     0,   116,   109,   119,     0,     0,     0,
       0,     0,   144,     0,    66,     0,   104,     0,     0,    68,
      88,    87,   123,     0,     0,     0,   125,   127,   129,    73,
      98,     0,    95,    99,   143,   145,   111,     0,   105,   112,
       0,     0,     0,    85,     0,   138,   117,   120,     0,    93,
      96,     0,   103,   113,    76,    79,    70,     0,    89,    74,
       0,     0,   146,     0,     0,     0,     0,    69,    86,     0,
      94,    97,   114,    77,     0,    71,    90,    80,     0,     0,
       0,     0,    81,     0,    82
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -138,  -138,  -138,  -138,  -138,  -138,  -138,  -138,   107,   -20,
     -10,  -138,  -138,   145,  -138,  -138,  -138,  -138,  -138,  -138,
    -138,  -138,   148,  -138,  -138,  -138,  -138,  -138,  -138,  -138,
     123,  -138,  -138,  -138,  -138,  -138,  -138,    68,   -79,  -138,
    -138,  -138,  -138,  -138,  -138,  -138,  -138,  -138,  -138,  -138,
    -138,  -138,  -138,  -138,  -138,  -138,  -138,  -138,  -138,  -138,
    -138,  -138,  -138,  -138,  -138,  -138,  -138,  -138,  -138,   -32,
    -138,  -138,    81,  -138,  -138,  -138,  -138,  -138,  -138,  -138,
    -138,  -138,  -105,  -138,    15,  -138,    11,  -138,    41,  -137,
      29,  -123,  -138,   -78,  -138,  -138,  -138,  -138
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     7,     8,    10,    11,    17,    24,    25,
      26,    34,    46,    35,    39,    45,    49,    58,    71,    13,
      18,    29,    30,    43,    48,    31,    47,    52,    53,    67,
      54,    56,    62,    73,    64,    69,    77,    78,    90,    91,
     113,    92,   119,   192,   217,    93,   140,   198,    94,   167,
     214,    95,   118,   215,   228,   233,    96,   106,   150,   207,
     170,   194,   219,    97,   110,   161,   210,   181,   211,   182,
      98,   102,   131,   166,   187,    99,   107,   108,   100,   144,
     188,   213,   183,   174,   133,   175,   134,   151,   135,   136,
     137,   138,   153,   139,   112,   142,   163,   201
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     101,   103,   101,   132,    32,   162,   152,   154,    28,    79,
     199,    80,   154,   154,   149,    81,   200,     1,    82,    28,
     176,   155,     4,   154,    83,    84,   186,   205,   154,    85,
      86,    87,   169,     5,    19,   160,   178,    51,    20,   165,
     148,     6,   227,    21,   154,    22,    27,     9,   173,    88,
     164,    89,    23,   179,    65,    12,    32,    51,    66,   154,
      16,   189,   190,   191,   212,   101,    19,    79,   195,    80,
      20,   154,   171,    81,   184,    21,    82,    22,   185,   122,
     204,   154,    83,    84,    23,    14,    15,    85,    86,    87,
     232,    33,   145,   123,   111,   157,   158,   124,   125,   126,
     127,   180,    36,   122,    38,   128,   129,    88,   222,    89,
     224,   130,    42,   206,   101,    40,    41,   123,    55,   209,
     101,   124,   125,   126,   127,   231,   122,    44,    57,   128,
     129,    59,    60,    61,    63,   130,    68,   225,   101,    70,
     123,   226,    75,  -106,   124,   125,   126,   127,    74,   104,
     229,   105,   109,   129,   234,   101,   111,   115,   130,   114,
     117,   120,   121,   141,   145,   146,   147,    87,   156,   168,
     159,   158,   154,   216,   193,   203,   208,    37,   202,   221,
      76,   143,   230,   116,   218,   220,   197,   177,   223,   196,
      72,    50,   172
};

static const yytype_uint8 yycheck[] =
{
      78,    80,    80,   108,    24,   142,   129,    31,    18,     3,
      40,     5,    31,    31,   119,     9,    46,    17,    12,    29,
     157,    45,     0,    31,    18,    19,    45,    45,    31,    23,
      24,    25,    40,    25,     4,   140,   159,    47,     8,   144,
     118,    43,    45,    13,    31,    15,    16,    11,   153,    43,
      44,    45,    22,    40,    42,    10,    76,    67,    46,    31,
      44,   166,   167,   168,   201,   143,     4,     3,    40,     5,
       8,    31,   150,     9,    42,    13,    12,    15,    46,     7,
      40,    31,    18,    19,    22,    47,    47,    23,    24,    25,
      40,    25,    39,    21,    41,    35,    36,    25,    26,    27,
      28,    29,    25,     7,    43,    33,    34,    43,   213,    45,
     215,    39,    39,   192,   192,    45,    46,    21,    14,   198,
     198,    25,    26,    27,    28,   230,     7,    41,    26,    33,
      34,    25,    40,    46,    20,    39,    47,   216,   216,    44,
      21,   219,    26,    45,    25,    26,    27,    28,    47,    39,
     228,    39,    39,    34,   233,   233,    41,    25,    39,    38,
      23,    39,    45,    39,    39,    45,    39,    25,    32,    38,
      37,    36,    31,     6,    40,    46,    46,    29,    40,   211,
      73,   113,    38,   102,    45,    45,   175,   158,    45,   174,
      67,    46,   151
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    17,    51,    52,     0,    25,    43,    53,    54,    11,
      55,    56,    10,    69,    47,    47,    44,    57,    70,     4,
       8,    13,    15,    22,    58,    59,    60,    16,    60,    71,
      72,    75,    59,    25,    61,    63,    25,    72,    43,    64,
      45,    46,    39,    73,    41,    65,    62,    76,    74,    66,
      63,    60,    77,    78,    80,    14,    81,    26,    67,    25,
      40,    46,    82,    20,    84,    42,    46,    79,    47,    85,
      44,    68,    80,    83,    47,    26,    58,    86,    87,     3,
       5,     9,    12,    18,    19,    23,    24,    25,    43,    45,
      88,    89,    91,    95,    98,   101,   106,   113,   120,   125,
     128,   143,   121,    88,    39,    39,   107,   126,   127,    39,
     114,    41,   144,    90,    38,    25,   122,    23,   102,    92,
      39,    45,     7,    21,    25,    26,    27,    28,    33,    34,
      39,   122,   132,   134,   136,   138,   139,   140,   141,   143,
      96,    39,   145,    87,   129,    39,    45,    39,   143,   132,
     108,   137,   141,   142,    31,    45,    32,    35,    36,    37,
     132,   115,   139,   146,    44,   132,   123,    99,    38,    40,
     110,   143,   138,   132,   133,   135,   139,   140,   141,    40,
      29,   117,   119,   132,    42,    46,    45,   124,   130,   132,
     132,   132,    93,    40,   111,    40,   134,   136,    97,    40,
      46,   147,    40,    46,    40,    45,    88,   109,    46,    88,
     116,   118,   139,   131,   100,   103,     6,    94,    45,   112,
      45,   119,   132,    45,   132,    88,   143,    45,   104,   143,
      38,   132,    40,   105,    88
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    50,    52,    53,    54,    51,    55,    56,    57,    55,
      58,    58,    59,    60,    60,    60,    60,    60,    61,    62,
      61,    64,    63,    65,    66,    65,    67,    68,    67,    70,
      69,    71,    71,    73,    74,    72,    75,    76,    75,    77,
      77,    78,    79,    78,    80,    81,    82,    83,    81,    85,
      86,    84,    87,    87,    88,    88,    88,    88,    88,    88,
      88,    88,    88,    88,    88,    90,    89,    92,    93,    91,
      94,    94,    96,    97,    95,    99,   100,    98,   102,   103,
     104,   105,   101,   107,   108,   109,   106,   110,   111,   112,
     110,   114,   115,   116,   113,   117,   118,   117,   119,   119,
     121,   120,   123,   122,   124,   124,   126,   125,   127,   125,
     129,   128,   130,   131,   130,   132,   133,   132,   134,   135,
     134,   136,   137,   136,   138,   138,   139,   139,   140,   140,
     141,   141,   141,   141,   141,   141,   141,   142,   141,   141,
     143,   144,   145,   144,   146,   147,   146
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     0,     0,     9,     0,     0,     0,     5,
       1,     2,     3,     1,     1,     1,     1,     1,     1,     0,
       4,     0,     3,     0,     0,     4,     1,     0,     4,     0,
       4,     1,     2,     0,     0,     7,     1,     0,     6,     0,
       1,     1,     0,     4,     2,     0,     0,     0,     5,     0,
       0,     5,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     0,     4,     0,     0,     8,
       0,     2,     0,     0,     7,     0,     0,     9,     0,     0,
       0,     0,    17,     0,     0,     0,     8,     1,     0,     0,
       5,     0,     0,     0,     8,     1,     0,     4,     1,     1,
       0,     4,     0,     5,     0,     1,     0,     3,     0,     4,
       0,     5,     1,     0,     4,     1,     0,     4,     1,     0,
       4,     1,     0,     3,     1,     3,     1,     3,     1,     3,
       1,     1,     1,     1,     1,     1,     2,     0,     4,     1,
       2,     0,     0,     4,     1,     0,     4
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
#line 84 "lab3.y" /* yacc.c:1646  */
    {printf("program ");}
#line 1509 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 84 "lab3.y" /* yacc.c:1646  */
    {printf("\{\n");}
#line 1515 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 84 "lab3.y" /* yacc.c:1646  */
    {printf("\{\n");}
#line 1521 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 84 "lab3.y" /* yacc.c:1646  */
    {printf("\}\n");}
#line 1527 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 85 "lab3.y" /* yacc.c:1646  */
    {printf("global");}
#line 1533 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 85 "lab3.y" /* yacc.c:1646  */
    {printf(":\n");}
#line 1539 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 87 "lab3.y" /* yacc.c:1646  */
    {printf(";\n");}
#line 1545 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 88 "lab3.y" /* yacc.c:1646  */
    {printf("int ");}
#line 1551 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 88 "lab3.y" /* yacc.c:1646  */
    {printf("float ");}
#line 1557 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 88 "lab3.y" /* yacc.c:1646  */
    {printf("char ");}
#line 1563 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 88 "lab3.y" /* yacc.c:1646  */
    {printf("logic ");}
#line 1569 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 88 "lab3.y" /* yacc.c:1646  */
    {printf("void ");}
#line 1575 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 89 "lab3.y" /* yacc.c:1646  */
    {printf(", ");}
#line 1581 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 90 "lab3.y" /* yacc.c:1646  */
    {printf("%s", (yyvsp[0].string)); }
#line 1587 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 91 "lab3.y" /* yacc.c:1646  */
    {printf("[");}
#line 1593 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 91 "lab3.y" /* yacc.c:1646  */
    {printf("]");}
#line 1599 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 92 "lab3.y" /* yacc.c:1646  */
    {printf("%d",(yyvsp[0].valor));}
#line 1605 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 92 "lab3.y" /* yacc.c:1646  */
    {printf(", ");}
#line 1611 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 93 "lab3.y" /* yacc.c:1646  */
    {printf(":\n");}
#line 1617 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 95 "lab3.y" /* yacc.c:1646  */
    {printf("\{\n");}
#line 1623 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 95 "lab3.y" /* yacc.c:1646  */
    {printf("\{\n");}
#line 1629 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 95 "lab3.y" /* yacc.c:1646  */
    {printf("\}\n");}
#line 1635 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 96 "lab3.y" /* yacc.c:1646  */
    {printf("\(\n");}
#line 1641 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 96 "lab3.y" /* yacc.c:1646  */
    {printf("\)\n");}
#line 1647 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 98 "lab3.y" /* yacc.c:1646  */
    {printf(", ");}
#line 1653 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 100 "lab3.y" /* yacc.c:1646  */
    {printf("local ");}
#line 1659 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 100 "lab3.y" /* yacc.c:1646  */
    {printf(":\n");}
#line 1665 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 101 "lab3.y" /* yacc.c:1646  */
    {printf("statements ");}
#line 1671 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 101 "lab3.y" /* yacc.c:1646  */
    {printf(":\n");}
#line 1677 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 105 "lab3.y" /* yacc.c:1646  */
    {printf(";\n");}
#line 1683 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 106 "lab3.y" /* yacc.c:1646  */
    {printf("\{\n");}
#line 1689 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 106 "lab3.y" /* yacc.c:1646  */
    {printf("\}\n");}
#line 1695 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 107 "lab3.y" /* yacc.c:1646  */
    {printf("\(\n");}
#line 1701 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 107 "lab3.y" /* yacc.c:1646  */
    {printf("\)\n");}
#line 1707 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 109 "lab3.y" /* yacc.c:1646  */
    {printf("\(\n");}
#line 1713 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 109 "lab3.y" /* yacc.c:1646  */
    {printf("\)\n");}
#line 1719 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 110 "lab3.y" /* yacc.c:1646  */
    {printf("\(\n");}
#line 1725 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 110 "lab3.y" /* yacc.c:1646  */
    {printf("\)\n");}
#line 1731 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 110 "lab3.y" /* yacc.c:1646  */
    {printf(";\n");}
#line 1737 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 111 "lab3.y" /* yacc.c:1646  */
    {printf("\(\n");}
#line 1743 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 111 "lab3.y" /* yacc.c:1646  */
    {printf(";\n");}
#line 1749 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 112 "lab3.y" /* yacc.c:1646  */
    {printf(";\n");}
#line 1755 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 113 "lab3.y" /* yacc.c:1646  */
    {printf("\)\n");}
#line 1761 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 114 "lab3.y" /* yacc.c:1646  */
    {printf("read ");}
#line 1767 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 114 "lab3.y" /* yacc.c:1646  */
    {printf("\(\n");}
#line 1773 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 114 "lab3.y" /* yacc.c:1646  */
    {printf("\)\n");}
#line 1779 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 114 "lab3.y" /* yacc.c:1646  */
    {printf(";\n");}
#line 1785 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 115 "lab3.y" /* yacc.c:1646  */
    {printf("read");}
#line 1791 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 115 "lab3.y" /* yacc.c:1646  */
    {printf(", ");}
#line 1797 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 116 "lab3.y" /* yacc.c:1646  */
    {printf("write ");}
#line 1803 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 116 "lab3.y" /* yacc.c:1646  */
    {printf("\(\n");}
#line 1809 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 116 "lab3.y" /* yacc.c:1646  */
    {printf("\)\n");}
#line 1815 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 116 "lab3.y" /* yacc.c:1646  */
    {printf(";\n");}
#line 1821 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 117 "lab3.y" /* yacc.c:1646  */
    {printf(", ");}
#line 1827 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 119 "lab3.y" /* yacc.c:1646  */
    {printf("call ")}
#line 1833 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 119 "lab3.y" /* yacc.c:1646  */
    {printf(";\n");}
#line 1839 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 120 "lab3.y" /* yacc.c:1646  */
    {printf("\(\n");}
#line 1845 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 120 "lab3.y" /* yacc.c:1646  */
    {printf("\)\n");}
#line 1851 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 122 "lab3.y" /* yacc.c:1646  */
    {printf("return");}
#line 1857 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 122 "lab3.y" /* yacc.c:1646  */
    {printf(";\n");}
#line 1863 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 122 "lab3.y" /* yacc.c:1646  */
    {printf("return");}
#line 1869 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 122 "lab3.y" /* yacc.c:1646  */
    {printf(";\n");}
#line 1875 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 123 "lab3.y" /* yacc.c:1646  */
    {printf(" <- ");}
#line 1881 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 123 "lab3.y" /* yacc.c:1646  */
    {printf(";\n");}
#line 1887 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 124 "lab3.y" /* yacc.c:1646  */
    {printf(", ");}
#line 1893 "y.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 125 "lab3.y" /* yacc.c:1646  */
    {printf(" | ");}
#line 1899 "y.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 126 "lab3.y" /* yacc.c:1646  */
    {printf(" & ");}
#line 1905 "y.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 127 "lab3.y" /* yacc.c:1646  */
    {printf(" ! ");}
#line 1911 "y.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 133 "lab3.y" /* yacc.c:1646  */
    {printf("\(\n");}
#line 1917 "y.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 133 "lab3.y" /* yacc.c:1646  */
    {printf("\)\n");}
#line 1923 "y.tab.c" /* yacc.c:1646  */
    break;

  case 142:
#line 135 "lab3.y" /* yacc.c:1646  */
    {printf("[");}
#line 1929 "y.tab.c" /* yacc.c:1646  */
    break;

  case 143:
#line 135 "lab3.y" /* yacc.c:1646  */
    {printf("]");}
#line 1935 "y.tab.c" /* yacc.c:1646  */
    break;

  case 145:
#line 136 "lab3.y" /* yacc.c:1646  */
    {printf(", ");}
#line 1941 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1945 "y.tab.c" /* yacc.c:1646  */
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
#line 137 "lab3.y" /* yacc.c:1906  */

#include "lex.yy.c"
void tabular () {
	int i;
	for (i = 1; i <= tab; i++)
   		printf ("\t");
}
