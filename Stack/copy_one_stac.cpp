//We are given two stack i Have to copy that Two stack in oe array 
#include<iostream> 
using namespace std;
class Stack
{
    public:
    int top1;
    int top2;
    int *arr;
    int size;

    Stack(int size)
    {
        this->size=size;
        arr=new int[size];
        top1=-1;
        top2=size;
    }
    //Pushing of first stack in an array
    void push1(int element)
    {
        if((top2-top1)>=1)
        {
            arr[top1]=element;
            top1++;
        }
        else
        {
            cout<<"CanNot Push An Element into a stack"<<endl;
        }

    }
    void push2(int element)
    {
        if((top2-top1)>=1)
        {
            arr[top2]=element;
            top2--;
        }
        else
        {
            cout<<"Sorry Stack is full"<<endl;
        }
    }
    void pop1()
    {
        if(top1==-1)
        {
            cout<<"Underflow Condition"<<endl;
        }
        else 
        {
            cout<<"Element deleted is"<<arr[top1]<<endl;
            top1--;
        }
    }
    void pop2()
    {
        if(top2>=size)
        {
            cout<<"Underflow"<<endl;
        }
        else
        {
            cout<<"Element Deleted is"<<arr[top2]<<endl;
            top2--;
        }
    }
    void print1()
    {
        while(top1!=-1)
        {
            cout<<arr[top1]<<endl;
            top1--;


        }
    }
    void print2()
    {
        while(top2!=size)
        {
            cout<<arr[top2]<<endl;
            top2++;
        }
    }

    



};
int main()
{
    Stack st(5);
    st.push1(12);
    st.push2(20);
    st.push1(576);
    st.push2(12);
    st.push1(121);
  
       
       //st.print1();
      st.print2();
    return 0;


}