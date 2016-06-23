## Process this file with automake to produce Makefile.in

TESTS = check_roman
check_PROGRAMS = check_roman
check_money_SOURCES = check_roman.c $(top_builddir)/src/roman.h
check_money_CFLAGS = @CHECK_CFLAGS@
check_money_LDADD = $(top_builddir)/src/libroman.la @CHECK_LIBS@
