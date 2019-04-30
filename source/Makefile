# -*- Makefile -*-
CC = g++

TARGET = game

LINKERFLAG = -lSDL2 -lSDL2_image 

DEP = main.cpp game.cpp ship.cpp rock.cpp bullet.cpp

$(TARGET): $(DEP)
	$(CC) $(DEP) $(LINKERFLAG) -o $(TARGET)

clean: 
	rm -rvf *.o $(TARGET)
