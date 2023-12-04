#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+5;
vector<int>a[N];
int b[N][N];
int main(){
    
    int n,m;
    cin>>n>>m;
        int u,v;
    for (int i = 0; i < m; i++)
    {
        cin>>u>>v;
        b[u][v]=1;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout<<b[i][j]<<" ";
        }
        cout<<endl;
    }
    




    return 0;
}