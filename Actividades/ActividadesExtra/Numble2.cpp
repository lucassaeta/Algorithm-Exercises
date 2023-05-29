#include <iostream>
using namespace std;

void numble(int *comb, int *incs, int x, int suma, int indice){

    if(suma == x){

        int ind = 0;
        for(int i = 0; i < 4; i++){

            if(comb[i] == -1){

                comb[i] = incs[ind];
                ind++;
            }
            
            
            cout<<comb[i]<<" ";

        }

        cout<<endl;
    }else{

        if(suma < x){

            for(int i = 1; i < x; i++){

                suma+=i;

                if(suma == x){
                    incs[indice] = i;

                    numble(comb, incs, x, suma, indice+1);
                    incs[indice] = 0;
                }
                
                suma-=i;
            }
        }
    }
}



int main(){

    int x; 
    int suma;
    int *arrayNums = new int[4];
    int numInc = 0;

    cin>>x;

    cin>>arrayNums[0]>>arrayNums[1]>>arrayNums[2]>>arrayNums[3];

    for(int i = 0; i < 4; i++){

        if(arrayNums[i] == -1){

            numInc++;
        }else{

            suma += arrayNums[i];
        }
    }

    int *incs = new int[numInc];

    numble(arrayNums, incs, x, suma, 0);



}