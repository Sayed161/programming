#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
const int N = 1e3+5;
const int INF = 1e9+5;

vector<pair<pii,int>>li;
 int n,m;
 int d[N];


void bellam_ford(int s)
{

    for (int i = 1; i <= n; i++)
    {
        d[i] = INF;
    }
    d[s] = 0;

for (int i = 1; i <= n - 1; i++)

    {
       for(auto edge : li){
        int u = edge.first.first;
        int v = edge.first.second;
        int w = edge.second;

        if(d[u]!= INF && d[v]>d[u]+w){
            d[v]= d[u]+w;
        }
       }
    }
}


int main(){
 
  cin>>n>>m;
  while(m--){

        int u,v,w;

        cin>>u>>v>>w;
        li.push_back({{u,v},w});



  }  
    
  bellam_ford(1);

    for (int i = 1; i <= n; i++)
    {
        cout << "Distance of " << i;
        cout << " :" << d[i] << endl;
    }




    return 0;
}