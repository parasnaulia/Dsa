#include<iostream>
using namespace std;
#include<bits/stdc++.h>
 bool solve(string s)
{
    stack<char> st;
    for(int i=0;i<s.length();i++)
    {
        
        if(s[i]=='('||s[i]=='+'||s[i]=='*')
        {
            st.push(s[i]);

        }
        else{
            if(s[i]==')'){
            bool is_valid=true;
            
            while(!st.empty()&&st.top()!='(')
            {
                if(st.top()=='*'||st.top()=='+')
                {
                    is_valid=false;
                }
                st.pop();  
            }
            if(is_valid)
            {
                return true;
            }
            st.pop();
        }
        }
         
    }
    return false;

}

int main()
{
    string s="(1+1)";
   bool ans= solve(s);
   if(ans)
   {
    cout<<"Yes HAving Dublicate"<<endl;

   }
   else
   {
    cout<<"No Dublicate is there"<<endl;
   }
    return 0;
}