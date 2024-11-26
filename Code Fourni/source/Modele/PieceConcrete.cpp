#include "include/Modele/PieceConcrete.hpp"


PieceConcrete::PieceConcrete(const vector<pair<int, int>>& coords): coordinates(coords) {}

const PieceConcrete::vector<pair<int, int>>& getCoordinates() const { return coordinates; }

void PieceConcrete::trigger(const pair<int,int> & coord, Piece &origin) {}

void PieceConcrete::accept(const PieceOperateur &v) {v.visit(*this);}