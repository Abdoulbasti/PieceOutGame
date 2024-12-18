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
    for (auto v : piece.getCoordinates())
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
        for (auto v : piece.getCoordinates())
        {
            if(estOccupee(v.first,v.second))
            return false;
        }
        return true;
    }
    return false;
}   
bool Plateau::placerPiece( Piece& piece,char c) 
{
    if (peutPlacer(piece))
    {
        for (auto v : piece.getCoordinates())
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
        // Applique mapPosition pour transformer les coordonnées
        for (auto& pos : pa) {
            operateur->mapPosition(pos);
        }

        // Libère les cases actuelles de la pièce
        for (auto v : p.getCoordinates()) {
            cases[v.second][v.first] = EtatCase::JOUABLE_LIBRE;
        }

        // Crée une nouvelle pièce avec les coordonnées transformées
        Piece* pc = new PieceConcrete{pa};

        // Vérifie si la pièce peut être placée
        if (peutPlacer(*pc)) {
            // Réoccupe les cases si l'opération est valide avec les nouvelles coordonnées de p
            for (auto v : pa) {
                occuperCase(v.first, v.second);
            }
            delete pc; // Libère la mémoire
            return true;
        }
        // Réoccupe les cases si l'opération n'est pas valide avec la piece initiale
            for (auto v : p.getCoordinates()) {
                occuperCase(v.first, v.second);
            }
        delete pc; // Libère la mémoire
    }

    return false; // Aucun des types spécifiés ou l'opération est invalide
}
void Plateau::initialiserNonJouable(vector<pair<int,int>> vecteur)
{
    for (auto v : vecteur)
    {
        if (v.first >= 0 && v.first < NB_COL && v.second >= 0 && v.second < NB_LIGNE) {
            cases[v.second][v.first] = EtatCase::NON_JOUABLE;
        } 
    }
}
void Plateau::afficher() const {
    // Créer une matrice vide avec des espaces
    vector<vector<char>> matrix(NB_LIGNE, vector<char>(NB_COL, '.'));
    
    // Marquer les positions avec des couleurs correspondantes
    for (const auto& piece : piecesEtCouleurs) {
        for (const auto& coord : piece.first.getCoordinates()) {
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
