#include<bits/stdc++.h>
using namespace std;

void merge(int a[],int b[],int n,int m,int rst[]){

int x=0,y=0,z=0;

    while(x<n && y<m){

            if(a[x]>=b[y]){
                rst[z]=a[x];
                x++;
               
            }
            else{
                rst[z]=b[y];
                y++;
               
            }
             z++;
    }

    while (x<n)
    {
        rst[z]=a[x];
        x++;
        z++;
    }
    while (y<m)
    {
        rst[z]=b[y];
        y++;
        z++;
    }

}


int main(){
  int n;
  cin>>n;

  int a[n];

  for (int i = 0; i < n; i++)
  {
    cin>>a[i];
  }
    int m;
    cin>>m;
    int b[m];
  for (int i = 0; i < m; i++)
  {
    cin>>b[i];
  }
    
    int result[n+m];

    merge(a,b,n,m,result);

    for(int i=0;i<(n+m);i++){
        cout<<result[i]<<" ";
    }


    return 0;
}