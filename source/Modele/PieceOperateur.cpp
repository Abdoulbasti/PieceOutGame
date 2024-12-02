#include "Modele/PieceOperateur.hpp"
#include "Modele/PieceConcrete.hpp"

PieceOperateur::PieceOperateur(Piece & source, const pair<int,int> & position) 
    : source{source},position{position} {}

vector<pair<int, int>>& PieceOperateur::getCoordinates() {return source.getCoordinates();}

pair<int, int> PieceOperateur::getPosition() const { return position;}

void PieceOperateur::trigger(const pair<int,int> & relativePos, Piece &origin) {
    if (relativePos==position) origin.accept(*this);
    else source.trigger(relativePos, origin);
}

//virtual void PieceOperateur::mapPosition(pair<int, int> &) const =0; 

void PieceOperateur::visit(PieceConcrete &p) const { 
    for (pair<int,int> &x : p.getCoordinates())  mapPosition(x);
}

//virtual void PieceOperateur::visit(OperateurDeplacement &) const =0;
//virtual void PieceOperateur::visit(OperateurRotation &) const =0;
//virtual void PieceOperateur::visit(OperateurSymetrie &) const =0;

//virtual void PieceOperateur::accept(const PieceOperateur &v)=0;