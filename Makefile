# $Id$ 
#
# loan - loan makefile

SHELL= /bin/sh
CC= cc
CFLAGS= -g -O

DESTDIR = /usr/local/bin
INSTALL= bsdinst
TARGETS= loan loanlen

all: ${TARGETS}

loan: loan.o
	${CC} ${CFLAGS} loan.o -o loan -lm

loan.o: loan.c
	${CC} ${CFLAGS} loan.c -c

loanlen: loanlen.o
	${CC} ${CFLAGS} loanlen.o -o loanlen -lm

loanlen.o: loanlen.c
	${CC} ${CFLAGS} loanlen.c -c

install: all
	${INSTALL} -c -m 0755 loan ${DESTDIR}
	${INSTALL} -c -m 0755 loanlen ${DESTDIR}

clean:
	rm -f *.o

clobber: clean
	rm -f ${TARGETS}
