CC := g++
CFLAGS := -g

simmaker: simulator.o car.o map.o
	$(CC) -o simulator simulator.o car.o map.o
