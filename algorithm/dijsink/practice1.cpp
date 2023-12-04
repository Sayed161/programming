#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
const int N = 1e3+5;
const int INF = 1e9+10;
vector<pii>g[N];
vector<bool>visited(N);
vector<int>level(N,INF);


void bfs(int s){
    priority_queue<pii,vector<pii>,greater<pii>>q;
    level[s]=0;
    q.push({level[s],s});
    while(!q.empty()){
        int u = q.top().second;
        q.pop();
         if(visited[u])continue;
        visited[u]=true;
        for(pii vpair : g[u]){
                int v = vpair.first;
                int w = vpair.second;
               
                if(level[u]+w <level[v]){
                    level[v]=(level[u]+w);
                    q.push({level[v],v});
                }
        }   
    }

    


}


int main(){
    
    int n,m;
    cin>>n>>m;
    for (int i = 0; i < m; i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        
    }
    
        int s,d;
        cin>>s>>d;

        bfs(s);
 

        cout<<level[d]<<endl;




    return 0;
}