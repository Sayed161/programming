#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  int s=(n/2)+1;
  int k=1;
  for (int i = 1; i <= n; i++)
  {
    if(i<s){
       for (int j = 1; j <= k; j++)
        {
          cout<<"\\";
        }
        for (int j = 1; j <= s; j++)
        {
          cout<<" ";
        }
         for (int j = 1; j <= k; j++)
        {
          cout<<"/";
        }
 cout<<endl;
    s=s-2;
  }
   else if(i==s){
      for (int j = 1; j <= s; j++)
        {
          cout<<" ";
        }
      cout<<"X"<<endl;
    }
    else {
       s=s+2;
      for (int j = 1; j <= k; j++)
        {
          cout<<"/";
        }
        for (int j = 1; j <= s; j++)
        {
          cout<<" ";
        }
        for (int j = 1; j <= k; j++)
        {
          cout<<"\\";
        }
         cout<<endl;
   
    }
  }
    
    




    return 0;
}