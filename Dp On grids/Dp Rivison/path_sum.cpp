#include <iostream>
using namespace std;
#include <bits/stdc++.h>
int solve(vector<vector<int>> &nums, int i, int j, vector<vector<int>> &dp)
{
      if (i == 0 && j == 0)
      {
            return nums[0][0];
      }
      if (i < 0 || j < 0)
      {
            return 1e9;
      }
      if(dp[i][j]!=-1)
      {
            return dp[i][j];
      }
      int left = nums[i][j] + solve(nums, i - 1, j,dp);
      int up = nums[i][j] + solve(nums, i, j - 1,dp);
      return  dp[i][j]=min(left, up);
}
int main()
{
      vector<vector<int>> nums = {{1, 2, 3}, {3, 4, 5}, {6, 7, 8}};
      int i = nums.size();
      int j = nums[0].size();
      vector<vector<int>> dp(i + 1, vector<int>(j + 1, -1));
      cout << solve(nums, i - 1, j - 1, dp);
}
