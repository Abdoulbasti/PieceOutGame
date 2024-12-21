#ifndef DECORER_
#define DECORER_

#include "VuePlateau.hpp"
#include <cmath>
#include <memory>



class Decorer {
public:
    Decorer();

    // Décorations principales
    void ajouterSymboleRotation(vector<Drawable*>& objets, VuePlateau& G, pair<int, int>& position, bool horaire );
    void ajouterSymboleSymetrie(vector<Drawable*>& objets, VuePlateau& G, pair<int, int>& position,  bool horizontale);
    void ajouterSymboleDeplacement(vector<Drawable*>& objets,VuePlateau& G, pair<int, int>& position, OrientationDeplacement& sens);
    void decoration(vector<Drawable*>& objets,Piece& p, VuePlateau& G);
};

#endif
