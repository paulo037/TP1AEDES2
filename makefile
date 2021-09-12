all:
	gcc `pkg-config --cflags gtk+-3.0` -o UI main.c TST.c `pkg-config --libs gtk+-3.0`

clean:
	rm -rf *.o *~ teste
