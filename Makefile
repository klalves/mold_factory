SHELL=/bin/sh
CC=gcc
CFLAGS= -O3

default:	aplicacao

aplicacao:	aplicacao.c  aplicacao.h
	$(CC) $(CFLAGS) aplicacao.c -o aplicacao

clean:
	rm -f aplicacao *.o core a.out *.*~ Makefile~

all: aplicacao
