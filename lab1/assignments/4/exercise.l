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
	int response = 1;

	char all[50], c;
	all[0] = start;
	int index=1;

	int size=0, last=0, i, qty1;
	while(1){
		c = input();
		if(c != '1' && c != '0') break;

		all[index] = c;

		if(index > 5){
			qty1=0;
			for(i=index; i>index-5;i--)
				qty1 += all[i] == '1';
			if(qty1 < 3)
				response = 0;
		}

		index++;
	}
	all[index]='\0';

	strcpy(yylval.string, all);

	if(response && index >= 5)
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
