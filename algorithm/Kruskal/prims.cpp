#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pi;
const int N = 1e5+5;
vector<pi>v[N];

bool vis[N];
class Edge{
    public:
    int a,b,w;
    Edge(int a,int b ,int w){
        this->a = a;
        this->b = b;
        this->w = w;
    }
};
class cmp{
    public:
    bool operator()(Edge a,Edge b){
            return a.w > b.w;
    }
};

void prims(int s){
    priority_queue<Edge,vector<Edge>,cmp>pq;
    pq.push(Edge(s,s,0));
  vector<Edge>ed;
    while(!pq.empty()){
        Edge parent = pq.top();
        pq.pop();
        int a = parent.a;
        int b = parent.b;
        int w = parent.w;
        if(vis[b])continue;
        vis[b]=true;
        ed.push_back(parent);
        for (int i = 0; i < v[b].size(); i++)
        {
            pi child = v[b][i];
            if(!vis[child.first]){
                pq.push(Edge(b,child.first,child.second));
            }
        }    
    }

   for(Edge p : ed){
        cout<<p.a<<" "<<p.b<<" "<<p.w<<endl;
     }
}

int main(){
    
    int n,e;
    cin>>n>>e;
    while(e--){
        int a,b,w;
        cin>>a>>b>>w;
        v[a].push_back({b,w});
        v[b].push_back({a,w});
    }
    prims(1);
    
//    while(t--)
     


    return 0;
}