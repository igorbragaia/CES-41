%{
#define	ACEITA	1
#define	OUTRA 	2

union {
	char string[5];
} yylval;
int readChain (char);
%}
drop [^01]
%%
{drop}	{ ;}
"0"		{return readChain('0');}
"1"		{return readChain('1');}
%%

int readChain (char start) {
	char all[50], c;
	all[0] = start;
	int estado = 1, index = 1;
	if(start == '1') estado = 2;
	else if(start == '0') estado = 4;

	while(1){
		c = input();
		if(c != '1' && c != '0') break;
		all[index++] = c;

		switch(estado){
			case 1:
				if(c == '0') estado = 4;
				else if(c == '1') estado = 2;
				break;
			case 2:
				if(c == '0') estado = 3;
				else if(c == '1') estado = 1;
				break;
			case 3:
				if(c == '0') estado = 2;
				else if(c == '1') estado = 4;
				break;
			case 4:
				if(c == '0') estado = 1;
				else if(c == '1') estado = 3;
				break;
		}
	}
	all[index] = '\0';

	strcpy(yylval.string, all);

	if(estado == 3)
		return ACEITA;
	else
		return OUTRA;
}

main () {
	int i;
	while (i = yylex ())
		switch (i) {
			case ACEITA:
				printf ("%-20s: Aceita\n", yylval.string);
				break;
			case OUTRA:
				printf ("%-20s: Rejeitada\n", yylval.string);
				break;
		}
}
