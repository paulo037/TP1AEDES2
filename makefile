
all: UI

UI: main.o TST.o
	gcc -Wno-format -o UI main.o TST.o -Wno-deprecated-declarations -Wno-format-security -lm `pkg-config --cflags --libs gtk+-3.0` -export-dynamic
main.o: main.c TST.h
	gcc `pkg-config --cflags gtk+-3.0` -o main.o main.c -c -W -Wall -ansi -pedantic
TST.o: TST.c TST.h
	gcc -o TST.o TST.c -c -W -Wall -ansi -pedantic

clean:
	rm -rf *.o *~ teste
