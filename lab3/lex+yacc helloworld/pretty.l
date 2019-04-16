delim		[ \t\n]
ws			{delim}+
digito	[0-9]
letra		[A-Za-z]
intct		{digito}+
id			{letra}({letra}|{digito})*
%%
{ws}		{ ;}
{id}		{strcpy (yylval.cadeia, yytext); return ID;}
{intct}	{yylval.valint = atoi(yytext); return INTCT;}
"+"		{yylval.atr = MAIS; return ADOP;}
"-"		{yylval.atr = MENOS; return ADOP;}
"("		{return OPPAR;}
")"		{return CLPAR;}
"{"		{return OPBRACE;}
"}"		{return CLBRACE;}
";"		{return SCOLON;}
"<-"		{return ASSIGN;}
.			{yylval.carac = yytext[0]; return INVAL;}
%%
