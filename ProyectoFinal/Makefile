# Makefile mejorado con 'run'

CXX = g++
CXXFLAGS = -Wall -std=c++17
TARGET = prog
SRC = main.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)

