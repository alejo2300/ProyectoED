#include "CodigoGenetico.h"

using namespace std;


string CodigoGenetico::getDescripcion(){

  return descripcion;

}


 vector<char> CodigoGenetico::getCodigos(){

  return codigo;

}

void CodigoGenetico::setDescripcion(string n_descripcion){

    descripcion = n_descripcion;

}


void CodigoGenetico::setCodigos(vector<char> n_codigo){


    codigo = n_codigo;
    
}