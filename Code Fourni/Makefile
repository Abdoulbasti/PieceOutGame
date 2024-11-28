CPP=g++ --std=c++11 -Wall

all : test

test : build/test.o  build/Piece.o  build/PieceConcrete.o  build/PieceOperateur.o  build/OperateurDeplacement.o build/OperateurRotation.o build/OperateurSymetrie.o
	$(CPP) -o test  build/test.o  build/Piece.o  build/PieceConcrete.o  build/PieceOperateur.o  build/OperateurDeplacement.o build/OperateurRotation.o build/OperateurSymetrie.o

build/Piece.o : source/Modele/Piece.cpp  include/Modele/Piece.hpp 
	$(CPP) -c source/Modele/Piece.cpp -o build/Piece.o

build/test.o : source/Modele/test.cpp  include/Modele/PieceConcrete.hpp include/Modele/OperateurDeplacement.hpp 
	$(CPP) -c source/Modele/test.cpp -o build/test.o

build/PieceOperateur.o : source/Modele/PieceOperateur.cpp  include/Modele/PieceOperateur.hpp include/Modele/PieceConcrete.hpp
	$(CPP) -c  source/Modele/PieceOperateur.cpp -o build/PieceOperateur.o

build/PieceConcrete.o : source/Modele/PieceConcrete.cpp  include/Modele/PieceConcrete.hpp include/Modele/PieceOperateur.hpp
	$(CPP) -c  source/Modele/PieceConcrete.cpp -o build/PieceConcrete.o

build/OperateurDeplacement.o : source/Modele/OperateurDeplacement.cpp  include/Modele/OperateurDeplacement.hpp 
	$(CPP) -c  source/Modele/OperateurDeplacement.cpp -o build/OperateurDeplacement.o

build/OperateurSymetrie.o : source/Modele/OperateurSymetrie.cpp  include/Modele/OperateurSymetrie.hpp 
	$(CPP) -c  source/Modele/OperateurSymetrie.cpp -o build/OperateurSymetrie.o

build/OperateurRotation.o : source/Modele/OperateurRotation.cpp  include/Modele/OperateurRotation.hpp 
	$(CPP) -c  source/Modele/OperateurRotation.cpp -o build/OperateurRotation.o

clean :
	rm -f build/*.o test 
