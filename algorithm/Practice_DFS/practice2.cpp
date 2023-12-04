#include<bits/stdc++.h>
using namespace std;


int main(){
  int n;
  cin>>n;

  int a[n][n];

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
        cin>>a[i][j];
    }
    
  }
  int u,v;
    for (int i = 1; i <= n; i++)
    {
        cout<<"List "<<i<<":";
        for (int j = 1; j <= n; j++)
        {
            if(a[i][j]==1){
                cout<<j<<" ";
            }
            if(j==n){
            cout<<endl;
        }
        }
        
    }
    
    




    return 0;
}