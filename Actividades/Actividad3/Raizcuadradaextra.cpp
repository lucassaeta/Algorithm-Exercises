#include <iostream>
#include <math.h>
#include <cstdlib>
#define assertdomjudge(x) if(!(x)){std::cout<<"ERROR"<<std::endl;exit(0);}
using namespace std;


float calculaRaiz(float num, float numIzq, float numDer, float error){

    float numMedio = (numIzq + numDer) / 2;
    
    if(abs((pow(numMedio, 2) - num)) < error){ //caso base

        return numMedio;

    }else if(pow(numMedio, 2) < num){ //mitad hacia derecha

        cout<<numMedio<<endl;
        return calculaRaiz(num, numMedio, numDer, error);

    }else if(pow(numMedio, 2) > num){ //mitad hacia izq

        cout<<numMedio<<endl;
        return calculaRaiz(num, numIzq, numMedio, error);

    }
}

int main(){

    float num, error;
    float numMedio = num/2;

    cin >> num >> error;

    float res = calculaRaiz(num, 0, num, error);

    cout<<res<<endl;


}