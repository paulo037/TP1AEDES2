all: teste

teste: main.o TST.o
	gcc -o teste main.o TST.o
main.o: main.c TST.h
	gcc -o main.o main.c -c -W -Wall -ansi -pedantic
TST.o: TST.c TST.h
	gcc -o TST.o TST.c -c -W -Wall -ansi -pedantic

clean:
	rm -rf *.o *~ teste
