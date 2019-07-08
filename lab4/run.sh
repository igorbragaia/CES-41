flex lab4.l
yacc lab4.y
gcc y.tab.c main.c yyerror.c -o lab4 -lfl
./lab4 < input3.dat
# ./lab4 < input1.dat > output1.dat
# ./lab4 < input2.dat > output2.dat
# ./lab4 < input3.dat > output3.dat
