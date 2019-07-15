flex lab4.l
yacc lab4.y
gcc y.tab.c main.c yyerror.c -o lab4 -lfl
./lab4 < input.1.dat > output.1.dat
./lab4 < input.2.dat > output.2.dat
./lab4 < input.3.dat > output.3.dat
./lab4 < input.4.dat > output.4.dat
