all: build

build:
	g++ -I include/ src/*.cpp -lWs2_32 -o build

run:
	.\build