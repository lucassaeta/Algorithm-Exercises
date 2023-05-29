#include<iostream>
using namespace std;
#define assertdomjudge(x) if(!(x)){std::cout<<"ERROR"<<std::endl;exit(0);}
#define TAMMAX 10



int main(){

 int matriz[10][10];
   
   
   for(int i = 0; i<TAMMAX; i++){
      for(int j = 0; j<TAMMAX; j++){

         matriz[i][j] = 0;
      }
   }

   matriz[0][0] = 1;

   for(int i = 1; i<TAMMAX; i++){
      for(int j = 0; j<TAMMAX; j++){
         if(j == 0){
            
            matriz[i][j] = 1;
         }else{
            
            matriz[i][j] = matriz[i-1][j-1] + matriz[i-1][j];
         }
      }
   }

/*
  for(int i = 0; i<TAMMAX; i++){
     cout<<endl;
      for(int j = 0; j<TAMMAX; j++){

         cout<<matriz[i][j]<<" ";
      }
   }
*/

 int n, r;
 cin>>n>>r;

 while(n>=0 && r>=0){
  
  assertdomjudge(n>=r);

  cout<<matriz[n][r]<<endl;
  cin>>n>>r;

 }

}