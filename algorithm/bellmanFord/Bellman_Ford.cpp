#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int N = 1e2;
const int INF = 100;

vector<pii> g[N+1];
int d[N+1];

int n,m;

void bellam_ford(int s)
{

    for (int i = 1; i <= n; i++)
    {
        d[i] = INF;
    }
    d[s] = 0;

for (int i = 1; i <= n - 1; i++)

    {
        for (int u = 1; u <= n; u++)
        {
            for (pii vpair : g[u])
            {
                int v = vpair.first;
                int w = vpair.second;

                if (d[u] != INF && d[v] > d[u] + w)
                {
                    d[v] = d[u] + w;
                }
            }
        }
    }
}

int main()
{

    cin >> n >> m;

    while (m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
    }

    bellam_ford(1);

    for (int i = 1; i <= n; i++)
    {
       
        if(d[i]==INF){
            cout<<"30000"<<" ";
        }
        else{
            cout<<d[i]<<" ";
        }
        
    }

    return 0;
}