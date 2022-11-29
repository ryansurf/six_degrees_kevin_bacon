CXX = g++
CXXFLAGS = -Wall -std=c++11

OBJECTS = main.o helper.o

sixdegrees: $(OBJECTS)
	$(CXX) -g $(CXXFLAGS) -o $@ $^

clean:
	rm -f *.o sixdegrees
$(OBJECTS): header.h