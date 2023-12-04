#include<bits/stdc++.h>
using namespace std;

void merge(int l, int r, int mid,int a[]){
    int ls = (mid - l)+1;
    int L[ls];

    int rs = r - mid;
    int R[rs];

    for(int i=l,j=0;i<=mid;i++,j++ ){

      L[j]=a[i];
    }

     for(int i=mid+1,j=0;i<=r;i++,j++ ){

      R[j]=a[i];
    }

    L[ls]=INT_MIN;
    R[rs]=INT_MIN;
    int rp=0,lp = 0;
    for (int i = l; i <= r; i++)
    {
      if(L[lp]<=R[rp]){
        a[i]=R[rp];
        rp++;
      }
      else{
        a[i]=L[lp];
        lp++;
      }
    }
    

}

void mergesort(int l,int r,int a[]){

  if(l==r) return;

  int mid = (l+r)/2;
  mergesort(l,mid,a);
  mergesort(mid+1,r,a);

  merge(l,r,mid,a);
}



int main(){
  int n;
  cin>>n;

  int a[n];
  for (int i = 0; i < n; i++)
  {
    cin>>a[i];
  }
    
    mergesort(0,n-1,a);
    

for(int i = 0;i<n;i++){
  cout<<a[i]<<" ";
}


    return 0;
}