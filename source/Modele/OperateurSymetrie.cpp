#include "Modele/OperateurDeplacement.hpp"
#include "Modele/OperateurSymetrie.hpp"
#include "Modele/OperateurRotation.hpp"

OperateurSymetrie::OperateurSymetrie(Piece & source, const pair<int,int> & position, OrientationSymetrie sens) : PieceOperateur(source,position) , sens{sens} {};

OrientationSymetrie& OperateurSymetrie::getSens() { return sens;}

void OperateurSymetrie::accept(const PieceOperateur &v) { v.visit(*this); }

void OperateurSymetrie::visit(OperateurSymetrie &x) const 
{
    mapPosition(x.position);
    x.source.accept(*this); 
}

void OperateurSymetrie::visit(OperateurRotation &x) const 
{
    mapPosition(x.getPosition());
    OrientationRotation& o = x.getSens();
    switch (o)
    {
        case OrientationRotation::HORAIRE : o = OrientationRotation::ANTIHORAIRE; break;
        case OrientationRotation::ANTIHORAIRE : o = OrientationRotation::HORAIRE; break;
    }
    x.source.accept(*this);
}

void OperateurSymetrie::visit(OperateurDeplacement &x) const 
{
    mapPosition(x.getPosition());
    OrientationDeplacement& o = x.getSens();
    switch (sens)
    {
    case OrientationSymetrie::VERTICALE :
        switch (o)
        {
            case OrientationDeplacement::NORD : o = OrientationDeplacement::SUD; break;
            case OrientationDeplacement::SUD : o = OrientationDeplacement::NORD; break;
        }
        break;
    
    case OrientationSymetrie::HORIZONTALE :
        switch (o)
        {
            case OrientationDeplacement::EST : o = OrientationDeplacement::OUEST; break;
            case OrientationDeplacement::OUEST : o = OrientationDeplacement::EST; break;
        }
        break;
    }
    x.source.accept(*this);
}

void OperateurSymetrie::mapPosition(pair<int, int>& pos) const {
    if (position.first == pos.first && position.second == pos.second) {
        // Si la position de référence et celle donnée sont identiques, rien à faire
        return;
    }

    switch (sens) {
        case OrientationSymetrie::VERTICALE:
            // La symétrie verticale modifie uniquement la coordonnée `second` (colonne)
            pos.second = position.second - (pos.second - position.second);
            break;

        case OrientationSymetrie::HORIZONTALE:
            // La symétrie horizontale modifie uniquement la coordonnée `first` (ligne)
            pos.first = position.first - (pos.first - position.first);
            break;
    }
}
