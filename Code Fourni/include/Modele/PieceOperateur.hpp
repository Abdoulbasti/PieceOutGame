#ifndef PIECEOPERATEUR_
#define PIECEOPERATEUR_

#include "Piece.hpp"

class PieceConcrete;
class OperateurDeplacement;

class PieceOperateur : public Piece {
	public:
	Piece & source;
	pair<int, int> position;
	PieceOperateur(Piece & source, const pair<int,int> & position);
	const vector<pair<int, int>>& getCoordinates() const;
	void trigger(const pair<int,int> & relativePos, Piece &origin);
	
	virtual void mapPosition(pair<int, int> &) const =0; 
	virtual void visit(PieceConcrete &p) const ;
	virtual void visit(OperateurDeplacement &) const =0;
	//virtual void visit(OperateurRotation &) const =0;
	//virtual void visit(OperateurSymetrie &) const =0;
	
	virtual void accept(const PieceOperateur &v)=0;
	
};
#endif