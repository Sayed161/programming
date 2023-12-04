#include<bits/stdc++.h>
using namespace std;
class Node{
  public:  
       int val;
       Node* next;
  Node(int val){

     this->val=val;
     this->next=NULL;


  }


};
int main(){
      
    Node* node = new Node(5);
    Node* newNode = new Node(10);
    // cout<<node<<endl;
    // cout<<newNode->next<<endl;
    cout<<node<<endl;
    cout<<newNode<<endl;
    newNode->next = node;
    node = newNode;
    cout<<"newNode->next: "<<newNode->next<<"="<<"node"<<": "<<node<<endl;
    cout<<"Node : "<<*&node<<" = "<<"newNode"<<": "<<newNode;
    return 0;
}