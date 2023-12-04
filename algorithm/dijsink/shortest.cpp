#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
vector<int>adj[N];
bool visited[N];
int level[N];
int parent[N];

void bfs(int s){

        queue<int>q;
       
        q.push(s);
        visited[s]=true;
           level[s]=0;
            parent[s]=-1;
        while(!q.empty()){
            int u = q.front();
            q.pop();
         
            for(int v: adj[u]){
                if(visited[v])continue;
                q.push(v);
                 level[v]=level[u]+1;

                visited[v]=true;
               parent[v]=u;
               
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
    
int s,d;
cin>>s>>d;
bfs(s);
cout<<level[d];
cout<<endl;

for (int i = 1; i <= n; i++)
{
    cout<<"Node's Parent "<<i<<":"<<parent[i]<<endl;
}

vector<int>path;
int cur = d;
while(cur != -1){
    path.push_back(cur);
    cur = parent[cur];
}
reverse(path.begin(),path.end());
for(int v: path){
    cout<<v<<" ";
}

    return 0;
}