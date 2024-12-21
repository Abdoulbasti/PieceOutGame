#ifndef VuePlateau_
#define VuePlateau_

#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;
#include "Modele/Plateau.hpp"
#include <cstdlib> 
#include <ctime>



class VuePlateau
{
    private:
        int TILE_SIZE;
        int NB_COL;
        int NB_LIGNE;
        RectangleShape centralPane;
        VertexArray trame;
    public:
        VuePlateau(int taille ,int colonnes, int lignes, int MARGIN_LEFT, int MARGIN_RIGHT, int MARGIN_TOP, int MARGIN_BOTTOM);
        Vector2f getPosition(); // Retourne la position du panneau
        int getTILESIZE() const;  // Retourne la taille d'une case
        bool estDansVuePlateau(Vector2f position); // Vérifie si une position est dans le panneau
        Vector2i obtenirCase(Vector2f position); // Calcule les indices d'une case
        //definition des accesseur
        RectangleShape& getCentralPane() ;
        VertexArray& getTrame();
        void tracerCaseGain(vector<Drawable*>& objets,vector<pair<vector<pair<int, int>>, Piece*>> vecteurgain);
        void tracerPiece(vector<Drawable*>& objets,vector<Drawable*>& objets1,Plateau & plateau);
        Color couleurs(char c);//cette fonction fait correspondre chaque caractére à une couleur
        // Fonction pour générer une couleur aléatoire avec transparence
        Color generateRandomTransparentColor();
};
#endif
