#ifndef OPERATEURROTATION_
#define OPERATEURROTATION_

#include "PieceOperateur.hpp"
#include "OrientationRotation.hpp"

class OperateurRotation : public PieceOperateur
{
	private:
	OrientationRotation sens;
	public:
	OperateurRotation(Piece & source, const pair<int,int> & position, OrientationRotation sens);
	OrientationRotation& getSens();
    virtual void accept(const PieceOperateur &v);
	virtual void visit(OperateurDeplacement &x) const ;
	virtual void visit(OperateurRotation &x) const;
	virtual void visit(OperateurSymetrie &x) const;
	
	virtual void mapPosition( pair<int, int> & pos) const ;
};
#endif