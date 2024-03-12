#include<iostream>
using namespace std;
#include<bits/stdc++.h>
int solve(vector<int> &nums,int index,int target,int n,vector<vector<int>> &dp)
{
      // if(index==n)
      // {
      //       return 0;
      // }
      // if(target==0)
      // {
      //       return 1;
      // }
      if (index >= n) {
            if(target==0)
            {
                  return 1;
            }
            return 0;
       
    }
    if(dp[index][target]!=-1)
    {
      return dp[index][target];
    }
    int pick=0;
    if(target>=nums[index])
    {
     
       pick=solve(nums,index+1,target-nums[index],n,dp);
       }

      
     int notpick=solve(nums,index+1,target,n,dp);
      return dp[index][target]= pick+notpick;
}
int main()
{
      vector<int> nums={2, 4, 6};
      int target=6;
      vector<vector<int>> dp(4,vector<int> (target+1,-1));
      int x=solve(nums,0,target,nums.size(),dp);
      cout<<x;
      return 0;

}