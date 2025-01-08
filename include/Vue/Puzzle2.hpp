#ifndef PUZZLE2_
#define PUZZLE2_

#include "Vue/VuePlateau.hpp"
#include "Vue/Decorer.hpp"
#include <SFML/Audio.hpp>


class Puzzle2{
    private:
        int TILE_SIZE;
        int NB_COL;
        int NB_LIGNE;
        int MARGIN_LEFT; 
        int MARGIN_RIGHT; 
        int MARGIN_TOP; 
        int MARGIN_BOTTOM;
    public:
        Puzzle2(int T ,int C, int L, int ML, int MR, int MT, int MB);
        int jouerPuzzle2();
};
#endif