#include "Modele/OperateurRotation.hpp"

OperateurRotation::OperateurRotation(Piece & source, const pair<int,int> & position, OrientationRotation sens) : PieceOperateur(source,position) , sens{sens} {};

void OperateurRotation::accept(const PieceOperateur &v) { v.visit(*this); }

void OperateurRotation::visit(OperateurRotation &x) const {}

//virtual void visit(OperateurSymetrie &x) const;
//virtual void visit(OperateurDeplacement &x) const;

void OperateurRotation::mapPosition( pair<int, int> & pos) const {}