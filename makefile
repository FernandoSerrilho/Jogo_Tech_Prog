CXX      := g++
CXXFLAGS := -std=c++20 -Iinclude -IC:/SFML/include
LDFLAGS  := -LC:/SFML/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network

TARGET   := bin/jogo.exe
SRCS     := $(wildcard src/*.cpp)
OBJS     := $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET) $(LDFLAGS)

src/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	del /Q /F src\*.o bin\*.exe

.PHONY: all clean