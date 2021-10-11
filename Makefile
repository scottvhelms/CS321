# Makefile for CS 321 Group 4 Starship project

#complier (make sure you have clang downlowded)
CC=clang

#compiler flags
CFLAGS= `sdl2-config --libs --cflags` -ggdb3 -O0 --std=c99 -Wall -lSDL2_image -lm  # -I. -std=c99

#header files
HDRS= environment.h interactables.h character.h

#source files
SRCS= main.c environment.c interactables.c character.c

#object files, generating names based on .c file names
OBJS=$(SRCS:.c=.o)

#executable file name
EXEC=Starship

all:$(EXEC)

showfont: showfont.c Makefile
	$(CC) -o $@ $@.c $(CFLAGS) $(LIBS)

glfont: glfont.c Makefile
	$(CC) -o $@ $@.c $(CFLAGS) $(LIB)

$(EXEC): $(OBJS) $(HDRS) Makefile
	$(CC) -o $@ $(OBJS) $(CFLAGS)

clean:
	rm -f $(EXEC) $(OBJS)

.PHONY: all clean


#Starship: main.o environment.o interactables.o character.o
#	$(CC) -o Starship main.o environment.o interactables.o character.o

	
#clean:
	
