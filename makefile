CC=gcc
CFLAGS=-Wall -O
EXEC=main.exe
SRC=$(wildcard */*.c)
OBJ=$(SRC:.c=.o)

all: $(EXEC)

run: all
	$(EXEC)

$(EXEC): $(OBJ) main.o
	$(CC) -o $@ $^ $(CFLAGS)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	del *.o *.exe