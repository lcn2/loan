# $Id$ 
#
# loan - loan makefile

SHELL= /bin/sh
CC= cc
CFLAGS= -O

DESTDIR = /usr/local/bin
TARGETS= loan

all: ${TARGETS}

loan: loan.o
	${CC} ${CFLAGS} loan.o -o loan -lm

loan.o: loan.c
	${CC} ${CFLAGS} loan.c -c

install: all
	install -c -m 0755 loan ${DESTDIR}

clean:
	rm -f *.o

clobber: clean
	rm -f ${TARGETS}
