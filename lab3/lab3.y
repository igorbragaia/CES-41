%{
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
%}
%union {
	char string[100];
  char carac;
	int atr;
	int valor;
	float valreal;
};

// reserved words
%token CALL
%token CHAR
%token DO
%token ELSE
%token FALSE
%token FLOAT
%token FOR
%token FUNCTIONS
%token GLOBAL
%token IF
%token INT
%token LOCAL
%token LOGIC
%token MAIN
%token PROGRAM
%token READ
%token RETURN
%token STATEMENTS
%token TRUE
%token VOID
%token WHILE
%token WRITE
// syntax
%token <string>  ID
%token <valor>	 INTCT
%token <string>	 CHARCT
%token <valreal> FLOATCT
%token <string>	 STRING
// operators
%token OP
%token OR
%token AND
%token NOT
%token NEG
%token <atr> RELOP
%token <atr> ADOP
%token <atr> MULTOP
// others
%token ASSIGN
%token OPPAR
%token CLPAR
%token OPBRAK
%token CLBRAK
%token OPBRACE
%token CLBRACE
%token SCOLON
%token COMMA
%token COLON
//
%token INVAL
%token COMMENT
%%
Prog			:	PROGRAM {printf("program ");}  ID OPBRACE {printf("\{\n");} {printf("\{\n");}  GlobDecls  Functions CLBRACE {printf("\}\n");}
GlobDecls 	:	   |  GLOBAL {printf("global");} COLON {printf(":\n");}  DeclList
DeclList		:	Declaration  |  DeclList  Declaration
Declaration 	:	Type  ElemList  SCOLON {printf(";\n");}
Type			: 	INT {printf("int ");} |  FLOAT {printf("float ");} |  CHAR {printf("char ");} |  LOGIC {printf("logic ");} |  VOID {printf("void ");}
ElemList    	:	Elem  |  ElemList  COMMA {printf(", ");} Elem
Elem        	:	ID {printf("%s", $1); }  Dims
Dims			:	   |  OPBRAK {printf("[");} DimList  CLBRAK {printf("]");}
DimList	    	: 	INTCT  {printf("%d",$1);} |  DimList  COMMA {printf(", ");} INTCT
Functions		:   	FUNCTIONS  COLON {printf(":\n");}    FuncList
FuncList		:   	Function   |   FuncList  Function
Function		:	Header  OPBRACE {printf("\{\n");} {printf("\{\n");}  LocDecls  Stats  CLBRACE {printf("\}\n");}
Header		:   	MAIN   |   Type  ID  OPPAR {printf("\(\n");}  Params  CLPAR {printf("\)\n");}
Params		:   	    |   ParamList
ParamList   	:   	Parameter  |  ParamList  COMMA {printf(", ");}  Parameter
Parameter   	:   	Type  ID
LocDecls		:   	    |   LOCAL {printf("local ");}  COLON {printf(":\n");}   DeclList
Stats       	:   	STATEMENTS {printf("statements ");}  COLON {printf(":\n");}   StatList
StatList		:	   |  StatList  Statement
Statement   	:   	CompStat  |  IfStat  |  WhileStat  |  DoStat
            	|   	ForStat  |  ReadStat  |  WriteStat  |  AssignStat
            	|   	CallStat  |  ReturnStat  |  SCOLON {printf(";\n");}
CompStat		:   	OPBRACE {printf("\{\n");} StatList  CLBRACE {printf("\}\n");}
IfStat		:   	IF  OPPAR {printf("\(\n");}  Expression  CLPAR {printf("\)\n");}  Statement  ElseStat
ElseStat		:	   |  ELSE  Statement
WhileStat   	:	WHILE  OPPAR {printf("\(\n");}  Expression  CLPAR {printf("\)\n");}  Statement
DoStat  		:   	DO  Statement  WHILE  OPPAR {printf("\(\n");}  Expression  CLPAR {printf("\)\n");}  					SCOLON {printf(";\n");}
ForStat	    	:   	FOR  OPPAR {printf("\(\n");}  Variable  ASSIGN  Expression  SCOLON {printf(";\n");}
			Expression  SCOLON {printf(";\n");}  Variable  ASSIGN  Expression
			CLPAR {printf("\)\n");}   Statement
ReadStat   	:   	READ {printf("read ");}  OPPAR {printf("\(\n");}  ReadList  CLPAR {printf("\)\n");}  SCOLON {printf(";\n");}
ReadList		:   	Variable  |  ReadList {printf("read");}  COMMA {printf(", ");}  Variable
WriteStat   	:	WRITE {printf("write ");}  OPPAR {printf("\(\n");}  WriteList  CLPAR {printf("\)\n");}  SCOLON {printf(";\n");}
WriteList		:	WriteElem  |  WriteList  COMMA {printf(", ");}  WriteElem
WriteElem		:   	STRING  |  Expression
CallStat		:   	CALL {printf("call ")}  FuncCall  SCOLON {printf(";\n");}
FuncCall		:   	ID  OPPAR {printf("\(\n");}  Arguments  CLPAR {printf("\)\n");}
Arguments		:	   |  ExprList
ReturnStat  	:	RETURN {printf("return");}  SCOLON {printf(";\n");}  |  RETURN {printf("return");} Expression  SCOLON {printf(";\n");}
AssignStat  	:   	Variable  ASSIGN {printf(" <- ");}  Expression  SCOLON {printf(";\n");}
ExprList		:   	Expression  |  ExprList  COMMA {printf(", ");}  Expression
Expression  	:   	AuxExpr1  |  Expression  OR {printf(" | ");}  AuxExpr1
AuxExpr1    	:   	AuxExpr2  |  AuxExpr1  AND {printf(" & ");} AuxExpr2
AuxExpr2    	:   	AuxExpr3  |  NOT {printf(" ! ");} AuxExpr3
AuxExpr3    	:   	AuxExpr4  |  AuxExpr4  RELOP  AuxExpr4
AuxExpr4    	:	Term  |  AuxExpr4  ADOP  Term
Term  	    	:   	Factor  |  Term  MULTOP  Factor
Factor		:   	Variable  |  INTCT  |  FLOATCT  |  CHARCT
            	|   	TRUE  |  FALSE  |  NEG  Factor
            	|   	OPPAR {printf("\(\n");}  Expression  CLPAR {printf("\)\n");}  |  FuncCall
Variable		:   	ID  Subscripts
Subscripts   	:	   |  OPBRAK {printf("[");}  SubscrList  CLBRAK {printf("]");}
SubscrList	:   	AuxExpr4   |   SubscrList  COMMA {printf(", ");}  AuxExpr4
%%
#include "lex.yy.c"
void tabular () {
	int i;
	for (i = 1; i <= tab; i++)
   		printf ("\t");
}
