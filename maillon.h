#ifndef MAILLON_H
#define MAILLON_H

#include "noeud.h"
#include<iostream>
#include<string>

using namespace std;


class maillon
{
    friend class pile;
    public : 
    string operateur;
    double operande;
    noeud *n;
    maillon *suivant;

    public :
        maillon();
        maillon(double &a);
        maillon(double &a, maillon *suiv);
        maillon(maillon *suiv);
        maillon(string &a);
        maillon(string &a, maillon *suiv);
        double priorite_operateur();
        maillon(noeud *z);
        maillon(noeud *z, maillon *suiv);
        ~maillon();
};

#endif