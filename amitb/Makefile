# Filename: Makefile
# Description: The make file is to build up the amitb lib
CC=gcc
OS=Linux
VERSION=0.0.1


CFLAGS= -Wall -pedantic -std=c99
#LDFLAGS=-lm

BUILDDIR = build
SOURCEDIR = src
HEADERDIR = src

#SOURCES=./list.h ./list.c ./crawler.c ./crawler.h
#CFILES=./list.c ./crawler.c

SOURCES := $(shell find $(SOURCEDIR) -name '*.c')

#UTILDIR=../util/
#UTILFLAG=-ltseutil
#UTILLIB=$(UTILDIR)libtseutil.a
#UTILC=$(UTILDIR)hash.c $(UTILDIR)html.c $(UTILDIR)file.c $(UTILDIR)dictionary.c
#UTILH=$(UTILC:.c=.h)

#crawler:$(SOURCES) $(UTILDIR)header.h $(UTILLIB)
#        $(CC) $(CFLAGS) -o $@ $(CFILES) -L$(UTILDIR) $(UTILFLAG)

#$(UTILLIB): $(UTILC) $(UTILH)
#        cd $(UTILDIR); make;

