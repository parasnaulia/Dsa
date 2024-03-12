#include<iostream>
using namespace std;
#include<bits/stdc++.h>
bool match(char ch,char st)
{
    if((ch=='}'&&st=='{')||(ch==')'&&st=='(')||(ch==']'&&st=='['))
    {
    return true;
    }
    return false;

}
bool is_valid(string s)
{
    stack<char> st;
    for(int i=0;i<s.length();i++)
    {
        char ch=s[i];
        if(ch=='{'||ch=='['||ch=='(')
        {
            st.push(ch);
        }
        else{
        if(!st.empty())
        {
            if(match(ch,st.top()))
            {
                st.pop();
            }
            else{
                return false;
               //st.push(ch);
            }
        }
        else
        {
            st.push(ch);
          // return false;
        }
        }
       
        
       
        
    }
     if(st.empty())
        {
            return true;
        }
        return false;

}
int main()
{
    string s="[()]";
    if(is_valid(s))
    {
        cout<<"its a valid parenthesis "<<endl;
    }
    else
    {
        cout<<"Not a valid Parenthesis"<<endl;
    }
    return 0;
}