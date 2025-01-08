#include "Vue/VuePlateau.hpp"

VuePlateau::VuePlateau(int taille,int colonnes, int lignes,  int MARGIN_LEFT, int MARGIN_RIGHT, int MARGIN_TOP, int MARGIN_BOTTOM)
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
        for (int i = 0; i < NB_LIGNE; ++i){
            trame[n++].position = Vector2f(MARGIN_LEFT, MARGIN_TOP + i * TILE_SIZE);
            trame[n].color = Color::White;
            trame[n++].position = Vector2f(nbPix_x-MARGIN_RIGHT, MARGIN_TOP + i * TILE_SIZE);
        }
        // pour les verticales
        for (int i = 1; i <= NB_COL; ++i){
            trame[n++].position = Vector2f(MARGIN_LEFT + i * TILE_SIZE, MARGIN_TOP );
            trame[n].color = Color::White;
            trame[n++].position = Vector2f(MARGIN_LEFT + i * TILE_SIZE, nbPix_y-MARGIN_BOTTOM);
        }
}

Vector2f VuePlateau::getPosition()
{
    return centralPane.getPosition();
}

int VuePlateau::getTILESIZE() const
{
    return TILE_SIZE;
}

bool VuePlateau::estDansVuePlateau(Vector2f position)
{
   return centralPane.getGlobalBounds().contains(position);
}

Vector2i VuePlateau::obtenirCase(Vector2f position)
{
    Vector2f topLeft = centralPane.getPosition();
    int trig_x=(position.x - topLeft.x)/ TILE_SIZE;
    int trig_y=(position.y - topLeft.y)/ TILE_SIZE;
    return Vector2i(trig_x,trig_y);
}

RectangleShape& VuePlateau::getCentralPane() { return centralPane;}

VertexArray& VuePlateau::getTrame() {return trame;}

Color VuePlateau::couleurs(char c)
{
    switch (c)
    {
        case 'R': return Color::Red; break;
        case 'G': return Color::Green; break;
        case 'B': return Color::Blue; break;
        case 'Y': return Color::Yellow; break;
        case 'M': return Color::Magenta; break;
    }
    return Color::Red;
}


Color VuePlateau::generateRandomTransparentColor() {
    // Composantes RVB aléatoires (0 à 255), mais avec un écart
    int r = rand() % 256;
    int g = (rand() + 100) % 256;  // Décale la génération pour éviter des couleurs trop proches
    int b = (rand() + 200) % 256;  // Encore un autre décalage pour garantir une distance

    // Transparence aléatoire (50 à 150 pour un effet semi-transparent)
    int alpha = 50 + rand() % 101;

    return Color(r, g, b, alpha);
}

void VuePlateau::tracerCaseGain(vector<Drawable*>& objets,vector<pair<vector<pair<int, int>>, Piece*>> vecteurgain)
{
    for (const pair<vector<pair<int, int>>, Piece*>& pairing : vecteurgain)
    {
        Color c = generateRandomTransparentColor();
        for(pair<int, int> pg : pairing.first)
        {
            // Créer un rectangle pour chaque bloc
            RectangleShape* rectangle = new RectangleShape(Vector2f(TILE_SIZE, TILE_SIZE)); 
            // Appliquer la position dans la grille
            rectangle->setPosition(getPosition()+Vector2f(pg.first*TILE_SIZE,pg.second*TILE_SIZE));
            // Appliquer la couleur et le contour
            rectangle->setFillColor(c);
            // Ajouter le rectangle au vecteur d'objets dessinables
            objets.push_back(rectangle);
        }
    }
}

void VuePlateau::tracerPiece(vector<Drawable*>& objets,vector<Drawable*>& objets1,Plateau & plateau)
{
    for (int i = 0; i < NB_LIGNE; ++i) {
        for (int j = 0; j < NB_COL; ++j){
            if(plateau.getCases()[i][j]==EtatCase::NON_JOUABLE)
            {
                // Créer un rectangle pour chaque bloc
                RectangleShape* rectangle = new RectangleShape(Vector2f(TILE_SIZE, TILE_SIZE)); 
                // Appliquer la position dans la grille
                rectangle->setPosition(getPosition()+Vector2f(j*TILE_SIZE,i*TILE_SIZE));
                // Appliquer la couleur et le contour
                rectangle->setFillColor(Color::Black);
                // Ajouter le rectangle au vecteur d'objets dessinables
                objets1.push_back(rectangle);
            }
        }
    }
    // Marquer les positions avec des couleurs correspondantes
    for (const pair<Piece&, char>& piece : plateau.getPiecesEtCouleurs()) {

        for (const pair<int, int>& coord : piece.first.getCoordinates()) {
            int x = coord.first;
            int y = coord.second;
            if (x >= 0 && x < NB_COL && y >= 0 && y < NB_LIGNE) { // Vérifie les limites
                // Créer un rectangle pour chaque bloc
                RectangleShape* rectangle = new RectangleShape(Vector2f(TILE_SIZE, TILE_SIZE)); 
                // Appliquer la position dans la grille
                rectangle->setPosition(getPosition()+Vector2f(x*TILE_SIZE,y*TILE_SIZE));
                // Appliquer la couleur et le contour
                rectangle->setFillColor(couleurs(piece.second));
                // Ajouter le rectangle au vecteur d'objets dessinables
                objets.push_back(rectangle);
            }
        }
    }
}