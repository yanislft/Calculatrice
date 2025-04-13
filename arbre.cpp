#include "arbre.h"

arbre::arbre()
{
    racine = nullptr;
}

arbre::arbre(noeud *r)
{
    racine = r;
}

arbre::arbre(string infix)
{
    // Transformer l'expression infix en suffix comme pour la question 1
    string infixe2;

    for (int i = 0; i< infix.size(); i++)
    {
        if (infix[i] == ')' or infix[i] == '(' or infix[i] == '*' or infix[i] == '+' or infix[i] == '-' or infix[i] == '/' or infix[i] == '^')
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

    //Fabrication de l'arbre
    istringstream s2(suffix); 
    string v;
    pile p;

    while (s2 >> v) 
    {
        if (v == " " || v == "#") {continue;}

        //Lorsqu'un opérateur est rencontré
        if (v == "+" || v == "-" || v == "*" || v == "/" || v == "^")
        {
            //On crée un noeud contenant l'opérateur 
            noeud *operateur = new noeud(v);

            //Puis on dépile les deux derniers éléments empiler qui constituront les opérandes de cet opérateur
            operateur->fils_droite = p.depiler_noeud();
            operateur->fils_gauche = p.depiler_noeud();

            //Puis on empile le noeud contenant l'opération
            p.empiler(operateur);
        }

        else if (v == "X" || v == "Y" || v == "Z")
        {
            noeud *variable = new noeud(v);

            p.empiler(variable);
        }

        //Lorsqu'une opérande est recontrée on la met dans un noeud et on l'empile
        else
        {
            double nb = stod(v);    
            noeud *operande = new noeud(nb);

            p.empiler(operande);
        }
    }
    racine = p.depiler_noeud();
}


arbre::~arbre()
{
    if (racine != nullptr) {delete racine;}
}

//Évaluation d'un arbre 
double arbre::evaluation(noeud *r)
{
    if (r == nullptr) {return -1;}

    if (r->fils_gauche->type == "o" && r->fils_droite->type == "o")
    {
        if (r->operateur == "+") {return (evaluation(r->fils_gauche) + evaluation(r->fils_droite));}
        if (r->operateur == "-") {return (evaluation(r->fils_gauche) - evaluation(r->fils_droite));}
        if (r->operateur == "*") {return (evaluation(r->fils_gauche) * evaluation(r->fils_droite));}
        if (r->operateur == "/") {return (evaluation(r->fils_gauche) / evaluation(r->fils_droite));}
        if (r->operateur == "^") {return (r->puissance(evaluation(r->fils_gauche), evaluation(r->fils_droite)));}
    }

    else if (r->fils_gauche->type == "o" && r->fils_droite->type == "f")
    {
        if (r->operateur == "+") {return (evaluation(r->fils_gauche) + r->fils_droite->valeur);}
        if (r->operateur == "-") {return (evaluation(r->fils_gauche) - r->fils_droite->valeur);}
        if (r->operateur == "*") {return (evaluation(r->fils_gauche) * r->fils_droite->valeur);}
        if (r->operateur == "/") {return (evaluation(r->fils_gauche) / r->fils_droite->valeur);}
        if (r->operateur == "^") {return (r->puissance(evaluation(r->fils_gauche), r->fils_droite->valeur));}
    }

    else if (r->fils_gauche->type == "f" && r->fils_droite->type == "o")
    {
        if (r->operateur == "+") {return (r->fils_gauche->valeur + evaluation(r->fils_droite));}
        if (r->operateur == "-") {return (r->fils_gauche->valeur - evaluation(r->fils_droite));}
        if (r->operateur == "*") {return (r->fils_gauche->valeur * evaluation(r->fils_droite));}
        if (r->operateur == "/") {return (r->fils_gauche->valeur / evaluation(r->fils_droite));}
        if (r->operateur == "^") {return (r->puissance(r->fils_gauche->valeur, evaluation(r->fils_droite)));}
    }

    else if (r->fils_gauche->type == "f" && r->fils_droite->type == "f")
    {
        if (r->operateur == "+") {return (r->fils_gauche->valeur + r->fils_droite->valeur);}
        if (r->operateur == "-") {return (r->fils_gauche->valeur - r->fils_droite->valeur);}
        if (r->operateur == "*") {return (r->fils_gauche->valeur * r->fils_droite->valeur);}
        if (r->operateur == "/") {return (r->fils_gauche->valeur / r->fils_droite->valeur);}
        if (r->operateur == "^") {return (r->puissance(r->fils_gauche->valeur, r->fils_droite->valeur));}

    }
    return -1;
}

double arbre::evaluation()
{
    return evaluation(racine);
}

//Afficher le contenu d'un arbre de manière infixe
void arbre::arbre_to_infixe(noeud *r)
{
    if (r == nullptr) {return;}

    if (r->type == "o")
    {
        if (r->operateur == "*" || r->operateur == "/" || r->operateur == "^")
        {
            arbre_to_infixe(r->fils_gauche);
            cout<<" "<<r->operateur<<" ";
            arbre_to_infixe(r->fils_droite);
        }

        else
        {
            cout<<"(";
            arbre_to_infixe(r->fils_gauche);
            cout<<" "<<r->operateur<<" ";
            arbre_to_infixe(r->fils_droite);
            cout<<")";
        }
    }

    else if (r->type == "f") {cout << r->valeur;}
    else if (r->type == "v") {cout << r->variable;}
}

void arbre::arbre_to_infixe()
{
    arbre_to_infixe(racine);
}

noeud* arbre::derivee(noeud *r, string var)
{
    if (r->type == "f")
    {
        noeud *v = new noeud();
        return (v);
    }

    else if (r->type == "v")
    {
        if (r->variable == var)
        {
            noeud *v = new noeud(1);
            return (v);
        }
        
        else
        {
            noeud *v = new noeud(0.0);
            return (v);
        }
    }

    else if (r->type == "o")
    {
        noeud *u_derivee = derivee(r->fils_gauche, var);
        noeud *v_derivee = derivee(r->fils_droite, var);

        if (r->operateur == "+")
        {
            noeud *v = new noeud("+", u_derivee, v_derivee);
            return (v);
        }

        else if (r->operateur == "-")
        {
            noeud *v = new noeud("-", u_derivee, v_derivee);
            return (v);
        }

        else if (r->operateur == "*")
        {
            noeud *v = new noeud("+", new noeud("*", u_derivee, r->fils_droite), new noeud("*", r->fils_gauche, v_derivee));
            return (v);
        }

        else if (r->operateur == "/")
        {
            noeud *v = new noeud("/", new noeud("-", new noeud("*", u_derivee, r->fils_droite), new noeud("*", r->fils_gauche, v_derivee)), new noeud("*", r->fils_droite, r->fils_droite));
            return (v);
        }

        else if (r->operateur == "^")
        {
            noeud *v = new noeud("*", new noeud("*", r->fils_droite, u_derivee), new noeud("^", r->fils_gauche, new noeud(r->fils_droite->valeur-1)));
            return (v);
        }
    }
    return(0);
}

noeud* arbre::derivee(string var)
{
    return (derivee(racine, var));
}