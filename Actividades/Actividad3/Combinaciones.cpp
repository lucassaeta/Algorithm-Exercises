#include<iostream>
#define assertdomjudge(x) if(!(x)){std::cout<<"ERROR"<<std::endl;exit(0);}
using namespace std;


int factorial(int n){

    if(n<=1){

        return 1;
    }else{
        
        return n * factorial(n-1);
    }
}

int main()
{
 
 int n, r, comb;
 cin>>n>>r;
 
 while(n>=0 && r>=0){
 assertdomjudge(n>=r);
 
 int factN = factorial(n);
 int factR = factorial(r);
 int factNR = factorial(n-r);

 comb = factN / (factR * factNR);

 cout<<comb<<endl;
  
 cin>>n>>r;

 }

}
