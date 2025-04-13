main : main.cpp pile.o maillon.o arbre.o noeud.o
	g++ -o main  pile.o maillon.o arbre.o noeud.o main.cpp

pile.o : pile.h maillon.h pile.cpp
	g++ -c pile.cpp

maillon.o : maillon.h maillon.cpp
	g++ -c maillon.cpp

arbre.o : arbre.h noeud.h arbre.cpp
	g++ -c arbre.cpp

noeud.o : noeud.h noeud.cpp
	g++ -c noeud.cpp