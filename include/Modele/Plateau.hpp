#ifndef GRILLE_
#define GRILLE_

#include "PieceConcrete.hpp"
#include "OperateurDeplacement.hpp"
#include "OperateurRotation.hpp"
#include "OperateurSymetrie.hpp"
#include "EtatCase.hpp"
#include <algorithm> // pour find



class Plateau
{
    private:
        int NB_COL;
        int NB_LIGNE;
        vector<vector<EtatCase>> cases; //enumération sur l'état de chaque case
        vector<pair<Piece&, char>> piecesEtCouleurs; // ce Vecteur contient les pieces qui sont sur le plateau de jeu et leurs couleurs
    public:
        Plateau(int colonnes, int lignes);
        ~Plateau(); //détruire le plateau
        int getNB_COL()const;
        int getNB_LIGNE()const;
        vector<vector<EtatCase>> getCases() const;
        vector<pair<Piece&, char>> getPiecesEtCouleurs()const;
        void occuperCase(int x, int y); // Marque une case comme occupée
        bool estOccupee(int x, int y) const; // Vérifie si une case est occupée
        bool estDansLimites(Piece& piece) const;   // Vérifie que la pièce reste dans les limites
        bool peutPlacer( Piece& piece) const;      // Vérifie qu'une pièce peut être placée (pas de collision)
        bool placerPiece( Piece& piece , char c);           // Place une pièce sur le Plateau
        bool estOperationValide(Piece &p,int x,int y); // verifie si une operation peut etre effectuée dans sur une piéce donnée
        void initialiserNonJouable(vector<pair<int,int>> vecteur); // Définit une case comme non jouable
        void afficher() const; // Affiche la grille (pour débogage)
        void initialiserJouableGain(vector<pair<int,int>> vecteur);
        void detectionGain(vector<pair<int,int>>& coordsGain, Piece* pieceAPlacer, int &exit);
        bool estUnGain(int x, int y) const;
};
#endif
