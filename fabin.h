#ifndef __fabin__H__
#define __fabin__H__

#include "Genoma.h"
#include <vector>
using namespace std;

class fabin
{
public:

struct Fabin{
  int tamSecuencia; //Numero de bases que hay
  int codBase;      //La posicion de la base en una lista EJ: A=0
  int frecBase;     //Veces que se repite la base en la secuencia
  static int numSec;       //Numero de secuencias en el .fabin
  int numSecPos;    //Numero de secuencia en la que estoy
  char Base;        //Caracter en el que estoy;
  int sizeofTamSec; //Tamano de la sec
  int repBin;       //Representacion binaria de la base en el arbol de Huffman

  /*
  Codificar necesita:
  La lista de los binarios
  Lo que sale del histograma:
    frecuencia
  Tamano de la frecuencia
  Listan huffman
  */
}

bool codificar(string nombreArch,vector <char> digitosdif){
  
  vector<Fabin> fabinVec;
  ofstream Fichero (nombreArch,ios::binary|ios::in|ios::app);
  for (int i){
   if (Fichero){
      Fichero.write((char*)&fabinVec[i], sizeof (fabinvec[i]));

    }else{
      return false;
    }
  }

  Fichero.close();
  return true;
}

}
#endif
