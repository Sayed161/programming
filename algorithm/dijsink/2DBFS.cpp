#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+5;
bool vis[N][N];
int dis[N][N];
typedef pair<int,int>pi;
vector<pi>path = {{-1,0},{1,0},{0,1},{0,-1}};
int n,m;
bool valid(int a,int b){
    if(a>=0 && a<n && b>=0 && b<m) return true;
    else return false;
}
void bfs(int si,int sj){
    queue<pi>q;
    q.push({si,sj});
    dis[si][sj]=0;
    vis[si][sj]=true;
    while(!q.empty()){
            pi parent = q.front();
            int Pi = parent.first;
            int Pj = parent.second;
            q.pop();
             
            for (int i = 0; i < 4; i++)
            {
                    pi p = path[i];
                    int ci = p.first+Pi;
                    int cj = p.second+Pj;
                    if(valid(ci,cj)&& !vis[ci][cj]){
                         vis[ci][cj]=true;
                         q.push({ci,cj});
                         dis[ci][cj]=dis[Pi][Pj]+1;
                    }
            }
            
    }
}

int main(){
    
    
    cin>>n>>m;
    char a[n][m];
     
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
            {
      cin>>a[i][j];
             }
    }
    
        int si,sj;
        cin>>si>>sj;
        bfs(si,sj);

 for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
            {
      cout<<dis[i][j]<<" ";
       }
       cout<<endl;
    }

    return 0;
}