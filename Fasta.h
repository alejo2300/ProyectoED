#ifndef __FASTA__H__
#define __FASTA__H__

#include "Genoma.h"
#include <vector>

typedef vector<Genoma> vecGenoma;

using namespace std;


class Fasta{

  public:

  void insertarGenoma(Genoma gnma)
  {
    vectorGenomas.push_back(gnma);
  }

  bool cargar(char *nombre_archivo){

    bool bandera = false;
    string texto;
    Genoma gnma;//Nombre y <vector>CodigosGeneticos
    CodigoGenetico codGen;//Descripcio(name) y <vector> codigo de char
    char cadena[100];
    vector<char> secuencia;


    //Definir archivo como un archivo a leer
    ifstream archivo;
    archivo.open(nombre_archivo, ios::in);

    //Apertura del archivo y validaci'on de contenido
    if(archivo.is_open()){
      //Verificar que el archivo no esta vacio
      gnma.setNombre(nombre_archivo);//Da el nombre del arch a gnma
      if ( archivo.peek() == std::ifstream::traits_type::eof() )
      {
          cout<<nombre_archivo<<" no contiene ninguna secuencia\n";
          return false;
      }


      //Lectura del archivo
      int number=0;
      bool cargar=false;
      int conter;
      while (!archivo.eof())
      {
        archivo>>texto;//Pone en texto lo que esta en la linea
        strcpy(cadena,texto.c_str());//Pone lo de texto en un char*

        //Viene el final de la lectura
        if(archivo.eof()){
          cout<<"\nEndOfFile\n";
          cargar=true;
        }

        if(cadena[0] == '>'){//Si es el nombre de sec

          int conter=0;
          texto.erase(0,1);//Elimina el >
          //cout<<"\n"<<texto;
          if(number>1){

          /*  for(int i=0;i<secuencia.size();i++){
              cout<<secuencia[i];
            }*/
            codGen.setCodigos(secuencia);
            codGen.setJustificacion(conter);
            gnma.insertarCodigo(codGen);
            secuencia.clear();
            cargar = false;int conter=0;

            number++;
            codGen.setDescripcion(texto);//Guarda el nombre de la sec
            cargar = false;
          }if(number==0){
            number++;
            codGen.setDescripcion(texto);//Guarda el nombre de la sec
          }


        }else{//Si es secuencia
          //cout<<"aaaase"<<texto<<"\n";
          if(!archivo.eof() && number>0){
            for(int i = 0; cadena[i] != '\0'; i++ ){
              secuencia.push_back(cadena[i]); //Guardamos en secuencia
              if(conter<i){
                conter = i+1;
              }
            }
          }
          //cout<<'\n';
        }
        //Metodo de cargar
        if(cargar){
        /*  for(int i=0;i<secuencia.size();i++){
            cout<<secuencia[i]<<"a";
          }*/
          codGen.setCodigos(secuencia);
          codGen.setJustificacion(conter);
          gnma.insertarCodigo(codGen);
          secuencia.clear();
          cargar = false;
        }
        number++;
      }
    }

    insertarGenoma(gnma);
    bandera = true;

/*
    //Imprimir codigos
    vector<CodigoGenetico> codigosGeneticosActual = gnma.getVectorDeCodigosGeneticos();


    for(int j=0; j<codigosGeneticosActual.size(); j++){
          cout << codigosGeneticosActual[j].getDescripcion() << "\n\n";

          vector<char> secuenciaActual = codigosGeneticosActual[j].getCodigos();
          for (int k=0;k<secuenciaActual.size();k++){
              cout<<secuenciaActual[k];
            }
          }


*/

    return bandera;
  }


int conteo()
{
  int total = 0;
  Genoma gnma;

  for(int i = 0; i < vectorGenomas.size(); i++){
    gnma = vectorGenomas[i];
    total = total + gnma.contarGen();
  }

  return total;
}


void listar_secuencias(){

  Genoma gnma;

  if(conteo() == 0)
  {
    cout<<"\nNo hay secuencias cargadas en memoria\n";
  }
  else
  {
    for(int i=0; i<vectorGenomas.size(); i++)
    {
        gnma = vectorGenomas[i];
        vector<CodigoGenetico> codigosGeneticosActual = gnma.getVectorDeCodigosGeneticos();

        for(int j=0; j<codigosGeneticosActual.size(); j++)
        {
          cout << codigosGeneticosActual[j].getDescripcion() << "\n";
          vector<char> secuenciaActual = codigosGeneticosActual[j].getCodigos();
          int counter=0;

          for (int k=0;k<secuenciaActual.size();k++)
          {
            if(secuenciaActual[k]=='A'||secuenciaActual[k]=='T'||secuenciaActual[k]=='C'||secuenciaActual[k]=='G'||secuenciaActual[k]=='U')//secuenciaActual[k]=='V'
            {
              counter++;
            }
          }
          cout<<"Numero de bases: "<<counter<<"\n\n";
        }
    }
  }
  cout<<"\n";
}

void histograma(char *nombre_histograma,vector<char> & digitosdif)
{
  int posva=0;
  for(int i=0; i<vectorGenomas.size(); i++){
    Genoma gnma = vectorGenomas[i];
    vector<CodigoGenetico> codigosGeneticosActual = gnma.getVectorDeCodigosGeneticos();

    int posSecuence=-1;

    for(int j=0; j<codigosGeneticosActual.size(); j++){
      if(codigosGeneticosActual[j].getDescripcion()==nombre_histograma){
        posSecuence=j;
      }
    }
      if(posSecuence < 0){
      cout<<"\nSecuencia no encontrada\n";
      break;
    }
      vector<char> secuenciaActual = codigosGeneticosActual[posSecuence].getCodigos();



      int counter=0;
      int A=0,C=0,G=0,T=0,U=0,R=0,Y=0,K=0,M=0,S=0,W=0,B=0,D=0,H=0,V=0,N=0;
      for (int k=0;k<secuenciaActual.size();k++){

        if(secuenciaActual[k]=='A'){
          A++;
        }

        if(secuenciaActual[k]=='C'){
          C++;
        }

        if(secuenciaActual[k]=='G'){
          G++;
        }

        if(secuenciaActual[k]=='T'){
          T++;
        }

        if(secuenciaActual[k]=='U'){
          U++;
        }

        if(secuenciaActual[k]=='R'){
          R++;
        }

        if(secuenciaActual[k]=='Y'){
          Y++;
        }

        if(secuenciaActual[k]=='K'){
          K++;
        }

        if(secuenciaActual[k]=='M'){
          M++;
        }

        if(secuenciaActual[k]=='S'){
          S++;
        }

        if(secuenciaActual[k]=='W'){
          W++;
        }

        if(secuenciaActual[k]=='B'){
          B++;
        }

        if(secuenciaActual[k]=='D'){
          D++;
        }

        if(secuenciaActual[k]=='H'){
          H++;
        }

        if(secuenciaActual[k]=='V'){
          V++;
        }

        if(secuenciaActual[k]=='N'){
          N++;
        }

        bool banderita=false;
        for (int h=0;h<digitosdif.size();h++)
        {

           if(secuenciaActual[k]==digitosdif[h])
           {
             banderita=true;
           }

        }

        if (!banderita)
        {
          //cout<<secuenciaActual[k]<<"fabio"<<endl;

          digitosdif.push_back(secuenciaActual[k]);

          posva++;
        }


      }



      cout<<"Adenina: "<<"\t"<<A<<"\t\nCitosina: "<<"\t"<<C<<"\t\nGuanina: "<<"\t"<<G<<"\t\nTimina: "<<"\t"<<T<<"\t\nUracilo: "<<"\t"<<U<<"\t\nA o G: "<<"\t"<<R<<"\t\nC,T o U: "<<"\t"<<Y<<"\t\nG,T o U: "<<"\t"<<K<<"\t\nA o C: "<<"\t"<<M<<"\t\nC o G: "<<"\t"<<S<<"\t\nA,T o U: "<<"\t"<<W<<"\t\nC,G,T o U: "<<"\t"<<B<<"\t\nA,G,T o U: "<<"\t"<<D<<"\t\nA,C,T o U: "<<"\t"<<H<<"\t\nA,C o G: "<<"\t"<<V<<"\t\nA,C,G,T o U: "<<"\t"<<N<<"\t\n";


    }
    /*cout<<"\n"<<digitosdif[0]<<endl;
    cout<<digitosdif[1];*/




  }

vector<int> frecuenciaSecuencias(vector<char> & digitosdif,int frecs[16]){
  int counter=0;
  int A=0,C=0,G=0,T=0,U=0,R=0,Y=0,K=0,M=0,S=0,W=0,B=0,D=0,H=0,V=0,N=0;

  for(int i=0; i<vectorGenomas.size(); i++){
    Genoma gnma = vectorGenomas[i];
    vector<CodigoGenetico> codigosGeneticosActual = gnma.getVectorDeCodigosGeneticos();

    for(int j=0; j<codigosGeneticosActual.size(); j++){

      vector<char> secuenciaActual = codigosGeneticosActual[j].getCodigos();



      for (int k=0;k<secuenciaActual.size();k++){

        if(secuenciaActual[k]=='A'){
          A++;
        }

        if(secuenciaActual[k]=='C'){
          C++;
        }

        if(secuenciaActual[k]=='G'){
          G++;
        }

        if(secuenciaActual[k]=='T'){
          T++;
        }

        if(secuenciaActual[k]=='U'){
          U++;
        }

        if(secuenciaActual[k]=='R'){
          R++;
        }

        if(secuenciaActual[k]=='Y'){
          Y++;
        }

        if(secuenciaActual[k]=='K'){
          K++;
        }

        if(secuenciaActual[k]=='M'){
          M++;
        }

        if(secuenciaActual[k]=='S'){
          S++;
        }

        if(secuenciaActual[k]=='W'){
          W++;
        }

        if(secuenciaActual[k]=='B'){
          B++;
        }

        if(secuenciaActual[k]=='D'){
          D++;
        }

        if(secuenciaActual[k]=='H'){
          H++;
        }

        if(secuenciaActual[k]=='V'){
          V++;
        }

        if(secuenciaActual[k]=='N'){
          N++;
        }

        bool banderita=false;
        for (int h=0;h<digitosdif.size();h++)
        {

           if(secuenciaActual[k]==digitosdif[h])
           {
             banderita=true;
           }

        }

        if (!banderita)
        {
          //cout<<secuenciaActual[k]<<"fabio"<<endl;

          digitosdif.push_back(secuenciaActual[k]);


        }
      }
      }



      //cout<<"Adenina: "<<"\t"<<A<<"\t\nCitosina: "<<"\t"<<C<<"\t\nGuanina: "<<"\t"<<G<<"\t\nTimina: "<<"\t"<<T<<"\t\nUracilo: "<<"\t"<<U<<"\t\nA o G: "<<"\t"<<R<<"\t\nC,T o U: "<<"\t"<<Y<<"\t\nG,T o U: "<<"\t"<<K<<"\t\nA o C: "<<"\t"<<M<<"\t\nC o G: "<<"\t"<<S<<"\t\nA,T o U: "<<"\t"<<W<<"\t\nC,G,T o U: "<<"\t"<<B<<"\t\nA,G,T o U: "<<"\t"<<D<<"\t\nA,C,T o U: "<<"\t"<<H<<"\t\nA,C o G: "<<"\t"<<V<<"\t\nA,C,G,T o U: "<<"\t"<<N<<"\t\n";

      vector<int> repeticiones;

      repeticiones.push_back(A);
      repeticiones.push_back(C);
      repeticiones.push_back(G);
      repeticiones.push_back(T);
      repeticiones.push_back(U);
      repeticiones.push_back(R);
      repeticiones.push_back(Y);
      repeticiones.push_back(K);
      repeticiones.push_back(M);
      repeticiones.push_back(S);
      repeticiones.push_back(W);
      repeticiones.push_back(B);
      repeticiones.push_back(D);
      repeticiones.push_back(H);
      repeticiones.push_back(V);
      repeticiones.push_back(N);

      for(int i=0;i<16;i++){
        frecs[i]=repeticiones[i];
      }

      return repeticiones;
    }
}

int subsecuencia (char *sequence){
  if(conteo()==0){
    cout<<"No hay secuencias en memoria\n";
  }else{
    char temp[300];
    char temp2[300];
     strcpy(temp,sequence);
    int tamano=strlen(temp);

    Genoma gem=vectorGenomas[0];
  vector<CodigoGenetico> aux=gem.getVectorDeCodigosGeneticos();
  int contador=0;
  int posva=0;
  for (int i=0;i<aux.size()-1;i++)
  {
    vector<char> codigos=aux[i].getCodigos();
     std::string s(codigos.begin(), codigos.end());
     string convertidor=convertToString(sequence,strlen(sequence));
    int mycount = count (codigos.begin(), codigos.end(), 'T');
   int contadores=countFreq(convertidor,s);
   if (contadores>=1){
cout<<"la cadena se repite:"<<contadores<<"veces\n";
return contadores;

   }
   else
   {
     cout<<"La subsecuencia dada no existe\n";
     return contadores;
   }

  }

  }
  return 0;
}

