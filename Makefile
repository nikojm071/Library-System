CC = gcc
CFLAGS = -Wall -Werror -pedantic -g

librarySystem: account.o library.o string.o vector.o librarySystem.o
	$(CC) account.o library.o string.o vector.o librarySystem.o -o librarySystem $(CFLAGS)

#These turn all of the .c files into their necessary .o counterpart
librarySystem.o: librarySystem.c
	$(CC) -c librarySystem.c $(CFLAGS)

vector.o: vector.c vector.h
	$(CC) -c vector.c $(CFLAGS)

string.o: string.c string.h
	$(CC) -c string.c $(CFLAGS)

library.o: library.c library.h
	$(CC) -c library.c $(CFLAGS)

account.o: account.c account.h
	$(CC) -c account.c $(CFLAGS)

#this will remove all of the .o files from the directory
clean:
	rm *.o librarySystem