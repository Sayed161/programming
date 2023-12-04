#include<bits/stdc++.h>
using namespace std;


int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        set<int>s;
        while (n--)
        {
           int x;
           cin>>x;
           s.insert(x);
        }
        stack<int>v;
        for(auto it = s.begin();it!= s.end();it++){
            v.push(*it);
        }
        while (!v.empty())
        {
            cout<<v.top()<<" ";
            v.pop();
        }
        cout<<endl;
    }
    
    




    return 0;
}