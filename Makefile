CC = gcc
CFLAGS = -g -pedantic -Wextra

all: main

main: main.o io.o commands.o stack_logic.o
	$(CC) $(CFLAGS) -o main main.o io.o commands.o stack_logic.o

main.o: src/main.c include
io.o: src/io.c include
commands.o: src/commands.c include
stack_logic.o: src/stack_logic.c include

%.o: src/%.c
	$(CC) -I./include $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o main
