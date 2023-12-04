#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
const int N = 1e3+5;
bool vis[N][N];
  int cnt;
  char s[N][N];
  bool valid(int a,int b,int n,int m){
    return (a>=0 && b>=0 && a<n && b<m);
   }
vector<pii>path = {{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1}};
int bfs(int si,int sj,int di,int dj,int n,int m){
        priority_queue<pii,vector<pii>,greater<pii>>q;
       
        q.push({si,sj});
         
        vis[si][sj]=true;
         
        while(!q.empty()){
            pair<int,int>p = q.top();
            q.pop();
            int pi = p.first;
            int pj = p.second;
                if(pi==di && pj == dj){
            return cnt;
        } 
            for(int i=0;i<8;i++){
                pii pr = path[i];
                int ci = pr.first+pi;
                int cj = pr.second+pj;
                if(valid(ci,cj,n,m) && !vis[ci][cj] ){
                   
                     
                            vis[ci][cj]=true;
                            q.push({ci,cj});
                           
                }
            }
        }

    return -1;   
        
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
        cnt=0;
        int mn = INT_MAX;
        for(int i = 0;i<n;i++){
            for(int j=0;j<m;j++){
                vis[i][j]=false;
            }
        }
       int k =  bfs(si,sj,di,dj,n,m);
        
       
        cout<<k<<endl;
            
        

    }


    return 0;
}