a.out:  main.o
	g++  main.o

main.o: Player.h Deck.h main.cc
	g++ -c main.cc
