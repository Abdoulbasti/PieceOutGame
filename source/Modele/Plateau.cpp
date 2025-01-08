#include"Modele/Plateau.hpp"


Plateau::Plateau(int colonnes, int lignes):NB_COL{colonnes},NB_LIGNE{lignes}
{
    // Initialiser les cases tous jouables_libre
    cases = vector<vector<EtatCase>>(NB_LIGNE,vector<EtatCase>(NB_COL,EtatCase::JOUABLE_LIBRE));
}
Plateau::~Plateau() {}
int Plateau::getNB_COL()const { return NB_COL;}
int Plateau::getNB_LIGNE()const { return NB_LIGNE;}
vector<vector<EtatCase>> Plateau::getCases()const { return cases;}
vector<pair<Piece&, char>> Plateau::getPiecesEtCouleurs()const { return piecesEtCouleurs;}
void Plateau::occuperCase(int x, int y)
{
    cases[y][x] = EtatCase::JOUABLE_OCCUPEE;
}  
bool Plateau::estOccupee(int x, int y) const 
{
    return  cases[y][x] == EtatCase::JOUABLE_OCCUPEE;
}

bool Plateau::estDansLimites(Piece& piece) const  
{
    for (pair<int, int> v : piece.getCoordinates())
    {
        if( v.first < 0 || v.first >= NB_COL || v.second < 0 || v.second >= NB_LIGNE || cases[v.second][v.first] == EtatCase::NON_JOUABLE)
        return false;
    }
    return true;
}
bool Plateau::peutPlacer( Piece& piece) const  
{
    if(estDansLimites(piece))
    {
        for (pair<int, int> v : piece.getCoordinates())
        {
            if(estOccupee(v.first,v.second))
            return false;
        }
        return true;
    }
    return false;
}   
bool Plateau::placerPiece( Piece& piece,int c) 
{
    if (peutPlacer(piece))
    {
        for (pair<int, int> v : piece.getCoordinates())
        {
            occuperCase(v.first,v.second) ; 
        }
        piecesEtCouleurs.push_back({piece,c});
        return true;
    }
    return false;
}        

bool Plateau::estOperationValide(Piece& p, int x, int y) {
    // Détermine si p est un des trois types et récupère l'opérateur
    OperateurDeplacement* deplacement = dynamic_cast<OperateurDeplacement*>(&p);
    OperateurRotation* rotation = dynamic_cast<OperateurRotation*>(&p);
    OperateurSymetrie* symetrie = dynamic_cast<OperateurSymetrie*>(&p);

    // Regroupe les trois types dans une seule variable générique
    PieceOperateur* operateur = deplacement ? static_cast<PieceOperateur*>(deplacement) :
                           rotation ? static_cast<PieceOperateur*>(rotation) :
                           symetrie ? static_cast<PieceOperateur*>(symetrie) : nullptr;
    if (operateur) {
        // Récupère les coordonnées de l'opérateur
        vector<pair<int, int>> pa = operateur->getCoordinates();
        // Vérifie si (x, y) existe dans les coordonnées de l'opérateur
        auto it = find(pa.begin(), pa.end(), make_pair(x, y));
        if (it == pa.end()) {
            return false; // (x, y) ne fait pas partie des coordonnées
        }
        if(operateur->getPosition().first==x && operateur->getPosition().second==y)
        {    
            // Applique mapPosition pour transformer les coordonnées
            for (pair<int, int>& pos : pa) {
                operateur->mapPosition(pos);
            }
            // Libère les cases actuelles de la pièce
            for (pair<int, int> v : p.getCoordinates()) {
                cases[v.second][v.first] = EtatCase::JOUABLE_LIBRE;
            }
            // Crée une nouvelle pièce avec les coordonnées transformées
            Piece* pc = new PieceConcrete{pa};
            // Vérifie si la pièce peut être placée
            if (peutPlacer(*pc)) {
                // Réoccupe les cases si l'opération est valide avec les nouvelles coordonnées de p
                for (pair<int, int> v : pa) {
                    occuperCase(v.first, v.second);
                }
                delete pc; // Libère la mémoire
                return true;
            }
            // Réoccupe les cases si l'opération n'est pas valide avec la piece initiale
                for (pair<int, int> v : p.getCoordinates()) {
                    occuperCase(v.first, v.second);
                }
            delete pc; // Libère la mémoire
        }
        else
        {
            if(estOperationValide(operateur->source,x,y)) return true;
        }
    }
    return false; // Aucun des types spécifiés ou l'opération est invalide
}

