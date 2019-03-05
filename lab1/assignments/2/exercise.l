%{
#define	ACEITA	1
#define 	OUTRA 	2
%}
delim		[ \t\n\r]
ws			{delim}+
aceita	(00|11|(10|01)(00|11)*(10|01))*(10|01)(00|11)*
string	[^ \t\n\r]+
%%
{ws}		{ ;}
{aceita}  {return ACEITA;}
{string}	{return OUTRA;}
%%
main () {
	int i;
	while (i = yylex ())
		switch (i) {
			case ACEITA:
				printf ("%-20s: Aceita\n", yytext);
				break;
			case OUTRA:
				printf ("%-20s: Rejeitada\n", yytext);
				break;
		}
}
