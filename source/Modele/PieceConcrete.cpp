#include "Modele/PieceConcrete.hpp"
#include "Modele/PieceOperateur.hpp"


PieceConcrete::PieceConcrete(const vector<pair<int, int>>& coords): coordinates(coords) {}

vector<pair<int, int>>& PieceConcrete::getCoordinates() { return coordinates; }

void PieceConcrete::trigger(const pair<int,int> & coord, Piece &origin) {}

void PieceConcrete::accept(const PieceOperateur &v) {v.visit(*this);}