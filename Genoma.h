#ifndef __GENOMA__H__
#define __GENOMA__H__

#include <vector>
#include "CodigoGenetico.h"

using namespace std;


class Genoma{

  public:

    string getNombre();

    vector<CodigoGenetico> getVectorDeCodigosGeneticos();

    void setNombre(string nombre);

    void setCodigos(vector<CodigoGenetico> codigos);

    void insertarCodigo(CodigoGenetico codigo);

    int contarGen();

    void setGenoma(Genoma gnoma);
    
  protected:

    
    string nombreGenoma;

    vector<CodigoGenetico> codigosGeneticos;


};

#include "Genoma.hxx"
#endif