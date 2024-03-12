#include<iostream>
using namespace std;
#include<bits/stdc++.h>
vector<int> solve(vector<int> nums,int k)
{
   // priority_queue<int> pq;
    int i=0;
    int j=0;
    vector<int> ans;
    queue<int> q;
    while(j<nums.size())
    {
        q.push(nums[j]);
        if(q.size()>k)
        {
            while(q.size()>k)
            {
                q.pop();
                
            }
        }
       
        if(q.size()==k)
        {
            vector<int> v;
            while(!q.empty())
            {
                v.push_back(q.front());
                q.pop();

            }
            int maxi=INT_MAX;
            for(int i=0;i<v.size();i++)
            {
                maxi=min(maxi,v[i]);

            }
            ans.push_back(maxi);
            for(int i=0;i<v.size();i++)
            {
                q.push(v[i]);
            }
            

        }
         

j++;
    
    }
    return ans;

}
int main()
{
    vector<int> nums={2,3,5,4,1,2};
    vector<int> ans=solve(nums,2);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }

}
