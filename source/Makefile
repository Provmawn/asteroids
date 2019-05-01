# -*- Makefile -*-
CC = g++

TARGET = game

COMPILERFLAG = -g

LINKERFLAG = -lSDL2 -lSDL2_image 

DEP = main.cpp game.cpp ship.cpp rock.cpp bullet.cpp

$(TARGET): $(DEP)
	$(CC) $(COMPILERFLAG) $(DEP) $(LINKERFLAG) -o $(TARGET)

clean: 
	rm -rvf *.o $(TARGET)
