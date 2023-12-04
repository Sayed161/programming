#include<bits/stdc++.h>
using namespace std;
class Edge{
    public:
        int u;
        int v;
        int w;
        Edge(int u,int v,int w){
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
        int a,b,c;
        cin>>a>>b>>c;
        Edge ed(a,b,c);
        v.push_back(ed);
    }
    int dis[n+1];
    for (int i = 1; i <= n; i++)
    {
        dis[i]=INT_MAX;
    }
    dis[1]=0;
    
    for(int i = 1;i<=n;i++){
        for(int j = 0;j < v.size();j++){
                Edge ed = v[j];
                int a = ed.u;
                int b = ed.v;
                int c = ed.w;
                if(dis[a]+c<dis[b]){
                    dis[b]=dis[a]+c;
                }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout<<"Node of "<<i<<": "<<dis[i];
        cout<<endl;
    }
    

    return 0;
}