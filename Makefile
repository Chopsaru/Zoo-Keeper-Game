project2: main.o Animal.o Penguin.o Tiger.o Turtle.o Validators.o Zoo.o
	g++ -std=c++11 main.o Animal.o Penguin.o Tiger.o Turtle.o Validators.o Zoo.o -o project2

main.o:	main.cpp
	g++ -c -std=c++11 main.cpp

Animal.o: Animal.hpp Animal.cpp
	g++ -c -std=c++11 Animal.cpp

Penguin.o: Penguin.hpp Penguin.cpp
	g++ -c -std=c++11 Penguin.cpp

Tiger.o: Tiger.hpp Tiger.cpp
	g++ -c -std=c++11 Tiger.cpp
	
Turtle.o: Turtle.hpp Turtle.cpp	
	g++ -c -std=c++11 Turtle.cpp

Validators.o: Validators.hpp Validators.cpp
	g++ -c -std=c++11 Validators.cpp
	
Zoo.o: Zoo.hpp Zoo.cpp
	g++ -c -std=c++11 Zoo.cpp

clean:
	rm *.o project2
