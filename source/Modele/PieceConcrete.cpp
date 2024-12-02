#include "Modele/PieceConcrete.hpp"
#include "Modele/PieceOperateur.hpp"


PieceConcrete::PieceConcrete(const vector<pair<int, int>>& coords): coordinates(coords) {}


//Declanchement des operation à effectuer sur une PieceConcrete
void PieceConcrete::trigger(const pair<int,int> & coord, Piece &origin) {
    cout << "Etat de la piece avant les décorations : " << endl;
}

const vector<pair<int, int>>& PieceConcrete::getCoordinates() const { return coordinates; }

void PieceConcrete::accept(const PieceOperateur &v) {v.visit(*this);}