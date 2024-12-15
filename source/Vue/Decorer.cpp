#include "Vue/Decorer.hpp"



// Fonction pour ajouter une petite flèche courbée
void ajouterFlecheCourbee(vector<Drawable*>& objets, Vector2f basePosition, float rayon, float angle, Color couleur) {
    ConvexShape* fleche = new ConvexShape(3); // Triangle pour la flèche
    float rad = angle * M_PI / 180.0f;

    Vector2f pointe = basePosition + Vector2f(cos(rad) * rayon, sin(rad) * rayon);
    Vector2f cote1 = basePosition + Vector2f(cos(rad - 0.2f) * (rayon - 5), sin(rad - 0.2f) * (rayon - 5));
    Vector2f cote2 = basePosition + Vector2f(cos(rad + 0.2f) * (rayon - 5), sin(rad + 0.2f) * (rayon - 5));

    fleche->setPoint(0, pointe);
    fleche->setPoint(1, cote1);
    fleche->setPoint(2, cote2);

    fleche->setFillColor(couleur);
    objets.push_back(fleche);
}

void Decorer::ajouterSymboleRotation(vector<Drawable*>& objets, Grille& G, Vector2f position, Color couleurArc, bool horaire) {
    float rayon = 6.0f;    // Rayon des arcs
    float epaisseur = 2.0f; // Épaisseur des lignes
    int pointCount = 10;    // Nombre de points pour les arcs

    Vector2f basePosition = G.getPosition() + Vector2f(position.x * G.getTILESIZE(), position.y * G.getTILESIZE());

    // --- Premier Arc ---
    ConvexShape* arc1 = new ConvexShape(pointCount);
    float angleDepart1 = horaire ? 45 : 225;
    float angleFin1 = horaire ? 180 : 360;

    for (int i = 0; i < pointCount; ++i) {
        float angle = angleDepart1 + i * (angleFin1 - angleDepart1) / (pointCount - 1);
        float rad = angle * M_PI / 180.0f;
        arc1->setPoint(i, Vector2f(cos(rad) * rayon, sin(rad) * rayon) + basePosition);
    }
    arc1->setFillColor(Color::Transparent);
    arc1->setOutlineThickness(epaisseur);
    arc1->setOutlineColor(couleurArc);
    objets.push_back(arc1);

    // --- Deuxième Arc ---
    ConvexShape* arc2 = new ConvexShape(pointCount);
    float angleDepart2 = horaire ? 225 : 45;
    float angleFin2 = horaire ? 360 : 180;

    for (int i = 0; i < pointCount; ++i) {
        float angle = angleDepart2 + i * (angleFin2 - angleDepart2) / (pointCount - 1);
        float rad = angle * M_PI / 180.0f;
        arc2->setPoint(i, Vector2f(cos(rad) * rayon, sin(rad) * rayon) + basePosition);
    }
    arc2->setFillColor(Color::Transparent);
    arc2->setOutlineThickness(epaisseur);
    arc2->setOutlineColor(couleurArc);
    objets.push_back(arc2);

    // --- Flèches Courbées (sur les extrémités des arcs) ---
    ajouterFlecheCourbee(objets, basePosition, rayon, angleFin1, couleurArc);
    ajouterFlecheCourbee(objets, basePosition, rayon, angleFin2, couleurArc);
}


// Ajouter un symbole de symétrie
void Decorer::ajouterSymboleSymetrie(std::vector<Drawable*>& objets,Grille& G, Vector2f position, Color color, bool horizontale) {
    VertexArray* doubleFleche = new VertexArray(Lines, 4);
    if (horizontale) {
        (*doubleFleche)[0].position = position - Vector2f(10, 0);
        (*doubleFleche)[1].position = position + Vector2f(10, 0);
        (*doubleFleche)[2].position = position - Vector2f(5, -5); // Flèche gauche
        (*doubleFleche)[3].position = position + Vector2f(5, 5);  // Flèche droite
    } else {
        (*doubleFleche)[0].position = position - Vector2f(0, 10);
        (*doubleFleche)[1].position = position + Vector2f(0, 10);
        (*doubleFleche)[2].position = position - Vector2f(-5, 5); // Flèche bas
        (*doubleFleche)[3].position = position + Vector2f(5, -5); // Flèche haut
    }
    for (int i = 0; i < 4; i++) (*doubleFleche)[i].color = color;
    objets.push_back(doubleFleche);
}

// Ajouter un symbole de déplacement
    void Decorer::ajouterSymboleDeplacement(std::vector<Drawable*>& objets, Grille& G,Vector2f position, Color color, OrientationDeplacement sens){
    int x = G.getTILESIZE();
     // Position de base en pixels, en tenant compte de la grille
    Vector2f basePosition =  G.getPosition()+Vector2f((position.x+1)*x,(position.y+1)*x);
    // Créer un triangle pour représenter la flèche de direction
    ConvexShape* fleche = new ConvexShape(3); // 3 points pour un triangle

    if (sens == OrientationDeplacement::NORD) {
        // Flèche pointant vers le haut
        fleche->setPoint(0,basePosition + Vector2f(-(x/2), -x));  // Pointe de la flèche (au-dessus de la position)
        fleche->setPoint(1,basePosition + Vector2f(-((3*x)/4), -((3*x)/4))); // Coin inférieur gauche
        fleche->setPoint(2,basePosition + Vector2f(-(x/4), -((3*x)/4)));  // Coin inférieur droit
    } else if (sens == OrientationDeplacement::SUD) {
        // Flèche pointant vers le bas
        fleche->setPoint(0,basePosition + Vector2f(-(x/2), 0));   // Pointe de la flèche (en dessous de la position)
        fleche->setPoint(1,basePosition + Vector2f(-((3*x)/4), -(x/4)));  // Coin supérieur gauche
        fleche->setPoint(2,basePosition + Vector2f(-(x/4), -(x/4)));  // Coin supérieur droit
    } else if (sens == OrientationDeplacement::OUEST) {
        // Flèche pointant vers la gauche
        fleche->setPoint(0,basePosition + Vector2f(-x, -(x/2)));    // Pointe de la flèche (à gauche de la position)
        fleche->setPoint(1,basePosition + Vector2f(-((3*x)/4), -((3*x)/4)));    // Coin supérieur droit
        fleche->setPoint(2,basePosition + Vector2f(-((3*x)/4), -(x/4)));    // Coin inférieur droit
    } else if (sens == OrientationDeplacement::EST) {
        // Flèche pointant vers la droite
        fleche->setPoint(0,basePosition + Vector2f(0, -(x/2)));    // Pointe de la flèche (à droite de la position)
        fleche->setPoint(1,basePosition + Vector2f(-(x/4),-((3*x)/4)));  // Coin supérieur gauche
        fleche->setPoint(2,basePosition + Vector2f(-(x/4), -(x/4))); // Coin inférieur gauche
    }
    // Appliquer la couleur à la flèche
    fleche->setFillColor(color);
    objets.push_back(fleche);
}
