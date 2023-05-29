#include <iostream> 
#include <string.h>
using namespace std;
#define assertdomjudge(x) if(!(x)){std::cout<<"ERROR"<<std::endl;exit(0);}
#define TAMMAX 25

bool esPalindromo(char string[], int indIzq, int indDer){

    if(indIzq>=indDer){ //condicion base

        return true;
    }else{

        if(string[indIzq] == string[indDer]){

            esPalindromo(string, indIzq+1, indDer-1);
        }else{

            return false;
        }
    }
}

int main(){

    char palabra[TAMMAX]; 

    cin>>palabra;
    
    int length = strlen(palabra);

    bool palindromo = esPalindromo(palabra, 0, (length-1));

    if(palindromo == true){

        cout<<1<<endl;

    }else{

        cout<<0<<endl;
    }
    
}
