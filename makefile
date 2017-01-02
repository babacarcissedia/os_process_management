IDIR=./include
ODIR=./obj
LDIR=./lib
SDIR=./src
CC=gcc
CFLAGS=-I$(IDIR)
LFLAGS=-L$(LDIR)

DEPS=$(ODIR)/%.h
OBJ=$(ODIR)/%.o

FORMS: fenetreacceuil.ui ordonnanceur.ui processus.ui
	$(CC) -g -o bin/slave src/slave.c src/explode.c $(CFLAGS) $(LFLAGS) -lpthread


projose: main.cpp ordonnanceur.cpp processus.cpp gantt.cpp fenetreacceuil.cpp
	$(CC) -g -o bin/master src/master.c $(CFLAGS) $(LFLAGS) -lpthread


