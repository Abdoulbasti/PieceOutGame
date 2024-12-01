#include "Modele/OperateurSymetrie.hpp"

/*#########################Classe DECORATEUR CONCRETE qui effectue les décorations suivantes : HORIZONTALE, VERTICALE##################*/

OperateurSymetrie::OperateurSymetrie(Piece & source, const pair<int,int> & position, OrientationSymetrie sens) : PieceOperateur(source,position) , sens{sens} {};

void OperateurSymetrie::accept(const PieceOperateur &v) { v.visit(*this); }

void OperateurSymetrie::visit(OperateurSymetrie &x) const {}

//virtual void visit(OperateurRotation &x) const;
//virtual void visit(OperateurDeplacement &x) const;

void OperateurSymetrie::mapPosition( pair<int, int> & pos) const {}