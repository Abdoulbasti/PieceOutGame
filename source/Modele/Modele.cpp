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
    coords = {{0,0},{1,0},{2,0},{3,0},{5,0},{0,1},{1,1},{2,1},{3,1},{5,1},{0,2},{5,2},{0,3},{5,3},{0,6},{1,6},{2,6},{3,6},{5,6},{0,7},{1,7},{2,7},{3,7},{5,7}};
    P->initialiserNonJouable(coords);
    //plaçage des pieces
    P->placerPiece(tetris_L,'B');
    P->placerPiece(tetris_T,'V');
    P->placerPiece(tetris_J,'M');
    P->placerPiece(tetris_I,'R');
    
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
                l->trigger(make_pair(x,y));
                t->trigger(make_pair(x,y));
                i->trigger(make_pair(x,y));
                j->trigger(make_pair(x,y));
            }
			P->afficher();
		}
	}
	
}