  string convertToString(char* a, int size)
{
    int i;
    string s = "";
    for (i = 0; i < size; i++) {
        s = s + a[i];
    }
    return s;
}

int countFreq(string &pat, string &txt)
{
    int M = pat.length();
    int N = txt.length();
    int res = 0;


    for (int i = 0; i <= N - M; i++)
    {

        int j;
        for (j = 0; j < M; j++)
            if (txt[i+j] != pat[j])
                break;

        if (j == M)
        {
           res++;
           j = 0;
        }
    }
    return res;
}


void enmascarar(char* secuencia){
  Genoma gnma;
  CodigoGenetico codGen;
  int posInicial, posFinal;
  int counter=0, tamano=0;
  int cantSubsecuencias = subsecuencia(secuencia);
  bool encontro=false;
  vector<char> nuevo;
  tamano=strlen(secuencia);
  if(cantSubsecuencias != 0)
  {
    int cantSubsecuencias = subsecuencia(secuencia);
    int res;
    for(int i=0; i<vectorGenomas.size(); i++)//Recorre Gnomas(archivos)
    {
      gnma = vectorGenomas[i];
      vector<CodigoGenetico> codigosGeneticosActual = gnma.getVectorDeCodigosGeneticos();

      for(int j=0; j<codigosGeneticosActual.size(); j++)//Recorre CodigosGeneticos
      {
        vector<char> secuenciaActual = codigosGeneticosActual[j].getCodigos();
        int counter=0;
        for (int k=0;k<secuenciaActual.size();k++)//Recorre el CodigoGenetico
        {
          if(secuenciaActual[k]==secuencia[counter])
          {
            if(counter==0)
              posInicial=k;
            counter++;
          }
          else if(secuenciaActual[k]!=secuencia[counter])
            counter=0;
          if(counter==tamano)
          {
            posFinal=k;
            for(int x=posInicial;x<posFinal+1;x++)
            {
              secuenciaActual[x]='x';
            }
            codigosGeneticosActual[j].setCodigos(secuenciaActual);

            for(int x=0;x<secuenciaActual.size();x++)
            {
              nuevo.push_back(secuenciaActual[x]);
              cout<<secuenciaActual[x];
            }
          }
        }
        cout<<"\n";
        codigosGeneticosActual[j].setCodigos(nuevo);
      }
    }

  }

  //Imprimir codigos
   /* vector<CodigoGenetico> codigosGeneticosActual = gnma.getVectorDeCodigosGeneticos();
    for(int j=0; j<codigosGeneticosActual.size(); j++){
          cout << codigosGeneticosActual[j].getDescripcion() << "\n\n";

          vector<char> secuenciaActual = codigosGeneticosActual[j].getCodigos();
          for (int k=0;k<secuenciaActual.size();k++){
              cout<<secuenciaActual[k];
            }
          }*/
}


void guardar(char *nombre_archivo){
  ofstream archivo;
  archivo.open(nombre_archivo,ios::out) ;
  if (archivo.fail())
  {
    cout<<"El archivo no se ha abierto correctamente"<<endl;
    exit(1);
  }
  else
  {
    Genoma gem=vectorGenomas[0];
  vector<CodigoGenetico> aux=gem.getVectorDeCodigosGeneticos();
  for (int i=0;i<aux.size();i++)
  {
    vector<char> codigos=aux[i].getCodigos();
    archivo<<"\n";
    for (int k=0;k<codigos.size();k++)
    {
      archivo<<codigos[k];
    }

  }
  archivo.close();
}
}
/*void guardar(char* nombre_archivo){
ofstream archivo;
archivo.open(nombre_archivo,ios::out)
if (archivo.fail())
{
  cout<<"El archivo no se ha abierto correctamente"<<endl;
  exit(1);
}
else
{
archivo<<
}


}*/

void setVectorDeGenomas(vector<Genoma> nVectorDeGenomas){

  vectorGenomas = nVectorDeGenomas;

}

vector<Genoma> getVectorDeGenomas(){

  return vectorGenomas;

}




 protected:


  vecGenoma vectorGenomas;




};

//Fasta implementation

#endif
