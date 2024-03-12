#include<iostream>
using namespace std;
#include<bits/stdc++.h>
int solve(vector<int> &nums,int n,int index,int prev)
{
      if(index>=n)
      {
            return 0;
      }
      int take=0;
      if(prev==-1||nums[index]>=nums[prev])
      {
            take=1+solve(nums,n,index+1,index);
      }
      int notTake=0+solve(nums,n,index+1,prev);
      return max(take,notTake);
}
int solve1(vector<int> &nums,int n)
{
      vector<vector<int>> dp(n+1,vector<int> (nums.size()+1,0));
      for(int index=n-1;index>=0;index--)
      {
            for(int prev=index-1;prev>=-1;prev--)
            {
                  int take=0;
                  if(prev==-1||nums[index]>nums[prev])
                  {
                        take=1+dp[index+1][prev+1];

                  }
                  int notTake=0+dp[index+1][prev+1];
                  dp[index][prev+1]=max(take,notTake);

            }
      }
      return dp[1][0];
}

int main()
{
      vector<int> nums={1,2,3,4,0,9,90};
      int n=nums.size();
      int prev=-1;
      cout<<solve1(nums,n);
      //cout<<solve(nums,n,0,-1);

}
