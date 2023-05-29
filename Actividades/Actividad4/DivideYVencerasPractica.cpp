#include <iostream>
using namespace std;
#define assertdomjudge(x) if(!(x)){std::cout<<"ERROR"<<std::endl;exit(0);}

int sumaArrayDyV(int inicio, int final, int * array);

int main(){

   int numMax;

    cout<<"Introduce el numero de elementos del array"<<endl;
    cin>>numMax;
    
    int *x=new int[numMax];

    int num;
    for(int i = 0; i<numMax; i++){

        cout<<"Introduce la posicion "<<i<<" del array"<<endl;    
        cin>>x[i];
    }

    for(int i = 0; i<numMax; i++){
        
        cout<<"Posicion: "<<i<<" Valor: "<<x[i]<<endl;
    }

    int resultado = sumaArrayDyV(0, numMax-1, x);
    cout<<"--> RESULTADO FINAL: "<<resultado<<endl;
}

int sumaArrayDyV(int inicio, int final, int * array){

    if(inicio==final){

        return array[inicio];
    }else{

        int medio = (inicio + final) / 2;
        
        cout<<endl;
        cout<<"INICIO: "<<inicio<<endl;
        cout<<"MEDIO: "<<medio<<endl;
        cout<<"FINAL: "<<final<<endl;
        cout<<endl;
        
        int x = sumaArrayDyV(inicio, medio, array);
        int y = sumaArrayDyV(medio+1, final, array);

        cout<<"X: "<<x<<endl; 
        cout<<"Y: "<<y<<endl;
        cout<<endl;

        return x+y;

    }


}