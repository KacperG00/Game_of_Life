all: main

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

clean:
	rm *.o main
