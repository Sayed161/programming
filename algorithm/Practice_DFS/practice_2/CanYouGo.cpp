#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int N = 1e3 + 5;
const int INF = 1e9 + 5;
vector<pii> adj[N];
int dis[N];
int n,m;
void bellman(int s)
{

    
    dis[s] = 0;

for (int i = 1; i <= n - 1; i++)

    {
        for (int u = 1; u <= n; u++)
        {
            for (pii vpair : adj[u])
            {
                int v = vpair.first;
                int w = vpair.second;

                if (dis[u] != INF && dis[v] > dis[u] + w)
                {
                    dis[v] = dis[u] + w;
                }
            }
        }
    }
}

int main(){
    
     cin >> n >> m;

    while (m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[u].push_back({v, w});
    }
    for (int i = 1; i <= n; i++)
    {
        dis[i] = INF;
    }
    int si,t;
    cin>>si>>t;
    bellman(si);
    while(t--){
        int di,dw;
        cin>>di>>dw;
        if(dis[di]<=dw){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }



    return 0;
}