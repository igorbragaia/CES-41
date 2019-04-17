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
Prog			:	PROGRAM {printf("program ");}  ID  OPBRACE  GlobDecls  Functions
				CLBRACE
GlobDecls 	:	   |  GLOBAL  COLON  DeclList
DeclList		:	Declaration  |  DeclList  Declaration
Declaration 	:	Type  ElemList  SCOLON
Type			: 	INT  |  FLOAT  |  CHAR  |  LOGIC  |  VOID
ElemList    	:	Elem  |  ElemList  COMMA  Elem
Elem        	:	ID  Dims
Dims			:	   |  OPBRAK  DimList  CLBRAK
DimList	    	: 	INTCT  |  DimList  COMMA  INTCT
Functions		:   	FUNCTIONS  COLON  FuncList
FuncList		:   	Function   |   FuncList  Function
Function		:	Header  OPBRACE  LocDecls  Stats  CLBRACE
Header		:   	MAIN   |   Type  ID  OPPAR  Params  CLPAR
Params		:   	    |   ParamList
ParamList   	:   	Parameter  |  ParamList  COMMA  Parameter
Parameter   	:   	Type  ID
LocDecls		:   	    |   LOCAL  COLON  DeclList
Stats       	:   	STATEMENTS  COLON  StatList
StatList		:	   |  StatList  Statement
Statement   	:   	CompStat  |  IfStat  |  WhileStat  |  DoStat
            	|   	ForStat  |  ReadStat  |  WriteStat  |  AssignStat
            	|   	CallStat  |  ReturnStat  |  SCOLON
CompStat		:   	OPBRACE  StatList  CLBRACE
IfStat		:   	IF  OPPAR  Expression  CLPAR  Statement  ElseStat
ElseStat		:	   |  ELSE  Statement
WhileStat   	:	WHILE  OPPAR  Expression  CLPAR  Statement
DoStat  		:   	DO  Statement  WHILE  OPPAR  Expression  CLPAR  					SCOLON
ForStat	    	:   	FOR  OPPAR  Variable  ASSIGN  Expression  SCOLON
			Expression  SCOLON  Variable  ASSIGN  Expression
			CLPAR   Statement
ReadStat   	:   	READ  OPPAR  ReadList  CLPAR  SCOLON
ReadList		:   	Variable  |  ReadList  COMMA  Variable
WriteStat   	:	WRITE  OPPAR  WriteList  CLPAR  SCOLON
WriteList		:	WriteElem  |  WriteList  COMMA  WriteElem
WriteElem		:   	STRING  |  Expression
CallStat		:   	CALL  FuncCall  SCOLON
FuncCall		:   	ID  OPPAR  Arguments  CLPAR
Arguments		:	   |  ExprList
ReturnStat  	:	RETURN  SCOLON  |  RETURN  Expression  SCOLON
AssignStat  	:   	Variable  ASSIGN  Expression  SCOLON
ExprList		:   	Expression  |  ExprList  COMMA  Expression
Expression  	:   	AuxExpr1  |  Expression  OR  AuxExpr1
AuxExpr1    	:   	AuxExpr2  |  AuxExpr1  AND  AuxExpr2
AuxExpr2    	:   	AuxExpr3  |  NOT  AuxExpr3
AuxExpr3    	:   	AuxExpr4  |  AuxExpr4  RELOP  AuxExpr4
AuxExpr4    	:	Term  |  AuxExpr4  ADOP  Term
Term  	    	:   	Factor  |  Term  MULTOP  Factor
Factor		:   	Variable  |  INTCT  |  FLOATCT  |  CHARCT
            	|   	TRUE  |  FALSE  |  NEG  Factor
            	|   	OPPAR  Expression  CLPAR  |  FuncCall
Variable		:   	ID  Subscripts
Subscripts   	:	   |  OPBRAK  SubscrList  CLBRAK
SubscrList	:   	AuxExpr4   |   SubscrList  COMMA  AuxExpr4
%%
#include "lex.yy.c"
void tabular () {
	int i;
	for (i = 1; i <= tab; i++)
   		printf ("\t");
}
