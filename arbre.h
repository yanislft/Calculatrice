#ifndef ARBRE_H
#define ARBRE_H

#include "noeud.h"
#include<iostream>
#include<sstream>
#include<string>
#include "pile.h"

using namespace std;

//Question 3: Classe arbre + Constructeur sans argument + avec une expression infixe + destructeur + fonction évaluation et affichage d'une expression contenue dans un arbre
//Question 4: Fonction qui dérive une expression contenue dans un arbre

class arbre
{   
    public:
    noeud *racine;

    public :
        arbre();
        arbre(noeud *r);
        arbre(string infix);
        ~arbre();
        double evaluation(noeud *a);
        double evaluation();
        void arbre_to_infixe(noeud *r);
        void arbre_to_infixe();
        noeud* derivee(noeud *r, string var);
        noeud* derivee(string var);
};
#endif