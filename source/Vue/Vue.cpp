#include "Vue/Grille.hpp"
#include "Vue/Decorer.hpp"
#include "Vue/EntreeSortie.hpp"
#include <cstdlib>
#include <ctime>
#include "Modele/PieceConcrete.hpp"
#include "Modele/OperateurDeplacement.hpp"
#include "Modele/OperateurRotation.hpp"
#include "Modele/OperateurSymetrie.hpp"

//Déclaration des variables globales
int MARGIN_LEFT=100, MARGIN_RIGHT=100, MARGIN_TOP=100, MARGIN_BOTTOM=100,TILE_SIZE=34,NB_COL=8, NB_LIGNE=10;

int main() {
    
    //déclration des variables locales
    unsigned int nbPix_x=MARGIN_LEFT+MARGIN_RIGHT+NB_COL*TILE_SIZE;
	unsigned int nbPix_y=MARGIN_TOP+MARGIN_BOTTOM+NB_LIGNE*TILE_SIZE;
    vector<Drawable*> scene_generale;
    vector<Drawable*> scene_particuliere;
    Texture texture_rouge;
    //Déclaration et initialisation de la grille
    Grille * G = new Grille(TILE_SIZE,NB_COL,NB_LIGNE,MARGIN_LEFT,MARGIN_RIGHT,MARGIN_TOP,MARGIN_BOTTOM);
	//Créatiion des pieces
	Vector2i premier_coord = G->genererPointAleatoire();
	vector<pair<int, int>> coords {{premier_coord.x, premier_coord.y}, {premier_coord.x, premier_coord.y+1}, {premier_coord.x, premier_coord.y+2}, {premier_coord.x+1, premier_coord.y+2}};
	PieceConcrete Tetris_L(coords);
	premier_coord = G->genererPointAleatoire();
	coords = { {premier_coord.x, premier_coord.y}, {premier_coord.x, premier_coord.y+1}, {premier_coord.x, premier_coord.y+2}, {premier_coord.x-1, premier_coord.y+2}};
	PieceConcrete Tetris_J(coords);
	//dessiner les pieces
	G->placerPiece(Tetris_L,Color::Blue,scene_particuliere);
	G->placerPiece(Tetris_J,Color::Red,scene_particuliere);
	Decorer::ajouterSymboleDeplacement(scene_particuliere,*G,Vector2f{1,5},Color::White,OrientationDeplacement::NORD);
	Decorer::ajouterSymboleDeplacement(scene_particuliere,*G,Vector2f{1,7},Color::White,OrientationDeplacement::SUD);
	Decorer::ajouterSymboleDeplacement(scene_particuliere,*G,Vector2f{0,7},Color::White,OrientationDeplacement::OUEST);
	Decorer::ajouterSymboleRotation(scene_particuliere,*G,Vector2f{1,6},Color::White,true);

    // on peut (ou pas) distinguer la scène générale cadre+frame et la scène particulière (les cases actuelles)
    scene_generale.push_back(&G->getCentralPane());
    scene_generale.push_back(&G->getTrame());
    // on place ici la définition d'une texture rouge, probablement qu'il y a mieux à faire (flightweight ? map ?)
    	if (!texture_rouge.loadFromFile("ressources/texture.jpg")) {
    		cerr << "Erreur lors du chargement de l'image" << endl;
        	return EXIT_FAILURE;
    	}
	// Opérations graphiques générales
	RenderWindow window{VideoMode{nbPix_x,nbPix_y},"Piece Out" };
	while (window.isOpen()) 
	{
		EntreeSortie::gererSouris(window,*G,texture_rouge,scene_particuliere);
		//nettoyagede la grille
		window.clear();
		window.setView(window.getDefaultView());
		// les affichages
		for (Drawable * x:scene_generale) window.draw(*x);		
		for (Drawable * x:scene_particuliere) window.draw(*x);
		window.display();
    }
	// Remarquez que la destruction des objets n'est pas faites
	// et que dans ce code il ne suffit pas de détruire scene_generale et scene_particuliere car on y a ajouté des objets créés par new et d'autre déclarés dans un bloc... ce qui n'est pas malin.
        return EXIT_SUCCESS;
}