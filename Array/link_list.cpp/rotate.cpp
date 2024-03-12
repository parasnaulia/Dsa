#include<iostream> 
using namespace std;
#include<bits/stdc++.h>
class Node
{
    public:
    int data;
    Node* next;
};
 Node* rotate(Node* &head, int k)
    {
        // Your code here
         if(head==NULL || head->next==NULL){
            return head;
        }
        Node*temp=head;
        int ans=0;
        while(temp->next!=NULL)
        {
            temp=temp->next;
            ans++;
        }
        if(ans==k){
        return head;
        }
        int count=0;
          Node*next=NULL;
        while(count!=k)
        {
          next=head->next;
             head->next=temp->next;
            temp->next=head;
           
              temp=head;
            head=next;
          
            count++;
        }
        return head;
    }
     void print(Node*head)
    {
        Node*temp=head;
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }

    }
    int main()
{
    
   Node* head=new Node();
    Node* second=new Node();
     Node* third=new Node();
       Node* forth=new Node();
       Node* fifth=new Node();
       Node* sixth=new Node();
       Node*seven=new Node();
       Node* eight=new Node();
     head->data=1;
     head->next=second;
     second->data=2;
     second->next=third;
     third->data=3;
     third->next=forth;
    forth->data=4;
     forth->next=fifth;
     fifth->data=5;
     fifth->next=sixth;
     sixth->data=9;
     sixth->next=seven;
     seven->data=7;
     seven->next=eight;
     eight->data=8;
     eight->next=NULL;
     print(head);
     cout<<endl;
rotate(head,4);
print(head);
     return 0;



}
