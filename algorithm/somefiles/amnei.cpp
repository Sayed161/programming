
#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+5;
vector<int>adj[N];
bool visited[N];
priority_queue<int,vector<int>,greater<int>>k;
void dfs(int u){
    int c=0;
   
        visited[u]= true;
             c++;
        for(int v: adj[u]){
           
            if(visited[v]) continue;
        
            dfs(v);
        }
    k.push(c);
  

}

void bfs(int u){

        queue<int>q;
        q.push(u);
        visited[u]=true;
    
        while(!q.empty()){
                int u = q.front();
                q.pop();
                for(int v: adj[u]){
                    if(visited[v])continue;
                 
                    q.push(v);
                    visited[v]= true;
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
    int cc=0;
    for (int i = 1; i <=n ; i++)
    {
        if(visited[i])continue;
        cc++;
        cout<<"Component "<<cc<<":";
        dfs(i);
        cout<<k.size();
        
        cout<<endl;
        
        
    }
    

   


    return 0;
}