#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5;
vector<int>adj[N];
int depth[N];
int height[N];
bool visited[N];
void dfs(int u){
        visited[u]= true;
      
        for(int v : adj[u]){
          
            cout<<"visited "<<u<<"\n";
              if(visited[v]== true) continue;
              // depth[v]=depth[u]+1;
              dfs(v);
              // if(height[v]+1>height[u]){
              //   height[u]=height[v]+1;
              // }
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
  //    for (int i = 1; i <= n; i++)
  // {
   
  //   cout<<"Depth of:"<<i<<"-"<<depth[i]<<endl;
  // }
  //   cout<<"****************************\n";
  // for (int i = 1; i <= n; i++)
  // {
   
  //   cout<<"height of:"<<i<<"-"<<height[i]<<endl;
  // }



    return 0;
}