#include "Vue/Puzzle4.hpp"

Puzzle4::Puzzle4(int T ,int C, int L, int ML, int MR, int MT, int MB):TILE_SIZE{T},NB_COL{C},
NB_LIGNE{L},MARGIN_LEFT{ML},MARGIN_RIGHT{MR},MARGIN_TOP{MT},MARGIN_BOTTOM{MB}{}

int Puzzle4::jouerPuzzle4()
{
    // Déclaration et initialisation des variables locales
    unsigned int nbPix_x = MARGIN_LEFT + MARGIN_RIGHT + NB_COL * TILE_SIZE;
    unsigned int nbPix_y = MARGIN_TOP + MARGIN_BOTTOM + NB_LIGNE * TILE_SIZE;
    vector<Drawable*> scene_generale;
    vector<Drawable*> scene_particuliere;

    // Déclaration et initialisation de la grille
    VuePlateau* G = new VuePlateau(TILE_SIZE, NB_COL, NB_LIGNE, MARGIN_LEFT, MARGIN_RIGHT, MARGIN_TOP, MARGIN_BOTTOM);

    // Création des pièces
    vector<pair<int, int>> coords{{2, 0}, {2, 1}, {2, 2}, {3, 0}};
    PieceConcrete tetris_L(coords);
    coords = {{4, 0}, {4, 1}, {4, 2}, {3, 1}};
    PieceConcrete tetris_T(coords);
    coords = {{1, 0}, {1, 1},{1, 2}};
    PieceConcrete tetris_I(coords);

    // Décoration des pièces
    Piece* l = new OperateurRotation{tetris_L, {2, 1}, OrientationRotation::ANTIHORAIRE};
    l = new OperateurDeplacement{*l, {2, 0}, OrientationDeplacement::NORD};
    l = new OperateurDeplacement{*l, {2, 2}, OrientationDeplacement::SUD};

    Piece* t = new OperateurDeplacement{tetris_T,{4,0},OrientationDeplacement::NORD};
    t = new OperateurDeplacement{*t,{4,2},OrientationDeplacement::SUD};
    t = new OperateurRotation{*t, {4, 1}, OrientationRotation::ANTIHORAIRE};

    Piece* i = new OperateurDeplacement{tetris_I, {1, 0}, OrientationDeplacement::NORD};
    i = new OperateurDeplacement{*i, {1, 2}, OrientationDeplacement::SUD};
    i = new OperateurRotation{*i, {1, 1}, OrientationRotation::ANTIHORAIRE};

    // Création du plateau de jeu
    Plateau* P = new Plateau{NB_COL, NB_LIGNE};

    // Élimination des cases non jouables
    coords = {{0, 0}, {5, 0},{0, 1},{5, 1},{0, 2},{5, 2}, {5,4}, {0,4}, {0,5},{5,5}, {0, 6}, {5, 6}};
    P->initialiserNonJouable(coords);

    // Définition des cases gagnantes
    vector<pair<vector<pair<int, int>>, Piece*>> vecteurGain = {{{{4, 4}, {4, 5},{4,6}}, i}, {{{3, 4}, {3, 5},{3,6}, {2,6}}, l}, {{{1, 4}, {1, 5},{1,6}, {2,5}}, t}};
    P->initialiserJouableGain(vecteurGain);

    // Placement des pièces sur le plateau
    P->placerPiece(*l, 'B');
    P->placerPiece(*t, 'G');
    P->placerPiece(*i, 'R');

    // Initialisation des scènes
    scene_generale.push_back(&G->getCentralPane());
    scene_generale.push_back(&G->getTrame());
    G->tracerPiece(scene_particuliere, scene_generale, *P);
	G->tracerCaseGain(scene_generale,vecteurGain);

    // Décoration des pièces
    Decorer* D = new Decorer();
    D->decoration(scene_particuliere, *l, *G);
    D->decoration(scene_particuliere, *t, *G);
    D->decoration(scene_particuliere, *i, *G);

    // Création de la fenêtre graphique
    RenderWindow window{VideoMode{nbPix_x, nbPix_y}, "Piece Out"};

	// Charger la musique de fond
		Music musiqueDeFond;
		if (!musiqueDeFond.openFromFile("ressources/sounds/playful.ogg")) {
			std::cerr << "Erreur de chargement de la musique de fond" << std::endl;
		}

		// Jouer la musique en boucle
		musiqueDeFond.setLoop(true);  // La musique boucle indéfiniment
		musiqueDeFond.play();

    // Boucle principale
    while (window.isOpen()) {
        int exit = 1;
        int trig_x = -1, trig_y = -1;
        Vector2i mousePos = Mouse::getPosition(window);
        Vector2f mouseWorldPos = window.mapPixelToCoords(mousePos);

        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed || (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape)) {
                window.close();
            }
            if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left &&
                G->estDansVuePlateau(mouseWorldPos)) {
                trig_x = (mouseWorldPos.x - G->getPosition().x) / TILE_SIZE;
                trig_y = (mouseWorldPos.y - G->getPosition().y) / TILE_SIZE;

                if (P->estOperationValide(*l, trig_x, trig_y) || P->estOperationValide(*t, trig_x, trig_y) ||
                    P->estOperationValide(*i, trig_x, trig_y) ) {
                    l->trigger({trig_x, trig_y});
                    t->trigger({trig_x, trig_y});
                    i->trigger({trig_x, trig_y});

                    // Détection de gain avec animation de fin
                    P->detectionGain(vecteurGain, exit);
                    if (!exit) {
                        for (int i = 0; i < 5; ++i) {
                            window.clear(Color::White);  // Clignotement  pour signaler la victoire
                            window.display();
                            sleep(milliseconds(300));

                            window.clear(Color::Black);
                            window.display();
                            sleep(milliseconds(300));
                        }

                        // Affichage du message de victoire
                        Font font;
                        if (!font.loadFromFile("ressources/fonts/arial.ttf")) {
                            cerr << "Erreur : Impossible de charger la police arial.ttf !" << endl;
                            return EXIT_FAILURE;
                        }
                        Text victoryText("PARTIE TERMINEE !", font, 35);
                        victoryText.setFillColor(Color::Red);
                        victoryText.setPosition(nbPix_x / 2 - victoryText.getGlobalBounds().width / 2, nbPix_y / 2 - 50);

                        for (int i = 0; i < 3000; i += 100) {
                            window.clear();
                            window.draw(victoryText);
                            window.display();
                            sleep(milliseconds(100));
                        }

                        window.close();
                    }

                    // Nettoyage et mise à jour des scènes
                    for (Drawable* x : scene_particuliere) delete x;
                    scene_particuliere.clear();
                    G->tracerPiece(scene_particuliere, scene_generale, *P);
                    D->decoration(scene_particuliere, *l, *G);
                    D->decoration(scene_particuliere, *t, *G);
                    D->decoration(scene_particuliere, *i, *G);
                }
            }
        }

        // Nettoyage de la grille
        window.clear();
        window.setView(window.getDefaultView());

        // Affichages
        for (Drawable* x : scene_generale) window.draw(*x);
        for (Drawable* x : scene_particuliere) window.draw(*x);

        window.display();
    }

    // Nettoyage final des pointeurs
    delete l;
    delete t;
    delete i;
    delete G;
    delete P;
    delete D;
    
   for (Drawable* x : scene_generale) {
        if (x != &G->getCentralPane() && x != &G->getTrame()) {
            delete x;  // Supprime uniquement les objets dynamiquement alloués
        }
    }
    scene_generale.clear();  // Vider le vecteur après suppression

    for (Drawable* x : scene_particuliere) delete x;
    scene_particuliere.clear();
    return 0;
}