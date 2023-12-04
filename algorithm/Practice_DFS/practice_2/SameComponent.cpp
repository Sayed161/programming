#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+5;
bool vis[N][N];
  int n,m;

  char s[N][N];
  bool valid(int a,int b){
    return (a>=0 && b>=0 && a<n && b<m && s[a][b]=='.');
  
  }
vector<pair<int,int>>path = {{1,0},{-1,0},{0,1},{0,-1}};
bool bfs(int si,int sj,int di,int dj){
        queue<pair<int,int>>q;
        q.push({si,sj});
        vis[si][sj]=true;
          
        while(!q.empty()){
            pair<int,int>p = q.front();
            q.pop();
            int pi = p.first;
            int pj = p.second;
            for(int i=0;i<4;i++){
                pair<int,int>pr = path[i];
                int ci = pr.first+pi;
                int cj = pr.second+pj;
                if(valid(ci,cj) && !vis[ci][cj] ){
                    if(ci==di && cj == dj){
            return true;
        }            vis[ci][cj]=true;
                    q.push({ci,cj});
                }
            }
        }
return false;
       
        
}

int main(){
  cin>>n>>m;
  for(int i = 0;i<n;i++){
    for(int j = 0;j<m;j++){
        cin>>s[i][j];
    }
  }  
    int si,sj,di,dj;
    cin>>si>>sj;
    cin>>di>>dj;
    if(si==di && sj == dj){
          cout<<"YES"<<endl;
    }
  else if(bfs(si,sj,di,dj)){
    cout<<"YES"<<endl;
   } 
   else{
    cout<<"NO"<<endl;
   }



    return 0;
}