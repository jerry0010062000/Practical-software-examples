#makefile

CC = gcc
CFLAGS= -Wall -fPIC

all: libmylib.so program

libmylib.so: mylib.o
	$(CC) -shared -o libmylib.so mylib.o

mylib.o: mylib.c mylib.h
	$(CC) $(CFLAGS) -c mylib.c

program: main.o
	$(CC) -L. -o program main.o -lmylib

main.o: main.c mylib.h
	$(CC) $(CFLAGS) -c main.c

clean:
	rm -f *.o *.so program
