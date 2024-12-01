#ifndef PIECECONCRETE_
#define PIECECONCRETE_

#include "Piece.hpp"


class PieceConcrete : public Piece {
	private:
	vector<pair<int, int>> coordinates;
	public :
	PieceConcrete(const vector<pair<int, int>>& coords);
	const vector<pair<int, int>>& getCoordinates() const;
	void trigger(const pair<int,int> & coord, Piece &origin);
	void accept(const PieceOperateur & v);
};
#endif