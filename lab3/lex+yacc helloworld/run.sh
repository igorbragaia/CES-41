flex $1.l
yacc $1.y
gcc y.tab.c main.c yyerror.c -o $1 -lfl
./$1 < $2
