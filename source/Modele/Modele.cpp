#include "Modele/PieceConcrete.hpp"
#include "Modele/OperateurDeplacement.hpp"

void afficher(Piece& p)
{
	vector<pair<int, int>> coords = p.getCoordinates();
    // Définir la taille de la matrice
    int rows = 10;  // L'axe des ordonnées va de 0 à 1
    int cols = 10;  // L'axe des abscisses va de 0 à 2
    
    // Créer une matrice vide avec des espaces
    vector<vector<char>> matrix(rows, vector<char>(cols, ' '));
    
    // Marquer les positions avec des '#'
    for (const auto& coord : coords) {
        int x = coord.first;
        int y = coord.second;
        matrix[y][x] = '#';
    }
    
    // Affichage de la matrice
    cout << "  0 1 2 3 4 5 6 7 8 9" << endl; // Afficher l'axe des abscisses
    for (int i = 0; i < rows; ++i) {
        if (i == 0) {
            cout << i << " ";
        } else {
            cout << i << " "; // Afficher l'axe des ordonnées
        }
        
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << " "; // Afficher les valeurs de la matrice
        }
        cout << endl;
    }

}

int main() {
	vector<pair<int, int>> coords { {0, 0}, {0, 1}, {0, 2}, {1, 2}};     
	PieceConcrete tetris_L(coords);
	//afficher(tetris_L);
	Piece *p = new OperateurDeplacement {tetris_L,{0,0},OrientationDeplacement::EST};
	/*p->trigger(make_pair(0,0));
	afficher(tetris_L);
	p->trigger(make_pair(1,0));
	afficher(tetris_L);*/

	int exit = 1;
	int x, y;
	while (exit)
	{
		afficher(tetris_L);
		cout << "Entrez trois entiers" << endl;
		cin >> x >> y >> exit;
		p->trigger(make_pair(x,y));
		afficher(tetris_L);
	}
	
}
