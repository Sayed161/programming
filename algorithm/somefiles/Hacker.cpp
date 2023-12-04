#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+5;
vector<int>adj[N];
bool visited[N];
int level[N];
int depth[N];


int dfs(int u,int &de){
        visited[u]= true;
        de++;
        for(int v : adj[u]){
         
            // cout<<"visited "<<u<<"\n";
              if(visited[v]== true) continue;
              depth[v]=depth[u]+1;
              dfs(v,de);
              // if(height[v]+1>height[u]){
              //   height[u]=height[v]+1;
              // }
              
        }
      return de;
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
    
    for(int i=1;i<=n;i++){
        if(visited[i])continue;
        depth[i]=0;
     cout<<dfs(i,depth[i]);
        
        cout<<endl;
    }




    return 0;
}