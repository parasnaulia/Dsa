#include <iostream>
using namespace std;
#include <bits/stdc++.h>
int solve(vector<int> &weight, vector<int> &value, int W,  int index,vector<vector<int>> &dp)
{
      if (index < 0)
      {
            return 0;
      }
      if(dp[index][W]!=-1)
      {
            return dp[index][W];
      }
      int take = INT_MIN;
      if (weight[index] <= W)
      {
            take = value[index] + solve(weight, value, W - weight[index], index - 1,dp);
      }
      int notTake=solve(weight,value,W,index-1,dp);
      return  dp[index][W]=max(take,notTake);
}
int main()
{
      vector<int> weight = {1, 2, 3, 4};
      vector<int> value = {4, 5, 6, 7};
      int W = 5;
      int index = 4;
      vector<vector<int>> dp(index+1,vector<int> (W+1,-1));
      cout << solve(weight, value, W, index - 1,dp);
      return 0;
}