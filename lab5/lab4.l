%{
#include 	<string.h>
void comentario();
%}
delim				[ \t\n\r]
ws					{delim}+
digito			[0-9]
letra				[A-Za-z]
id 					{letra}({letra}|{digito})*
intct 			{digito}+
charct 			'\\?({letra}|{digito})'
floatct 		{digito}+\.{digito}*([Ee][+-]?{digito}+)?
string 			\"(\\.|[^\\\"])*\"
%%
"/*"			  {comentario();}
{ws}				{;}
call				{return CALL;}
char				{return CHAR;}
do					{return DO;}
else				{return ELSE;}
false				{return FALSE;}
float				{return FLOAT;}
for					{return FOR;}
functions		{return FUNCTIONS;}
global			{return GLOBAL;}
if					{return IF;}
int					{return INT;}
local				{return LOCAL;}
logic				{return LOGIC;}
main				{return MAIN;}
program			{return PROGRAM;}
read				{return READ;}
return			{return RETURN;}
statements	{return STATEMENTS;}
true				{return TRUE;}
void				{return VOID;}
while				{return WHILE;}
write				{return WRITE;}
{id}				{
  						strcpy (yylval.string, yytext);
  						return ID;
  					}
{intct}			{
  						yylval.valor = atoi(yytext);
  						return INTCT;
  					}
{charct} 		{
  						strcpy (yylval.string, yytext);
  						return CHARCT;
			    	}
{floatct} 	{
  						yylval.valreal = atof(yytext);
  						return FLOATCT;
  					}
{string} 		{
			        strcpy (yylval.string, yytext);
			        return STRING;
			    	}

"||"				{return OR;}
"&&"				{return AND;}
"!"					{return NOT;}
"~"					{return NEG;}
"<"					{
  						yylval.atr = RELOP_1;
						atr = RELOP_1;
  						return RELOP;
  					}
"<="				{
  						yylval.atr = RELOP_2;
						atr = RELOP_2;
  						return RELOP;
  					}
">"					{
  						yylval.atr = RELOP_3;
						atr = RELOP_3;
  						return RELOP;
  					}
">="				{
  						yylval.atr = RELOP_4;
						atr = RELOP_4;
  						return RELOP;
  					}
"="					{
  						yylval.atr = RELOP_5;
						atr = RELOP_5;
  						return RELOP;
  					}
"!="				{
  						yylval.atr = RELOP_6;
						atr = RELOP_6;
  						return RELOP;
  					}
"+"					{
  						yylval.atr = ADOP_1;
						atr = ADOP_1;
  						return ADOP;
  					}
"-"					{
  						yylval.atr = ADOP_2;
						atr = ADOP_2;
  						return ADOP;
  					}
"*"					{
  						yylval.atr = MULTOP_1;
						atr = MULTOP_1;
  						return MULTOP;
  					}
"/"					{
  						yylval.atr = MULTOP_2;
						atr = MULTOP_2;
  						return MULTOP;
  					}
"%"					{
  						yylval.atr = MULTOP_3;
						atr = MULTOP_3;
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
	printf("\n/*");
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
