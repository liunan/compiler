LEX=flex
scanner.o:lex.yy.c scanner.l
	cc -c lex.yy.c -o scanner.o
lex.yy.c:scanner.l paser.y
	flex scanner.l
paser:paser.y scanner.o
	yacc -d paser.y
	cc -c y.tab.c -o paser.o
	cc paser.o scanner.o -o paser.exe
pasert:
	./paser.exe < ./sample/funcdeclare.h