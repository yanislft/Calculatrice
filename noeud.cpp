#include "noeud.h"
#include<iostream>

using namespace std; 

noeud::noeud()
{
    type = 'n';
    valeur = 0.0;
    operateur = ' ';
    variable =' ';
    fils_gauche = nullptr;
    fils_droite = nullptr;  
}

noeud::noeud(string c)
{
    if (c == "+" || c == "-" || c == "*" || c == "/" || c == "^")
    {
        type = "o";
        operateur = c;
        variable = " ";
    }

    else 
    {
        type ="v";
        variable = c;
        operateur = " ";
    }

    valeur = 0;
    fils_gauche = nullptr;
    fils_droite = nullptr;
}

noeud::noeud(double x)
{
    type = "f";
    valeur = x;
    operateur = " ";
    fils_gauche = nullptr;
    fils_droite = nullptr;  
}

noeud::noeud(noeud *n)
{
    type = n->type;
    valeur = n->valeur;
    operateur = n->operateur;
    fils_gauche = n->fils_gauche;
    fils_droite = n->fils_droite;
}

void noeud::afficher() 
{
    if (type == "n") {cout<<"Noeud nul";}

    else if (type == "o") {cout<<"Type: "<<type<<"; Opérateur: "<<operateur;}
    else if (type == "f") {cout<<"Type: "<<type<<"; Valeur: "<<valeur;}
    else if (type == "v") {cout<<"Type: "<<type<<"; Valeur: "<<variable;}
    cout<<endl;
}

noeud::noeud(string c, noeud *u, noeud *v)
{
    if (c == "+" || c == "-" || c == "*" || c == "/" || c == "^")
    {
        type = "o";
        operateur = c;
        variable = " ";
    }

    else 
    {
        type ="v";
        variable = c;
        operateur = " ";
    }

    fils_gauche = u;
    fils_droite = v;
    valeur = 0;
}

double noeud::puissance(double x, double n)
{
    if (n == 0) {return (1);}
    else if (n == 1) {return (x);}
    else {return (puissance(x, n-1) * x);}
}

noeud::~noeud()
{
    delete fils_gauche;
    delete fils_droite;
}