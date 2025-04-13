#ifndef NOEUD_H
#define NOEUD_H
#include<iostream>
#include<sstream>

using namespace std;
class noeud
{   
    public :
    friend class arbre;
    friend class pile;
    string type; //‘o’ pour opérateur ,‘f’ pour valeur, 'v' pour variable ou 'n' pour nul.
    string operateur;
    string variable;
    double valeur ;
    noeud *fils_gauche, *fils_droite;

    public :
        noeud();
        noeud(string c);
        noeud(double x);
        noeud(noeud *n);
        void afficher();
        noeud(string c, noeud *u, noeud *v);
        double puissance(double x, double n);
        ~noeud();

};
#endif