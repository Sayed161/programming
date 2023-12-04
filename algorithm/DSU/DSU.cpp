#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
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

int main(){
    
    int n,e;
    cin>>n>>e;
    dsu_set(n);
    while(e--){
        int a,b;
        cin>>a>>b;
        
        dsu_union(a,b);
        
    }
map<int,bool>mp;
for (int i = 1; i <=n; i++)
{
    int ldr = dsu_find(i);
    mp[ldr]= true;
}
vector<int>g;
for (auto v: mp )
{
   g.push_back(v.first);
}
cout<<g.size()-1<<endl;
for(int i = 0;i<g.size()-1;i++){
    cout<<g[i]<<" "<<g[i+1]<<endl;
}



    return 0;
}