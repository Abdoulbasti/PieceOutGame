#include "Modele/Piece.hpp"


//Interface de base decorateur
void Piece::trigger(const pair<int,int> & coord ) { trigger(coord, *this); }