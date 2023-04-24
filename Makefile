mysh: main.o shell.o 
	g++ main.o shell.o -o mysh

main.o: main.cpp
	g++ -c main.cpp

shell.o: shell.cpp shell.hpp
	g++ -c shell.cpp

clean:
	rm *.o mysh