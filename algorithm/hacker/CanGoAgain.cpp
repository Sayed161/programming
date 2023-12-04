#include<bits/stdc++.h>
using namespace std;
class Edge{
    public:
        int u;
        int v;
        long long w;
        Edge(int u,int v,long long w){
            this->u = u;
            this->v = v;
            this->w = w;
            
        }
};

int main(){
    int n,e;
    cin>>n>>e;
    vector<Edge>v;
    while(e--){
        int a,b;
        long long c;
        cin>>a>>b>>c;
        Edge ed(a,b,c);
        v.push_back(ed);
    }
    long long dis[n+1];
    for (int i = 1; i <= n; i++)
    {
        dis[i]=LONG_MAX;
    }
    int a;
    cin>>a;
    dis[a]=0;
    
    for(int i = 1;i<=n-1;i++){
        for(int j = 0;j < v.size();j++){
                Edge ed = v[j];
                int a = ed.u;
                int b = ed.v;
                long long c = ed.w;
                if(dis[a]!=LONG_MAX && dis[a]+c<dis[b]){
                    dis[b]=dis[a]+c;
                }
        }
    }
    int flag = 0;
     for(int j = 0;j < v.size();j++){
                Edge ed = v[j];
                int a = ed.u;
                int b = ed.v;
                long long c = ed.w;
                if(dis[a]!=LONG_MAX &&dis[a]+c<dis[b]){
                  
                    flag = 1;
                    break;
                }
        }
        int t;
        cin>>t;
        while(t--){
            int d;
            cin>>d;
            if(!flag){
                if(dis[d]==LONG_MAX ){
                 cout<<"Not Possible"<<endl;
                }
                else{      
                 cout<<dis[d]<<endl;
                }
            }

        }
if(flag)cout<<"Negative Cycle Detected"<<endl;
   
    

    return 0;
}