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
#line 1 "lab4.y" /* yacc.c:339  */

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

/* 	Definicao dos atributos dos atomos operadores   */

#define 		LT 		1
#define 		LE 		2
#define		GT		3
#define		GE		4
#define		EQ		5
#define		NE		6
#define		MAIS     	7
#define		MENOS    	8
#define		MULT    	9
#define		DIV   		10
#define		RESTO   	11

/*   Definicao dos tipos de identificadores   */

#define 	IDPROG			1
#define 	IDVAR_LOCAL		2
#define 	IDVAR_GLOBAL	3
#define		IDVAR_FUNC		4

/*  Definicao dos tipos de variaveis   */

#define 	NAOVAR		0
#define 	INTEIRO		1
#define 	LOGICO		2
#define 	REAL		3
#define 	CARACTERE	4

/*   Definicao de outras constantes   */

#define	NCLASSHASH	23
#define	VERDADE		1
#define	FALSO		0

/*  Strings para nomes dos tipos de identificadores  */

char *nometipid[4] = {" ", "IDPROG", "IDVAR_LOCAL", "IDVAR_GLOBAL", "IDVAR_GLOBAL"};

/*  Strings para nomes dos tipos de variaveis  */

char *nometipvar[5] = {"NAOVAR",
	"INTEIRO", "LOGICO", "REAL", "CARACTERE"
};

/*    Declaracoes para a tabela de simbolos     */

typedef struct celsimb celsimb;
typedef celsimb *simbolo;
struct celsimb {
	char *cadeia;
	int tid, tvar;
	char inic, ref;
	simbolo prox;
};

/*  Variaveis globais para a tabela de simbolos e analise semantica
 */

simbolo tabsimb[NCLASSHASH];
simbolo simb;

int tid;
int tipocorrente;

/*
	Prototipos das funcoes para a tabela de simbolos
    	e analise semantica
 */

void InicTabSimb (void);
void ImprimeTabSimb (void);
void VerificaInicRef (void);
simbolo InsereSimb (char *, int, int);
int hash (char *);
simbolo ProcuraSimb (char *, int);
void DeclaracaoRepetida (char *);
void TipoInadequado (char *);
void NaoDeclarado (char *);

#line 169 "y.tab.c" /* yacc.c:339  */

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
#line 106 "lab4.y" /* yacc.c:355  */

	char string[100];
  	char carac;
	int atr;
	int valor;
	float valreal;
  	simbolo simb;

#line 313 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);



/* Copy the second part of user declarations.  */

#line 330 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   211

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  50
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  126
/* YYNRULES -- Number of rules.  */
#define YYNRULES  174
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  263

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
static const yytype_uint16 yyrline[] =
{
       0,   170,   170,   170,   170,   170,   170,   170,   171,   171,
     171,   171,   172,   172,   173,   174,   174,   174,   174,   174,
     175,   175,   175,   176,   176,   177,   177,   177,   178,   178,
     178,   179,   179,   179,   180,   180,   181,   181,   182,   182,
     182,   182,   183,   183,   184,   184,   184,   185,   186,   186,
     186,   186,   187,   187,   187,   188,   188,   189,   189,   189,
     189,   189,   189,   189,   190,   190,   190,   190,   190,   190,
     190,   190,   191,   191,   191,   191,   191,   192,   192,   192,
     192,   193,   193,   193,   193,   194,   194,   194,   194,   195,
     195,   195,   195,   196,   196,   196,   197,   197,   197,   197,
     198,   198,   199,   197,   200,   200,   200,   200,   201,   201,
     201,   201,   202,   202,   202,   202,   203,   203,   203,   204,
     204,   205,   205,   206,   206,   206,   207,   207,   208,   208,
     208,   208,   209,   209,   209,   210,   210,   210,   211,   211,
     211,   212,   212,   212,   213,   213,   213,   214,   214,   214,
     236,   236,   236,   237,   237,   237,   250,   251,   252,   253,
     254,   255,   256,   256,   257,   257,   258,   259,   259,   267,
     267,   267,   268,   268,   268
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
  "$@4", "$@5", "GlobDecls", "$@6", "$@7", "DeclList", "Declaration",
  "Type", "ElemList", "$@8", "Elem", "$@9", "Dims", "$@10", "DimList",
  "$@11", "Functions", "$@12", "$@13", "FuncList", "Function", "$@14",
  "Header", "$@15", "$@16", "Params", "ParamList", "$@17", "Parameter",
  "LocDecls", "$@18", "$@19", "Stats", "$@20", "$@21", "StatList",
  "Statement", "$@22", "$@23", "$@24", "$@25", "$@26", "$@27", "$@28",
  "$@29", "$@30", "CompStat", "$@31", "$@32", "$@33", "IfStat", "$@34",
  "$@35", "$@36", "ElseStat", "$@37", "$@38", "WhileStat", "$@39", "$@40",
  "$@41", "DoStat", "$@42", "$@43", "ForStat", "$@44", "$@45", "$@46",
  "$@47", "$@48", "$@49", "$@50", "ReadStat", "$@51", "$@52", "$@53",
  "ReadList", "$@54", "$@55", "WriteStat", "$@56", "$@57", "$@58",
  "WriteList", "$@59", "WriteElem", "CallStat", "$@60", "FuncCall", "$@61",
  "$@62", "Arguments", "ReturnStat", "$@63", "$@64", "AssignStat", "$@65",
  "$@66", "ExprList", "$@67", "Expression", "$@68", "AuxExpr1", "$@69",
  "AuxExpr2", "$@70", "AuxExpr3", "$@71", "AuxExpr4", "$@72", "Term",
  "$@73", "Factor", "$@74", "$@75", "Variable", "$@76", "Subscripts",
  "$@77", "SubscrList", "$@78", YY_NULLPTR
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

#define YYPACT_NINF -162

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-162)))

