CXX = clang++
CXXFLAGS = -std=c++0x

all: constexpr

a.o: a.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

constexpr: a.o main.o
	$(CXX) -o constexpr $^
