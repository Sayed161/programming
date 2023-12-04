#include<bits/stdc++.h>
using namespace std;


int main(){
  int n;
  cin>>n;
  int a[n];
  for (int i = 0; i < n; i++)
  {
    cin>>a[i];
  }
    int k;
    cin>>k;

    int l =0;
    int r=n-1;
    int index = 0;
    while(l<=r){
        int mid = (l+r)/2;
        if(k==a[mid]){
            index = mid;
            break;
        }
        if(k<a[mid]){
            r=mid-1;
        }
        else{
            l=mid+1;
        }

    }
    
    if(index==0) {
        cout<<"NO";
    }
    else if(a[index+1]==k || a[index-1]==k){
        cout<<"YES";
    }
    else {
        cout<<"NO";
    }


    return 0;
}