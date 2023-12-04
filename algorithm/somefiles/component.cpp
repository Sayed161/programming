#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+5;
vector<int>adj[N];
bool visited[N];
int level[N];
int depth[N];
queue<int>q;
priority_queue<int,vector<int>,greater<int>>q2;
void dfs(int u){
        
        
        visited[u]= true;
         q.push(u);
        for(int v : adj[u]){
          
              if(visited[v]== true) continue;
                q.push(v);
              dfs(v);
             
        }


}

void bfs(int c){
        int m =0;
    queue<int>q;
    q.push(c);
    int k = 0;
    visited[c]= true;
    
    while(!q.empty()){

        int u = q.front();
        
        q.pop();
        k++;
          
        for(int v: adj[u]){
            if(visited[v]== true) continue;
                    q.push(v);
                   
                    visited[v]= true;
                    
            
        }
    }
q.push(k);

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
    
for(int i=0;i<=n;i++){
         
        if(!visited[i]){
                bfs(i);
             cout<<q.size();
                    q.empty();
        } 
        for(int i;i<=n;i++){
            visited[i]=false;
        }   
       
}
 

    return 0;
}