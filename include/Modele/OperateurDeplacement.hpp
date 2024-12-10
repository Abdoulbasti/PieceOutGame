#ifndef OPERATEURDEPLACEMENT_
#define OPERATEURDEPLACEMENT_

#include "PieceOperateur.hpp"
#include "OrientationDeplacement.hpp"
#include "OperateurRotation.hpp"

class OperateurDeplacement : public PieceOperateur
{
	private:
	OrientationDeplacement sens;
	public:
	OperateurDeplacement(Piece & source, const pair<int,int> & position, OrientationDeplacement sens);
	OrientationDeplacement& getSens() ;
	virtual void accept(const PieceOperateur &v);
	virtual void visit(OperateurDeplacement &x) const ;
	virtual void visit(OperateurRotation &x) const;
	virtual void visit(OperateurSymetrie &x) const;
	
	virtual void mapPosition( pair<int, int> & pos) const ;
};
#endif