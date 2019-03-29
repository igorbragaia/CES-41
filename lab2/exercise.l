%{
#include 	<string.h>
// reserved words
#define CALL 		1
#define CHAR 		2
#define DO 			3
#define ELSE 		4
#define FALSE 		5
#define FLOAT 		6
#define FOR 		7
#define FUNCTIONS 	8
#define GLOBAL 		9
#define IF 			10
#define INT 		11
#define LOCAL 		12
#define LOGIC 		13
#define MAIN 		14
#define PROGRAM 	15
#define READ 		16
#define RETURN 		17
#define STATEMENTS 	18
#define TRUE 		19
#define VOID 		20
#define WHILE 		21
#define WRITE 		22
// syntax
#define ID 			23
#define INTCT 		24
#define CHARCT 		25
#define FLOATCT 	26
#define STRING 		27
// operators
#define OP 			28
#define OR 			29
#define AND 		30
#define NOT 		31
#define NEG 		35
#define RELOP 		32
#define ADOP 		33
#define MULTOP 		34
#define RELOP_1		1
#define RELOP_2		2
#define RELOP_3		3
#define RELOP_4		4
#define RELOP_5		5
#define RELOP_6		6
#define ADOP_1		1
#define ADOP_2		2
#define MULTOP_1 	1
#define MULTOP_2	2
#define MULTOP_3	3
// others
#define ASSIGN 		35
#define OPPAR 		36
#define CLPAR 		37
#define OPBRAK 		38
#define CLBRAK 		39
#define OPBRACE 	40
#define CLBRACE 	41
#define SCOLON 		42
#define COMMA 		43
#define COLON 		44
//
#define INVAL   	45
#define COMMENT 	46
//
union {
	char string[50];
	int atr, valor;
  	float valreal;
	char carac;
} yylval;

void comentario();

%}
delim				[ \t\n\r]
ws					{delim}+
digito				[0-9]
letra				[A-Za-z]
id 					{letra}({letra}|{digito})*
intct 				{digito}+
charct 				'\\?({letra}|{digito})'
floatct 			{digito}+\.{digito}*([Ee][+-]?{digito}+)?
string 				\"(\\.|[^\\\"])*\"
%%
"/*"			    {comentario();}
{ws}				{;}
call				{return CALL;}
char				{return CHAR;}
do					{return DO;}
else				{return ELSE;}
false				{return FALSE;}
float				{return FLOAT;}
for					{return FOR;}
functions			{return FUNCTIONS;}
global				{return GLOBAL;}
if					{return IF;}
int					{return INT;}
local				{return LOCAL;}
logic				{return LOGIC;}
main				{return MAIN;}
program				{return PROGRAM;}
read				{return READ;}
return				{return RETURN;}
statements			{return STATEMENTS;}
true				{return TRUE;}
void				{return VOID;}
while				{return WHILE;}
write				{return WRITE;}
{id}				{
						strcpy (yylval.string, yytext); 
						return ID;
					}
{intct}				{
						yylval.valor = atoi(yytext); 
						return INTCT;
					}
{charct} 			{
						strcpy (yylval.string, yytext); 
						return CHARCT;
				        int i;
				        for(i=0;i<strlen(yytext)-2; i++)
				        	yytext[i] = yytext[i+1];
				        yytext[i] = '\0';
				        strcpy (yylval.string, yytext); 
				        return CHARCT;
			    	}
{floatct} 			{
						yylval.valreal = atof(yytext); 
						return FLOATCT;
					}
{string} 			{
				        int i;
				        for(i=0;i<strlen(yytext)-2; i++)
				        	yytext[i] = yytext[i+1];
			        	yytext[i] = '\0';
				        strcpy (yylval.string, yytext); 
				        return STRING;
			    	}
"||"				{return OR;}
"&&"				{return AND;}
"!"					{return NOT;}
"~"					{return NEG;}
"<"					{
						yylval.atr = RELOP_1; 
						return RELOP;
					}
"<="				{
						yylval.atr = RELOP_2; 
						return RELOP;
					}
">"					{
						yylval.atr = RELOP_3; 
						return RELOP;
					}
">="				{
						yylval.atr = RELOP_4; 
						return RELOP;
					}
"="					{
						yylval.atr = RELOP_5; 
						return RELOP;
					}
"!="				{
						yylval.atr = RELOP_6; 
						return RELOP;
					}
"+"					{
						yylval.atr = ADOP_1; 
						return ADOP;
					}
"-"					{
						yylval.atr = ADOP_2; 
						return ADOP;
					}
"*"					{
						yylval.atr = MULTOP_1; 
						return MULTOP;
					}
"/"					{
						yylval.atr = MULTOP_2; 
						return MULTOP;
					}
"%"					{
						yylval.atr = MULTOP_3; 
						return MULTOP;
					}
"<"-				{return ASSIGN;}
"(" 				{return OPPAR;}
")"					{return CLPAR;}
"["					{return OPBRAK;}
"]"					{return CLBRAK;}
"{"					{return OPBRACE;}
"}"					{return CLBRACE;}
";"					{return SCOLON;}
","					{return COMMA;}
":"					{return COLON;}
.	 			   	{
						yylval.carac = yytext[0]; 
						return INVAL;
					}
%%

void comentario () {
	char c;  
	int estado = 1;
	printf("Comentario:\n/*");
	while (estado != 3) {
		c = input ();
		printf("%c", c);
		switch (estado) {
			case 1:
				if (c == EOF) estado = 3;
				else if (c == '*') estado = 2;
				break;
			case 2:
				if (c == EOF || c == '/') estado = 3;
				else if(c != EOF && c != '/' && c != '*') estado = 1;
				break;
		}
	}
	printf("\n");
}

main () {
	int i;
	printf ("\n%15s|%15s|%15s\n", "texto", "tipo", "atributo");
	printf ("--------------------------------\n");
	while (i = yylex ()) {
		printf ("%15s|%15d|", yytext, i);
		switch (i) {
	    	case ID:
				printf ("%15s", yylval.string); break;
			case INTCT:
				printf ("%15d", yylval.valor); break;
	    	case FLOATCT:
	        	printf ("%f", yylval.valreal); break;
	      	case CHARCT:
				printf ("%15s", yylval.string); break;
	      	case STRING:
				printf ("%15s", yylval.string); break;
			case RELOP:
				printf ("%15d", yylval.atr); break;
			case ADOP:
				printf ("%15d", yylval.atr); break;
			case MULTOP: 
				printf ("%15d", yylval.atr); break;
	      	case INVAL:
	        	printf ("%15c", yylval.carac); break;
		}
		printf ("\n");
	}
}
