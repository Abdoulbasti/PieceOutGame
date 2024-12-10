#include "Modele/OperateurSymetrie.hpp"

OperateurSymetrie::OperateurSymetrie(Piece & source, const pair<int,int> & position, OrientationSymetrie sens) : PieceOperateur(source,position) , sens{sens} {};

OrientationSymetrie& OperateurSymetrie::getSens() { return sens;}

void OperateurSymetrie::accept(const PieceOperateur &v) { v.visit(*this); }

void OperateurSymetrie::visit(OperateurSymetrie &x) const 
{
    mapPosition(x.position);
    x.source.accept(*this); 
}

void OperateurSymetrie::visit(OperateurRotation &x) const {}
void OperateurSymetrie::visit(OperateurDeplacement &x) const {}

void OperateurSymetrie::mapPosition( pair<int, int> & pos) const
{
     if(position.first != pos.first|| position.second != pos.second )
    {
        switch (sens) {
            case OrientationSymetrie::VERTICALE : 
                if (position.first == pos.first and position.second < pos.second ) {pos.second-=2;}
                else if (position.first == pos.first and position.second > pos.second ) {pos.second+=2;}
                else if (position.first > pos.first and position.second == pos.second ) {/*on ne fait rien*/}
                else if (position.first < pos.first and position.second == pos.second ) {/*on ne fait rien*/}
                else if (position.first < pos.first and position.second < pos.second ) {pos.second-=2;}
                else if (position.first > pos.first and position.second < pos.second ) {pos.second-=2;}
                else if (position.first < pos.first and position.second > pos.second ) {pos.second+=2;}   
                else if (position.first > pos.first and position.second > pos.second ) {pos.second+=2;}                
                break;
            case OrientationSymetrie::HORIZONTALE :
                if (position.first == pos.first and position.second < pos.second ) {/*rien*/}
                else if (position.first == pos.first and position.second > pos.second ) {/*rien*/}
                else if (position.first > pos.first and position.second == pos.second ) {pos.first+=2;}
                else if (position.first < pos.first and position.second == pos.second ) {pos.first-=2;}
                else if (position.first < pos.first and position.second < pos.second ) {pos.first-=2;}
                else if (position.first > pos.first and position.second < pos.second ) {pos.first+=2;}
                else if (position.first < pos.first and position.second > pos.second ) {pos.first-=2;}   
                else if (position.first > pos.first and position.second > pos.second ) {pos.second+=2;}                
                break;
        }
    }
}