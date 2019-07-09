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
#define		INVALIDO	5

/*   Definicao de outras constantes   */

#define	NCLASSHASH	23
#define	VERDADE		1
#define	FALSO		0

/*  Strings para nomes dos tipos de identificadores  */

char *nometipid[5] = {" ", "IDPROG", "IDVAR_LOCAL", "IDVAR_GLOBAL", "IDVAR_GLOBAL"};

/*  Strings para nomes dos tipos de variaveis  */

char *nometipvar[6] = {"NAOVAR","INTEIRO", "LOGICO", "REAL", "CARACTERE", "INVALIDO"};

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
int atr;

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
void DimInvalida (void);
void ApagarVariaveis (int);
%}

/* Definicao do tipo de yylval e dos atributos dos nao terminais */

%union {
	char string[100];
  	char carac;
	int atr;
	int valor;
	float valreal;
	int expr;
  	simbolo simb;
};

%type <simb> Variable

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
Prog			:  		{InicTabSimb ();}	PROGRAM {printf("program ");}  ID {printf("%s",yylval.string); InsereSimb (yylval.string, IDPROG, NAOVAR);} OPBRACE {printf("\{\n");}  GlobDecls  Functions CLBRACE {printf("\}\n");} {ImprimeTabSimb (); VerificaInicRef();}
GlobDecls 		:	   |  GLOBAL {printf("global"); tid = IDVAR_GLOBAL;} COLON {printf(":\n");tab++;}  DeclList {tab--;}
DeclList		:		Declaration  |  DeclList  Declaration
Declaration 	:		Type  ElemList  SCOLON {printf(";\n");}
Type			: 		INT {tabular();printf("int "); tipocorrente=INTEIRO;} |  FLOAT {tabular();printf("float "); tipocorrente=FLOAT;} |  CHAR {tabular();printf("char "); tipocorrente=CARACTERE;} |  LOGIC {tabular();printf("logic "); tipocorrente=LOGICO;} |  VOID {tabular();printf("void ");}
ElemList    	:		Elem  |  ElemList  COMMA {printf(", ");} Elem
Elem        	:		ID {printf("%s",yylval.string); if(ProcuraSimb(yylval.string, tid) != NULL) DeclaracaoRepetida(yylval.string); else InsereSimb(yylval.string, tid, tipocorrente);}  Dims
Dims			:	   |  OPBRAK {printf("[");} DimList  CLBRAK {printf("]");}
DimList	    	: 		INTCT  {printf("%d",yylval.valor); if(yylval.valor < 0) DimInvalida(); } |  DimList  COMMA {printf(", ");} INTCT {printf("%d",yylval.valor);  if(yylval.valor < 0) DimInvalida();}
Functions		:   	FUNCTIONS {printf("functions");} COLON {printf(":\n");}    FuncList
FuncList		:   	Function   |   FuncList  Function
Function		:		Header  OPBRACE {printf("\{\n");} LocDecls  Stats  CLBRACE {printf("\}\n"); ApagarVariaveis(IDVAR_LOCAL);}
Header			:   	MAIN {printf("main");}  |   Type  ID {tid=IDVAR_FUNC; printf("%s",yylval.string); if(ProcuraSimb(yylval.string, tid) != NULL) DeclaracaoRepetida(yylval.string); else InsereSimb(yylval.string, tid, NAOVAR);} OPPAR {printf("\(");}  Params  CLPAR {printf("\)");}
Params			:   	    |   ParamList
ParamList   	:   	Parameter  |  ParamList  COMMA {printf(", ");}  Parameter
Parameter   	:   	Type  ID {printf("%s",yylval.string);}
LocDecls		:   	    |   LOCAL {printf("local ");tab++; tid = IDVAR_LOCAL;}  COLON {printf(":\n");}   DeclList {tab--;}
Stats       	:   	STATEMENTS {printf("statements");}  COLON {printf(":\n");tab++;}   StatList {tab--;}
StatList		:	   |  StatList  Statement
Statement   	:   	CompStat  | {tabular();} IfStat  | {tabular();}  WhileStat  |  {tabular();} DoStat
            	|   	{tabular();} ForStat  |  {tabular();} ReadStat  |  {tabular();} WriteStat  |  {tabular();} AssignStat
            	|   	{tabular();} CallStat  |  {tabular();} ReturnStat  |  SCOLON {printf(";\n");}
