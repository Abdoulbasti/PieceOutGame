#ifndef PIECEOPERATEUR_
#define PIECEOPERATEUR_

#include "Piece.hpp"

class PieceConcrete;
class OperateurDeplacement;
class OperateurSymetrie;
class OperateurRotation;

class PieceOperateur : public Piece {
	public:
	Piece & source; // La pièce source sur laquelle l'opérateur agit.
	
	/*La position relative pour déclencher l'action : La position surlequel l'operateur agit par rapport à la piece
	Le point d'entrée sur la pièce*/
	pair<int, int> position;
	PieceOperateur(Piece & source, const pair<int,int> & position);
	const vector<pair<int, int>>& getCoordinates() const;
	void trigger(const pair<int,int> & relativePos, Piece &origin);
	
	virtual void mapPosition(pair<int, int> &) const =0; 
	virtual void visit(PieceConcrete &p) const ;
	virtual void visit(OperateurDeplacement &) const =0;
	virtual void visit(OperateurRotation &) const =0;
	virtual void visit(OperateurSymetrie &) const =0;
	
	virtual void accept(const PieceOperateur &v)=0;
	
};
#endif