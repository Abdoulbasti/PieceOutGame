#include "Modele/Plateau.hpp"



int main() {
	vector<pair<int, int>> coords { {0, 4}, {1, 4}, {2, 4}, {2, 5}};     
	PieceConcrete tetris_L(coords);
    coords = {{2, 3}, {3, 3}, {4, 3}, {3, 4}};
    PieceConcrete tetris_T(coords);
    coords = {{3,5}, {4,5}, {5,5}, {5, 4}};
    PieceConcrete tetris_J(coords);
    coords = {{4, 6}, {4, 7}};
    PieceConcrete tetris_I(coords);
    //Decoration de la piece L
	Piece *l = new OperateurDeplacement {tetris_L,{0,4},OrientationDeplacement::OUEST};
	l = new OperateurDeplacement {*l,{2,4},OrientationDeplacement::EST};
	l = new OperateurRotation {*l,{1,4},OrientationRotation::ANTIHORAIRE};
    //Decoration de la piece T
    Piece *t = new OperateurRotation {tetris_T,{3, 3},OrientationRotation::ANTIHORAIRE};
    //Decoration de la piece J
    Piece *j = new OperateurDeplacement {tetris_J,{3,5},OrientationDeplacement::OUEST};
    j = new OperateurDeplacement {*j,{5,5},OrientationDeplacement::EST};
    //Decoration de la piece I
    Piece *i = new OperateurDeplacement {tetris_I,{4,6},OrientationDeplacement::NORD};
    i = new OperateurDeplacement {*i,{4,7},OrientationDeplacement::SUD};

    //création de plateau de jeu
    Plateau * P = new Plateau{6,8};
    //elimination des cases non jouables
    P->placerPiece(tetris_L,'B');
    P->placerPiece(tetris_T,'V');
    P->placerPiece(tetris_J,'M');
    P->placerPiece(tetris_I,'R');
    cout << "État initial de la grille :" << endl;
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 6; ++j) {
            cout << ( P->getCases()[i][j] == EtatCase::JOUABLE_LIBRE ? "JL " :
                      P->getCases()[i][j] == EtatCase::JOUABLE_OCCUPEE ? "JO " :
                     "NJ ");
        }
        cout << endl;
    }
	int exit = 1;
	int x, y;
	while (exit)
	{
		cout << "Voulez vous jouer? 1:oui 0:non" << endl;
		cin >> exit;
		if(exit)
		{
			P->afficher();
			cout << "Entrez deux entiers" << endl;
			cin >> x >> y;
            if(P->estOperationValide(*l,x,y) || P->estOperationValide(*t,x,y) || P->estOperationValide(*i,x,y) || P->estOperationValide(*j,x,y))
            {
                for (int i = 0; i < 8; ++i) {
                    for (int j = 0; j < 6; ++j) {
                        cout << ( P->getCases()[i][j] == EtatCase::JOUABLE_LIBRE ? "JL " :
                                P->getCases()[i][j] == EtatCase::JOUABLE_OCCUPEE ? "JO " :
                                "NJ ");
                    }
                   cout << endl;
                }
                l->trigger(make_pair(x,y));
                t->trigger(make_pair(x,y));
                i->trigger(make_pair(x,y));
                j->trigger(make_pair(x,y));
            }
			P->afficher();
		}
	}
	
}
