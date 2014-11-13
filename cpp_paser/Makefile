LEX=flex
a.exe:scanner.o	
	cc scanner.o
scanner.o:scanner.l	
test:a.exe sample.txt
	./a.exe < sample.txt