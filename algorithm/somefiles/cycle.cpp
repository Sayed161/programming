#include<bits/stdc++.h>
using namespace std;

const int N = 1e3+5;
vector<int>adj[N];
bool visited[N];
bool dfs(int u,int p){
        bool cycle = false;
       visited[u]= true;

        
       for(int v: adj[u]){
        if(v==p) continue;
        if(visited[v]) return true;
        cycle |= dfs(v,u);
       }
       return cycle;


}

void bfs(int u){

    queue<int>q;
    q.push(u);
    visited[u]= true;
    while(!q.empty()){
            int p = q.front();
            q.pop();
            for(int j: adj[p]){
                if(visited[j]== true) continue;
                q.push(j);
                visited[j]= true;
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
    //***For same nodes**//
    // if(dfs(1,-1)){
    //     cout<<"YES"<<endl;
    // }
    // else{
    //     cout<<"NO"<<endl;
    // }
        bool cycle = false;
    //**For different nodes**//
    for (int i = 1; i <= n; i++)
    {
        if(visited[i]) continue;
        cycle |= dfs(i,-1);
    }
    
 if(cycle){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }

    return 0;
}