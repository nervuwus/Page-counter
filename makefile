all: main

main:
	g++ -Wall -o count ./src/main.cpp

clean:
	rm count