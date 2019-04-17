flex lab3.l
yacc lab3.y
gcc y.tab.c main.c yyerror.c -o lab3 -lfl
./lab3 < input1.dat > output1.dat
./lab3 < input2.dat > output2.dat
