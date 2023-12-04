#include<bits/stdc++.h>
using namespace std;
    const int N = 1e3+5;
    int parent[N];
    int parentSize[N];

    void dsu_set(int n){
        for(int i=0;i<n;i++){
            parent[i]=-1;
            parentSize[i]=1;
        }
    }
    int dsu_find(int Node){
        while(parent[Node]!=-1){
                Node = parent[Node];
        }
    
        return Node;
    }
    
    void dsu_union(int a,int b){
            int ldrA = dsu_find(a);
            int ldrB = dsu_find(b);
            if(ldrA!=ldrB){
                if(parentSize[ldrA]>parentSize[ldrB]){
                     parent[ldrB]=ldrA;
                     parentSize[ldrA]+=parentSize[ldrB];
                }
                else{
                    parent[ldrA]=ldrB;
                    parentSize[ldrB]+=parentSize[ldrA];
                }        
            }        
    }
    class Edge{
    public:
    int a,b,w;
    Edge(int a,int b ,int w){
        this->a = a;
        this->b = b;
        this->w = w;
    }
};
bool cmp(Edge a,Edge b){
            return a.w < b.w;
    }

int main(){
    int n,e;
    cin>>n>>e;
    dsu_set(n);
    vector<Edge>ed;
    vector<Edge>ans;
    while(e--){
        int a,b,w;
        cin>>a>>b>>w;
       ed.push_back(Edge(a,b,w));
    }
    sort(ed.begin(),ed.end(),cmp);
    for(Edge val : ed){
       int a = val.a;
       int b = val.b;
       int leadrA = dsu_find(a);
       int leadrB = dsu_find(b);
       if(leadrA==leadrB)continue;
       ans.push_back(val);
       dsu_union(a,b);
    }
for (Edge k: ans)
{
    cout<<k.a<<" "<<k.b<<" "<<k.w<<endl;
}





    return 0;
}