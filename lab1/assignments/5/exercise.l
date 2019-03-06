%{
#include 	<string.h>
#define OPAD		1
#define OPMLT		2
#define PROGRAM	3
#define	VAR			4
#define INT			5
#define REAL		6
#define ABPAR		7
#define FPAR		8
#define ABCHAV  9
#define FCHAV		10
#define ATRIB	  11
#define VIRG		12
#define PVIRG		13
#define ID	   	14
#define CTINT		15
#define CTREAL  16
#define VEZES		1
#define DIV			2
#define MAIS		3
#define MENOS		4

union {
	char string[50];
	int atr, valor;
  float valreal;
	char carac;
} yylval;

%}
delim		[ \t\n\r]
ws			{delim}+
digito	[0-9]
letra		[A-Za-z]
id			{letra}({letra}|{digito})*
ctint		{digito}+
ctreal  {digito}+\.{digito}*([Ee][+-]?{digito}+)?
%%
{ws}			{ ;}
program   {return PROGRAM;}
var	  		{return VAR;}
int 			{return INT;}
real    	{return REAL;}
{id}		 	{strcpy (yylval.string, yytext); return ID;}
{ctint} 	{yylval.valor = atoi(yytext); return CTINT;}
{ctreal}  {yylval.valreal = atof(yytext); return CTREAL;}
"+"				{yylval.atr = MAIS; return OPAD;}
"-"				{yylval.atr = MENOS; return OPAD;}
"*"				{yylval.atr = VEZES; return OPMLT;}
"/"				{yylval.atr = DIV; return OPMLT;}
"("				{return ABPAR;}
")"				{return FPAR;}
"{"				{return ABCHAV;}
"}"				{return FCHAV;}
"="				{return ATRIB;}
","				{return VIRG;}
";"				{return PVIRG;}
%%
main () {
	int i;
	printf ("\n   texto  |   tipo   | atributo \n");
	printf ("--------------------------------\n");
	while (i = yylex ()) {
		printf ("%10s|%10d|", yytext, i);
		switch (i) {
			case ID:
				printf ("%10s", yylval.string); break;
			case CTINT:
				printf ("%10d", yylval.valor); break;
      case CTREAL:
        printf ("%.5f", yylval.valreal); break;
			case OPAD:
				printf ("%10d", yylval.atr); break;
			case OPMLT:
				printf ("%10d", yylval.atr); break;
		}
		printf ("\n");
	}
}
