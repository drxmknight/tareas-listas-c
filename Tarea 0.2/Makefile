# Compiler
CC = gcc
# options
CFLAGS = -c -Wall
#all .o
OBJS = list.o course.o main.o

main: $(OBJS)
	$(CC) $(OBJS) -o main
	rm -f *.o

main.o: main.c 
	$(CC) $(CFLAGS) main.c

list.o: list.c list.h course.o
	$(CC) $(CFLAGS) list.c

course.o: course.c course.h
	$(CC) $(CFLAGS) course.c
