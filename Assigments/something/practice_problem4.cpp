#include<bits/stdc++.h>
using namespace std;
class student{

            public:
                    string name;
                    int roll;
                    int marks;
                student(string name,int roll,int marks){
                    this->name = name;
                    this->roll = roll;
                    this->marks = marks;
                    }
                };
class cmp{

        public:
        bool operator()(student a,student b){
            if(a.marks<b.marks) return true;
           else if(a.marks>b.marks) return false;
            else{
                if(a.roll > b.roll)
                return true;
                else{
                        return false;
                }
            } 
        }

} ;
int main(){
    int n;
    cin>>n;
    priority_queue<student,vector<student>,cmp>q;
    while (n--)
    {
        string name;
        int roll,marks;
        cin>>name>>roll>>marks;
        student obj(name,roll,marks);
        q.push(obj);
    }
      
      int l;
      cin>>l;
      while (l--)
      {
        int a;
        cin>>a;
        if(a==0){
                string name;
                int roll,marks;
                cin>>name>>roll>>marks;
                student obj(name,roll,marks);
                q.push(obj);
                cout<<q.top().name<<" "<<q.top().roll<<" "<<q.top().marks<<endl;
        }
        else if(a==1){
            if(!q.empty()){
                cout<<q.top().name<<" "<<q.top().roll<<" "<<q.top().marks<<endl;
            }
            else{
                cout<<"Empty"<<endl;
            }
        }
        else if(a==2){
                if(!q.empty()){
                    q.pop();
                }
                  if(!q.empty()){
                cout<<q.top().name<<" "<<q.top().roll<<" "<<q.top().marks<<endl;
            }
            else{
                cout<<"Empty"<<endl;
            }

        }
      }
    //   while (!q.empty())
    //   {
    //     cout<<q.top().name<<" "<<q.top().marks<<" "<<q.top().roll<<endl;
    //     q.pop();
    //   }
      
      
    




    return 0;
}