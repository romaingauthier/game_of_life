CC = gcc
CFLAGS = -O3 -std=gnu99 -Wall -g
LDFLAGS = -lncurses

SRC = $(wildcard *.c)
OBJS = $(SRC:.c=.o)
AOUT = gameOfLife

all : $(AOUT)

gameOfLife: $(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS)
%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<
clean:
	@rm *.o
