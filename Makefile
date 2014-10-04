CXX = clang++
SOURCE = main.cpp
EXEC = mainExec
FLAGS = -std=c++11 -g
CLEAR = clear

all:
	$(CXX) $(SOURCE) -o $(EXEC) $(FLAGS)
	$(CLEAR)
run:
	./$(EXEC)
	$(CLEAR)
