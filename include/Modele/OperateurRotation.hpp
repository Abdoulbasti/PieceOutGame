#ifndef OPERATEURROTATION_
#define OPERATEURROTATION_

#include "PieceOperateur.hpp"
#include "OrientationRotation.hpp"

class OperateurRotation : public PieceOperateur
{
	public:
	OrientationRotation sens;
	OperateurRotation(Piece & source, const pair<int,int> & position, OrientationRotation sens);
    virtual void accept(const PieceOperateur &v);
	virtual void visit(OperateurDeplacement &x) const ;
	virtual void visit(OperateurRotation &x) const;
	virtual void visit(OperateurSymetrie &x) const;
	
	virtual void mapPosition( pair<int, int> & pos) const ;

	void trigger(const pair<int,int> & coord , Piece &origin);
};
#endif