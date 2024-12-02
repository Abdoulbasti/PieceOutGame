#include "Modele/OperateurSymetrie.hpp"

/*#########################Classe DECORATEUR CONCRETE qui effectue les décorations suivantes : HORIZONTALE, VERTICALE##################*/

OperateurSymetrie::OperateurSymetrie(Piece & source, const pair<int,int> & position, OrientationSymetrie sens) : PieceOperateur(source,position) , sens{sens} {};


//Declancheur décoration : HORIZONTALE, VERTICALE
void OperateurSymetrie::trigger(const pair<int,int> & coord , Piece &origin){
    source.trigger(coord, origin);
    cout << "Piece décoré avec : HORIZONTALE, VERTICALE" << endl;
    cout << "FIN DE DECORATION" << endl;
}


void OperateurSymetrie::accept(const PieceOperateur &v) { v.visit(*this); }

void OperateurSymetrie::visit(OperateurSymetrie &x) const {}

void OperateurSymetrie::visit(OperateurRotation &x) const{}

void OperateurSymetrie::visit(OperateurDeplacement &x) const{}

void OperateurSymetrie::mapPosition( pair<int, int> & pos) const {}