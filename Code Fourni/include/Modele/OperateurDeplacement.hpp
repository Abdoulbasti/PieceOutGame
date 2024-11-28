#ifndef OPERATEURDEPLACEMENT_
#define OPERATEURDEPLACEMENT_

#include "PieceOperateur.hpp"
#include "OrientationDeplacement.hpp"

class OperateurDeplacement : public PieceOperateur
{
	public:
	OrientationDeplacement sens;
	OperateurDeplacement(Piece & source, const pair<int,int> & position, OrientationDeplacement sens);
	virtual void accept(const PieceOperateur &v);
	virtual void visit(OperateurDeplacement &x) const ;
	//virtual void visit(OperateurRotation &x) const;
	//virtual void visit(OperateurSymetrie &x) const;
	
	virtual void mapPosition( pair<int, int> & pos) const ;
};
#endif