#include<iostream>
using namespace std;
#include<bits/stdc++.h>
int fg(int n,int k,vector<int> &nums,vector<int> &dp)
{
   
      if(n==0)
      {
            return 0;
      }
      if(dp[n]!=-1)
      {
            return dp[n];
      }
      int mx=INT_MAX;
      
      for(int i=1;i<=k;i++)
      {
            if(n-i>=0){
            int ans=fg(n-i,k,nums,dp)+abs(nums[n]-nums[n-i]);
            dp[n-i]=min(mx,ans);
            }
            
      }
      return dp[n-1];
}
int main()
{
      vector<int> dp(8,-1);
      dp[0]=0;
      vector<int> nums={2,3,4,5,7,8,9,10};
      cout<<fg(7,2,nums,dp);
      return 0;

}