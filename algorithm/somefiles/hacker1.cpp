#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+5;
vector<int>adj[N];
bool visited[N];
int level[N];


int bfs(int s,int d){

        queue<int>q;
        q.push(s);
        
        visited[s]=true;
           level[s]=0;
        if(s==d) return level[s];
        while(!q.empty()){
            int u = q.front();
            q.pop();
         
            for(int v: adj[u]){
                if(visited[v])continue;
                q.push(v);
                 level[v]=level[u]+1;
                visited[v]=true;
                  if(v==d) return level[v];
            }

        }
return -1;

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
    int q;
    cin>>q;
    while (q--)
    {
        int s,d;
        cin>>s>>d;
        int c= bfs(s,d);
        cout<<c<<"\n";
    }
    




    return 0;
}