CXXFLAGS += -Wall -std=c++17 -pedantic -fsanitize=address

main:	main.o shape.o
	$(CXX) -o $@ $^ -fsanitize=address
