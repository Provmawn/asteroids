# -*- Makefile -*-
CC = g++

TARGET = game

COMPILERFLAG = -g

LINKERFLAG = -lSDL2 -lSDL2_image 

DEP = main.cc game.cc player.cc asteroid.cc bullet.cc timer.cc
HEADER = game.h player.h asteroid.h bullet.h timer.h

$(TARGET): $(DEP) $(HEADER)
	$(CC) $(COMPILERFLAG) $(DEP) $(LINKERFLAG) -o $(TARGET)

clean: 
	rm -rvf *.o $(TARGET)
