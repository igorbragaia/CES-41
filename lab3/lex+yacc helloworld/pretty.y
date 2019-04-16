%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define		MAIS		7
#define		MENOS		8
int tab = 0;
%}
%union {
	char cadeia[50];
	int atr, valint;
	char carac;
}
%token	<cadeia>	ID
%token	<valint>	INTCT
%token	<atr>		ADOP
%token			OPPAR
%token			CLPAR
%token			OPBRACE
%token			CLBRACE
%token			SCOLON
%token			ASSIGN
%token	<carac>	INVAL
%%
CompStat    :	OPBRACE
				{tabular (); printf ("\{\n"); tab++;}
				StatList CLBRACE
				{tab--; tabular (); printf ("}\n");}
			;
StatList	:	Statement
			|	StatList Statement
			;
Statement   :	AssignStat
			|	CompStat
			;
AssignStat 	:	ID {tabular (); printf ("%s ", $1);}
				ASSIGN {printf ("<- ");}
				Expression SCOLON {printf(";\n");}
			;
Expression	:	Term
			|	Expression ADOP {
            		if ($2 == MAIS) printf ("+ ");
					else printf ("- ");
            	} Term
			;
Term	   	:	ID {printf ("%s ", $1);}
			|	INTCT {printf ("%d ", $1);}
			|  	OPPAR {printf("\( ");}
         		Expression CLPAR {printf (") ");}
          	;
%%
#include "lex.yy.c"
tabular () {
	int i;
	for (i = 1; i <= tab; i++)
   	printf ("\t");
}
