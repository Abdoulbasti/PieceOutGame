CPP=g++ --std=c++11 -Wall -Wextra -Iinclude
LSFML_OPTIONS=-lsfml-system -lsfml-graphics -lsfml-window -lsfml-audio
SOURCE_MODELE_DIR=source/Modele
INCLUDE_MODELE_DIR=include/Modele
SOURCE_VUE_DIR=source/Vue
INCLUDE_VUE_DIR=include/Vue
BD_DIR=build

# La Liste des fichiers objets pour le modele
#Ajouter ici d'autres objet .o 
OBJ_MODELE_LIST = 	$(BD_DIR)/Modele.o  $(BD_DIR)/Piece.o $(BD_DIR)/PieceConcrete.o  $(BD_DIR)/PieceOperateur.o $(BD_DIR)/OperateurDeplacement.o \
					$(BD_DIR)/OperateurRotation.o  $(BD_DIR)/OperateurSymetrie.o $(BD_DIR)/Plateau.o

# La Liste des fichiers objets pour la vue
#Ajouter ici d'autres objet .o 
OBJ_VUE_LIST = $(BD_DIR)/Vue.o $(BD_DIR)/VuePlateau.o $(BD_DIR)/Piece.o $(BD_DIR)/PieceConcrete.o  $(BD_DIR)/PieceOperateur.o $(BD_DIR)/OperateurDeplacement.o \
					$(BD_DIR)/OperateurRotation.o  $(BD_DIR)/OperateurSymetrie.o  $(BD_DIR)/Plateau.o $(BD_DIR)/Decorer.o $(BD_DIR)/Puzzle1.o $(BD_DIR)/Puzzle2.o $(BD_DIR)/Puzzle3.o $(BD_DIR)/Puzzle4.o


#--------------------------------------- compilation du modele ------------------------------------------#
all_modele : $(BD_DIR)/ProgramModele

#Compilation et excution
$(BD_DIR)/ProgramModele : $(OBJ_MODELE_LIST)
	$(CPP) -o $(BD_DIR)/ProgramModele  $(OBJ_MODELE_LIST)
	./$(BD_DIR)/ProgramModele
	
$(BD_DIR)/Modele.o : $(SOURCE_MODELE_DIR)/Modele.cpp
	mkdir -p build
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

$(BD_DIR)/Plateau.o : $(SOURCE_MODELE_DIR)/Plateau.cpp
	$(CPP) -c $(SOURCE_MODELE_DIR)/Plateau.cpp -o $(BD_DIR)/Plateau.o

#Ajouter ici d'autres regles de dependances .o ajouter dans OBJ_MODELE_LIST

clean_modele :
	rm -f $(BD_DIR)/*.o $(BD_DIR)/ProgramModele




#--------------------------------------- compilation de la vue ------------------------------------------#
all_vue : $(BD_DIR)/ProgramVue

$(BD_DIR)/ProgramVue : $(OBJ_VUE_LIST)
	$(CPP) -o $(BD_DIR)/ProgramVue $(OBJ_VUE_LIST) $(LSFML_OPTIONS)
	./$(BD_DIR)/ProgramVue

$(BD_DIR)/Vue.o : $(SOURCE_VUE_DIR)/Vue.cpp
	mkdir -p build
	$(CPP) -c $(SOURCE_VUE_DIR)/Vue.cpp -o $(BD_DIR)/Vue.o

$(BD_DIR)/VuePlateau.o : $(SOURCE_VUE_DIR)/VuePlateau.cpp
	$(CPP) -c $(SOURCE_VUE_DIR)/VuePlateau.cpp -o $(BD_DIR)/VuePlateau.o $(LSFML_OPTIONS)

$(BD_DIR)/Decorer.o : $(SOURCE_VUE_DIR)/Decorer.cpp
	$(CPP) -c $(SOURCE_VUE_DIR)/Decorer.cpp -o $(BD_DIR)/Decorer.o

$(BD_DIR)/Puzzle1.o : $(SOURCE_VUE_DIR)/Puzzle1.cpp
	$(CPP) -c $(SOURCE_VUE_DIR)/Puzzle1.cpp -o $(BD_DIR)/Puzzle1.o

$(BD_DIR)/Puzzle2.o : $(SOURCE_VUE_DIR)/Puzzle2.cpp
	$(CPP) -c $(SOURCE_VUE_DIR)/Puzzle2.cpp -o $(BD_DIR)/Puzzle2.o

$(BD_DIR)/Puzzle3.o : $(SOURCE_VUE_DIR)/Puzzle3.cpp
	$(CPP) -c $(SOURCE_VUE_DIR)/Puzzle3.cpp -o $(BD_DIR)/Puzzle3.o

$(BD_DIR)/Puzzle4.o : $(SOURCE_VUE_DIR)/Puzzle4.cpp
	$(CPP) -c $(SOURCE_VUE_DIR)/Puzzle4.cpp -o $(BD_DIR)/Puzzle4.o
#Ajouter ici d'autres regles de dependances .o ajouter dans OBJ_VUE_LIST

clean_vue :
	rm -f *.o $(BD_DIR)/ebaucheVue.o $(BD_DIR)/ProgramVue
	