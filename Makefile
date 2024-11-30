CPP=g++ --std=c++11 -Wall -Wextra -Iinclude
LSFML_OPTIONS=-lsfml-system -lsfml-graphics -lsfml-window
SOURCE_MODELE_DIR=source/Modele
INCLUDE_MODELE_DIR=include/Modele
BD_DIR=build

# La Liste des fichiers objets pour le modele
#Ajouter ici d'autres objet .o 
OBJ_MODELE_LIST = 	$(BD_DIR)/Modele.o  $(BD_DIR)/Piece.o $(BD_DIR)/PieceConcrete.o  $(BD_DIR)/PieceOperateur.o $(BD_DIR)/OperateurDeplacement.o \
					$(BD_DIR)/OperateurRotation.o  $(BD_DIR)/OperateurSymetrie.o

# La Liste des fichiers objets pour la vue
#Ajouter ici d'autres objet .o 
OBJ_VUE_LIST = $(BD_DIR)/ebaucheVue.o 


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
#Ajouter ici d'autres regles de dependances .o ajouter dans OBJ_MODELE_LIST

clean_modele :
	rm -f $(BD_DIR)/*.o $(BD_DIR)/ProgramModele




#--------------------------------------- compilation de la vue ------------------------------------------#
all_vue : $(BD_DIR)/ProgramVue

$(BD_DIR)/ProgramVue : $(OBJ_VUE_LIST)
	$(CPP) -o $(BD_DIR)/ProgramVue $(OBJ_VUE_LIST) $(LSFML_OPTIONS)
	./$(BD_DIR)/ProgramVue

$(BD_DIR)/ebaucheVue.o : ebaucheVue.cpp
	mkdir -p build
	$(CPP) -c ebaucheVue.cpp -o $(BD_DIR)/ebaucheVue.o
#Ajouter ici d'autres regles de dependances .o ajouter dans OBJ_VUE_LIST

clean_vue :
	rm -f *.o $(BD_DIR)/ebaucheVue.o $(BD_DIR)/ProgramVue
	


#-----------------------------------------------------------------------------#
#all_vue : ebaucheVue

#ebaucheVue : $(OBJ_VUE_LIST)
#	$(CPP) -o $(BD_DIR)/ProgramVue $(OBJ_VUE_LIST) $(LSFML_OPTIONS)
#	./$(BD_DIR)/ProgramVue

#$(BD_DIR)/ebaucheVue.o : ebaucheVue.cpp
#	$(CPP) -c ebaucheVue.cpp -o $(BD_DIR)/ebaucheVue.o
#Ajouter ici d'autres regles de dependances .o ajouter dans OBJ_VUE_LIST

#clean :
#	rm *.o $(BD_DIR)/ebaucheVue.o $(BD_DIR)/ebaucheVue