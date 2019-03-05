%{
#include 	<string.h>
#define 	ELSE 		1
#define 	IF 	  	2
#define	  WHILE   3
#define	  ID	   	4
#define	  CTINT		5
#define	  OPREL		6
#define   CTREAL  7
#define   CHAR    8
#define   STRING  9
#define   INVAL   10
#define 	LT 	   	1
#define 	LE   	 	2
#define	  GT  		3
#define	  GE	  	4
#define	  EQ  		5
#define	  NE	   	6
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
ctint		{digito}+
id			{letra}({letra}|{digito})*
ctreal  {digito}+\.{digito}*([Ee][+-]?{digito}+)
char    '\\?.'
string  "{char}*"
%%
{ws}		{ ;}
else		{return ELSE;}
if			{return IF;}
while		{return WHILE;}
{id}		{strcpy (yylval.string, yytext); return ID;}
{ctint}	{yylval.valor = atoi(yytext); return CTINT;}
{ctreal} {yylval.valreal = atof(yytext); return CTREAL;}
{char}  {
          int i;
          for(i=0;i<strlen(yytext)-2; i++)
            yytext[i] = yytext[i+1];
          yytext[i] = '\0';
          strcpy (yylval.string, yytext); return CHAR;}
{string} {
          int i;
          for(i=0;i<strlen(yytext)-2; i++)
            yytext[i] = yytext[i+1];
          yytext[i] = '\0';
          strcpy (yylval.string, yytext); return STRING;}
"<"	  	{yylval.atr = LT; return OPREL;}
"<="		{yylval.atr = LE; return OPREL;}
">"	  	{yylval.atr = GT; return OPREL;}
">="		{yylval.atr = GE; return OPREL;}
"=="		{yylval.atr = EQ; return OPREL;}
"!="		{yylval.atr = NE; return OPREL;}
.	    	{yylval.carac = yytext[0]; return INVAL;}
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
        printf ("%f", yylval.valreal); break;
      case CHAR:
				printf ("%10s", yylval.string); break;
      case STRING:
				printf ("%10s", yylval.string); break;
			case OPREL:
				printf ("%10d", yylval.atr); break;
      case INVAL:
        printf("%10c", yylval.carac); break;
		}
		printf ("\n");
	}
}
