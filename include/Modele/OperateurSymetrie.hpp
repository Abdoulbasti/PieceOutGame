#ifndef OPERATEURSYMETRIE_
#define OPERATEURSYMETRIE_

#include "PieceOperateur.hpp"
#include "OrientationSymetrie.hpp"

class OperateurSymetrie : public PieceOperateur
{
	public:
	OrientationSymetrie sens;
	OperateurSymetrie(Piece & source, const pair<int,int> & position, OrientationSymetrie sens);
    virtual void accept(const PieceOperateur &v);
	virtual void visit(OperateurDeplacement &x) const;
	virtual void visit(OperateurRotation &x) const;
	virtual void visit(OperateurSymetrie &x) const;
	
	virtual void mapPosition( pair<int, int> & pos) const ;

	void trigger(const pair<int,int> & coord , Piece &origin);
};
#endif