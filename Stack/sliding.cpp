#include<iostream> 
using namespace std;
#include<bits/stdc++.h>
int longestSubarray(vector<int>& nums) {
        vector<pair<int,int>> pq;
        for(int i=0;i<nums.size();i++)
        {
            pq.push_back({nums[i],i});
        }
        int maxi=INT_MIN;
        for(auto x:pq)
    {
        int x1=x.first;
        int x2=x.second;
        int count=0;
        int i=x2;
        while(i>=0)
        {
            if((i-1)<0)
            {
                break;
            }
            if(nums[i-1]!=1)
            {
                break;
            }
            count++;
            i--;
        }
        i=x2;
        while(i<nums.size())
        {
            if((i+1)>nums.size())
            {
                break;
            }
            if(nums[i+1]!=1)
            {
                break;
            }
            count++;
            i++;
        }
        if(maxi<count)
        {
            maxi=count;
        }
        count=0;

    }
    return maxi;
      
    }
int main()
{
    vector<int> ans={0,1,0,1,1,0,1,1,1,0,1,1,1,1,1,1,1,1,0};
     int x=longestSubarray(ans);
     cout<<x;
     return 0;


}