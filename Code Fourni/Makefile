CPP=g++ --std=c++11 -Wall

all : test

test : build/test.o build/Piece.o build/PieceConcrete.o build/PieceOperateur.o build/OperateurDeplacement.o
	$(CPP) -o test build/test.o build/Piece.o build/PieceConcrete.o build/PieceOperateur.o build/OperateurDeplacement.o

build/Piece.o : source/Modele/Piece.cpp include/Modele/Piece.hpp 
	$(CPP) -c source/Modele/Piece.cpp

build/test.o : source/Modele/test.cpp include/Modele/Piece.hpp 
	$(CPP) -c source/Modele/test.cpp

build/PieceOperateur.o : source/Modele/PieceOperateur.cpp include/Modele/PieceOperateur.hpp
	$(CPP) -c source/Modele/PieceOperateur.cpp

build/PieceConcrete.o : source/Modele/PieceConcrete.cpp include/Modele/PieceConcrete.hpp
	$(CPP) -c source/Modele/PieceConcrete.cpp

build/OperateurDeplacement.o : source/Modele/OperateurDeplacement.cpp include/Modele/OperateurDeplacement.hpp
	$(CPP) -c source/Modele/OperateurDeplacement.cpp

clean :
	rm -f *.o test 
