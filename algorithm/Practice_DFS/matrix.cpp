#include<bits/stdc++.h>
using namespace std;

const int N = 1e3+5;
int a[N][N];
int main(){
  int n;
  cin>>n;
  int m =n;

  int u,v;
  for (int i = 0; i < m; i++)
  {
    cin>>u>>v;
    a[u][v]=1;
  }
    for (int i = 1; i <=n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    
    




    return 0;
}