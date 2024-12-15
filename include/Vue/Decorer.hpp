#ifndef DECORER_
#define DECORER_

#include "Modele/OrientationSymetrie.hpp"
#include "Modele/OrientationRotation.hpp"
#include "Modele/OrientationDeplacement.hpp"
#include "Grille.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;
#include <vector>
#include <cmath>



class Decorer {
public:
    // Décorations principales
    static void ajouterSymboleRotation(vector<Drawable*>& objets, Grille& G, Vector2f position, Color color, bool horaire );
    static void ajouterSymboleSymetrie(vector<Drawable*>& objets, Grille& G, Vector2f position, Color color, bool horizontale);
    static void ajouterSymboleDeplacement(vector<Drawable*>& objets,Grille& G, Vector2f position, Color color, OrientationDeplacement sens);
};

#endif
