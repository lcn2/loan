#!/usr/bin/env make
#
# loan - loan makefile
#
# Please do not copyright this code.  This code is in the public domain.
#
# LANDON CURT NOLL DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE,
# INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO
# EVENT SHALL LANDON CURT NOLL BE LIABLE FOR ANY SPECIAL, INDIRECT OR
# CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF
# USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR
# OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
# PERFORMANCE OF THIS SOFTWARE.
#
# chongo <was here> /\oo/\
#
# Share and enjoy!

SHELL= bash
CC= cc
CFLAGS= -O3 -g3 

DESTDIR = /usr/local/bin
INSTALL= install
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
