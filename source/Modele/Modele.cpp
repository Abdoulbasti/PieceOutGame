#include "Modele/OperateurRotation.hpp"
#include "Modele/PieceConcrete.hpp"
#include "Modele/OperateurDeplacement.hpp"
#include "Modele/OperateurSymetrie.hpp"

int main() {
	vector<pair<int, int>> coords { {0, 0}, {0, 1}, {0, 2}, {1, 2}};     
	PieceConcrete tetris_L(coords);
	Piece *p = new OperateurDeplacement {tetris_L,{0,0},OrientationDeplacement::EST};
	p->trigger(make_pair(0,0));
	p->trigger(make_pair(1,0));

	/*vector<pair<int, int>> coords { {0, 0}, {0, 1}, {0, 2}, {1, 2}};     
	PieceConcrete tetris_L(coords);
	Piece *p1 = new OperateurDeplacement {tetris_L,{0,0},OrientationDeplacement::EST};
	Piece *p2 = new OperateurRotation (*p1,{0,0},OrientationRotation::ANTIHORAIRE);
	Piece *p3 = new OperateurSymetrie {*p2,{0,0},OrientationSymetrie::HORIZONTALE};
	
	p3->trigger(make_pair(0,0));*/
	//pp->trigger(make_pair(1,0)); 

	cout << "JE SUIS LE MODELE DU PROJET" <<endl;
}