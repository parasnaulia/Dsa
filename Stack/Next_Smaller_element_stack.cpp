#include<iostream>
using namespace std;
#include<bits/stdc++.h>
vector<int> solve(vector<int>&v)
{
    stack<int> st;
    int n=v.size();
    vector<int> ans;
    st.push(-1);
;    for(int i=n-1;i>=0;i--)
    {
        if(!st.empty()&&st.top()>=v[i])
        {
            while(st.top()>v[i])
            {
                st.pop();
            }
           
            ans.push_back(st.top());
             st.push(v[i]);
            

        }
        else
        {
            ans.push_back(st.top());
           st.push(v[i]);
        }

    }
     reverse(ans.begin(),ans.end());
    return ans;
}
vector<int> solve1(vector<int>&v)
{
    stack<int> st;
    int n=v.size();
    vector<int> ans;
    st.push(-1);
;    for(int i=0;i<n;i++)
    {
        if(!st.empty()&&st.top()>v[i])
        {
            while(st.top()>=v[i])
            {
                st.pop();
            }
           
            ans.push_back(st.top());
             st.push(v[i]);
            

        }
        else
        {
            ans.push_back(st.top());
           st.push(v[i]);
        }

    }
     //reverse(ans.begin(),ans.end());
    return ans;
}
int main()
{
    vector<int> v={2,1,5,6,2,3};
     vector<int> v1={2,1,5,6,2,3};
     vector<int> ans=solve(v);
      
    
     for(int i=0;i<ans.size();i++)
     {
        cout<<ans[i]<<" ";
     }
     cout<<endl;
     
     cout<<"Solve 2"<<endl;
     vector<int> ans1=solve1(v1);
     for(int i=0;i<ans1.size();i++)
     {
        cout<<ans1[i]<<" ";
     }

     return 0;

}