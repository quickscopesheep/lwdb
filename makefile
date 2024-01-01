all: build

build:
	g++ -g -I include/ src/*.cpp -lWs2_32 -o build

run:
	.\build