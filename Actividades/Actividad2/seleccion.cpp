#include<iostream>
using namespace std;

void ordenarSeleccion(int x[],int len)
{

/* El algoritmo de seleccion recorre el array y encuentra el elemento más pequeño
   y lo va colocando en el último índice del array ordenado que se encuentra al inicio del array. 

	   Precondicion: Ninguna
	   Complejidad Temporal: T(n) = n^2/2 + n/2 + 1
     Orden de Complejidad: O(n^2)
	   Complejidad Espacial: M(1) 
  */
  int min = 0;
  int aux;

  for(int i=0;i<len;i++)
    {

      min = i; //se da por hecho que al principio el valor minimo es la primera posicion
      for(int j = i+1; j<len; j++){ //empieza contando de la 2nda posicion

          if(x[j] < x[min]){ //j es flecha q indica posicion que estamos, x[min] es el numero min encontrado en el array

            min = j; //guarda posicion de nuevo numero min           //recorre el array para buscar el numero menor
                                                                    // comparando j (indicador de posicion) con el supuesto valor min
          }      
      }

      aux = x[i]; //primera posicion del array (o las siguientes)
      x[i] = x[min]; //guarda valor q esta en posicion min en primera posicion de array (o la consecuente a medida que se itera i)
      x[min] = aux; // guarda lo que habia en la primera o consecuente posicion en donde estaba localizado el minimo anteriormente

      /*No tener en cuenta el siguiente bucle de impresion  para el calculo de la complejidad*/
      for(int k=0;k<len;k++)
	cout<<x[k]<<" ";
      cout<<endl;
    }  
}



int main()
{
 int n;
 cin>>n;
 int *x=new int[n];
 for(int i=0;i<n;i++)
   cin>>x[i];
 ordenarSeleccion(x,n);
}

