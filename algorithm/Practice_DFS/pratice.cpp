#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
vector<int>adj[N];
bool visited [N];
void dfs(int u){
        visited[u]= true;
        for(int j : adj[u]){
               
                if(visited[j]== false){
cout<<"Visited "<<u<<"\n";
                dfs(j);

                }
                 
        }

}

int main(){
  int n,m;
  cin>>n>>m;

  int u,v;
    for (int i = 0; i < m; i++)
    {
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
dfs(1);
    




    return 0;
}