#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int dis[N];
bool visited[N];
  vector<int>adj[N];


void bfs(int src){
        queue<int>q;
        q.push(src);
        visited[src]=true;
        dis[src]=0;
        while(!q.empty()){
                    int parent = q.front();
                    q.pop();
                    // cout<<parent<<endl;
        for(int i = 0;i<adj[parent].size();i++){
             int child = adj[parent][i];
             if(visited[child]==false){
                q.push(child);
                dis[child]= dis[parent]+1;
                visited[child]=true;
             }
         }


        }
}

int main(){
  int n,e;
  cin>>n>>e;


  while(e--){
    int a,b;
    cin>>a>>b;
    adj[a].push_back(b);
    adj[b].push_back(a);

  }  
    bfs(1);
for (int i = 1; i <= n; i++)
{
    cout<<"Node values"<<i<<": "<<dis[i]<<endl;
}




    return 0;
}