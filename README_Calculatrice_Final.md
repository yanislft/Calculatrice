# Projet : Calculatrice Symbolique en C++

## Présentation

Ce projet est une calculatrice symbolique développée en C++ dans le cadre du module de Programmation Orientée Objet (L1 Informatique).  
Elle permet de manipuler des expressions mathématiques sous forme infixée, de les convertir en suffixée (notation post-fixée), de construire un arbre syntaxique, de l’évaluer, et d’en calculer la dérivée symbolique.

## Fonctionnalités

- **Évaluation d'expressions en notation suffixée** (postfixée)
- **Conversion infixée → suffixée** (shunting-yard algorithm)
- **Construction d’un arbre syntaxique** à partir d’une expression
- **Affichage infixé** d’une expression à partir de l’arbre
- **Évaluation d’un arbre syntaxique**
- **Calcul de dérivées symboliques** par rapport à une variable (`X`, `Y`, `Z`)
- **Gestion dynamique avec piles, maillons et arbres**

## Fichiers du projet

- `main.cpp` : Point d’entrée du programme, avec des tests d’évaluation, de transformation et de dérivation.
- `pile.h / pile.cpp` : Implémentation d’une pile avec une liste chaînée.
- `maillon.h / maillon.cpp` : Définition des maillons utilisés dans la pile.
- `noeud.h / noeud.cpp` : Définition des nœuds de l’arbre (valeurs, opérateurs, variables).
- `arbre.h / arbre.cpp` : Construction et manipulation des arbres (évaluation, dérivée, affichage).

## Compilation

Utilisez la commande suivante dans un terminal pour compiler l’ensemble des fichiers :

```bash
g++ main.cpp pile.cpp maillon.cpp noeud.cpp arbre.cpp -o calculatrice
```

Assurez-vous que tous les fichiers `.cpp` et `.h` se trouvent dans le même répertoire.

## Exemple d'utilisation

```cpp
arbre arbre1("(10+1)*5");
arbre1.arbre_to_infixe();           // Affiche l’expression formatée
cout << arbre1.evaluation();        // Évalue l’expression

arbre arbre2("X^6");
arbre arbre2_der(arbre2.derivee("X"));
arbre2_der.arbre_to_infixe();       // Affiche la dérivée de l'expression
```

## Auteur

Réalisé par **Yanis Laftimi**  
Licence 1 Informatique – Projet de Programmation Orientée Objet
