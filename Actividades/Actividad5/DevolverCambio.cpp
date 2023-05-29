#include<iostream>
using namespace std;
#define assertdomjudge(x) if(!(x)){std::cout<<"ERROR"<<std::endl;exit(0);}
#define TAMMAX 8

int * devolverCambio(int pesetas, int * billetes);

int main(){

 int pasta;
 int billetes[TAMMAX] = {0, 0, 0, 0, 0, 0, 0, 0};

 cin>>pasta;
 
 while(pasta>=0){

    devolverCambio(pasta, billetes);
 
        for(int i = 0; i < TAMMAX; i++){

            cout<<billetes[i]<<" ";

        }
    
    cout<<endl;

        for(int i = 0; i < TAMMAX; i++){

            billetes[i] = 0;

        }
    
    cin>>pasta; 
    }
  return 0;
}

int * devolverCambio(int pasta, int * billetes){

    int pesetas[TAMMAX] = {500, 200, 100, 50, 25, 10, 5, 1};
    int cociente = 0;

    while(pasta>0){

        for(int i = 0; i<TAMMAX; i++){
            
            if(pasta / pesetas[i] > 0 ){
                
                cociente = pasta / pesetas[i]; 
                billetes[i] = billetes[i] + cociente;
                pasta -= pesetas[i] * cociente;

            }

        }

    }

    return billetes;
   
}

