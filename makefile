all:
	gcc `pkg-config --cflags gtk+-3.0` -o start2 main.c `pkg-config --libs gtk+-3.0`