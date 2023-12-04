#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
vector<int>g[N];

bool visited[N];

void dfs(int v){

        visited[v]=true;
        for(int i : g[v]){
            if(visited[i])continue;
            dfs(i);
        }


}

int main(){
    
    int n,m;
  cin>>n>>m;

  int u,v;
  for (int i = 0; i < m; i++)
  {
    cin>>u>>v;
    g[u].push_back(v);
    g[v].push_back(u);
    
  }  
vector<int>dis;
for(int i=1;i<=n;i++){
        if(visited[i])continue;
        dis.push_back(i);
        dfs(i);
}

cout<<dis.size()-1<<endl;

for (int i = 1; i < dis.size(); i++)
{
    cout<<dis[i-1]<<" "<<dis[i]<<endl;
}



    return 0;
}