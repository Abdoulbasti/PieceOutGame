#include "Modele/OperateurRotation.hpp"
#include "Modele/OperateurDeplacement.hpp"
#include "Modele/OperateurSymetrie.hpp"

OperateurRotation::OperateurRotation(Piece & source, const pair<int,int> & position, OrientationRotation sens) : PieceOperateur(source,position) , sens{sens} {};

OrientationRotation& OperateurRotation::getSens() { return sens; }

void OperateurRotation::accept(const PieceOperateur &v) { v.visit(*this); }

void OperateurRotation::visit(OperateurRotation &x) const 
{
    mapPosition(x.position);
    x.source.accept(*this); 
}

void OperateurRotation::visit(OperateurSymetrie &x) const 
{
    mapPosition(x.getPosition());
    OrientationSymetrie& o = x.getSens();
    switch (o)
    {
        case OrientationSymetrie::HORIZONTALE : o = OrientationSymetrie::VERTICALE; break;
        case OrientationSymetrie::VERTICALE : o = OrientationSymetrie::HORIZONTALE; break;
    }
    x.source.accept(*this);
}

void OperateurRotation::visit(OperateurDeplacement &x) const
{
    mapPosition(x.getPosition());
    OrientationDeplacement& o = x.getSens();
    switch (sens)
    {
    case OrientationRotation::HORAIRE :
        switch (o)
        {
            case OrientationDeplacement::NORD : o = OrientationDeplacement::EST; break;
            case OrientationDeplacement::SUD : o = OrientationDeplacement::OUEST; break;
            case OrientationDeplacement::EST : o = OrientationDeplacement::SUD; break;
            case OrientationDeplacement::OUEST : o = OrientationDeplacement::NORD; break;
        }
        break;
    
    case OrientationRotation::ANTIHORAIRE :
        switch (o)
        {
            case OrientationDeplacement::NORD : o = OrientationDeplacement::OUEST; break;
            case OrientationDeplacement::SUD : o = OrientationDeplacement::EST; break;
            case OrientationDeplacement::EST : o = OrientationDeplacement::NORD; break;
            case OrientationDeplacement::OUEST : o = OrientationDeplacement::SUD; break;
        }
        break;
    }
    x.source.accept(*this);
}

void OperateurRotation::mapPosition( pair<int, int> & pos) const
{
    int translatedX, translatedY, rotatedX, rotatedY;
    if(position.first != pos.first|| position.second != pos.second )
    {
        switch (sens) {
            case OrientationRotation::HORAIRE :
                translatedX = pos.first - position.first;
                translatedY = pos.second - position.second;

                rotatedX = -translatedY;
                rotatedY = translatedX;

                pos.first = rotatedX + position.first;
                pos.second = rotatedY + position.second;

                break;
            case OrientationRotation::ANTIHORAIRE :
                translatedX = pos.first - position.first;
                translatedY = pos.second - position.second;

                rotatedX = translatedY;
                rotatedY = -translatedX;

                pos.first = rotatedX + position.first;
                pos.second = rotatedY + position.second;

                break;
        }
    }
}