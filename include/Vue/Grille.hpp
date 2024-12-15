#ifndef GRILLE_
#define GRILLE_

#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;
#include <vector>
#include "Modele/PieceConcrete.hpp"
#include "Modele/OperateurDeplacement.hpp"
#include "Modele/OperateurRotation.hpp"
#include "Modele/OperateurSymetrie.hpp"



class Grille
{
    private:
        int TILE_SIZE;
        int NB_COL;
        int NB_LIGNE;
        RectangleShape centralPane;
        VertexArray trame;
        vector<vector<int>> cases; // 0: vide, 1: occupé
    public:
        Grille(int taille ,int colonnes, int lignes, int MARGIN_LEFT, int MARGIN_RIGHT, int MARGIN_TOP, int MARGIN_BOTTOM);
        ~Grille(); //détruire la Grille
        Vector2f getPosition(); // Retourne la position du panneau
        int getTILESIZE() const;  // Retourne la taille d'une case
        bool estDansGrille(Vector2f position); // Vérifie si une position est dans le panneau
        Vector2i obtenirCase(Vector2f position); // Calcule les indices d'une case
        int getNB_COL()const;
        int getNB_LIGNE()const;
        RectangleShape& getCentralPane() ;
        VertexArray& getTrame();
        vector<vector<int>>& getCases();
        void occuperCase(int x, int y); // Marque une case comme occupée
        bool estOccupee(int x, int y) const; // Vérifie si une case est occupée
        bool estDansLimites(Piece& piece) const;   // Vérifie que la pièce reste dans les limites
        bool peutPlacer( Piece& piece) const;      // Vérifie qu'une pièce peut être placée (pas de collision)
        void placerPiece( Piece& piece,Color color,vector<Drawable*>& objets);           // Place une pièce sur la grille
        // Génère un point de départ aléatoire pour chaque piece
        Vector2i genererPointAleatoire() ;
};
#endif
