CFLAGS = -g -D_GNU_SOURCE -Wall -Wshadow -Wextra -Werror -funsigned-char -std=gnu99 -pedantic

all: clean apparatus 

csrc = $(wildcard src/*.c)
obj  = $(csrc:.c=.o)

apparatus: $(obj)
	cc $(CFLAGS) -o $@ $^

test: apparatus
	cc ./tests/check_roman.c -g -lcheck -lc -o ./tests/check_roman
	cd  tests && ./check_roman

clean:
	rm -fr apparatus tests/check_roman apparatus.dSYM src/*.o tests/check_roman.dSYM

valgrind:
	valgrind ./apparatus
