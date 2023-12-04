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

int main(){
  int n;
  cin>>n;
  int a[n];  
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    merge(a,0,3,n-1);

 
for (int i = 0; i < n; i++)
{
  cout<<a[i]<<" ";
}



    return 0;
}