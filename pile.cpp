#include<iostream>
#include "pile.h"
using namespace std;

pile::pile()
{
    tete = nullptr;
}

void pile::empiler(double a)
{
   maillon *m = new maillon(a,tete);
   tete = m;
}

void pile::empiler(string a)
{
   maillon *m = new maillon(a,tete);
   tete = m;
}

void pile::empiler(noeud *a)
{
    maillon *m = new maillon(a,tete);
    tete = m;
}

double pile::depiler()
{
    if (tete != NULL) 
    {
        int v; 
        v = tete->operande; 

        maillon* tmp = new maillon(tete);
        tete = tete->suivant;
        delete tmp;

        return(v);
    }
    return(-1);
}

string pile::depiler_string()
{
    if (tete != NULL) 
    {
        string v; 
        v = tete->operateur; 

        maillon* tmp = new maillon(tete);
        tete = tete->suivant;
        delete tmp;

        return(v);
    }
    return(0);
}

noeud* pile::depiler_noeud()
{
    if (tete != NULL) 
    {
        noeud *v;
        v = tete->n;

        maillon* tmp = new maillon(tete);
        tete = tete->suivant;

        delete tmp;

        return(v);
    }
    return (nullptr);
}

bool pile::vide()
{
    if (tete != NULL) {return (false);}
    else {return(true);}
}

void pile::afficher(maillon *x)
{
    if (x == NULL) {return;}
    cout<<x->operande<<';';
    afficher(x->suivant);
}

void pile::afficher()
{
    afficher(tete);
}

double pile::puissance(double x, double n)
{
    if (n == 0) {return (1);}
    else if (n == 1) {return (x);}
    else {return (puissance(x, n-1) * x);}
}

pile::~pile()
{
    while (tete != nullptr)
    {
        maillon *tmp = new maillon(tete);
        tete = tete->suivant;
        delete tmp;
    }
}
