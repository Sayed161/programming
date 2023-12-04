#include<bits/stdc++.h>
using namespace std;


int main() {
   
 
vector<int> heights; 
int m ;
cin>>m;
for(int i = 0;i<m;i++){
    int x;
    cin>>x;
    heights.push_back(x);
}
      int n = heights.size();
      queue<int>v;
      priority_queue<int>q;
      for(int i=0;i<n;i++){
          v.push(heights[i]);
          q.push(heights[i]);
      }
      int cnt=0;
      while(n--){
        cout<<q.top()<<" "<<v.front()<<endl;
          if(q.top()!=v.front()){
              cnt++;
          }
          q.pop();
          v.pop();
      }
      cout<< cnt;
      set<int>s;
      for (auto i = s.begin(); i!= s.end(); i++)
      {
        cout<<*i<<" ";
      }
      
        return 0;

}
    

   
  