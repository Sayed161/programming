#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+5;
vector<int>adj[N];
bool visited[N];
int level[N];

void bfs(int u){
    queue<int>q;
    q.push(u);
    level[u]=0;
    visited[u]=true;
    while(!q.empty()){
        int a = q.front();
        q.pop();
        
        for(int v: adj[a]){
            if(visited[v])continue;
            q.push(v);
            visited[v]=true;
            level[v]=level[a]+1;
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
    int l;
    cin>>l;
   bfs(0);
   bool nodes = false;
  for (int i = 0; i <= n; i++)
  {
    if(level[i]==l){
       cout<<i<<" ";
       nodes = true;
    }
    
  }
if(!nodes){
    cout<<"-1";
}


    return 0;
}