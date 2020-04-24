#ifndef __CODIGOGENETICO__H__
#define __CODIGOGENETICO__H__


#include <vector>

using namespace std;


class CodigoGenetico{

  public: 

    string getDescripcion();
    
    vector<char> getCodigos();

    void setDescripcion(string n_descripcion);

    void addGenCod(char news){
      codigo.push_back(news);
    }

    void setCodigos(vector<char> n_codigo);

    void setJustificacion(int jusr){
      justificacion = jusr;
    }

    int getJustificacion(){
      return justificacion;
    }

    
  protected:

    string descripcion;

    vector<char> codigo;

    int justificacion;


};

#include "CodigoGenetico.hxx"

#endif