#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+5;
typedef pair<int,int>pii;
vector<string>g;
vector<pii>dire = {{0,-1},{0,1},{-1,0},{1,0}};
bool visited[N][N];
int level[N][N];
pii parent[N][N];
  int n,m;
bool valid (int a,int b){

    return (a>=0 && a<n && b>=0 && b<m);

}
void bfs(int si,int sj){

        queue<pii>q;
        q.push({si,sj});
        visited[si][sj]=true;
        level[si][sj]=0;
        while(!q.empty()){
                pii vpair = q.front();
                q.pop();
                int a = vpair.first;
                int b = vpair.second;
                for(auto d : dire){
                    int i = a+d.first;
                    int j = b+d.second;
                         if(valid(i,j) && !visited[i][j] && g[i][j]!='X'){
                        q.push({i,j});
                        visited[i][j]=true;
                        level[i][j]=level[a][b]+1;
                        parent[i][j]={a,b};

                }
                }
               

        }

}
int main(){
    
  
    cin>>n>>m;
    int si,sj,di,dj;
    for (int i = 0; i < n; i++)
    {
        string x;
        cin>>x;
        for(int j = 0;j<m;j++){
            if(x[j]=='s'){
                    si = i;
                    sj = j;
            }
            if(x[j]=='e'){
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
    return 0;
}
vector<pii>path;
pii curr = {di,dj};
pii durr = {si,sj};
while(curr!=durr){
       path.push_back(curr);
       curr = parent[curr.first][curr.second];
}

reverse(path.begin(),path.end());
for (int i = 1; i < path.size(); i++)
{
    if(path[i-1].first == path[i].first){
            if(path[i-1].second == path[i].second-1){
                cout<<"R";
            }
            else{
                cout<<"L";
            }
    }
    else{
            if(path[i-1].first == path[i].first-1){
                cout<<"D";
            }
            else{
                cout<<"U";
            }
    }
}




    return 0;
}