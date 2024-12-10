#include "Modele/OperateurRotation.hpp"

OperateurRotation::OperateurRotation(Piece & source, const pair<int,int> & position, OrientationRotation sens) : PieceOperateur(source,position) , sens{sens} {};

OrientationRotation& OperateurRotation::getSens() { return sens;}

void OperateurRotation::accept(const PieceOperateur &v) { v.visit(*this); }

void OperateurRotation::visit(OperateurRotation &x) const 
{
    mapPosition(x.position);
    x.source.accept(*this); 
}

void OperateurRotation::visit(OperateurSymetrie &x) const {}

void OperateurRotation::visit(OperateurDeplacement &x) const {}

void OperateurRotation::mapPosition( pair<int, int> & pos) const
{
    if(position.first != pos.first|| position.second != pos.second )
    {
        switch (sens) {
            case OrientationRotation::HORAIRE : 
                if (position.first == pos.first and position.second < pos.second ) {pos.first--; pos.second --;}
                else if (position.first == pos.first and position.second > pos.second ) {pos.first++; pos.second ++;}
                else if (position.first > pos.first and position.second == pos.second ) {pos.first++; pos.second --;}
                else if (position.first < pos.first and position.second == pos.second ) {pos.first--; pos.second ++;}
                else if (position.first < pos.first and position.second < pos.second ) {pos.first-=2;}
                else if (position.first > pos.first and position.second < pos.second ) {pos.second-=2;}
                else if (position.first < pos.first and position.second > pos.second ) {pos.second+=2;}   
                else if (position.first > pos.first and position.second > pos.second ) {pos.first+=2;}                
                break;
            case OrientationRotation::ANTIHORAIRE :
                if (position.first == pos.first and position.second < pos.second ) {pos.first++; pos.second --;}
                else if (position.first == pos.first and position.second > pos.second ) {pos.first--; pos.second ++;}
                else if (position.first > pos.first and position.second == pos.second ) {pos.first++; pos.second ++;}
                else if (position.first < pos.first and position.second == pos.second ) {pos.first--; pos.second --;}
                else if (position.first < pos.first and position.second < pos.second ) {pos.second-=2;}
                else if (position.first > pos.first and position.second < pos.second ) {pos.first+=2;}
                else if (position.first < pos.first and position.second > pos.second ) {pos.first-=2;}   
                else if (position.first > pos.first and position.second > pos.second ) {pos.second+=2;}                
                break;
        }
    }
}