#include "Matriz.h"
#include <iostream>
#include<math.h>
#include<stdlib.h>
#define assertdomjudge(x) if(!(x)){std::cout<<"ERROR"<<std::endl;exit(0);}

Matriz::Matriz(){ //:: pertenece a 

  this->n_filas = 0;
  this->n_columnas = 0; 
  this->matriz = NULL; 

}

Matriz::Matriz(int n_filas, int n_columnas){
  
  this->n_filas=n_filas; 
  this->n_columnas = n_columnas; 
  this->matriz = NULL;
  //deberá reservar de forma dinámica espacio suficiente para
  //poder almacenar una matriz con las dimensiones solicitadas. 
  
    matriz = new double *[n_filas]; //reserva numero filas 

  for(int i = 0; i < n_filas; i++){

    matriz[i] = new double[n_columnas]; //para cada elemento de cada fila reservas doubles de los numeros de columnas que haya 

  }

}

Matriz::Matriz(const Matriz &m){

  this->n_filas = m.n_filas; 
  this->n_columnas = m.n_columnas;
  //deberá inicializar su matriz con las mismas
  //dimensiones que las indicadas por el parámetro
  this->matriz = m.matriz; 
}

Matriz::~Matriz(){

  //liberar la memoria que fue
  //reservada de forma dinámica para almacenar la matriz.
  for(int i = 0; i < n_filas; i++){

    delete[] matriz[i]; //borra cada espacio reservado para cada valor de la matriz 

  }
  delete[] matriz; //borra las filas de la matriz 

}

//Asignacion de matrices

Matriz Matriz::operator+ (const Matriz &m){

  assertdomjudge(n_filas == m.n_filas && n_columnas==m.n_columnas);
  Matriz m3(m.n_filas, m.n_columnas);

  for(int i = 0; i<n_filas; i++){
    for(int j = 0; j<n_columnas; j++){

      m3.matriz[i][j] = this->matriz[i][j] + m.matriz[i][j];
    }
  }

  return m3;
}

Matriz Matriz::operator- (const Matriz &m){

  assertdomjudge(n_filas == m.n_filas && n_columnas==m.n_columnas);
  Matriz m3(m.n_filas, m.n_columnas);

  for(int i = 0; i<n_filas; i++){
    for(int j = 0; j<n_columnas; j++){

      m3.matriz[i][j] = this->matriz[i][j] - m.matriz[i][j];
    }
  }

  return m3;
}

Matriz Matriz::operator* (const double num){

  Matriz m3(n_filas, n_columnas);
  
  for(int i = 0; i<this->n_filas; i++){
    for(int j = 0; j<this->n_columnas; j++){

        m3.matriz[i][j] = this->matriz[i][j] * num;
    }
  }

  return m3;
}


Matriz Matriz::operator* (const Matriz &m){

  assertdomjudge(n_columnas == m.n_filas);
  Matriz m3(n_filas, m.n_columnas);
  double suma;

  for(int i = 0; i<this->n_filas; i++){
    for(int j = 0; j<m.n_columnas; j++){
      
    suma = 0;

      for(int x = 0; x<this->n_columnas; x++){

      suma += this->matriz[i][x] * m.matriz[x][j];

      }
    
    m3.matriz[i][j] = suma;

    }
  }

  return m3;
}

Matriz Matriz::calcularTraspuesta(){

Matriz mTras(n_columnas,n_filas);

  for(int i = 0; i<this->n_filas; i++){
    for(int j = 0; j<this->n_columnas; j++){

        mTras.matriz[j][i] = this->matriz[i][j];

    }
  }

return mTras;
}

bool Matriz::esSimetrica(){

  if (n_filas != n_columnas){
    return false;
  }

  for(int i = 0; i<this->n_filas; i++){
    for(int j = 0; j<this->n_columnas; j++){

        if(this->matriz[i][j] != matriz[j][i]){
         return false;
        }
    }
  }

  return true;
}

double Matriz::obtenerMaximo(){

  double max = matriz[0][0];

  for(int i = 0; i<this->n_filas; i++){
    for(int j = 0; j<this->n_columnas; j++){

       if(this->matriz[i][j] > max){
         
         max = this->matriz[i][j];
         
       }

    }
  }

  return max;
}

double Matriz::obtenerMinimo(){

  double min = matriz[0][0];

  for(int i = 0; i<this->n_filas; i++){
    for(int j = 0; j<this->n_columnas; j++){

       if(this->matriz[i][j] < min){
         
         min = this->matriz[i][j];
         
       }

    }
  }

  return min;
}

double Matriz::calcularDeterminante(){

    assertdomjudge(n_filas == n_columnas);
    for(int i = 0; i<n_columnas; i++){
        
        

    }

/*
    

        return (this->matriz[0][0] * this->matriz[1][1]) - (this->matriz[0][1] * this->matriz[1][0]);

    


    }

*/
    
}

Matriz& Matriz::operator= (const Matriz &m) // lo que devuelve , de donde pertenece :: nombre clase
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


