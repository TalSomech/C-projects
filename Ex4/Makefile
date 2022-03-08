

CC=gcc
FLAGS= -Wall

all: frequency
frequency: tree.o
	$(CC) $(FLAGS) -o frequency $^

tree.o:tree.c tree.h
	$(CC) $(FLAGS) -c $^

.PHONY:clean all

clean:
	rm *.o frequency *.h.gch
