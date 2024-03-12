#include<iostream> 
using namespace std;
#include<bits/stdc++.h>
class Node
{
    public:
    int data;
    Node* next;
};

 bool isPalindrome(Node *&head)
    {
        //Your code here
        Node*slow=head;
        Node*fast=head;
        while(fast!=NULL&&fast->next!=NULL)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
      
        Node*prev=NULL;
        while(slow!=NULL)
        {
            Node*next=slow->next;
            slow->next=prev;
            prev=slow;
            slow=next;
            
        }
        Node*head1=prev;
        Node*temp=head;
        while(head1!=NULL)
        {
            if(head1->data!=temp->data)
            {
                return false;
            }
           head1= head1->next;
           temp=temp->next;
        }
        return true;
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
     head->data=3;
     head->next=second;
     second->data=4;
     second->next=third;
     third->data=4;
     third->next=forth;
     forth->data=3;
     forth->next=NULL;
     print(head);
     cout<<endl;
bool palin=isPalindrome(head);
cout<<"The string is palin "<<palin;
     return 0;



}