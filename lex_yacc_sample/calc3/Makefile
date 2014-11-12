LEX=flex
YACC=yacc

calc3_i.exe:lex.yy.o y.tab.o interpreter.o
	CC lex.yy.o y.tab.o interpreter.o -o calc3_i.exe
lex.yy.o:lex.yy.c y.tab.h
	$(CC) -c lex.yy.c
lex.yy.c:calc.lex
	$(LEX) calc.lex
y.tab.o:y.tab.c y.tab.h
	$(CC) -c y.tab.c
y.tab.c y.tab.h:calc.yacc
	$(YACC) calc.yacc -d
interpreter.o:interpreter.c
	$(CC) -c interpreter.c
compiler.o:compiler.c
	$(CC) -c compiler.c
calc3_c.exe:lex.yy.o y.tab.o compiler.o
	$(CC) lex.yy.o y.tab.o compiler.o -o calc3_c.exe
clean:
	rm -f *.o

	