#include<bits/stdc++.h>
using namespace std;

const int N = 1e3+5;
vector<int>adj[N];
bool visited[N];
int level[N];
priority_queue<int,vector<int>,greater<int>>k;


void dfs(int u,int &c){
   
    visited[u]=true;
   c++;
    for(int v:adj[u]){
        if(visited[v])continue;
            dfs(v,c);
          
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
    

int cc=0;
for (int i = 0; i <= n; i++)
{
    
    if(visited[i])continue;
    dfs(i,cc);
   cout<<cc;
   
}



    return 0;
}