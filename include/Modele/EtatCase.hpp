#ifndef ETATCASE_H
#define ETATCASE_H

#include <iostream>
using namespace std;

enum class EtatCase {
    NON_JOUABLE,   // La case ne peut pas être utilisée
    JOUABLE_LIBRE, // La case est jouable et vide
    JOUABLE_OCCUPEE, // La case est jouable mais occupée par une pièce
    JOUABLE_GAIN
};

#endif 
