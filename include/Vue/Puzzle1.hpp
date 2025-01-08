#ifndef PUZZLE1_
#define PUZZLE1_

#include "Vue/VuePlateau.hpp"
#include "Vue/Decorer.hpp"
#include <SFML/Audio.hpp>


class Puzzle1{
    private:
        int TILE_SIZE;
        int NB_COL;
        int NB_LIGNE;
        int MARGIN_LEFT; 
        int MARGIN_RIGHT; 
        int MARGIN_TOP; 
        int MARGIN_BOTTOM;
    public:
        Puzzle1(int T ,int C, int L, int ML, int MR, int MT, int MB);
        int jouerPuzzle1();
};
#endif