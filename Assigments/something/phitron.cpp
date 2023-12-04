#include<bits/stdc++.h>
using namespace std;
int main(){
    int q;
    cin>>q;
    while(q--){
    int n;
     cin>>n;

  int a[n];
  for (int i = 0;i<n; i++)
  {
   cin>>a[i];
  }
  int flag = 1;
  if(n==1)flag=1;
  else{
    for (int i = 0; i < n-1; i++)
  {
    for (int j = i+1; j < n; j++)
    {
        if(a[i]>a[j]){
            flag=0;
            break;
          
        }
        
    }
    
  }

  }
  
  
  if(flag==1){
    cout<<"YES"<<endl;
  }
  else {
    cout<<"NO"<<endl;
  }

    }
 





    return 0;
}