#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
const int N = 1e5+5;
vector<pii>v[N];
int dis[N];
bool vis[N];


void naive(int s){
        priority_queue<pii,vector<pii>,greater<pii>>q;
        q.push({0,s});
        dis[s]=0;
        while (!q.empty())
        {
            pii parent = q.top();
            q.pop();
            int parentNode = parent.second;
            int parentCost = parent.first;
            if(vis[parentNode]){
                continue;
            }
                
            
            vis[parentNode]=true;
            for (int i = 0; i < v[parentNode].size(); i++)
            {
               pii child = v[parentNode][i];
                int childNode = child.first;
                int childcost = child.second;
                
                if(parentCost+childcost<dis[childNode]){
                    dis[childNode]=parentCost+childcost;
                    q.push({dis[childNode],childNode});
                }
            }
            
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
    int t;
    cin>>t;
    
    naive(1);
    
    while(t--){
    
    int a,b;
    cin>>a>>b;
    
    if(dis[b]==INT_MAX){
        cout<<"-1"<<endl;
    }
    else{
        cout<<dis[b]<<endl;
    }
    }
   
    
naive(1);


for (int i = 1; i <= n; i++)
{
    cout<<"Node "<<i<<": "<<dis[i]<<endl;
}

    return 0;
}