#define YYTABLE_NINF -129

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -162,     9,   -10,  -162,  -162,    -6,  -162,   -22,  -162,    20,
    -162,    29,    -3,  -162,     2,  -162,     4,  -162,    12,  -162,
    -162,  -162,  -162,  -162,  -162,  -162,    12,  -162,    48,   157,
    -162,  -162,    45,  -162,  -162,    54,   157,  -162,    19,    56,
    -162,  -162,  -162,  -162,  -162,  -162,  -162,    48,    65,    92,
      86,  -162,  -162,  -162,    94,  -162,    63,    12,    70,  -162,
      72,  -162,  -162,    93,    79,    76,  -162,  -162,    80,  -162,
     100,  -162,  -162,  -162,    12,  -162,  -162,    12,    12,  -162,
    -162,     5,  -162,  -162,  -162,   120,   110,   130,   129,   122,
     117,   118,   141,   127,  -162,  -162,  -162,  -162,  -162,  -162,
      51,  -162,  -162,  -162,  -162,  -162,  -162,  -162,  -162,  -162,
    -162,  -162,  -162,   102,  -162,  -162,   109,   111,   126,   112,
     115,   116,   128,   125,   131,   123,   103,    40,  -162,  -162,
     135,  -162,  -162,  -162,  -162,  -162,  -162,  -162,   133,  -162,
    -162,  -162,   136,  -162,  -162,  -162,  -162,  -162,  -162,  -162,
     -13,   144,  -162,  -162,    57,   140,  -162,  -162,   137,   103,
     103,  -162,   118,   118,    74,   132,   103,   143,  -162,   132,
     132,   103,  -162,  -162,  -162,  -162,  -162,  -162,  -162,   -25,
     -18,   103,   142,   145,  -162,  -162,    21,  -162,   152,   148,
      69,    -5,  -162,  -162,  -162,    46,   103,   103,   132,   132,
     132,  -162,  -162,    47,  -162,  -162,   121,  -162,  -162,  -162,
    -162,  -162,   103,  -162,   144,  -162,   148,   140,  -162,    51,
      51,  -162,   103,   146,  -162,   147,    74,   132,   149,   150,
     152,   180,  -162,   153,     7,  -162,   118,  -162,  -162,   148,
    -162,  -162,  -162,  -162,  -162,  -162,  -162,   103,  -162,   103,
     152,    51,    37,  -162,  -162,   118,   155,  -162,   103,    49,
    -162,    51,  -162
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     1,     3,     0,     4,     0,     5,     8,
       9,     0,     0,    31,     0,    10,     0,     6,     0,    32,
       7,    17,    16,    15,    18,    19,    11,    12,     0,     0,
      13,    23,     0,    20,    38,     0,    33,    34,     0,    25,
      14,    21,    39,    35,    36,    26,    24,     0,     0,    48,
       0,    22,    40,    49,     0,    28,     0,    42,     0,    52,
       0,    27,    29,     0,     0,    43,    44,    50,     0,    37,
       0,    47,    41,    45,     0,    53,    30,     0,    51,    55,
      46,    54,    77,    76,    56,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    57,    78,    81,    59,    89,    61,
      58,    63,    96,    65,   104,    67,   112,    69,   167,    71,
     132,   121,    73,   130,    75,    55,     0,     0,     0,     0,
       0,     0,   169,     0,     0,     0,     0,    58,    82,    90,
       0,    97,   105,   113,   170,   168,   133,   123,     0,   129,
     161,   160,   167,   157,   159,   158,   145,   162,   164,   166,
       0,   138,   141,   144,   147,   150,   153,   156,     0,     0,
       0,    93,     0,     0,     0,     0,     0,     0,   122,     0,
       0,     0,   139,   131,   142,   148,   151,   154,    80,     0,
       0,     0,     0,   109,   108,   119,     0,   116,   120,   172,
       0,     0,   124,   146,   163,     0,     0,     0,     0,     0,
       0,    83,    91,     0,    98,   106,     0,   114,   117,   171,
     173,   134,   126,   165,   140,   143,   149,   152,   155,    58,
      58,    94,     0,     0,   110,     0,     0,     0,     0,   127,
     135,    85,    92,     0,     0,   107,     0,   115,   118,   174,
     125,   136,    86,    84,    95,    99,   111,     0,    87,     0,
     137,    58,     0,    88,   100,     0,     0,   101,     0,     0,
     102,    58,   103
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -162,  -162,  -162,  -162,  -162,  -162,  -162,  -162,  -162,  -162,
     113,   -23,   -24,  -162,  -162,   154,  -162,  -162,  -162,  -162,
    -162,  -162,  -162,  -162,  -162,   158,  -162,  -162,  -162,  -162,
    -162,  -162,  -162,   134,  -162,  -162,  -162,  -162,  -162,  -162,
      73,   -99,  -162,  -162,  -162,  -162,  -162,  -162,  -162,  -162,
    -162,  -162,  -162,  -162,  -162,  -162,  -162,  -162,  -162,  -162,
    -162,  -162,  -162,  -162,  -162,  -162,  -162,  -162,  -162,  -162,
    -162,  -162,  -162,  -162,  -162,  -162,  -162,  -162,  -162,  -162,
    -162,  -162,  -162,  -162,  -162,  -162,  -162,  -162,  -162,  -162,
     -36,  -162,  -162,    71,  -162,  -162,  -162,  -162,  -162,  -162,
    -162,  -162,  -162,  -162,  -162,  -124,  -162,     1,  -162,     3,
    -162,    30,  -162,  -161,  -162,     6,  -162,  -159,  -162,  -162,
     -91,  -162,  -162,  -162,  -162,  -162
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     5,     7,     9,    20,    11,    12,    18,
      26,    27,    28,    32,    47,    33,    39,    46,    50,    56,
      70,    14,    16,    29,    36,    37,    49,    38,    48,    57,
      64,    65,    77,    66,    54,    58,    74,    60,    68,    79,
      81,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,   115,   158,    97,   116,   159,   219,   243,
     248,   251,    99,   117,   160,   220,   101,   181,   233,   103,
     119,   162,   222,   249,   255,   258,   261,   105,   120,   163,
     223,   183,   206,   236,   107,   121,   164,   225,   186,   226,
     187,   112,   124,   149,   167,   212,   228,   114,   125,   126,
     109,   123,   166,   229,   247,   188,   196,   151,   197,   152,
     169,   153,   198,   154,   199,   155,   200,   156,   170,   171,
     157,   122,   135,   165,   190,   227
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     110,   118,   150,    30,   189,    35,   172,     4,   -72,     3,
     -62,   194,    35,   172,   -64,   201,    21,   -58,   172,     6,
      22,     8,   202,   -66,   -74,    23,   172,    24,   -60,   -68,
     -70,    10,   173,    63,    25,   179,   180,   216,   172,    13,
     211,   218,   191,   -72,    15,   -62,    17,   195,    82,   -64,
      83,    19,   245,    63,   -72,    30,   -62,   203,   -66,   -74,
     -64,   207,    44,   -60,   -68,   -70,   239,   208,   172,   -66,
     -74,   182,   184,    31,   -60,   -68,   -70,   172,   172,    42,
     172,   140,   254,    82,   -79,    83,   213,   221,   230,   260,
      40,    41,   175,   176,    82,   141,    83,    45,   234,   142,
     143,   144,   145,   185,    52,    61,    53,   146,   147,    62,
     140,   209,    55,   148,    59,   210,    69,    67,    71,    72,
     231,   232,    73,   250,   141,   252,    76,    75,   142,   143,
     144,   145,    96,    98,   259,   100,   146,   147,   102,   140,
     104,   106,   148,   108,   111,   246,   113,  -128,   128,   130,
     129,   131,   253,   141,   132,   133,   137,   142,   143,   144,
     145,    21,   262,   136,   256,    22,   147,   224,   139,   134,
      23,   148,    24,    34,   161,  -123,   174,   177,   168,    25,
     204,   178,   192,   172,   176,   205,   242,    78,   127,   240,
     238,   235,   237,   257,    43,   138,   241,   214,   244,   193,
     215,    51,     0,     0,     0,   217,     0,     0,     0,     0,
       0,    80
};

