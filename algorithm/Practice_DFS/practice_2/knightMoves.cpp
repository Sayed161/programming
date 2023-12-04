#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
const int INF = 1e5+3;
const int N = 1e2+5;
bool vis[N][N];
  int cnt;
  bool valid(int a,int b,int n,int m){
    return (a>=0 && b>=0 && a<n && b<m);
   }
   int dis[N][N];
vector<pii>path = {{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1},{-2,1}};

void bfs(int si,int sj,int di,int dj,int n,int m){
        queue<pii>q;
        q.push({si,sj});
        vis[si][sj]=true;
        dis[si][sj]=0;       
        while(!q.empty()){
            pii p = q.front();
            q.pop();
            int pi = p.first;
            int pj = p.second;
            for(int i=0;i<8;i++){
                pii pr = path[i];
                int ci = pr.first+pi;
                int cj = pr.second+pj;
                if(valid(ci,cj,n,m) && !vis[ci][cj]){
                  
                    vis[ci][cj]=true;
                     dis[ci][cj]=dis[pi][pj]+1;  
                    q.push({ci,cj});
                     
                }
               
            }
                    
        }



}


int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n,m;
        cin>>n>>m;
        int si,sj;
        cin>>si>>sj;
        int di,dj;
        cin>>di>>dj;
       
        int mn = INT_MAX;
        for(int i = 0;i<n;i++){
            for(int j=0;j<m;j++){
                vis[i][j]=false;
                dis[i][j]=-1;
            }
        }
         cnt=0;
         bfs(si,sj,di,dj,n,m);
        
       
        cout<<dis[di][dj]<<endl;
            
        

    }
    




    return 0;
}
