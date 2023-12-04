#include<bits/stdc++.h>
using namespace std;

const int N = 1e3+5;
int adjas[N][N];
int main(){
    int n,m,w;
    cin>>n>>m;
    int u,v;
    for (int i = 0; i < m; i++)
    {
        cin>>u>>v>>w;
        adjas[u][v]=w;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout<<adjas[i][j]<<" ";
        }
        cout<<endl;
    
    }
    
    




    return 0;
}