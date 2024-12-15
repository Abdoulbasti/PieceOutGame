#ifndef ENTREESORTIE_
#define ENTREESORTIE_

#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;
#include <vector>
#include"Grille.hpp"

class EntreeSortie{
    public:
    static void gererSouris(RenderWindow& window, Grille& G, Texture& texture, vector<Drawable*>& objets);
};
#endif