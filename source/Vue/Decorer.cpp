#include "Vue/Decorer.hpp"


Decorer::Decorer(){}

void Decorer::ajouterSymboleRotation(vector<Drawable*>& objets, VuePlateau& G, pair<int, int>& position, bool horaire) {
    int tileSize = G.getTILESIZE();
    Vector2f basePosition = G.getPosition() + Vector2f((position.first + 1) * tileSize, (position.second + 1) * tileSize);

    // Tracer le point
    CircleShape* point = new CircleShape(2, 10);
    point->setPosition(basePosition - Vector2f(tileSize * 0.6, tileSize * 0.55));
    point->setFillColor(Color::White);
    objets.push_back(point);

    // Dessiner l'arc
    CircleShape* arc = new CircleShape(8, 40);
    arc->setFillColor(Color::Transparent);
    arc->setOutlineThickness(2);
    arc->setOutlineColor(Color::White);
    arc->setPosition(basePosition - Vector2f(tileSize * 0.75, tileSize * 0.7));
    arc->setPointCount(30);
    objets.push_back(arc);

    // Coordonnées et tailles pour les flèches
    vector<Vector2f> positions;
    vector<Vector2f> tailles;

    if (horaire) {
        positions = {
            basePosition - Vector2f(tileSize * 0.65, tileSize * 0.75),
            basePosition - Vector2f(tileSize * 0.4, tileSize * 0.4),
            basePosition - Vector2f(tileSize * 0.8, tileSize * 0.75),
            basePosition - Vector2f(tileSize * 0.4, tileSize * 0.25)
        };
        tailles = {
            Vector2f(2, 7), Vector2f(2, 7), Vector2f(6, 2), Vector2f(7, 2)
        };
    } else {
        positions = {
            basePosition - Vector2f(tileSize * 0.8, tileSize * 0.75),
            basePosition - Vector2f(tileSize * 0.25, tileSize * 0.4),
            basePosition - Vector2f(tileSize * 0.75, tileSize * 0.6),
            basePosition - Vector2f(tileSize * 0.4, tileSize * 0.4)
        };
        tailles = {
            Vector2f(2, 8), Vector2f(2, 8), Vector2f(6, 2), Vector2f(6, 2)
        };
    }

    // Création et ajout des flèches
    for (size_t i = 0; i < positions.size(); ++i) {
        RectangleShape* ligne = new RectangleShape(tailles[i]);
        ligne->setFillColor(Color::White);
        ligne->setPosition(positions[i]);
        objets.push_back(ligne);
    }
}



// Ajouter un symbole de symétrie
void Decorer::ajouterSymboleSymetrie(vector<Drawable*>& objets, VuePlateau& G, pair<int, int>& position, bool horizontale) {
    int tileSize = G.getTILESIZE();
    Vector2f basePosition = G.getPosition() + Vector2f((position.first + 1) * tileSize, (position.second + 1) * tileSize);

    if(!horizontale)
    {
        // "L" plein
        RectangleShape* ligneH = new RectangleShape(Vector2f(18,3));
        ligneH->setFillColor(Color::White);
        ligneH->setPosition(basePosition - Vector2f(tileSize * 0.9, tileSize * 0.85));
        objets.push_back(ligneH);

        RectangleShape* ligneV = new RectangleShape(Vector2f(3,10));
        ligneV->setFillColor(Color::White);
        ligneV->setPosition(basePosition - Vector2f(tileSize * 0.9, tileSize * 0.85));
        objets.push_back(ligneV);

        //Barre Horizontale
        RectangleShape* Barre = new RectangleShape(Vector2f(28,1));
        Barre->setFillColor(Color::White);
        Barre->setPosition(basePosition - Vector2f(tileSize * 0.95, tileSize * 0.5));
        objets.push_back(Barre);

        // symetrie de L par rapport à la barre
        RectangleShape* ligneHs = new RectangleShape(Vector2f(18,3));
        ligneHs->setFillColor(Color::White);
        ligneHs->setPosition(basePosition - Vector2f(tileSize * 0.9, tileSize * 0.2));
        objets.push_back(ligneHs);

        RectangleShape* ligneVs = new RectangleShape(Vector2f(3,10));
        ligneVs->setFillColor(Color::White);
        ligneVs->setPosition(basePosition - Vector2f(tileSize * 0.9, tileSize * 0.4));
        objets.push_back(ligneVs);
    }
    else
    {
        // "L" plein
        RectangleShape* ligneH = new RectangleShape(Vector2f(10,3));
        ligneH->setFillColor(Color::White);
        ligneH->setPosition(basePosition - Vector2f(tileSize * 0.9, tileSize * 0.25));
        objets.push_back(ligneH);

        RectangleShape* ligneV = new RectangleShape(Vector2f(3,18));
        ligneV->setFillColor(Color::White);
        ligneV->setPosition(basePosition - Vector2f(tileSize * 0.9, tileSize * 0.75));
        objets.push_back(ligneV);

        //Barre verticale
        RectangleShape* Barre = new RectangleShape(Vector2f(1,30));
        Barre->setFillColor(Color::White);
        Barre->setPosition(basePosition - Vector2f(tileSize * 0.5, tileSize * 0.95));
        objets.push_back(Barre);

        // symetrie de L par rapport à la barre
        RectangleShape* ligneHs = new RectangleShape(Vector2f(10,3));
        ligneHs->setFillColor(Color::White);
        ligneHs->setPosition(basePosition - Vector2f(tileSize * 0.4, tileSize * 0.25));
        objets.push_back(ligneHs);

        RectangleShape* ligneVs = new RectangleShape(Vector2f(3,18));
        ligneVs->setFillColor(Color::White);
        ligneVs->setPosition(basePosition - Vector2f(tileSize * 0.2, tileSize * 0.75));
        objets.push_back(ligneVs);
    }
}


