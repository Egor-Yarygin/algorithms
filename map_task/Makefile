CC = mingw32-g++
CFLAGS = -std=c++11 -Wall -pedantic
SOURCE = c++.cpp

ifeq ($(OS), Windows_NT)
	RM = del
	TARGET = result.exe
else
	RM = rm
	TARGET = result
endif



all:
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCE)

run: all
	$(TARGET) | py .\python.py

clean:
	$(RM) $(TARGET)
