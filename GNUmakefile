CFLAGS = -g -D_GNU_SOURCE -Wall -Wshadow -Wextra -Werror -funsigned-char -std=gnu99 -pedantic
LDFLAGS = -lcheck -lc -lm -lrt -lpthread

OS := $(shell uname)
ifeq ($(OS),Darwin)
	LDFLAGS = -lcheck -lc -lm -lpthread  
endif

all: clean apparatus 

csrc = $(wildcard src/*.c)
obj  = $(csrc:.c=.o)

apparatus: $(obj)
	cc $(CFLAGS) -o $@ $^ $(LDFLAGS)

test: apparatus
	cc $(CFLAGS) ./tests/check_roman.c -o ./tests/check_roman $(LDFLAGS)
	cd  tests && ./check_roman

clean:
	rm -fr apparatus tests/check_roman apparatus.dSYM src/*.o tests/check_roman.dSYM

valgrind:
	valgrind ./apparatus