// Ajouter un symbole de déplacement
    void Decorer::ajouterSymboleDeplacement(vector<Drawable*>& objets, VuePlateau& G, pair<int, int>& position, OrientationDeplacement& sens) {
    int x = G.getTILESIZE();
    Vector2f basePosition = G.getPosition() + Vector2f((position.first + 1) * x, (position.second + 1) * x);
    // Coordonnées des points de la flèche en fonction de l'orientation
    std::vector<Vector2f> points;
    switch (sens) {
        case OrientationDeplacement::NORD:
            points = {
                basePosition + Vector2f(-0.5 * x, -1.0 * x),      // Pointe
                basePosition + Vector2f(-0.75 * x, -0.75 * x),   // Coin inférieur gauche
                basePosition + Vector2f(-0.25 * x, -0.75 * x)    // Coin inférieur droit
            };
            break;
        case OrientationDeplacement::SUD:
            points = {
                basePosition + Vector2f(-0.5 * x, 0.0 * x),      // Pointe
                basePosition + Vector2f(-0.75 * x, -0.25 * x),   // Coin supérieur gauche
                basePosition + Vector2f(-0.25 * x, -0.25 * x)    // Coin supérieur droit
            };
            break;
        case OrientationDeplacement::OUEST:
            points = {
                basePosition + Vector2f(-1.0 * x, -0.5 * x),     // Pointe
                basePosition + Vector2f(-0.75 * x, -0.75 * x),   // Coin supérieur droit
                basePosition + Vector2f(-0.75 * x, -0.25 * x)    // Coin inférieur droit
            };
            break;
        case OrientationDeplacement::EST:
            points = {
                basePosition + Vector2f(0.0 * x, -0.5 * x),      // Pointe
                basePosition + Vector2f(-0.25 * x, -0.75 * x),   // Coin supérieur gauche
                basePosition + Vector2f(-0.25 * x, -0.25 * x)    // Coin inférieur gauche
            };
            break;
    }
    // Créer la flèche en utilisant les points calculés
    ConvexShape* fleche = new ConvexShape(points.size());
    for (size_t i = 0; i < points.size(); ++i) {
        fleche->setPoint(i, points[i]);
    }
    // Appliquer la couleur à la flèche
    fleche->setFillColor(Color::White);
    objets.push_back(fleche);
}

void Decorer::decoration(vector<Drawable*>& objets,Piece& p, VuePlateau& G)
{
    // Détermine si p est un des trois types et récupère l'opérateur
    OperateurDeplacement* deplacement = dynamic_cast<OperateurDeplacement*>(&p);
    OperateurRotation* rotation = dynamic_cast<OperateurRotation*>(&p);
    OperateurSymetrie* symetrie = dynamic_cast<OperateurSymetrie*>(&p);
    PieceConcrete* piececoncrete = dynamic_cast<PieceConcrete*>(&p);

    if(deplacement)
    {
        pair<int, int>& v = deplacement->getPosition();
        ajouterSymboleDeplacement(objets,G,v,deplacement->getSens());
        decoration(objets,deplacement->source,G);
    }
    else if(rotation)
    {
        pair<int, int>& v = rotation->getPosition();
        ajouterSymboleRotation(objets,G,v,rotation->getSens()==OrientationRotation::HORAIRE);
        decoration(objets,rotation->source,G);
    }
    else if(symetrie)
    {
        pair<int, int>& v = symetrie->getPosition();
        ajouterSymboleSymetrie(objets,G,v,symetrie->getSens()==OrientationSymetrie::HORIZONTALE);
        decoration(objets,symetrie->source,G);
    }
    else if(piececoncrete)
    {
        return;
    }

}
