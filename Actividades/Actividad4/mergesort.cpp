#include<iostream>
using namespace std;

void  combinar (int a[ ] , int len_a , int b[ ] , int len_b , int c[ ])
{
  /*Añadir código que permite combinar dos arrays */

  int ciA = 0; //sirve como contador y como indicador en que posicion estamos del array temporal
  int ciB = 0; //sirve como contador y como indicador en que posicion estamos del array temporal

  while(ciA + ciB != len_a + len_b){ //mientras que no se hayan ocupado todas las posiciones del array temporal

    if(ciA == len_a ){ //esto significa que el array/valor a  ha sido introducido, es decir era menor a b, entoces metemos b en la sig posicion

      c[ciA+ciB] = b[ciB]; //metemos en c[sig posicion, que seria 1 por el contador de a] el valor b
      ciB++; //e incrementamos contador b 

    }else if(ciB == len_b){ //esto significa que el array/valor b  ha sido introducido, es decir era menor a a, entoces metemos a en la sig posicion

      c[ciA+ciB] = a[ciA];
      ciA++;

    }else if(a[ciA] < b[ciB]){ //esto significa que a es menor que b

      c[ciA+ciB] = a[ciA]; //entoces metemos en c[0] a a, e incrementamos valor (por ej de la primera iteracion)
      ciA++;

    }else if(b[ciB] < a[ciA]){

      c[ciA+ciB] = b[ciB];
      ciB++;

    }else{ // si ambos valores son iguales

      c[ciA+ciB] = a[ciA]; //si son iguales ps metemos uno primero y el otro despues e incrementamos ambos valores 
      ciA++;
      
      c[ciA+ciB] = b[ciB];
      ciB++;

    }

  }

}


void ordenarMergeSort (int x[], int len){
  
  int temp[len]; //array c en donde vamos a ir almacenando el array ordenado
  int mitad = (len) / 2; //mitad
  
  if(len == 1){ //si el array es de/solo hay un solo valor
    
    return;
  }
  else
    {
      
      /*Ordenar dos mitades*/

      ordenarMergeSort(x, mitad); // parte a (desde inicio hasta final), empieza desde primera posicion array y el numero de valores es la mitad del de antes
      ordenarMergeSort(&x[mitad], len-mitad); //parte b (desde mitad hasta el final), & para que pase direccion no el valor que hay en esa posicion, numero de valores es el len menos los que se ha llevado la parte a

      /*Combinar ambas mitades y guardarlo en temp */

      //no llega aqui hasta que no sean arrays de 1 (hasta que no haya un return, como el ejemplo de factorial que hasta que no llega al final no corre las anteriores
      combinar (x, mitad, &x[mitad], len-mitad , temp); //envia parte a con su longitud y tamaño b con su longitud


      /*Copiar del array temporal al array resultado */
    for (int k = 0; k < len; k++){
      x[k] = temp[k];
      cout<<x[k]<<" ";
    }
      
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
 ordenarMergeSort(x,n);
}

