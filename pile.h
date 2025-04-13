#include "maillon.h"
#include "noeud.h"
#include<iostream>
#include<sstream>

using namespace std;

//Question 1 : Classe pile implémentée avec une liste chainée + fonction empiler, dépiler, vide

class pile
{
    public :
    maillon *tete;

    public :
        pile();
        void empiler(double a);
        void empiler(string a);
        void empiler(noeud *n);
        double depiler();
        string depiler_string();
        noeud* depiler_noeud();
        bool vide();
        void afficher(maillon *x);
        void afficher();
        double puissance(double x, double n);
        ~pile();
};