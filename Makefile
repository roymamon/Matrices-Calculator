CXX = g++
CXXFLAGS = -Wall -std=c++11

MAIN_TARGET = demo
TEST_TARGET = test

MAIN_SOURCES = Graph.cpp Algorithms.cpp Demo.cpp
TEST_SOURCES = Graph.cpp Algorithms.cpp Test.cpp

MAIN_OBJECTS = $(MAIN_SOURCES:.cpp=.o)
TEST_OBJECTS = $(filter-out Demo.o, $(MAIN_OBJECTS)) Test.o

HEADERS = Graph.hpp Algorithms.hpp

all: $(MAIN_TARGET) $(TEST_TARGET)

$(MAIN_TARGET): $(MAIN_OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(MAIN_TARGET) $(MAIN_OBJECTS)

$(TEST_TARGET): $(TEST_OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TEST_TARGET) $(TEST_OBJECTS)

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f $(MAIN_TARGET) $(TEST_TARGET) $(MAIN_OBJECTS) Test.o

.PHONY: all clean
