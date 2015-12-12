all: main

main: main.o functions.o non-blocking.o EditMode.o Menu.o game.o
	g++ main.o functions.o non-blocking.o EditMode.o Menu.o game.o -o main
	
main: main.o functions.o non-blocking.o EditMode.o
	g++ main.o functions.o non-blocking.o EditMode.o -o main

main.o: main.cpp
	g++ -c main.cpp
	
functions.o: functions.cpp
	g++ -c functions.cpp
	
non-blocking.o: non-blocking.cpp
	g++ -c non-blocking.cpp
	
EditMode.o: EditMode.cpp
	g++ -c EditMode.cpp

Menu.o: Menu.cpp
	g++ -c Menu.cpp

game.o: game.cpp
	g++ -c game.cpp

clean:
	rm *.o main
