#include <iostream>
using namespace std;
#include <bits/stdc++.h>
int solve(vector<vector<int>> &nums, int i, int j, vector<vector<int>> &dp)
{
      if (i ==nums.size()-1)
      {
            return nums[nums.size()-1][j];
      }
      // if (i < 0 || j < 0)
      // {
      //       return 1e9;
      // }
      if(dp[i][j]!=-1)
      {
            return dp[i][j];
      }
      int left = nums[i][j] + solve(nums, i+1, j,dp);
      int up = nums[i][j] + solve(nums, i+1, j+1,dp);
      return  dp[i][j]=min(left, up);
}
int main()
{
      vector<vector<int>> nums = {{1}, {3, 4}, {9, 9, 8}};
      int i = 0;
      int j =0;
      vector<vector<int>> dp(3 + 1, vector<int>(3 + 1, -1));
      cout << solve(nums, i , j , dp);
}
