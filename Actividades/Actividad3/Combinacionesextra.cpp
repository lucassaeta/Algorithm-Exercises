#include <iostream>
#define assertdomjudge(x) if(!(x)){std::cout<<"ERROR"<<std::endl;exit(0);}
using namespace std;

int factorial(int num){

    if(num == 1 || num == 0){

        return 1;

    }else{

        return num * factorial(num-1);
    }
}

int main(){
 
    int n, r, comb;
    cin>>n>>r;
    
    while(n>=0 && r>=0){
    
        assertdomjudge(n>=r);

        comb = factorial(n) / (factorial(r) * factorial(n-r));

        cout<<comb<<endl;
        
        cin>>n>>r;
    }
}