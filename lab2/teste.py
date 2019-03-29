arr = ["call", 
"char", 
"do", 
"else", 
"false", 
"float", 
"for", 
"functions", 
"global", 
"if", 
"int", 
"local", 
"logic", 
"main", 
"program", 
"read", 
"return", 
"statements", 
"true", 
"void", 
"while", 
"write"]

i=1
for x in arr:
	print(x + "	{return " + x.upper() + ";}")