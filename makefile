run:main
	./main
main:main.o
	g++ main.o -o main
main.o:main.cpp
	g++ main.cpp -c -o main.o
