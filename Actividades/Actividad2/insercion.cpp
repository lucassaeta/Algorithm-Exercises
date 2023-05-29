#include<iostream>
using namespace std;

void ordenarInsercion(int x[],int len)
{
 
   /* El algoritmo de insercion recorre el array y compara cada posicion con su anterior para ver si habria que realizar un cambio
      cuando se cumpla la condicion de que el numero de la izquierda sea mayor. Si es asi, los intercambia y vuelve a compararlo
      con el valor de la izquierda hasta que no hayan mas o no se cumpla la condicion. 

	   Precondicion: Ninguna
	   Complejidad Temporal: T(n) = n^2/2 + n/2 + 1
     Orden de Complejidad: O(n^2)
	   Complejidad Espacial: M(1) 
  */

  int posicionActual, aux;

  for(int i=1;i<len;i++)
    {

      posicionActual = i; //flechita que recorre array indicando posicion en la que estamos situados 
      aux = x[i]; //guarda por el numero que vamos, no la posicion

      while(x[posicionActual-1] > aux){      //si numero a la izquierda es mayor que el numero actual
         
        x[posicionActual] = x[posicionActual-1]; //intercambio de dichos numeros en el caso de que num a la izq sea mayor que num derecha
        posicionActual--; //disminuye para ir comprobando que num izq es mayor a actual para todas las iteraciones hacia atras hasta la posicion primera

      }

      x[posicionActual] = aux; //para que vaya refrescando en que numero vamos (lo mete en su posicion correcta una vez encontrada) 
      
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
 ordenarInsercion(x,n);
}