static const yytype_int16 yycheck[] =
{
      91,   100,   126,    26,   165,    29,    31,    17,     3,     0,
       5,   170,    36,    31,     9,    40,     4,    12,    31,    25,
       8,    43,    40,    18,    19,    13,    31,    15,    23,    24,
      25,    11,    45,    57,    22,   159,   160,   198,    31,    10,
      45,   200,   166,     3,    47,     5,    44,   171,    43,     9,
      45,    47,    45,    77,     3,    78,     5,   181,    18,    19,
       9,    40,    43,    23,    24,    25,   227,    46,    31,    18,
      19,   162,   163,    25,    23,    24,    25,    31,    31,    25,
      31,     7,    45,    43,    44,    45,    40,    40,   212,    40,
      45,    46,    35,    36,    43,    21,    45,    41,   222,    25,
      26,    27,    28,    29,    39,    42,    14,    33,    34,    46,
       7,    42,    26,    39,    20,    46,    44,    47,    25,    40,
     219,   220,    46,   247,    21,   249,    26,    47,    25,    26,
      27,    28,    12,    23,   258,     5,    33,    34,     9,     7,
      18,    24,    39,    25,     3,   236,    19,    45,    39,    23,
      39,    39,   251,    21,    39,    39,    25,    25,    26,    27,
      28,     4,   261,    38,   255,     8,    34,    46,    45,    41,
      13,    39,    15,    16,    39,    39,    32,    37,    45,    22,
      38,    44,    39,    31,    36,    40,     6,    74,   115,    40,
     226,    45,    45,    38,    36,   124,    46,   196,    45,   169,
     197,    47,    -1,    -1,    -1,   199,    -1,    -1,    -1,    -1,
      -1,    77
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    51,    52,     0,    17,    53,    25,    54,    43,    55,
      11,    57,    58,    10,    71,    47,    72,    44,    59,    47,
      56,     4,     8,    13,    15,    22,    60,    61,    62,    73,
      61,    25,    63,    65,    16,    62,    74,    75,    77,    66,
      45,    46,    25,    75,    43,    41,    67,    64,    78,    76,
      68,    65,    39,    14,    84,    26,    69,    79,    85,    20,
      87,    42,    46,    62,    80,    81,    83,    47,    88,    44,
      70,    25,    40,    46,    86,    47,    26,    82,    60,    89,
      83,    90,    43,    45,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,    12,   105,    23,   112,
       5,   116,     9,   119,    18,   127,    24,   134,    25,   150,
     170,     3,   141,    19,   147,   103,   106,   113,    91,   120,
     128,   135,   171,   151,   142,   148,   149,    90,    39,    39,
      23,    39,    39,    39,    41,   172,    38,    25,   143,    45,
       7,    21,    25,    26,    27,    28,    33,    34,    39,   143,
     155,   157,   159,   161,   163,   165,   167,   170,   104,   107,
     114,    39,   121,   129,   136,   173,   152,   144,    45,   160,
     168,   169,    31,    45,    32,    35,    36,    37,    44,   155,
     155,   117,   170,   131,   170,    29,   138,   140,   155,   163,
     174,   155,    39,   161,   167,   155,   156,   158,   162,   164,
     166,    40,    40,   155,    38,    40,   132,    40,    46,    42,
      46,    45,   145,    40,   157,   159,   163,   165,   167,   108,
     115,    40,   122,   130,    46,   137,   139,   175,   146,   153,
     155,    91,    91,   118,   155,    45,   133,    45,   140,   163,
      40,    46,     6,   109,    45,    45,   170,   154,   110,   123,
     155,   111,   155,    91,    45,   124,   170,    38,   125,   155,
      40,   126,    91
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    50,    52,    53,    54,    55,    56,    51,    57,    58,
      59,    57,    60,    60,    61,    62,    62,    62,    62,    62,
      63,    64,    63,    66,    65,    67,    68,    67,    69,    70,
      69,    72,    73,    71,    74,    74,    76,    75,    77,    78,
      79,    77,    80,    80,    81,    82,    81,    83,    84,    85,
      86,    84,    88,    89,    87,    90,    90,    91,    92,    91,
      93,    91,    94,    91,    95,    91,    96,    91,    97,    91,
      98,    91,    99,    91,   100,    91,    91,   102,   103,   104,
     101,   106,   107,   108,   105,   109,   110,   111,   109,   113,
     114,   115,   112,   117,   118,   116,   120,   121,   122,   123,
     124,   125,   126,   119,   128,   129,   130,   127,   131,   132,
     133,   131,   135,   136,   137,   134,   138,   139,   138,   140,
     140,   142,   141,   144,   145,   143,   146,   146,   148,   147,
     149,   147,   151,   152,   150,   153,   154,   153,   155,   156,
     155,   157,   158,   157,   159,   160,   159,   161,   162,   161,
     163,   164,   163,   165,   166,   165,   167,   167,   167,   167,
     167,   167,   168,   167,   169,   167,   167,   171,   170,   172,
     173,   172,   174,   175,   174
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     0,     0,     0,     0,    11,     0,     0,
       0,     5,     1,     2,     3,     1,     1,     1,     1,     1,
       1,     0,     4,     0,     3,     0,     0,     4,     1,     0,
       4,     0,     0,     5,     1,     2,     0,     6,     1,     0,
       0,     7,     0,     1,     1,     0,     4,     2,     0,     0,
       0,     5,     0,     0,     5,     0,     2,     1,     0,     2,
       0,     2,     0,     2,     0,     2,     0,     2,     0,     2,
       0,     2,     0,     2,     0,     2,     1,     0,     0,     0,
       6,     0,     0,     0,     9,     0,     0,     0,     4,     0,
       0,     0,     8,     0,     0,     9,     0,     0,     0,     0,
       0,     0,     0,    20,     0,     0,     0,     8,     1,     0,
       0,     5,     0,     0,     0,     8,     1,     0,     4,     1,
       1,     0,     4,     0,     0,     6,     0,     1,     0,     3,
       0,     4,     0,     0,     6,     1,     0,     4,     1,     0,
       4,     1,     0,     4,     1,     0,     3,     1,     0,     4,
       1,     0,     4,     1,     0,     4,     1,     1,     1,     1,
       1,     1,     0,     3,     0,     4,     1,     0,     3,     0,
       0,     4,     1,     0,     4
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
#line 170 "lab4.y" /* yacc.c:1646  */
    {InicTabSimb ();}
#line 1621 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 170 "lab4.y" /* yacc.c:1646  */
    {printf("program ");}
#line 1627 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 170 "lab4.y" /* yacc.c:1646  */
    {printf("%s",yylval.string); InsereSimb (yylval.string, IDPROG, NAOVAR);}
#line 1633 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 170 "lab4.y" /* yacc.c:1646  */
    {printf("\{\n");}
#line 1639 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 170 "lab4.y" /* yacc.c:1646  */
    {printf("\}\n");}
#line 1645 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 170 "lab4.y" /* yacc.c:1646  */
    {ImprimeTabSimb (); VerificaInicRef();}
#line 1651 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 171 "lab4.y" /* yacc.c:1646  */
    {printf("global"); tid = IDVAR_GLOBAL;}
#line 1657 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 171 "lab4.y" /* yacc.c:1646  */
    {printf(":\n");tab++;}
#line 1663 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 171 "lab4.y" /* yacc.c:1646  */
    {tab--;}
#line 1669 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 173 "lab4.y" /* yacc.c:1646  */
    {printf(";\n");}
#line 1675 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 174 "lab4.y" /* yacc.c:1646  */
    {tabular();printf("int "); tipocorrente=INTEIRO;}
#line 1681 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 174 "lab4.y" /* yacc.c:1646  */
    {tabular();printf("float "); tipocorrente=FLOAT;}
#line 1687 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 174 "lab4.y" /* yacc.c:1646  */
    {tabular();printf("char "); tipocorrente=CARACTERE;}
#line 1693 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 174 "lab4.y" /* yacc.c:1646  */
    {tabular();printf("logic "); tipocorrente=LOGICO;}
#line 1699 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 174 "lab4.y" /* yacc.c:1646  */
    {tabular();printf("void ");}
#line 1705 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 175 "lab4.y" /* yacc.c:1646  */
    {printf(", ");}
#line 1711 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 176 "lab4.y" /* yacc.c:1646  */
    {printf("%s",yylval.string); if(ProcuraSimb(yylval.string, tid) != NULL) DeclaracaoRepetida(yylval.string); else InsereSimb(yylval.string, tid, tipocorrente);}
#line 1717 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 177 "lab4.y" /* yacc.c:1646  */
    {printf("[");}
#line 1723 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 177 "lab4.y" /* yacc.c:1646  */
    {printf("]");}
#line 1729 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 178 "lab4.y" /* yacc.c:1646  */
    {printf("%d",yylval.valor);}
#line 1735 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 178 "lab4.y" /* yacc.c:1646  */
    {printf(", ");}
#line 1741 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 178 "lab4.y" /* yacc.c:1646  */
    {printf("%d",yylval.valor);}
#line 1747 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 179 "lab4.y" /* yacc.c:1646  */
    {printf("functions");}
#line 1753 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 179 "lab4.y" /* yacc.c:1646  */
    {printf(":\n");}
#line 1759 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 181 "lab4.y" /* yacc.c:1646  */
    {printf("\{\n");}
#line 1765 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 181 "lab4.y" /* yacc.c:1646  */
    {printf("\}\n"); ApagarVariaveis(IDVAR_LOCAL);}
#line 1771 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 182 "lab4.y" /* yacc.c:1646  */
    {printf("main");}
#line 1777 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 182 "lab4.y" /* yacc.c:1646  */
    {tid=IDVAR_FUNC; printf("%s",yylval.string); if(ProcuraSimb(yylval.string, tid) != NULL) DeclaracaoRepetida(yylval.string); else InsereSimb(yylval.string, tid, NAOVAR);}
#line 1783 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 182 "lab4.y" /* yacc.c:1646  */
    {printf("\(");}
#line 1789 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 182 "lab4.y" /* yacc.c:1646  */
    {printf("\)");}
#line 1795 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 184 "lab4.y" /* yacc.c:1646  */
    {printf(", ");}
#line 1801 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 185 "lab4.y" /* yacc.c:1646  */
    {printf("%s",yylval.string);}
#line 1807 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 186 "lab4.y" /* yacc.c:1646  */
    {printf("local ");tab++; tid = IDVAR_LOCAL;}
#line 1813 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 186 "lab4.y" /* yacc.c:1646  */
    {printf(":\n");}
#line 1819 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 186 "lab4.y" /* yacc.c:1646  */
    {tab--;}
#line 1825 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 187 "lab4.y" /* yacc.c:1646  */
    {printf("statements");}
#line 1831 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 187 "lab4.y" /* yacc.c:1646  */
    {printf(":\n");tab++;}
#line 1837 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 187 "lab4.y" /* yacc.c:1646  */
    {tab--;}
#line 1843 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 189 "lab4.y" /* yacc.c:1646  */
    {tabular();}
#line 1849 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 189 "lab4.y" /* yacc.c:1646  */
    {tabular();}
#line 1855 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 189 "lab4.y" /* yacc.c:1646  */
    {tabular();}
#line 1861 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 190 "lab4.y" /* yacc.c:1646  */
    {tabular();}
#line 1867 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 190 "lab4.y" /* yacc.c:1646  */
    {tabular();}
#line 1873 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 190 "lab4.y" /* yacc.c:1646  */
    {tabular();}
#line 1879 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 190 "lab4.y" /* yacc.c:1646  */
    {tabular();}
#line 1885 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 191 "lab4.y" /* yacc.c:1646  */
    {tabular();}
#line 1891 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 191 "lab4.y" /* yacc.c:1646  */
    {tabular();}
#line 1897 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 191 "lab4.y" /* yacc.c:1646  */
    {printf(";\n");}
#line 1903 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 192 "lab4.y" /* yacc.c:1646  */
    {printf("\{\n");}
#line 1909 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 192 "lab4.y" /* yacc.c:1646  */
    {tab++;}
#line 1915 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 192 "lab4.y" /* yacc.c:1646  */
    {tab--;}
#line 1921 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 192 "lab4.y" /* yacc.c:1646  */
    {tabular();printf("\}\n");}
#line 1927 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 193 "lab4.y" /* yacc.c:1646  */
    {printf("if");}
#line 1933 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 193 "lab4.y" /* yacc.c:1646  */
    {printf("\(");}
#line 1939 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 193 "lab4.y" /* yacc.c:1646  */
    {printf("\)");}
#line 1945 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 194 "lab4.y" /* yacc.c:1646  */
    {tabular();printf("else");}
#line 1951 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 194 "lab4.y" /* yacc.c:1646  */
    {tab++;}
#line 1957 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 194 "lab4.y" /* yacc.c:1646  */
    {tab--;}
#line 1963 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 195 "lab4.y" /* yacc.c:1646  */
    {printf("while");}
#line 1969 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 195 "lab4.y" /* yacc.c:1646  */
    {printf("\(");}
#line 1975 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 195 "lab4.y" /* yacc.c:1646  */
    {printf("\)");}
#line 1981 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 196 "lab4.y" /* yacc.c:1646  */
    {printf("\(");}
#line 1987 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 196 "lab4.y" /* yacc.c:1646  */
    {printf("\)");}
#line 1993 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 196 "lab4.y" /* yacc.c:1646  */
    {printf(";\n");}
#line 1999 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 197 "lab4.y" /* yacc.c:1646  */
    {printf("for");}
#line 2005 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 197 "lab4.y" /* yacc.c:1646  */
    {printf("\(");}
#line 2011 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 197 "lab4.y" /* yacc.c:1646  */
    {printf("<-");}
#line 2017 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 197 "lab4.y" /* yacc.c:1646  */
    {printf(";");}
#line 2023 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 198 "lab4.y" /* yacc.c:1646  */
    {printf(";");}
#line 2029 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 198 "lab4.y" /* yacc.c:1646  */
    {printf("<-");}
#line 2035 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 199 "lab4.y" /* yacc.c:1646  */
    {printf("\)");}
#line 2041 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 200 "lab4.y" /* yacc.c:1646  */
    {printf("read");}
#line 2047 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 200 "lab4.y" /* yacc.c:1646  */
    {printf("\(");}
#line 2053 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 200 "lab4.y" /* yacc.c:1646  */
    {printf("\)");}
#line 2059 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 200 "lab4.y" /* yacc.c:1646  */
    {printf(";\n");}
#line 2065 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 201 "lab4.y" /* yacc.c:1646  */
    {printf("read");}
#line 2071 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 201 "lab4.y" /* yacc.c:1646  */
    {printf(", ");}
#line 2077 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 202 "lab4.y" /* yacc.c:1646  */
    {printf("write");}
#line 2083 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 202 "lab4.y" /* yacc.c:1646  */
    {printf("\(");}
#line 2089 "y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 202 "lab4.y" /* yacc.c:1646  */
    {printf("\)");}
#line 2095 "y.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 202 "lab4.y" /* yacc.c:1646  */
    {printf(";\n");}
#line 2101 "y.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 203 "lab4.y" /* yacc.c:1646  */
    {printf(", ");}
#line 2107 "y.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 204 "lab4.y" /* yacc.c:1646  */
    {printf("%s",yylval.string);}
#line 2113 "y.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 205 "lab4.y" /* yacc.c:1646  */
    {printf("call ");}
#line 2119 "y.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 205 "lab4.y" /* yacc.c:1646  */
    {printf(";\n");}
#line 2125 "y.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 206 "lab4.y" /* yacc.c:1646  */
    {printf("%s",yylval.string);}
#line 2131 "y.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 206 "lab4.y" /* yacc.c:1646  */
    {printf("\(");}
#line 2137 "y.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 206 "lab4.y" /* yacc.c:1646  */
    {printf("\)");}
#line 2143 "y.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 208 "lab4.y" /* yacc.c:1646  */
    {printf("return ");}
#line 2149 "y.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 208 "lab4.y" /* yacc.c:1646  */
    {printf(";\n");}
#line 2155 "y.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 208 "lab4.y" /* yacc.c:1646  */
    {printf("return ");}
#line 2161 "y.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 208 "lab4.y" /* yacc.c:1646  */
    {printf(";\n");}
#line 2167 "y.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 209 "lab4.y" /* yacc.c:1646  */
    {if  (yylval.simb != NULL) yylval.simb->inic = yylval.simb->ref = VERDADE;}
#line 2173 "y.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 209 "lab4.y" /* yacc.c:1646  */
    {printf("<-");}
#line 2179 "y.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 209 "lab4.y" /* yacc.c:1646  */
    {printf(";\n");}
#line 2185 "y.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 210 "lab4.y" /* yacc.c:1646  */
    {printf(", ");}
#line 2191 "y.tab.c" /* yacc.c:1646  */
    break;

  case 139:
#line 211 "lab4.y" /* yacc.c:1646  */
    {printf(" | ");}
#line 2197 "y.tab.c" /* yacc.c:1646  */
    break;

  case 142:
#line 212 "lab4.y" /* yacc.c:1646  */
    {printf(" & ");}
#line 2203 "y.tab.c" /* yacc.c:1646  */
    break;

  case 145:
#line 213 "lab4.y" /* yacc.c:1646  */
    {printf("!");}
#line 2209 "y.tab.c" /* yacc.c:1646  */
    break;

  case 148:
#line 214 "lab4.y" /* yacc.c:1646  */
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
#line 2236 "y.tab.c" /* yacc.c:1646  */
    break;

  case 151:
#line 236 "lab4.y" /* yacc.c:1646  */
    {if((yyvsp[0].atr) == ADOP_1) printf("+"); else printf("-"); }
#line 2242 "y.tab.c" /* yacc.c:1646  */
    break;

  case 154:
#line 237 "lab4.y" /* yacc.c:1646  */
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
#line 2260 "y.tab.c" /* yacc.c:1646  */
    break;

  case 156:
#line 250 "lab4.y" /* yacc.c:1646  */
    {if(yylval.simb != NULL)  yylval.simb->ref=VERDADE;}
#line 2266 "y.tab.c" /* yacc.c:1646  */
    break;

  case 157:
#line 251 "lab4.y" /* yacc.c:1646  */
    {printf("%d",yylval.valor);}
#line 2272 "y.tab.c" /* yacc.c:1646  */
    break;

  case 158:
#line 252 "lab4.y" /* yacc.c:1646  */
    {printf("%f",yylval.valreal);}
#line 2278 "y.tab.c" /* yacc.c:1646  */
    break;

  case 159:
#line 253 "lab4.y" /* yacc.c:1646  */
    {printf("%s",yylval.string);}
#line 2284 "y.tab.c" /* yacc.c:1646  */
    break;

  case 160:
#line 254 "lab4.y" /* yacc.c:1646  */
    {printf("true");}
#line 2290 "y.tab.c" /* yacc.c:1646  */
    break;

  case 161:
#line 255 "lab4.y" /* yacc.c:1646  */
    {printf("false");}
#line 2296 "y.tab.c" /* yacc.c:1646  */
    break;

  case 162:
#line 256 "lab4.y" /* yacc.c:1646  */
    {printf("~");}
#line 2302 "y.tab.c" /* yacc.c:1646  */
    break;

  case 164:
#line 257 "lab4.y" /* yacc.c:1646  */
    {printf("\(");}
#line 2308 "y.tab.c" /* yacc.c:1646  */
    break;

  case 165:
#line 257 "lab4.y" /* yacc.c:1646  */
    {printf("\)");}
#line 2314 "y.tab.c" /* yacc.c:1646  */
    break;

  case 167:
#line 259 "lab4.y" /* yacc.c:1646  */
    {
                        printf("%s",(yyvsp[0].string)); 
                        simb = ProcuraSimb ((yyvsp[0].string), -1);
                        if (simb == NULL) 
                          NaoDeclarado ((yyvsp[0].string));                      
                        else if (simb->tid != IDVAR_GLOBAL && simb->tid != IDVAR_LOCAL) TipoInadequado ((yyvsp[0].string));
                        yylval.simb = simb;
                      }
#line 2327 "y.tab.c" /* yacc.c:1646  */
    break;

  case 170:
#line 267 "lab4.y" /* yacc.c:1646  */
    {printf("[");}
#line 2333 "y.tab.c" /* yacc.c:1646  */
    break;

  case 171:
#line 267 "lab4.y" /* yacc.c:1646  */
    {printf("]");}
#line 2339 "y.tab.c" /* yacc.c:1646  */
    break;

  case 173:
#line 268 "lab4.y" /* yacc.c:1646  */
    {printf(", ");}
#line 2345 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2349 "y.tab.c" /* yacc.c:1646  */
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
#line 269 "lab4.y" /* yacc.c:1906  */

#include "lex.yy.c"
void tabular () {
	int i;
	for (i = 1; i <= tab; i++)
   		printf ("\t");
}

/*  InicTabSimb: Inicializa a tabela de simbolos   */

void InicTabSimb () {
	int i;
	for (i = 0; i < NCLASSHASH; i++) 
		tabsimb[i] = NULL;
}

/*
	ProcuraSimb (cadeia): Procura cadeia na tabela de simbolos;
	Caso ela ali esteja, retorna um ponteiro para sua celula;
	Caso contrario, retorna NULL.
 */

simbolo ProcuraSimb (char *cadeia, int tid_filtro) {
	simbolo s; int i;
	i = hash (cadeia);
	s = tabsimb[i];
	while(s != NULL) {
		if(strcmp(cadeia, s->cadeia) == 0 && (tid_filtro == -1 || tid_filtro == s->tid))
			return s;
		s = s->prox;
	}
	return NULL;
	if(s!=NULL)
		printf("\ncadeia=%s, s->cadeia=%s, tid=%d, local tid=%d\n",cadeia, s->cadeia, s->tid, tid_filtro);
	return s;
}

void ApagarVariaveis (int tid) {
	simbolo s;
	int i;
	for ( i = 0; i < NCLASSHASH; i++) {
		while (tabsimb[i] != NULL && tabsimb[i]->tid == tid)
			tabsimb[i] = tabsimb[i]->prox;
		s = tabsimb[i];
		while(s != NULL) {
			if (s->prox != NULL && s->prox->tid == tid)
				s->prox = s->prox->prox;
			s = s->prox;
		}
	}
}

/*
	InsereSimb (cadeia, tid, tvar): Insere cadeia na tabela de
	simbolos, com tid como tipo de identificador e com tvar como
	tipo de variavel; Retorna um ponteiro para a celula inserida
 */

simbolo InsereSimb (char *cadeia, int tid, int tvar) {
	int i; simbolo aux, s;
	i = hash (cadeia); aux = tabsimb[i];
	s = tabsimb[i] = (simbolo) malloc (sizeof (celsimb));
	s->cadeia = (char*) malloc ((strlen(cadeia)+1) * sizeof(char));
	strcpy (s->cadeia, cadeia);
	s->tid = tid;		
	s->tvar = tvar;
	s->inic = FALSO;	
	s->ref = FALSO;
	s->prox = aux;	
	return s;
}

/*
	hash (cadeia): funcao que determina e retorna a classe
	de cadeia na tabela de simbolos implementada por hashing
 */

int hash (char *cadeia) {
	int i, h;
	for (h = i = 0; cadeia[i]; i++) {h += cadeia[i];}
	h = h % NCLASSHASH;
	return h;
}

/* ImprimeTabSimb: Imprime todo o conteudo da tabela de simbolos  */

void ImprimeTabSimb () {
	int i; simbolo s;
	printf ("\n\n   TABELA  DE  SIMBOLOS:\n\n");
	for (i = 0; i < NCLASSHASH; i++)
		if (tabsimb[i]) {
			printf ("Classe %d:\n", i);
			for (s = tabsimb[i]; s!=NULL; s = s->prox){
				printf ("  (%s, %s", s->cadeia,  nometipid[s->tid]);
				if (s->tid == IDVAR_GLOBAL || s->tid == IDVAR_LOCAL)
					printf (", %s, %d, %d", nometipvar[s->tvar], s->inic, s->ref);
				printf(")\n");
			}
		}
}

/* VerificaInicRef: Checa e avisa os casos de identificadores não-inicializados e/ou não-referenciados  */

void VerificaInicRef () {
	int i; simbolo s;
  printf("\n\n/*************************************************************/\n");
	printf ("   SIMBOLOS NAO INICIALIZADOS E NAO REFERENCIADOS:\n\n");
	for (i = 0; i < NCLASSHASH; i++)
		if (tabsimb[i]) {
			for (s = tabsimb[i]; s!=NULL; s = s->prox)
				if ((s->tid == IDVAR_GLOBAL || s->tid == IDVAR_LOCAL) && s->inic == 0 && s->ref == 0)
          printf ("%s, ", s->cadeia);
		}
  printf("\n/*************************************************************/\n");
	printf ("   SIMBOLOS NAO INICIALIZADOS MAS REFERENCIADOS:\n\n");
	for (i = 0; i < NCLASSHASH; i++)
		if (tabsimb[i]) {
			for (s = tabsimb[i]; s!=NULL; s = s->prox)
				if ((s->tid == IDVAR_GLOBAL || s->tid == IDVAR_LOCAL) && s->inic == 0 && s->ref != 0)
          printf ("%s, ", s->cadeia);
		}    
  printf("\n/*************************************************************/\n");
	printf ("   SIMBOLOS INICIALIZADOS MAS NÃO REFERENCIADOS:\n\n");
	for (i = 0; i < NCLASSHASH; i++)
		if (tabsimb[i]) {
			for (s = tabsimb[i]; s!=NULL; s = s->prox)
				if ((s->tid == IDVAR_GLOBAL || s->tid == IDVAR_LOCAL) && s->inic != 0 && s->ref == 0)
          printf ("%s, ", s->cadeia);
		}      
  printf("\n/*************************************************************/\n");
}

/*  Mensagens de erros semanticos  */

void DeclaracaoRepetida (char *s) {
	printf ("\n\n***** Declaracao Repetida: %s *****\n\n", s);
}

void NaoDeclarado (char *s) {
  printf ("\n\n***** Identificador Nao Declarado: %s *****\n\n", s);
}

void TipoInadequado (char *s) {
  printf ("\n\n***** Identificador de Tipo Inadequado: %s *****\n\n", s);
}


