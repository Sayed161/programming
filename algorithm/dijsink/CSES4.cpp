#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+5;
 int n,m;
typedef pair<int,int> pii;
vector<string>g;
int visited[N][N];
int level[N][N];
pii parent[N][N];
vector<pii>dire = {{0,-1},{0,1},{-1,0},{1,0}};
bool isValid(int i,int j){
            return (i>=0 && i<n && j>=0 && j<m);


}
void bfs(int si,int sj){
        queue<pii>q;
        q.push({si,sj});
        visited[si][sj]=true;
        level[si][sj]=0;
        while(!q.empty()){
            pii u = q.front();
            q.pop();
            int i = u.first;
            int j = u.second;
            for(auto v : dire){
                int ni = i+v.first;
                int nj = j+v.second;
                if(!(isValid(ni,nj)) && visited[ni][nj] && g[ni][nj]=='#'){ 
                    continue;
                }
                q.push({ni,nj});
                visited[ni][nj] = true;
                level[ni][nj] = level[i][j]+1;
                parent[ni][nj] = {i,j};
            }
        }

}
int main(){
    int si,sj,di,dj;
     cin>>n>>m;
        for(int i=0;i<n;i++){
            string x;
            cin>>x;
            for (int j = 0; j < m; j++)
            {
                if(x[j]=='A'){
                    si=i;
                    sj = j;
                }
                else if(x[j]=='B'){
                    di = i;
                    dj = j;
                }
            }
            
            g.push_back(x);
        }

bfs(si,sj);

if(level[di][dj]!=0){
    cout<<"YES"<<endl;
    cout<<level[di][dj]<<endl;
}
else{
    cout<<"NO"<<endl;
}
    return 0;
}