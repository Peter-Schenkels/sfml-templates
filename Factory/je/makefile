CXX = g++
CXXFLAGS = -std=c++0x -Wall
LIBS=-lsfml-graphics -lsfml-window -lsfml-system

OBJECTS = main.o 
main: $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LIBS)

$(OBJECTS): json.hpp jsonsfml.hpp object.cpp rectangle.cpp circle.cpp factory.hpp object.hpp rectangle.hpp circle.hpp 

clean: $(OBJECTS) main
	rm -f $(OBJECTS) main

run: main	
	./main