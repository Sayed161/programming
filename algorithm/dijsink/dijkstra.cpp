#include<bits/stdc++.h>
using namespace std;


typedef pair<int,int>pii;
const int N = 1e3+5;
const int F = 1e9+10;
vector<pii>adj[N];
vector<bool>visited(N+1);
vector<int> dist(N+1,F);




void dij(int source){ 
 
    priority_queue<pii,vector<pii>,greater<pii>>pq;

     dist[source]=0;

     pq.push({dist[source],source});

     while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
         if(visited[u]) continue;
        visited[u]= true;

        for(pii pro: adj[u]){
                int v = pro.first;
                int w = pro.second;

               
   
                if(dist[u]+w <dist[v]){

                    dist[v] = dist[u]+w;
                  
                    pq.push({dist[v],v});
                     
                }
        }
     }
}

int main(){
    
   
 int n,m;
  cin>>n>>m;

  int u,v,w;
  for (int i = 0; i < m; i++)
  {
    cin>>u>>v>>w;
    adj[u].push_back({v,w});
    adj[v].push_back({u,w});
    
  }  
  int t;
  cin>>t;
  dij(1);
  while(t--){
      int s,d;
      cin>>s>>d; 
         cout<<dist[d]<<endl;

  }
  



    


    return 0;
}