#include<iostream>
using namespace std;
#define assertdomjudge(x) if(!(x)){std::cout<<"ERROR"<<std::endl;exit(0);}
#define TAMMAX 10

void combinacionesSuma(int num, int *combinaciones, int suma);

int main(){

    int num;
    int combinaciones[TAMMAX];
    int suma = 0;

    cout<<"Introduce el numero del cual quieres sacar combinaciones de sumas"<<endl;
    cin>>num;

    combinacionesSuma(num, combinaciones, suma);

    return 0;
}

void combinacionesSuma(int num, int *combinaciones, int suma){

    if(suma == num){

        for(int i = 0; i < TAMMAX; i++){
            cout<<combinaciones[i]<<" + ";
        }

    cout<<endl;
    
    }else{

        for (int i = 1; i <= num; i++){
            
            suma+= i;

            if(suma <= num){

                combinaciones[i-1] = i;
                combinacionesSuma(num, combinaciones, suma);
                combinaciones[i-1] = 0;
            }
            suma-= i;
        }
        
    }

}

