#include <iostream>
using namespace std;

void formasSumarN(int *comb, int n, int suma, int indiceComb){

    if(suma == n){

        for(int i = 0; i < indiceComb; i++){

            cout<<comb[i]<<" ";
        }
        cout<<endl;
    }else{

        if(suma < n){

            for(int i = 1; i < n; i++){

                suma += i;
                comb[indiceComb] = i;
                formasSumarN(comb, n, suma, indiceComb+1);       //ANOTO, LLAMO, DESANOTO
                
                suma -= i;
                comb[indiceComb] = 0;
            }
        }
    }
}

int main(){

    int n;
    int *combinaciones; 

    cin>>n;
    combinaciones = new int[n];

    formasSumarN(combinaciones, n, 0, 0);

}