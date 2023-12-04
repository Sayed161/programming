#include<bits/stdc++.h>
using namespace std;

const long long L = 1e18;
int main(){
  int n,e;
  cin>>n>>e;
  long long dis[n+1][n+1];
  for (int i = 1; i <=n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      
        if(i==j){
            dis[i][j]=0;
        }
        else{
              dis[i][j]=L;
        }
    }
    
  }
    while(e--){
    
    long long int a,b,w;
    cin>>a>>b>>w;
    if(dis[a][b]>w ){
            dis[a][b]=w;
    }

    }
   
        
   for (int k = 1; k <= n; k++)
   {
    for (int i = 1; i <=n; i++)
        {
            for (int j = 1; j <= n; j++)
                {
                if(dis[i][k]+dis[k][j]<dis[i][j] && dis[i][k]!=L && dis[k][j]!=L){
                    dis[i][j]= dis[i][k]+dis[k][j];
                }
                    
                }
        }
   }
   
    
 int t;
 cin>>t;
 while(t--){
    int a,b;
    cin>>a>>b;
    if(dis[a][b]==L){
        cout<<"-1"<<endl;
    }
    else{ cout<<dis[a][b]<<endl;}
 }



    return 0;
}