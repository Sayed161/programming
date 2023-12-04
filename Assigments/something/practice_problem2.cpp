#include<bits/stdc++.h>
using namespace std;


int main(){
  int n;
  cin>>n;

  while (n--)
  {
    int s;
    cin>>s;
 
    int a[s];
      int cnt = INT_MIN;
      int mx=0;
    for (int i = 0; i < s; i++)
    {
        cin>>a[i]; 
    }
   
  map<int,int>mp;

  for (int i = 0; i < s; i++)
  {
    mp[a[i]]++;
    if(mp[a[i]]>cnt){
     
        cnt = mp[a[i]];
      mx = a[i];
      }
      else if(mp[a[i]]==cnt){
      if(a[i]>mx){
        cnt = mp[a[i]];
      mx = a[i];
      }
     
    }
    
    }
  
  vector<int>k;
  k.size();
  
    for (int i = 0; i < mx; i++)
    {
      cout<<k[i];
    }
    

    // while (ss>>word)
    // {
    //     mp[word]++;
    //     if(mp[word]>x){
    //         x = mp[word];
    //         k = word;
    //     }
    // }
   
    cout<<mx<<" "<<cnt;  cout<<endl;
    
  }

    
    




    return 0;
}