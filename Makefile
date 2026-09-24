CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2
TARGET = blackjack

SRCS = main.cpp
HEADERS = ascii.h def_library.h history.h money.h

all: $(TARGET)

$(TARGET): $(SRCS) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET)

clean:
	rm -f $(TARGET) $(TARGET).exe *.o
