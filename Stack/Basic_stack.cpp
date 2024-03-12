#include<iostream>
using namespace std;
class Stack
{
    public:
    int top;
    int *arr;
    int size;
    Stack(int size)
    {
        this->size=size;
        arr= new int[size];
        top=-1;
    }
    void push(int element)
    {
        if(top==size-1)
        {
            cout<<"Stack is full"<<endl;
        }
        else 
        {
            top++;
            arr[top]=element;
        }


    }
    void pop()
    {
        if(top==-1)
        {
            cout<<"stack is Empty"<<endl;
        }
        else 
        {
               cout<<"Element poped is "<<arr[top]<<endl;
            top--;
         
        }
    }
    void peek()
    {
        if(top>=0)
        {
            cout<<"The Peek Element is "<<arr[top]<<endl;
        }
        else 
        {
            cout<<"Sorry No peek Element"<<endl;
        }
    
    }
    void is_empty()
    {
        if(top==-1)
        {
            cout<<"Stack is empty"<<endl;
        }
        else 
        {
            cout<<"Stack is Not Empty"<<endl;

        }

    }
    void is_Full()
    {
        if(top==size-1)
        {
            cout<<"stack is Full"<<endl;
        }
        else 
        {
            cout<<"Stack is Not Full"<<endl;

        }

    }


};
int main()
{
    Stack st(5);
    st.push(12);
    st.push(11);
    st.push(20);
    st.push(32);
    st.pop();
    st.peek();
    st.is_empty();

    return 0;
}