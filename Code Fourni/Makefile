CPP=g++ --std=c++11 -Wall -Iinclude
SOURCE_MODELE_DIR=source/Modele
INCLUDE_MODELE_DIR=include/Modele
BD_DIR=build

# La Liste des fichiers objets pour le modele
#Ajouter ici d'autres objet .o 
OBJ_MODELE_LIST = 	$(BD_DIR)/Modele.o  $(BD_DIR)/Piece.o $(BD_DIR)/PieceConcrete.o  $(BD_DIR)/PieceOperateur.o $(BD_DIR)/OperateurDeplacement.o \
					$(BD_DIR)/OperateurRotation.o  $(BD_DIR)/OperateurSymetrie.o

OBJ_VUE_LIST = 


all_modele : $(BD_DIR)/ProgramModele

#Compilation et excution
$(BD_DIR)/ProgramModele : $(OBJ_MODELE_LIST)
	$(CPP) -o $(BD_DIR)/ProgramModele  $(OBJ_MODELE_LIST)
	./$(BD_DIR)/ProgramModele
	
$(BD_DIR)/Modele.o : $(SOURCE_MODELE_DIR)/Modele.cpp
	$(CPP) -c $(SOURCE_MODELE_DIR)/Modele.cpp -o $(BD_DIR)/Modele.o

$(BD_DIR)/Piece.o : $(SOURCE_MODELE_DIR)/Piece.cpp
	$(CPP) -c $(SOURCE_MODELE_DIR)/Piece.cpp -o $(BD_DIR)/Piece.o

$(BD_DIR)/PieceOperateur.o : $(SOURCE_MODELE_DIR)/PieceOperateur.cpp
	$(CPP) -c  $(SOURCE_MODELE_DIR)/PieceOperateur.cpp -o $(BD_DIR)/PieceOperateur.o

$(BD_DIR)/PieceConcrete.o : $(SOURCE_MODELE_DIR)/PieceConcrete.cpp
	$(CPP) -c  $(SOURCE_MODELE_DIR)/PieceConcrete.cpp -o $(BD_DIR)/PieceConcrete.o

$(BD_DIR)/OperateurDeplacement.o : $(SOURCE_MODELE_DIR)/OperateurDeplacement.cpp
	$(CPP) -c  $(SOURCE_MODELE_DIR)/OperateurDeplacement.cpp -o $(BD_DIR)/OperateurDeplacement.o

$(BD_DIR)/OperateurSymetrie.o : $(SOURCE_MODELE_DIR)/OperateurSymetrie.cpp
	$(CPP) -c  $(SOURCE_MODELE_DIR)/OperateurSymetrie.cpp -o $(BD_DIR)/OperateurSymetrie.o

$(BD_DIR)/OperateurRotation.o : $(SOURCE_MODELE_DIR)/OperateurRotation.cpp 
	$(CPP) -c  $(SOURCE_MODELE_DIR)/OperateurRotation.cpp -o $(BD_DIR)/OperateurRotation.o

#Ajouter ici d'autres regles de dependances .o ajouter dans OBJ_MODELE_LIST

clean_modele :
	rm -f $(BD_DIR)/*.o $(BD_DIR)/ProgramModele