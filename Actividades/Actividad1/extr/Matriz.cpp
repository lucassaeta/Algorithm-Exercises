#include "Matriz.h"
#include <iostream>
#include<math.h>
#include<stdlib.h>
#define assertdomjudge(x) if(!(x)){std::cout<<"ERROR"<<std::endl;exit(0);}

//constructor defecto 
Matriz::Matriz(){

  this->n_filas = 0;
  this->n_columnas = 0; 
  this->matriz = NULL;
} 

//constructor parametros
Matriz::Matriz(int n_filas, int n_columnas){

  this->n_filas = n_filas;
  this->n_columnas = n_columnas; 
  
  matriz = new double *[n_filas]; //pregunta

  for(int i = 0; i<n_filas; i++){

    matriz[i] = new double[n_columnas];

  } 
}

//constructor copia
Matriz::Matriz(const Matriz &m){

  this->n_filas = m.n_filas; //pregunta flecha y columnas
  this->n_columnas = m.n_columnas; 

  for(int i = 0; i<this->n_filas; i++){
    for(int j = 0; j<this->n_columnas; j++){

      this->matriz[i][j] = m.matriz[i][j];

    }
  }
}

//destructor
Matriz::~Matriz(){

  for(int i = 0; i<this->n_filas; i++){

    delete[] matriz[i];
  
  }

  delete[] matriz;

}

//suma
Matriz Matriz::operator+ (const Matriz &m){

  assertdomjudge(n_filas == m.n_filas && n_columnas==m.n_columnas);

  Matriz nuevaMatriz(this->n_filas, this->n_columnas);

  for(int i = 0; i<this->n_filas; i++){
    for(int j = 0; j<this->n_columnas; j++){

      nuevaMatriz.matriz[i][j] = this->matriz[i][j] + m.matriz[i][j];

    }
  }

  return nuevaMatriz;
}

Matriz Matriz::operator* (const double num){

  Matriz nuevaMatriz(this->n_filas, this->n_columnas);

  for(int i = 0; i<this->n_filas; i++){
    for(int j = 0; j<this->n_columnas; j++){

      nuevaMatriz.matriz[i][j] = this->matriz[i][j] * num;

    }
  }

  return nuevaMatriz;

}

Matriz Matriz::operator* (const Matriz &m){

  assertdomjudge(n_filas == m.n_filas && n_columnas==m.n_columnas);

  Matriz nuevaMatriz(this->n_filas, m.n_columnas);

  for(int i = 0; i<this->n_filas; i++){
    for(int j = 0; j<this->n_columnas; j++){

      nuevaMatriz.matriz[i][j] = this->matriz[i][j] * num;

    }
  }

  return nuevaMatriz;

}


//Asignacion de matrices
Matriz& Matriz::operator= (const Matriz &m)
{
  if(matriz!=NULL)
    {
      for (int i = 0; i < n_filas; i++)
	delete[] matriz[i];
      
      delete[] matriz;
      matriz=NULL;
    }

  this->n_filas=m.n_filas;
  this->n_columnas=m.n_columnas;
  this->matriz=NULL;
  if(n_filas>0 && n_columnas>0)
    {
      matriz= new double *[n_filas];
  
      for (int i = 0; i < n_filas; i++)
	{
	  matriz[i] = new double[n_columnas];  
	  for(int j=0; j <n_columnas; j++)
	    matriz[i][j]=m.matriz[i][j];
	}
    }
  
    return(*this); 
}


// Leer matriz
void Matriz::rellenarManual()
{
  double elemento;
  for (int i = 0; i < n_filas; i++)
    {
      cout << "Fila " << i << endl;
      for (int j = 0; j < n_columnas; j++)
	{
	  cout << "Elemento " << j  << endl;
	  cin >> elemento;
	  matriz[i][j] = elemento;
        }
      cout << endl;
    }
  
}

// Rellenar Matriz Aleatoria
void Matriz::rellenarAleatorio(long seed)
{
  srand(seed);
  for (int i = 0; i < n_filas; i++)
    for (int j = 0; j < n_columnas; j++)
      matriz[i][j]=rand();
  
}



// Imprimir Matriz
void Matriz::mostrarMatriz()
{
  for (int i = 0; i < n_filas; i++)
      {
	for (int j = 0; j < n_columnas; j++)
	  cout << matriz[i][j] << " ";       
        cout << endl;
    }
}

