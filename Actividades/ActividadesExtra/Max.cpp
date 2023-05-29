#include <iostream>
using namespace std;


int buscarMax(int* numeros, int indice){

    if(indice == 1){

        return numeros[0];
    }else{

        int mitad = indice/2; //para num impares
        int num1 = buscarMax(numeros, mitad);
        int num2 = buscarMax(&numeros[mitad], indice-mitad);

        if(num1>num2){

            return num1;
        }else if(num2>num1){

            return num2;
        }else{ //si son iguales

            return num1;
        }
    }
}

int main(){
    
    int n;
    cin >> n;
    int *numeros = new int[n+1];
    
    for(int i = 0; i<n; i++){
        int num;
        cin >> num;
        numeros[i]= num;
    }

   // numeros[n]=0;
    
  int max =  buscarMax(numeros,n);

  cout<<max<<endl;

}