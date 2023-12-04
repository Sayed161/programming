#include<bits/stdc++.h>
using namespace std;


int main(){
 int n;
 cin>>n;
  int cnt=0;
 while (n--)
 {
   int x,y,z;
  
   cin>>x>>y>>z;
   if(x==1 && y==1){
      cnt++;
   }
   else if(x==1 && z==1){
    cnt++;
   }
   else if(y==1 && z==1){
    cnt++;
   }
   
  
 }
 cout<<cnt;
    

    




    return 0;
}