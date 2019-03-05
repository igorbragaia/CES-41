%{
#define	ACEITA	1
#define OUTRA 	2
%}
delim		[ \t\n\r]
ws			{delim}+
rejeita  (0|1)*101(0|1)*
string	[^ \t\n\r]+
%%
{ws}		{ ;}
{rejeita}  {return OUTRA;}
{string}	{return ACEITA;}
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
