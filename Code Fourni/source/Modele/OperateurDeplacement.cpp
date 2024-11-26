#include "include/Modele/OperateurDeplacement.hpp"

OperateurDeplacement::OperateurDeplacement(Piece & source, const pair<int,int> & position, OrientationDeplacement sens) : PieceOperateur(source,position) , sens{sens} {};

virtual void OperateurDeplacement::accept(const PieceOperateur &v) { v.visit(*this); }

virtual void OperateurDeplacement::visit(OperateurDeplacement &x) const {
    // le deplacement ne modifie pas le sens
    mapPosition(x.position);
    x.source.accept(*this); 
}

//virtual void visit(OperateurRotation &x) const;
//virtual void visit(OperateurSymetrie &x) const;

virtual void OperateurDeplacement::mapPosition( pair<int, int> & pos) const {
    switch (sens) {
        case NORD : pos.second--; break;
        case SUD : pos.second++; break;
        case EST : pos.first++; break;
        case OUEST : pos.first--; break;
    }
}