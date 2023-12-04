#include<bits/stdc++.h>
using namespace std;
const int N = 1e2+5;
vector<int>ad[N];
bool visited[N];
int level[N];
stack<int>s;
void bfs(int c){

    queue<int>q;
    q.push(c);
    visited[c]= true;
    
    while(!q.empty()){

        int u = q.front();
        s.push(u);
        q.pop();
        level[c]=0;
        
        for(int v: ad[u]){
            if(visited[v]== true) continue;
                    q.push(v);
                    visited[v]= true;
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
    ad[u].push_back(v);
    ad[v].push_back(u);
  }
  int k;
  cin>>k;
   bfs(1);
    
 
// for (int i = 1; i <= n; i++)
// {
         
       
     cout<<"Level of : "<<k<<":"<<level[k]<<" ";
        
        cout<<endl;
// }


    return 0;
}