void Plateau::initialiserNonJouable(vector<pair<int,int>> vecteur)
{
    for (pair<int, int> v : vecteur)
    {
        if (v.first >= 0 && v.first < NB_COL && v.second >= 0 && v.second < NB_LIGNE) {
            cases[v.second][v.first] = EtatCase::NON_JOUABLE;
        } 
    }
}

void Plateau::afficher() const {
    // Créer une matrice vide avec des espaces
    vector<vector<char>> matrix(NB_LIGNE, vector<char>(NB_COL, '.'));
    for (int i = 0; i < NB_LIGNE; ++i) {
        for (int j = 0; j < NB_COL; ++j){
            if(cases[i][j]==EtatCase::NON_JOUABLE) matrix[i][j] = ' ';

            //Etat des cellules gagnante
            if(cases[i][j]==EtatCase::JOUABLE_GAIN) matrix[i][j] = '!';
        }
    }
    // Marquer les positions avec des couleurs correspondantes
    for (const pair<Piece &, char>& piece : piecesEtCouleurs) {
        for (const pair<int, int>& coord : piece.first.getCoordinates()) {
            int x = coord.first;
            int y = coord.second;
            if (x >= 0 && x < NB_COL && y >= 0 && y < NB_LIGNE) { // Vérifie les limites
                matrix[y][x] = piece.second; // Insère la couleur ou caractère
            }
        }
    }
    // Affichage des indices des colonnes
    cout << "  ";
    for (int i = 0; i < NB_COL; ++i) {
        cout << i << " ";
    }
    cout << endl;
    // Affichage de la matrice
    for (int i = 0; i < NB_LIGNE; ++i) {
        cout << i << " "; // Indice des lignes
        for (int j = 0; j < NB_COL; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

//initialiation des cellules(piece) gagnantes
void Plateau::initialiserJouableGain(vector<pair<vector<pair<int, int>>, Piece*>> vecteur)
{
    for (const pair<vector<pair<int, int>>, Piece *>& config : vecteur) 
    { 
        for (pair<int, int> v : config.first)
        {
            if (v.first >= 0 && v.first < NB_COL && v.second >= 0 && v.second < NB_LIGNE) {
                cases[v.second][v.first] = EtatCase::JOUABLE_GAIN;
            } 
        }
    }
}
bool Plateau::estDansGain(vector<pair<int, int>> vecteur, vector<pair<vector<pair<int, int>>, Piece*>> vecteurgain)
{
    for (const pair<vector<pair<int, int>>, Piece *>& config : vecteurgain) {
        // Récupère les coordonnées de gain associées à la pièce dans la paire
        vector<pair<int, int>> coordsGain = config.first; // Coordonnées gagnantes à vérifier
        // Trie les deux ensembles de coordonnées pour une comparaison fiable
        sort(coordsGain.begin(), coordsGain.end());
        sort(vecteur.begin(), vecteur.end());

        // Compare les coordonnées
        if (coordsGain == vecteur) {
            return true; // Quitte la fonction dès qu'un gain n'est pas détecté
        }
    }
    return false;
}

vector<pair<int, int>> Plateau::estPieceGain(Piece* p, vector<pair<vector<pair<int, int>>, Piece*>> vecteurgain)
{
    for (const pair<vector<pair<int, int>>, Piece *>& config : vecteurgain)
    {
        if(p == config.second) return config.first;
    }
}
//Detection de gain dans une configuration
void Plateau::detectionGain(vector<pair<vector<pair<int, int>>, Piece*>> vecteur, int& exit) {
    for (const pair<vector<pair<int, int>>, Piece *>& config : vecteur) {
        Piece* pieceAPlacer = config.second;              // Pièce associée
         // Récupérer les coordonnées de la pièce
        vector<pair<int, int>> coordsPiece = pieceAPlacer->getCoordinates();
        if(!estDansGain(coordsPiece,vecteur)) return;
    }
    exit = 0; // Terminer le jeu
    cout << "############ YOUPI... VOUS AVEZ GAGNE !!! ##############" << endl;
}