#include "Modele/OperateurRotation.hpp"


/*##############################"Classe DECORATEUR CONCRETE qui effectue les décorations suivantes : HORAIRE, ANTIHORAIRE###########################*/

OperateurRotation::OperateurRotation(Piece & source, const pair<int,int> & position, OrientationRotation sens) : PieceOperateur(source,position) , sens{sens} {};


//Declancheur décoration : HORAIRE, ANTIHORAIRE
void OperateurRotation::trigger(const pair<int,int> & coord , Piece &origin){
    source.trigger(coord, origin);
    cout << "Piece décoré avec : HORAIRE, ANTIHORAIRE" << endl;
}

void OperateurRotation::accept(const PieceOperateur &v) { v.visit(*this); }

void OperateurRotation::visit(OperateurRotation &x) const {}

void OperateurRotation::visit(OperateurSymetrie &x) const{}

void OperateurRotation::visit(OperateurDeplacement &x) const{}

void OperateurRotation::mapPosition( pair<int, int> & pos) const {}