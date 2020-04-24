#include "Genoma.h"


using namespace std;


string Genoma::getNombre(){

  return nombreGenoma;

}

vector<CodigoGenetico> Genoma::getVectorDeCodigosGeneticos(){

  return codigosGeneticos;

}

void Genoma::setNombre(string n_nombre){

    nombreGenoma = n_nombre;
  
}

void Genoma::setCodigos(vector<CodigoGenetico> n_codigos){

    codigosGeneticos = n_codigos;
}

void Genoma::insertarCodigo(CodigoGenetico codigo){

    codigosGeneticos.push_back(codigo);

}

int Genoma::contarGen(){

    return codigosGeneticos.size();
}

void setGenoma(Genoma gnoma){
  
}







