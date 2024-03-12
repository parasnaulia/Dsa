#include<iostream> 
using namespace std;
#include<bits/stdc++.h>
int solve(int n,vector<int> &nums)
{
      if(n==0)
      {
            return nums[0];
      }
      if(n<0)
      {
            return 0;
      }
      int pick=nums[n]+solve(n-2,nums);
      int notpick=0+solve(n-1,nums);
      return max(pick,notpick);
}
//memo code(top-down dp)
int solve1(int n,vector<int> &nums,vector<int> &dp)
{
      if(n==0)
      {
            return nums[0];
      }
      if(n<0)
      {
            return 0;
      }
      if(dp[n]!=-1)
      {
            return dp[n];
      }
       int pick=nums[n]+solve1(n-2,nums,dp);
      int notpick=0+solve1(n-1,nums,dp);
      return dp[n]=max(pick,notpick);

}
//TAbulation(botoom-up)
int solve3(int n,vector<int> &nums,vector<int> &dp)
{
      dp[0]=nums[0];
      for(int i=1;i<=n;i++)
      {
            int pick=nums[i];
            if(i>1)
            {
                  pick+=dp[i-2];
            }
            int notpick=0+dp[i-1];
            dp[i]=max(pick,notpick);
      }
      return dp[n];
}

int main()
{
      vector<int> dp(6,-1);
      vector<int> nums={1,2,3,4,9};
      cout<<"The maximum cost the robber can rob "<<solve3(4,nums,dp);
      return 0;
}