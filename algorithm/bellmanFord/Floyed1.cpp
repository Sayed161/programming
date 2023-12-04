#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int dis[n+1][n+1];
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == j)
                dis[i][j] = 0;
            else
                dis[i][j] = INT_MAX;
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            int w;
            cin >> w;
            if(w!=-1){
                      dis[i][j] = w;
            }
          
        }
    }

  

    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(dis[i][k] + dis[k][j] < dis[i][j] && dis[i][k]!=INT_MAX && dis[k][j]!=INT_MAX) {
                    dis[i][j] = dis[i][k] + dis[k][j];
                }
            }
        }
    }
int g =0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(dis[i][j]==INT_MAX)continue;
          else g=max(dis[i][j],g);
        }
        
    }
cout<<g<<endl;
    return 0;
}
