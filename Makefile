
algorithm: data_structure.o main.o
	g++ -g -o algorithm data_structure.o main.o -lpthread

main.o: main.cpp
	g++ -c -g main.cpp -o main.o

data_structure.o: data_structure.cpp data_structure.h
	g++ -c -g data_structure.cpp
