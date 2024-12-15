#include "Vue/EntreeSortie.hpp"

void EntreeSortie::gererSouris(RenderWindow& window, Grille& G, Texture& texture, vector<Drawable*>& objets)
{
    int trig_x=-1, trig_y=-1;
    Vector2i mousePos = Mouse::getPosition(window);
    Vector2f mouseWorldPos = window.mapPixelToCoords(mousePos);
    string message = "Mouse Position: (" + to_string(int(mouseWorldPos.x)) + ", " +to_string(int(mouseWorldPos.y)) + ")";
    if (G.estDansGrille(mouseWorldPos))
     {
        trig_x=G.obtenirCase(mouseWorldPos).x;
        trig_y=G.obtenirCase(mouseWorldPos).y;
        message += " case :" + to_string(trig_x) + " ; " + to_string(trig_y);
     }

    Event event;
    while (window.pollEvent(event)) {
            if (event.type == Event::Closed ||  (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape))
                    window.close();
            if (event.type == Event::MouseButtonPressed 
            && event.mouseButton.button == Mouse::Left 
            && G.estDansGrille(mouseWorldPos)) {
                cout << "trigger " << trig_x << " " << trig_y << endl;
            // création d'un sprite pour afficher une case d'exemple
            Sprite* sprite=new Sprite;
            sprite->setTexture(texture);
            Vector2u textureSize = texture.getSize();
            sprite->setScale(static_cast<float>(G.getTILESIZE()) / textureSize.x, static_cast<float>(G.getTILESIZE()) / textureSize.y);
            sprite->setPosition(G.getPosition()+Vector2f(trig_x*G.getTILESIZE(),trig_y*G.getTILESIZE())); 
            objets.push_back(sprite);
        }
    }
}
