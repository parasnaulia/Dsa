#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s="paras";
    stack<char> st;
    cout<<"Before Reverse"<<endl;
    cout<<s;
    for(int i=0;i<s.length();i++)
    {
        st.push(s[i]);

    }
    int i=0;
    while(!st.empty())
    {
        s[i]=st.top();
        i++;
        st.pop();
        
    }
    cout<<"The Reverse String is"<<endl;
    cout<<s;
    

}