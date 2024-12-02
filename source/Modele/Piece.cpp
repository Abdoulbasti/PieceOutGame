#include "Modele/Piece.hpp"


//Interface de base decorateur



//le trigger : est le delancheur des operations de decoration qui sont possible sur une Piece en particulier
void Piece::trigger(const pair<int,int> & coord ) { trigger(coord, *this); }
