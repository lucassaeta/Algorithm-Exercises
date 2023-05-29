#include <iostream>
#include <string.h> 
#define assertdomjudge(x) if(!(x)){std::cout<<"ERROR"<<std::endl;exit(0);}
#define TAMMAX 20
using namespace std;


bool palindromo(char string[], int i, int tamCadena){
 
    if(i>=tamCadena){  //ha ido comparando letra a letra sin fallar hasta que ha llegado a la mitad (si es impar) o i (indicador inicio) 
                      //ha sobrepasado a tamCadena (indicador ultima posicion) en el caso de que sea par
          
        //cout<<"Es palindromo"<<endl;
        return true;
    }

        if(string[i] == string[tamCadena-1]){
            
            return palindromo(string, i+1, tamCadena-1);
        
        }
        else{
            
          // cout<<"No es palindromo"<<endl;
           return false; 
        }   

}

int main(){

    char string[TAMMAX];
    cin>>string;
    int tamCadena = strlen(string);  
    bool palin;
    
    palin = palindromo(string, 0, tamCadena);

   if(palin == true){

      cout<<1<<endl;
    }else{

      cout<<0<<endl;

    } 
}