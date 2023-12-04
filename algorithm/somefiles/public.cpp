#include<bits/stdc++.h>
using namespace std;



int main(){
    const int N = 1e3+5;
vector<int>adjas[N];
    int n,m;
    cin>>n>>m;
    int u,v,w;
    for (int i = 0; i < m; i++)
    {
        cin>>u>>v;
        adjas[u].push_back(v);
        adjas[v].push_back(u);
    }
  for (int i = 1; i <= n; i++)
  {
   
    for(auto j: adjas[i]){
        cout<<i<<"->"<<j;
    }
    cout<<endl;
  }
  
    
    




    return 0;
}