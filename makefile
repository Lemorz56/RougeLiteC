CC = gcc
CFLAGS = -lpdcurses -I$(IDIR)

IDIR = ./include/
SRCDIR = ./src/

SOURCES = $(SRCDIR)*.c

all: rouge run clean

rouge:	
	$(CC) $(SOURCES) $(CFLAGS) -o $@

run:
	./rouge

clean:
	del rouge.exe