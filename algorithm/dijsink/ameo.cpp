#include<bits/stdc++.h>
using namespace std;
void merge(int a[],int l,int mid, int r){
    int left = (mid-l)+1;
    int right = r-mid;
    int L[left];
    int R[right];
    int k = 0;
    for (int i = l; i <= mid; i++)
    {
        L[k]=a[i];
        k++;
    }
    int t= 0;
    for (int i = mid+1; i <= r; i++)
    {
        R[t]=a[i];
        t++;
    }
    int i=0,j=0;
    int cur = l;
    while(i<left && j<right){
        if(L[i]<=R[j]){
            a[cur]=L[i];
            i++;
            cur++;
        }
        else{
            a[cur]=R[j];
            j++;
            cur++;
        }

    }
    while(i<left){
        a[cur]=L[i];
        i++;
        cur++;
    }
    while(j<right){
        a[cur]=R[j];
        j++;
        cur++;
    }
}
void devide(int a[],int l, int r){
    if(l<r){
        
        int mid = (l+r)/2;
        devide(a,l,mid);
        devide(a,mid+1,r);
         merge(a,l,mid,r);
        for (int i = l; i <= mid; i++)
        {
                cout<<a[i]<<" ";
        } 
        
        cout<<endl;
        for (int i = mid+1; i <= r; i++)
        {
                cout<<a[i]<<" ";
        } 
             cout<<endl;
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
    
    devide(a,0,n-1);




    return 0;
}