#include "include/Modele/PieceOperateur.hpp"

PieceOperateur::PieceOperateur(Piece & source, const pair<int,int> & position) 
    : source{source},position{position} {}

const PieceOperateur::vector<pair<int, int>>& getCoordinates() const {return source.getCoordinates();}

void PieceOperateur::trigger(const pair<int,int> & relativePos, Piece &origin) {
    if (relativePos==position) origin.accept(*this);
    else source.trigger(relativePos, origin);
}

//virtual void PieceOperateur::mapPosition(pair<int, int> &) const =0; 

virtual void PieceOperateur::visit(PieceConcrete &p) const { 
    for (pair<int,int> &x : p.coordinates)  mapPosition(x);
}

//virtual void PieceOperateur::visit(OperateurDeplacement &) const =0;
//virtual void PieceOperateur::visit(OperateurRotation &) const =0;
//virtual void PieceOperateur::visit(OperateurSymetrie &) const =0;

//virtual void PieceOperateur::accept(const PieceOperateur &v)=0;