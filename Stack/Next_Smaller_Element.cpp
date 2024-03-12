// brute force approach To  Solve Next greater Element
#include<iostream>
using namespace std;
#include<bits/stdc++.h>
vector<int> Next(vector<int> &nums)
{
    vector<int> ans;
    int n=nums.size();
    for(int i=0;i<n;i++)
    {
        int mini=INT_MAX;
        for(int j=i+1;j<n;j++)
        {
            
            if(nums[i]>nums[j])
            {
                mini=min(nums[j],mini);

            }
        }
        if(mini!=INT_MAX)
        {
            ans.push_back(mini);
        }
        else
        {
            ans.push_back(-1);
        }
    }
    return ans;
}
int main()
{
    vector<int> nums={12,43,21,25,122};
     vector<int> ans=Next(nums);
     for(int i=0;i<ans.size();i++)
     {
        cout<<ans[i]<<" ";
     }
    return 0;

}