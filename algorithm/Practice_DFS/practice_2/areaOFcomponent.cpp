#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
const int N = 1e3+5;
bool vis[N][N];
  int n,m,cnt;
  char s[N][N];
  bool valid(int a,int b){
    return (a>=0 && b>=0 && a<n && b<m && s[a][b]=='.');
  
  }
vector<pii>path = {{1,0},{-1,0},{0,1},{0,-1}};
void bfs(int si,int sj){
        queue<pii>q;
       
        q.push({si,sj});
         
        vis[si][sj]=true;
         
        while(!q.empty()){
            pair<int,int>p = q.front();
            q.pop();
            int pi = p.first;
            int pj = p.second;
            for(int i=0;i<4;i++){
                pii pr = path[i];
                int ci = pr.first+pi;
                int cj = pr.second+pj;
                if(valid(ci,cj) && !vis[ci][cj] ){
                     cnt++;
                            vis[ci][cj]=true;
                            q.push({ci,cj});
                           
                }
            }
        }

       
        
}

int main(){

     cin>>n>>m;
  for(int i = 0;i<n;i++){
    for(int j = 0;j<m;j++){
        cin>>s[i][j];
       
    }
  }  

int mn= INT_MAX;
 for(int i = 0;i<n;i++){
    for(int j = 0;j<m;j++){
       if(!vis[i][j] && s[i][j]=='.'){
         cnt=1;
        bfs(i,j);
        mn = min(cnt,mn);
       }
    }
  } 

if(mn==INT_MAX){
    cout<<"-1"<<endl;
}
else{
    cout<<mn<<endl;
}


    return 0;
}