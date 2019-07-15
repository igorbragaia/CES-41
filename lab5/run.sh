flex lab4.l
yacc lab4.y
gcc y.tab.c main.c yyerror.c -o lab4 -lfl
./lab4 < input.dat