#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
vector<int>g[N];
vector<int>level(N,0);
vector<int>parent(N,-1);
bool visited[N];

 
    void bfs(int s){
            queue<int>q;
            q.push(s);
            visited[s]= true;
            level[s]= 0;
            while(!q.empty()){
                int u = q.front();
                q.pop();
                
                for (int v : g[u])
                {
                    if(visited[v])continue;
                    q.push(v);
                    visited[v]=true;
                    parent[v]=u;
                    level[v]=level[u]+1;

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
    g[u].push_back(v);
    g[v].push_back(u);
    
  }

bfs(1);
vector<int>path;
int curr = n;
while(curr != -1){
    path.push_back(curr);
    curr = parent[curr];
}
reverse(path.begin(),path.end());


if(level[n]==1){
    cout<<"IMPOSSIBLE";
}
else{
cout<<level[n]+1<<endl;
for(auto v: path){
    cout<<v<<" ";
}
}




    return 0;
}