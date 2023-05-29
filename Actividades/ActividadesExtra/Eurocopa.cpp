#include<iostream>
using namespace std;

char calcular_ganador(char *equipos, int n, int ronda){

    if(n == 1){
        
        return equipos[0];
    }else{

        int mitad = n / 2;
        char ganador1 = calcular_ganador(equipos, mitad, ronda+1);
        char ganador2 = calcular_ganador(&equipos[mitad], n - mitad, ronda+1);

        if(ronda % 2 == 0){

            cout<<"Ronda "<<ronda<<" Ganador "<<ganador1<<endl;;
            return ganador1;

        }else{

            cout<<"Ronda "<<ronda<<" Ganador "<<ganador2<<endl;
            return ganador2;
        }
    }
}

int main(){


 int n;
 cin >> n;
 char *equipos = new char[n+1];
 for(int i = 0;i <n; i++)
 	equipos[i]='A'+i;
 equipos[n]=0;
 
 calcular_ganador(equipos,n,0);
}
