
#include <iostream>
#include <string.h>
#include <string>
#include <algorithm>  
#include <fstream>
#include <vector>
#include "Fasta.h"
#include <bits/stdc++.h> 


using namespace std;



void ayuda();

void dividir_entrada(char entrada[],char* palabra1[], char* palabra2[], char* palabra3[], char* palabra4[], char* palabra5[],char* palabra6[]);


int main(){

  Fasta faste;

	char entrada[300];
  char* palabra1[300];
  char* palabra2[300];
  char* palabra3[300];
  char* palabra4[300];
  char* palabra5[300];
  char* palabra6[300];

  *palabra2=NULL;
  *palabra3=NULL;
  *palabra4=NULL;
  *palabra5=NULL;
  *palabra6=NULL;

  string comando;

	cout<<"****************************************************************************************************************** "<<endl;
	cout<<"Estructuras de Datos Proyecto del curso, 2020-10   \n\nFabio Camargo\nJuan Jose Bolaños\nJulian Rizo\nFelipe Becerra "<<endl;
	cout<<"****************************************************************************************************************** "<<endl;

	//Bandera para validar entrada a algun method
	bool flag = true;
  do{
    cout<<"Para desplegar el menu de interacciones digite el comando <<ayuda>> "<<endl;
    cout<<"$";
		flag = true;

    cin.getline(entrada,300,'\n');

		dividir_entrada(entrada,palabra1,palabra2,palabra3,palabra4,palabra5,palabra6);
    comando = *palabra1;
    
    if(comando == "ayuda" || comando == "Ayuda" || comando == "AYUDA"){
      ayuda();
    }
    if(comando == "cargar" || comando == "Cargar" || comando == "CARGAR"){
      if( *palabra2!=NULL &&  *palabra3==NULL  &&  *palabra4==NULL  &&  *palabra5==NULL  &&*  palabra6==NULL)
      {
        bool aux = false;
        cout<<"\nCARGANDO CADENA DESDE ARCHIVO .FA";
				//faste.cargar(*palabra2); 1==true 0==false;
        flag = false; //Valida la entrada al metodo

        //Manejo de errores en la lectura
        if(faste.cargar(*palabra2)){
          cout<<faste.conteo()<<" cadenas en memoria\n\n";
        }
        else{
          cout<<"Error en el archivo\n\n";
        }/*
          aux = Fasta::cargar(palabra2);
          cout<<aux<<endl;
          */
      }
      else{
        cout<<"Se envio Parametros invalidos"<<endl;
      }
    }
    if(comando == "conteo" || comando == "Conteo" || comando == " CONTEO"){
      flag = false;

      //Conteo de secuencias
      int secuenceCount = faste.conteo();

      //Manejo de resultados del conteo
      if(secuenceCount == 1){
        cout<<"1 secuencia cargada en memoria\n";
      }
      else if(secuenceCount > 1){
        cout<<faste.conteo()<<" secuencias cargadas en memoria\n"; 
      }
      else if(secuenceCount == 0){
        cout<<"No hay secuencias cargadas en memoria\n";
      }

    }

		if(comando == "listar_secuencias" || comando == "Listar_secuencias" || comando == "LISTAR_SECUENCIAS"){
      flag = false;
      faste.listar_secuencias();
		}
    if(comando == "histograma" || comando == "Histograma" || comando == "HISTOGRAMA")
    {
      if( *palabra2!=NULL &&  *palabra3==NULL  &&  *palabra4==NULL  &&  *palabra5==NULL  &&*  palabra6==NULL){
        // histograma(palabra2);
        flag = false;
        faste.histograma(*palabra2);
      }
      else{
        cout<<"Se envio Parametros invalidos"<<endl;
      }
    }
    if(comando == "es_subsecuencia" || comando == "EsSubsecuencia" || comando == "ESSUBSECUENCIA"){
      if(*palabra2!=NULL &&  *palabra3==NULL  &&  *palabra4==NULL  &&  *palabra5==NULL  &&*  palabra6==NULL){
          //faste.subsecuencia(palabra2);
          flag = false;
          int x=faste.subsecuencia(*palabra2);
      }
      else{
        cout<<"Se envio Parametros invalidos"<<endl;
      }
    }
	  if(comando == "enmascarar" || comando == "Enmascarar" || comando == "ENMASCARAR"){
      if(*palabra2!=NULL &&  *palabra3==NULL  &&  *palabra4==NULL  &&  *palabra5==NULL  &&*  palabra6==NULL){
          faste.enmascarar(*palabra2);
          flag = false;
          //cout<<"prueba"<<endl;
      }
      else{
        cout<<"Se envio Parametros invalidos"<<endl;
      }
    }

    if(comando == "guardar" || comando == "Guardar" || comando == "GUARDAR"){
      if(*palabra2!=NULL &&  *palabra3==NULL  &&  *palabra4==NULL  &&  *palabra5==NULL  &&*  palabra6==NULL)
      {
        //guardar(palabra2);
        flag = false;
        faste.guardar(*palabra2);
      }
      else
      {
        cout<<"Se envio Parametros invalidos"<<endl;
      }
    }
    if(comando == "salir" || comando == "Salir" || comando == "SALIR")
    {
        return -1;
    }

    if(comando == "codificar" || comando == "Codificar" || comando == "CODIFICAR")
    {
      if( *palabra2!=NULL &&  *palabra3==NULL  &&  *palabra4==NULL  &&  *palabra5==NULL  &&*  palabra6==NULL)
      {
          //codificar(palabra2);
          flag = false;
          cout<<"prueba"<<endl;
      }
      else
      {
        cout<<"Se envio Parametros invalidos"<<endl;
      }
    }
    else if(comando == "decodificar" || comando == "DECODIFICAR" || comando == "Decodificar")
    {
      if(*palabra2!=NULL &&  *palabra3==NULL  &&  *palabra4==NULL  &&  *palabra5==NULL  &&*  palabra6==NULL)
      {
        //decodificar(palabra2);
        flag = false;
        cout<<"prueba"<<endl;
      }
      else
      {
        cout<<"Se envio Parametros invalidos"<<endl;
      }
    }

    if(comando == "ruta_mas_corta" || comando == "Ruta_mas_corta" || comando == "RUTA_MAS_CORTA")
    {
      if(*palabra2!=NULL &&  *palabra3!=NULL  &&  *palabra4!=NULL  &&  *palabra5!=NULL  &&*  palabra6!=NULL)
      {
          //ruta_mas_corta(palabra2,palabra3,palabra4,palabra5,palabra5);
          flag = false;
          cout<<"prueba"<<endl;
      }
      else
      {
      cout<<"Se envio Parametros invalidos"<<endl;
      }
    }
    if(comando  == "base_remota" || comando  == "Base_remota" || comando  == "BASE_REMOTA")
    {
      if(*palabra2!=NULL &&  *palabra3!=NULL  &&  *palabra4!=NULL  &&  *palabra5==NULL  &&*  palabra6==NULL)
      {
          //base_remota(palabra2,palabra3,palabra4);
          flag = false;
          cout<<"prueba"<<endl;
      }
      else
      {
          cout<<"Se envio Parametros invalidos"<<endl;
      }
    }
    if(flag)
    {
        cout<<"Digite un comando valido... "<<endl;
    }
  }
  while(comando != "salir" || comando != "Salir" || comando != "SALIR");

  return 0;
};




void ayuda()
{
	cout<<"_________________________________________"<<endl<<endl;
	cout<<"Lista de Comandos Existentes : "<<endl;
	cout<<"> Cargar"<<endl;
	cout<<"> Conteo"<<endl;
	cout<<"> Listar_Secuencias"<<endl;
	cout<<"> Histograma"<<endl;
	cout<<"> es_subsecuencia"<<endl;
	cout<<"> enmascarar"<<endl;
	cout<<"> guardar"<<endl;
	cout<<"> salir"<<endl;
	cout<<"_________________________________________"<<endl<<endl;
}



void dividir_entrada(char entrada[],char* palabra1[], char* palabra2[], char* palabra3[], char* palabra4[], char* palabra5[],char* palabra6[]){


	char *token;
	token = strtok(entrada, " ");
	*palabra1 = token;

	token = strtok(NULL, " ");
	*palabra2 = token;

	token = strtok(NULL, " ");
	*palabra3 = token;

	token = strtok(NULL, " ");
	*palabra4	= token;

	token = strtok(NULL, " ");
	*palabra5 = token;

	token = strtok(NULL, " ");
	*palabra6 = token;


}
