# Profile : add -pg
CFLAGS  = -std=c++17 -Wall -g -I/usr/include/SDL2/ # -fopenmp
LDFLAGS = -lSDL2

CC = g++
RM = rm -f

EXE = poule
HEADERS = Constants.h Game.h Partie.h Render.h Input.h Poule.h Gnome.h Oeuf.h
OBJS = main.o Game.o Partie.o Render.o Input.o Poule.o Gnome.o Oeuf.o

ALL : $(EXE)

%.o: %.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

$(EXE) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(EXE) $(LDFLAGS)

clean :
	$(RM) $(OBJS) $(EXE)
