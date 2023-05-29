#include<iostream>
using namespace std;

void ordenarBurbuja(int x[],int len)
{

  /* El algoritmo burbuja realiza la comparación repetida de elementos adyacentes e implementa un intercambio si están 
  en el orden incorrecto (derecha menor que izquierda). Recorre el array de elementos un numero de veces intercambiando 
  estos elementos hasta que el array queda ordenado. 

	   Precondicion: Ninguna
	   Complejidad Temporal: T(n) = n^2/2 + n/2 + 1
     Orden de Complejidad: O(n^2)
	   Complejidad Espacial: M(1) 
  */




  int posActual, posIzq, aux;
  for(int i=1;i<len;i++) //for para hacer las comparaciones el numero de veces por cada valor del array
    {
      for(int j = 1; j<len; j++){ // sirve para coger un valor y va comparandolo y moviendolo acorde al if
      
      posActual = j; //flecha indicando el numero de la posicion actual
      posIzq = j-1; //el numero de la izq del numero indicado actual
      
        if(x[posActual] < x[posIzq]){ //comparacion si el numero actual es menor al de la izquierda

            aux = x[posIzq]; 
            x[posIzq] = x[posActual];  //intercambio de valores para cambiar segun el if
            x[posActual] = aux;
      }
    }  
  
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
 ordenarBurbuja(x,n);
}
