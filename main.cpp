#include<iostream>
#include<sstream>
#include<string>
#include "arbre.h"

using namespace std;

//Question 1 : Évaluer une expression suffixée
double calcul_suffixe(string x)
{
    istringstream s(x); 
    pile p;
    string v;

    while (s >> v)
    {
        if (v == " " || v == "#") {continue;}

        //Lorsqu'un opérateur et dépiler les deux derniers éléments de la pile et leur appliquer l'opération corespondante
        else if (v == "+" || v == "-" || v == "*" || v == "/" || v == "^")
        {
            double op2 = p.depiler();
            double op1 = p.depiler();

            if (v == "+") {p.empiler(op1 + op2);}
            
            else if (v == "-") {p.empiler(op1 - op2);}

            else if (v == "*") {p.empiler(op1 * op2);}
            
            else if (v == "/") {p.empiler(op1 / op2);}

            else if (v == "^") {p.empiler(p.puissance(op1,op2));}
        }
        
        //Lorsqu'une opérande est rencontrée on la place au dessus de la pile
        else
        {   
            //Convertir le chiffre de string en double
            double nb = stod(v);

            p.empiler(nb);
        }
    }
    
    double resultat = p.depiler();
    
    return resultat;
}

//Question 2 : Transformer une expression infixée en suffixée
string infix_to_suffix(string infix)
{
    string infixe2;

    for (int i = 0; i< infix.size(); i++)
    {
        if (infix[i] == ')' || infix[i] == '(' || infix[i] == '*' || infix[i] == '+' || infix[i] == '-' || infix[i] == '/' || infix[i] == '^')
        {
            infixe2 += ' ';
            infixe2 += infix[i];
            infixe2 += ' ';
        }

        else {infixe2 += infix[i];}
    }
    
    istringstream s(infixe2);
    string h,suffix;

    pile ope;

    while (s >> h)
    {
        //Lorsqu'un opérateur est rencontré
        if (h == "+" || h == "-" || h == "*" || h == "/" || h == "^")
        {
            //Définir sa priorité
            int prio_ope;

            if (h == "+" || h == "-") {prio_ope = 1;}
            else {prio_ope = 2;}

            //Vider la pile vers l'expression tant que la priorité de l'opérateur est inférieure ou égale à celle de l'élément du haut de la pile
            while (!ope.vide() && ope.tete->priorite_operateur() >= prio_ope && ope.tete->priorite_operateur() != 0)
            {
                string ajout_ope = ope.depiler_string();
                suffix += ajout_ope;
                suffix += " ";
            }
            
            ope.empiler(h);
        }
        //Traiter les parenthèses
        else if (h == "(" || h == ")")
        {
            if (h == "(") {ope.empiler(h);}

            else
            {
                while (!ope.vide() && ope.tete->operateur != "(")
                {
                    string ajout_ope = ope.depiler_string();
                    suffix += ajout_ope;
                    suffix += " ";
                }
                ope.depiler_string();
            }
        }

        //Lorsqu'une opérande est recontrée l'ajouter à l'expression 
        else {suffix += h; suffix += " ";}
    }

    //Lorsque la pile est vide, ajouter le reste de la pile à l'expression
    while (!ope.vide())
    {
        string ajout_ope = ope.depiler_string();
        suffix += ajout_ope;
        suffix += " ";
    }
    
    suffix += '#';

    return (suffix);    
}

int main()
{
    //Question 2 : Transformer une expression infixée en suffixée
    string suffix = infix_to_suffix("(10-6)^5");
    cout<<suffix<<" = ";

    //Question 1 : Évaluer une expression suffixée
    double a = calcul_suffixe(suffix);
    cout << a << endl << endl;

    //Question 3: Constructeur d'arbre + évaluation de l'arbre + afficher expression contenue dans l'arbre
    arbre arbre1("(10+1)*5");
    
    arbre1.arbre_to_infixe();

    cout<<" = "<<arbre1.evaluation()<<endl;
    cout<<endl;

    //Question 4 : Fonction qui dérive la fonction contenue dans l'arbre
    arbre arbre2("X^6");
    cout<<"La dérivée de "; arbre2.arbre_to_infixe(); cout<<" est :"<<endl;
    arbre arbre2_der(arbre2.derivee("X"));
    arbre2_der.arbre_to_infixe();
    cout<<endl<<endl;

    return 0;
}