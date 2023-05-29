#include<iostream>
#define assertdomjudge(x) if(!(x)){std::cout<<"ERROR"<<std::endl;exit(0);}
using namespace std;

int raizCuadrada(float num, float error, float numizq, float numderecha){

    float medio = (numizq + numderecha) / 2;
    float cuadrado = medio * medio;
    float calculacion = cuadrado - num; // por encima del numero que se quede corto(dos)
    float calculacion2 = num - cuadrado; // 2 - 2.25 por debajo del numero que se quede largo(dos)
    
    if(calculacion2 > error){ // por debajo
        
        cout<<medio<<endl;
        return raizCuadrada(num, error, medio, numderecha);    
    
    }else if(calculacion > error){ //por encima
        
        cout<<medio<<endl;
        return raizCuadrada(num, error, numizq, medio);
        
    }else{
        
        cout<<medio<<endl;
        return 0;

    }
}

int main()
{
 
 float num; 
 float numizq = 0;
 float error;
 float numderecha;

 cin>>num>>error;
 assertdomjudge(num>0);
 numderecha = num;
 raizCuadrada(num, error, numizq, numderecha);

}

