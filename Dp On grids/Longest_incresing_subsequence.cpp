#include<iostream>
using namespace std;
#include<bits/stdc++.h>
//Memoization code
int solve(int index,int prev,vector<int> &nums,vector<vector<int>> &dp)
{
      if(index==nums.size())
      {
            return 0;
      }
      if(dp[index][prev+1]!=-1)
      {
            return dp[index][prev+1];
      }
      int take=0;
      if(prev==-1||nums[index]>nums[prev])
      {
            take=1+solve(index+1,index,nums,dp);
      }
      int notTake=0+solve(index+1,prev,nums,dp);
      return dp[index][prev+1]= max(take,notTake);

}
//bOTTOM UP
// int solve1(int inpkdqmoqknvo kdkklksdcksckck knck)
vector<int> solve2( vector<int> &nums)
{
      int n=nums.size();
      vector<int> dp(n,1);
      for(int i=0;i<n;i++)
      {
            for(int j=0;j<=i-1;j++)
            {
                  if(nums[i]>nums[j])
                  {
                        if(dp[i]<1+dp[j])
                        {
                              dp[i]=1+dp[j];
                        }
                  }

            }
      }
      return dp;


}
int main()
{
      vector<int>nums= {7,7,7,7,7,7,7};
    //  vector<vector<int>> dp(nums.size()+1,vector<int> (nums.size()+1,0));
     // cout<<"Longest Increasing subsequence"<<solve(0,-1,nums,dp);
     //bottom up
     //Writing Base case
//      int n=nums.size();
//      for(int i=0;i<=n;i++)
//      {
//       dp[n][i]=0;
//      }
//      //Writing loops
//      for(int i=n-1;i>=0;i--)
//      {
//       for(int j=i-1;j>=-1;j-- )
//       {
//             int take=0;
//             if(j==-1||nums[i]>nums[j])
//             {
//                   take=1+dp[i+1][i];


//             }
//             int notTake=0+dp[i+1][j+1];
//             dp[i][j+1]=max(take,notTake);
//       }
//      }
//      cout<<dp[0][0];
vector<int> dp=solve2(nums);
for(int i=0;i<dp.size();i++)
{
      cout<<dp[i]<<" ";
}

      return 0;

}