#include<iostream>
using namespace std;
#include<bits/stdc++.h>
void Sort(stack<int> &st,int ele)
{
    if(st.empty()||st.top()<ele)
    {
        st.push(ele);
        return;
    }
    int ans=st.top();
    st.pop();
    Sort(st,ele);
    st.push(ans);

}
void Element(stack<int> &st)
{
    if(st.empty())
    {
        return;
    }
    int ele=st.top();
    st.pop();
    Element(st);
    Sort(st,ele);

}
int main()
{
    stack<int> st;
    for(int i=0;i<4;i++)
    {
        st.push(i);
    }
    st.push(1220);
    st.push(8);
    st.push(5);
    st.push(90);
    Element(st);
    cout<<"The Element of Stack After Swap"<<endl;
    while(!st.empty())
    {
        cout<<st.top();
        cout<<endl;
        st.pop();
    }
    return 0;

}