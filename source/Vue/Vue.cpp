#include "Vue/Puzzle1.hpp"
#include "Vue/Puzzle2.hpp"
#include "Vue/Puzzle3.hpp"
#include "Vue/Puzzle4.hpp"


// Déclaration des variables globales
int MARGIN_LEFT = 100, MARGIN_RIGHT = 100, MARGIN_TOP = 100, MARGIN_BOTTOM = 100, TILE_SIZE = 34;



int choisirPuzzle(RenderWindow& window)
{
    // Affiche les quatres options de puzzles
    Texture puzzle1Texture, puzzle2Texture, puzzle3Texture, puzzle4Texture;
    puzzle1Texture.loadFromFile("ressources/puzzle1.png");
    puzzle2Texture.loadFromFile("ressources/puzzle2.png");
    puzzle3Texture.loadFromFile("ressources/puzzle3.png");
    puzzle4Texture.loadFromFile("ressources/puzzle4.png");

    Sprite puzzle1(puzzle1Texture), puzzle2(puzzle2Texture), puzzle3(puzzle3Texture), puzzle4(puzzle4Texture);
    puzzle1.setPosition(60, 60);
    puzzle2.setPosition(210, 60);
    puzzle3.setPosition(60, 210);
    puzzle4.setPosition(210, 210);

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) window.close();

            if (event.type == Event::MouseButtonPressed) {
                Vector2i mousePos = Mouse::getPosition(window);
                if (puzzle1.getGlobalBounds().contains(mousePos.x, mousePos.y)) { window.close();return 1;}
                if (puzzle2.getGlobalBounds().contains(mousePos.x, mousePos.y)) { window.close();return 2;}
                if (puzzle3.getGlobalBounds().contains(mousePos.x, mousePos.y)) { window.close();return 3;}
                if (puzzle4.getGlobalBounds().contains(mousePos.x, mousePos.y)) { window.close();return 4;}
            }
        }

        window.clear();
        window.draw(puzzle1);
        window.draw(puzzle2);
        window.draw(puzzle3);
        window.draw(puzzle4);
        window.display();
    }
    return -1; // En cas de fermeture
}

int main() {
// Création de la fenêtre graphique
    RenderWindow window{VideoMode{400, 400}, "Selection du Puzzle"};

    // Sélection du puzzle
    int choix = choisirPuzzle(window);
    if (choix == 1)
    {
        Puzzle1 p1(TILE_SIZE,6,8,MARGIN_LEFT,MARGIN_RIGHT,MARGIN_TOP,MARGIN_BOTTOM);
        p1.jouerPuzzle1();
    }
    else if(choix == 2)
    {
        Puzzle2 p2(TILE_SIZE,5,8,MARGIN_LEFT,MARGIN_RIGHT,MARGIN_TOP,MARGIN_BOTTOM);
        p2.jouerPuzzle2();
    }
    else if(choix == 3)
    {
        Puzzle3 p3(TILE_SIZE,6,6,MARGIN_LEFT,MARGIN_RIGHT,MARGIN_TOP,MARGIN_BOTTOM);
        p3.jouerPuzzle3();
    }
    else if(choix == 4)
    {
        Puzzle4 p4(TILE_SIZE,6,7,MARGIN_LEFT,MARGIN_RIGHT,MARGIN_TOP,MARGIN_BOTTOM);
        p4.jouerPuzzle4();
    }

    return EXIT_SUCCESS;
}
