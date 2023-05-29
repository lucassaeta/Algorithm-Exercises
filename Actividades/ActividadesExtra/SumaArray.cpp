#include <iostream>
using namespace std;

//divide y venceras
int sumaArray(int *arrayNums, int longitud){

    if(longitud==1){

        return arrayNums[0];
    }else{

        int mitad = longitud / 2; 

        int suma = sumaArray(arrayNums, mitad) + sumaArray(&arrayNums[mitad], longitud - mitad);

        return suma;
    }
}

int main(){

    int numElementos;
    cin>>numElementos; 

    int *array = new int[numElementos];

    for(int i = 0; i<numElementos; i++){

        int num; 
        cin>>num; 
        array[i] = num;
    }

   int suma =  sumaArray(array, numElementos);
   cout<<suma<<endl;
}