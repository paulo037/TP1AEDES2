all: ./obj/main.o ./obj/arquivo.o ./obj/Patricia.o ./obj/interface.o ./obj/tst.o
	gcc `pkg-config --cflags gtk+-3.0` -o app  ./obj/interface.o ./obj/arquivo.o ./obj/Patricia.o ./obj/main.o ./obj/tst.o `pkg-config --libs gtk+-3.0` -lm

./obj/tst.o: ./src/tst.c
	gcc `pkg-config --cflags gtk+-3.0` -o ./obj/tst.o -c ./src/tst.c `pkg-config --libs gtk+-3.0`

./obj/main.o: ./src/main.c
	gcc `pkg-config --cflags gtk+-3.0` -o ./obj/main.o -c ./src/main.c `pkg-config --libs gtk+-3.0`

./obj/arquivo.o: ./src/arquivo.c
	gcc `pkg-config --cflags gtk+-3.0` -o ./obj/arquivo.o -c ./src/arquivo.c -lm `pkg-config --libs gtk+-3.0`

./obj/Patricia.o: ./src/Patricia.c
	gcc `pkg-config --cflags gtk+-3.0` -o ./obj/Patricia.o -c ./src/Patricia.c `pkg-config --libs gtk+-3.0`

./obj/interface.o: ./src/interface.c
	gcc `pkg-config --cflags gtk+-3.0` -o ./obj/interface.o -c ./src/interface.c `pkg-config --libs gtk+-3.0`


clean:
	rm ./obj/*o
