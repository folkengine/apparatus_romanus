CFLAGS = -g  -v -Wall -Wshadow -Wextra -Werror -funsigned-char -std=c99 -pedantic
RM = rm -rf

SOURCES = src/main.c src/roman.h src/roman.c
OBJ = main.o roman.o

clean:
	rm -rf *.o apparatus

apparatus : main.o
	cc -o apparatus main.o roman.o

main.o : src/main.c src/roman.h
	cc -c src/main.c src/roman.c


