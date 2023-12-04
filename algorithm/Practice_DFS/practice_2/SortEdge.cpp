#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
vector<pair<int,int>>v;


int main(){
    
    int e;
    cin>>e;
    while(e--){
        int a,b;
        cin>>a>>b;
        v.push_back({a,b});
    }
    
    sort(v.begin(),v.end());
    for(int i = 0;i<v.size();i++){
                cout<<v[i].first<<" "<<v[i].second<<endl;
    }



    return 0;
}