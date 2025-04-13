#include<iostream>
#include "maillon.h"

using namespace std;

maillon::maillon()
{
    operande = 0;
    operateur = " ";
    n = nullptr;
    suivant = nullptr;
}

maillon::maillon(double &a)
{
    operande = a;

    operateur = " ";
    n = nullptr;
    suivant = nullptr;
}

maillon::maillon(double &a, maillon *s)
{
    operande = a;
    suivant = s;

    operateur = " ";
    n = nullptr;
}

maillon::maillon(maillon *suiv)
{
    suivant = suiv;

    operande = 0;
    operateur = " ";
    n = nullptr;
}

maillon::maillon(string &a)
{
    operateur = a;

    operande = 0;
    n = nullptr;
    suivant = nullptr;
}

maillon::maillon(string &a, maillon *suiv)
{
    operateur = a;
    suivant = suiv;

    operande = 0;
    n = nullptr;
}

double maillon::priorite_operateur()
{
    double prio_ope;

    if (operateur == "(" || operateur == ")") {prio_ope = 0;}
    else if (operateur == "+" || operateur == "-") {prio_ope = 1;}
    else {prio_ope = 2;}

    return (prio_ope);
}

maillon::maillon(noeud *z)
{
    n = z;

    operande = 0;
    operateur = " ";
    suivant = nullptr;
}

maillon::maillon(noeud *z, maillon *suiv)
{
    operateur = " ";
    operande = 0;

    n = z;
    suivant = suiv;
}

maillon::~maillon()
{
    delete n;
}