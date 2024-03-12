#include<iostream>
using namespace std;
#include<bits/stdc++.h>
int jump(int n,vector<int>&nums)
{
      if(n==0)
      {
            return 0;
      }
      int jump1=jump(n-1,nums)+abs(nums[n]-nums[n-1]);
      int jump2=INT_MAX;
      if(n>1)
      {
            jump2=jump(n-2,nums)+abs(nums[n]-nums[n-2]);
            
      }
      return min(jump1,jump2);
}
int memo_jump(int n,vector<int> &nums,vector<int> &dp)
{
       if(n==0)
      {
            return 0;
      }
      if(dp[n]!=-1)
      {
            return dp[n];
      }
      int jump1=jump(n-1,nums)+abs(nums[n]-nums[n-1]);
      int jump2=INT_MAX;
      if(n>1)
      {
            jump2=jump(n-2,nums)+abs(nums[n]-nums[n-2]);
            
      }
      return  dp[n]=min(jump1,jump2);

}
int bottom_up(int n,vector<int> &nums,vector<int> &dp)
{
      dp[0]=0;
      for(int i=1;i<=n;i++)
      {
             int jump1=dp[i-1]+abs(nums[i]-nums[i-1]);
             int jump2=INT_MAX;
             if(i>1)
             {
                  jump2=dp[i-2]+abs(nums[i]-nums[i-2]);

             }
             dp[i]=min(jump1,jump2);

      }
      return dp[n];
}
int main()
{
      vector<int> nums={2,3,4,5,7,8,9};
      vector<int> dp(7,-1);
      //cout<<"The Minmum sum to get minimum cost is"<<jump(6,nums);
     // cout<<memo_jump(6,nums,dp)<<"is a answer"<<endl;
     cout<<bottom_up(6,nums,dp)<<"is a answer"<<endl;
     cout<<dp[6]<<"adadw";
      return 0;

}