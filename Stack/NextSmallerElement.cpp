#include<iostream>
using namespace std;
#include<bits/stdc++.h>
vector<int> next(vector<int>&v)
{
    int n=v.size();
    stack<int> st;
    st.push(-1);
    vector<int> ans(n);
    for(int i=n-1;i>=0;i--)
    {
        while(st.top()!=-1&&v[st.top()]>=v[i])
        {
            st.pop();
        }
        ans[i]=st.top();
        st.push(i);

        
    }
    return ans;
}
vector<int> prev(vector<int>&v)
{
    int n=v.size();
    stack<int> st;
    st.push(-1);
    vector<int> ans(n);
    for(int i=0;i<n;i++)
    {
        while(st.top()!=-1&&v[st.top()]>=v[i])
        {
            st.pop();
        }
        ans[i]=st.top();
        st.push(i);

        
    }
    return ans;
}

int main()
{
    vector<int> v={2,1,5,6,2,3};
    vector<int> next1=next(v);
    vector<int> prev1=prev(v);
    //Applying the concpect of Histogram
    int area=INT_MIN;

    for(int i=0;i<v.size();i++)
    {
        int length=v[i];
        if(next1[i]==-1)
        {
            next1[i]=v.size();
        }
    
        int breath=(next1[i]-prev1[i]-1);
        int area1=length*breath;
        area=max(area,area1);

        
    }
    cout<<"MAximum Area is"<<area<<endl;

    return 0;

}











class Solution {
public:
vector<int> next(vector<int>nums)
{
    int n=nums.size();
    stack<int> st;
    vector<int> ans(n);
    st.push(-1);
    for(int i=n-1;i>=0;i--)
    {
        while(st.top()!=-1&&nums[st.top()]>=nums[i])
        {
            st.pop();
        }
        ans[i]=st.top();
        st.push(i);
    }
    return ans;

}
vector<int> prev(vector<int> nums)
{
    int n=nums.size();
    stack<int> st;
    vector<int> ans(n);
    st.push(-1);
    for(int i=0;i<n;i++)
    {
        while(st.top()!=-1&&nums[st.top()]>=nums[i])
        {
            st.pop();
        }
        ans[i]=st.top();
        st.push(i);
    }
    return ans;

}
int MaxRectangle(vector<int> nums)
{
    vector<int> next1=next(nums);
    vector<int> prev1=prev(nums);
    int maxi=INT_MIN;
    for(int i=0;i<nums.size();i++)
    {
        int l=nums[i];
        if(next1[i]==-1)
        {
            next1[i]=nums.size();
        }
        int b=(next1[i]-prev1[i]-1);
        int area=l*b;
        maxi=max(maxi,area);

    }
    return maxi;
}


    int maximalRectangle(vector<vector<char>>& matrix) {

      vector<vector<int>> nums(matrix.size());
       for(int i=0;i<matrix.size();i++)
       {
           for(int j=0;j<matrix[i].size();j++)
           {
               if(matrix[i][j]=='0')
               {
                   nums[i].push_back(0);
               }
               else
               {
                   nums[i].push_back(1);
               }
           }
       }
        int area=MaxRectangle(nums[0]);
       for(int i=1;i<v.size();i++)
       {
           for(int j=0;j<v[i].size();j++){
           if(v[i][j]!=0)
           {
               v[i][j]=v[i-1][j]+v[i][j];
           }
           else
           {
               v[i][j]=0;
           }
       }
       int area1=MaxRectangle(v[i]);
       area=max(area,area1);
       }

return area;
        
    }
};