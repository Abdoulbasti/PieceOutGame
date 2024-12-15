#include "Vue/Grille.hpp"

Grille::Grille(int taille,int colonnes, int lignes,  int MARGIN_LEFT, int MARGIN_RIGHT, int MARGIN_TOP, int MARGIN_BOTTOM)
:TILE_SIZE{taille},NB_COL{colonnes}, NB_LIGNE{lignes},centralPane(Vector2f(colonnes*taille,lignes*taille)),
trame(Lines,(colonnes+1+lignes+1)*2)
{
    unsigned int nbPix_x=MARGIN_LEFT+MARGIN_RIGHT+NB_COL*TILE_SIZE;
	unsigned int nbPix_y=MARGIN_TOP+MARGIN_BOTTOM+NB_LIGNE*TILE_SIZE;

    // définition d'un panneau "central"
	centralPane.setPosition(MARGIN_LEFT,MARGIN_TOP);
	centralPane.setFillColor(Color::White);

    // definition d'une trame (lignes horizontales+verticales).
    // pour les lignes horizontales
        int n=0;
        for (int i = 0; i <= NB_LIGNE; ++i){
            trame[n++].position = Vector2f(MARGIN_LEFT, MARGIN_TOP + i * TILE_SIZE);
            trame[n].color = Color::White;
            trame[n++].position = Vector2f(nbPix_x-MARGIN_RIGHT, MARGIN_TOP + i * TILE_SIZE);
        }
        // pour les verticales
        for (int i = 0; i <= NB_COL; ++i){
            trame[n++].position = Vector2f(MARGIN_LEFT + i * TILE_SIZE, MARGIN_TOP );
            trame[n].color = Color::White;
            trame[n++].position = Vector2f(MARGIN_LEFT + i * TILE_SIZE, nbPix_y-MARGIN_BOTTOM);
        }

    // Initialiser les cases
    cases = vector<vector<int>>(NB_LIGNE,vector<int>(NB_COL,0));
}

Grille::~Grille()
{

}

Vector2f Grille::getPosition()
{
    return centralPane.getPosition();
}

int Grille::getTILESIZE() const
{
    return TILE_SIZE;
}

bool Grille::estDansGrille(Vector2f position)
{
   return centralPane.getGlobalBounds().contains(position);
}

Vector2i Grille::obtenirCase(Vector2f position)
{
    Vector2f topLeft = centralPane.getPosition();
    int trig_x=(position.x - topLeft.x)/ TILE_SIZE;
    int trig_y=(position.y - topLeft.y)/ TILE_SIZE;
    return Vector2i(trig_x,trig_y);
}

int Grille::getNB_COL()const {return NB_COL;}

int Grille::getNB_LIGNE()const {return NB_LIGNE;}

RectangleShape& Grille::getCentralPane() { return centralPane;}

VertexArray& Grille::getTrame() {return trame;}

vector<vector<int>>& Grille::getCases() { return cases;}

void Grille::occuperCase(int x, int y)
{
    cases[x][y]=1;
}
bool Grille::estOccupee(int x, int y) const
{
    return cases[x][y]==1;
}

Vector2i Grille::genererPointAleatoire() {
        int x = rand() % NB_COL; // x entre 0 et nbColonnes - 1
        int y = rand() % NB_LIGNE;   // y entre 0 et nbLignes - 1
        return {x, y};
        }

bool Grille::estDansLimites(Piece& piece) const
{
    for (auto v : piece.getCoordinates())
    {
        if( v.first < 0 || v.first >= NB_COL || v.second < 0 || v.second >= NB_LIGNE)
        return false;
    }
    return true;
}
bool Grille::peutPlacer( Piece& piece) const
{
    if(estDansLimites(piece))
    { 
        for (auto v : piece.getCoordinates())
        {
            if( estOccupee(v.first,v.second))
            return false;
        }
        return true;
    }
} 
void Grille::placerPiece(Piece& piece,Color color,vector<Drawable*>& objets)
{
    if (peutPlacer(piece))
    {
        // Parcourir les blocs de la pièce
        for (auto& bloc : piece.getCoordinates()) 
        {
            // Créer un rectangle pour chaque bloc
            RectangleShape* rectangle = new RectangleShape(Vector2f(TILE_SIZE, TILE_SIZE)); 
            // Appliquer la position dans la grille
            rectangle->setPosition(getPosition()+Vector2f(bloc.first*TILE_SIZE,bloc.second*TILE_SIZE));
            // Appliquer la couleur et le contour
            rectangle->setFillColor(color);
            // Ajouter le rectangle au vecteur d'objets dessinables
            objets.push_back(rectangle);
        }
    }  
}