#ifndef PIECE_
#define PIECE_
#include "PieceOperateur.hpp"
#include <utility> // pour pair
#include <vector>
#include <iostream> 
using namespace std;

class Piece{
    public :
	virtual void trigger(const pair<int,int> & coord , Piece &origin)=0;
	void trigger(const pair<int,int> & coord );
	virtual const vector<pair<int, int>>& getCoordinates() const =0  ;
	virtual void accept(const PieceOperateur &v)=0;
};
#endif