CompStat		:   	OPBRACE {printf("\{\n");} {tab++;}StatList{tab--;}  CLBRACE {tabular();printf("\}\n");}
IfStat			:   	IF {printf("if");} OPPAR {printf("\(");}  Expression  CLPAR {printf("\)");} Statement ElseStat
ElseStat		:	   |  ELSE {tabular();printf("else");} {tab++;}Statement{tab--;}
WhileStat   	:		WHILE {printf("while");} OPPAR {printf("\(");}  Expression  CLPAR {printf("\)");}  Statement
DoStat  		:   	DO  Statement  WHILE  OPPAR {printf("\(");}  Expression  CLPAR {printf("\)");}  					SCOLON {printf(";\n");}
ForStat	    	:   	FOR {printf("for");} OPPAR {printf("\(");}  Variable  ASSIGN {printf("<-");}  Expression  SCOLON {printf(";");}
						Expression  SCOLON {printf(";");}  Variable  ASSIGN {printf("<-");}  Expression
						CLPAR {printf("\)");} Statement
ReadStat   		:   	READ {printf("read");}  OPPAR {printf("\(");}  ReadList  CLPAR {printf("\)");}  SCOLON {printf(";\n");}
ReadList		:   	Variable  |  ReadList {printf("read");}  COMMA {printf(", ");}  Variable
WriteStat   	:		WRITE {printf("write");}  OPPAR {printf("\(");}  WriteList  CLPAR {printf("\)");}  SCOLON {printf(";\n");}
WriteList		:		WriteElem  |  WriteList  COMMA {printf(", ");}  WriteElem
WriteElem		:   	STRING {printf("%s",yylval.string);} |  Expression
CallStat		:   	CALL {printf("call ");}  FuncCall  SCOLON {printf(";\n");}
FuncCall		:   	ID {printf("%s",yylval.string);} OPPAR {printf("\(");}  Arguments  CLPAR {printf("\)");}
Arguments		:	   |  ExprList
ReturnStat  	:		RETURN {printf("return ");}  SCOLON {printf(";\n");}  |  RETURN {printf("return ");} Expression  SCOLON {printf(";\n");}
AssignStat  	:   	Variable {if  (yylval.simb != NULL) yylval.simb->inic = yylval.simb->ref = VERDADE;}  ASSIGN {printf("<-");}  Expression  SCOLON {printf(";\n");}
ExprList		:   	Expression  |  ExprList  COMMA {printf(", ");}  Expression
Expression  	:   	AuxExpr1  |  Expression  OR {printf(" | ");}  AuxExpr1 
AuxExpr1    	:   	AuxExpr2  |  AuxExpr1  AND {printf(" & ");} AuxExpr2
AuxExpr2    	:   	AuxExpr3  |  NOT {printf("!");} AuxExpr3
AuxExpr3    	:   	AuxExpr4  |  AuxExpr4  RELOP {
    switch(atr){
      case RELOP_1:
        printf(" < ");
        break;
      case RELOP_2:
        printf(" <= ");
        break;
      case RELOP_3:
        printf(" > ");
        break;
      case RELOP_4:
        printf(" >= ");
        break;
      case RELOP_5:
        printf(" = ");
        break;
      case RELOP_6:
        printf(" != ");
        break;
    };
} AuxExpr4
AuxExpr4    	:	 Term  |  AuxExpr4  ADOP {if($2 == ADOP_1) printf("+"); else printf("-"); } Term
Term  	    	:   	Factor  |  Term  MULTOP {
    switch($2){
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
} Factor
Factor		:   	Variable {if(yylval.simb != NULL)  yylval.simb->ref=VERDADE;} 
                |  INTCT  {printf("%d",yylval.valor); yylval.expr = INTEIRO;} 
                |  FLOATCT {printf("%f",yylval.valreal); yylval.expr = REAL;}  
                |  CHARCT {printf("%s",yylval.string);  yylval.expr = CARACTERE;}
              	|  TRUE {printf("true");  yylval.expr = LOGICO;} 
                |  FALSE {printf("false");  yylval.expr = LOGICO;}  
                |  NEG {printf("~");}  Factor
              	|  OPPAR {printf("\(");}  Expression  CLPAR {printf("\)");}  
                |  FuncCall
Variable		:   	ID {
                        printf("%s",$1); 
                        simb = ProcuraSimb ($1, -1);
                        if (simb == NULL) 
                          NaoDeclarado ($1);                      
                        else if (simb->tid != IDVAR_GLOBAL && simb->tid != IDVAR_LOCAL) TipoInadequado ($1);
                        yylval.simb = simb;
                      } Subscripts
Subscripts   	:	   |  OPBRAK {printf("[");}  SubscrList  CLBRAK {printf("]");}
SubscrList	:   	AuxExpr4   |   SubscrList  COMMA {printf(", ");}  AuxExpr4
%%
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

void DimInvalida () {
	printf ("\n\n*****Dimensao invalida, valor negativo!*****\n\n");
}