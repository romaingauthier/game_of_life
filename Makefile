CFLAGS = -O3 -std=gnu99 -Wall -o
CC = gcc

all: gameOfLife cleanup

gameOfLife: main.o gol.o cmd.o patterns.o
	$(CC) $(CFLAGS) gameOfLife main.o gol.o cmd.o patterns.o -lncurses

main.o:
	$(CC) -c $(CFLAGS) main.o main.c

cmd.o:
	$(CC) -c $(CFLAGS) cmd.o cmdline.c

patterns.o:
	$(CC) -c $(CFLAGS) patterns.o patterns.c

gol.o:
	$(CC) -c $(CFLAGS) gol.o gameoflife.c

cleanup:
	rm -f *.o

clean: cleanup
	rm -f gameOfLife

