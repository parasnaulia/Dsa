#include<iostream>
using namespace std;
#include<bits/stdc++.h>
int solve(vector<int> &weight,vector<int> &value,int index,int W,vector<vector<int>> &dp)
{
      // if(index<=0)
      // {
      //       return value[index];
      // }
       if(index<0)
       {
             return 0;
      }
      if(dp[index][W]!=-1)
      {
            return dp[index][W];
      }
      //Taking the weight
      int take=0;
      if(W>=weight[index])
      {
            take=value[index]+solve(weight,value,index-1,W-weight[index],dp);


      }
      int notTake=solve(weight,value,index-1,W,dp);

      return dp[index][W]= max(take,notTake);
}
// int solve(vector<int> &weight, vector<int> &value, int index, int W, vector<vector<int>> &dp) {
//     if (index < 0 || W <= 0) {
//         return 0;
//     }
//     if (dp[index][W] != -1) {
//         return dp[index][W];
//     }

//     int take = 0;
//     if (W >= weight[index]) {
//         take = value[index] + solve(weight, value, index - 1, W - weight[index], dp);
//     }

//     int notTake = solve(weight, value, index - 1, W, dp);

//     return dp[index][W] = max(take, notTake);
// }

int bottom_up(vector<int> &weight,vector<int> &value,int sum,int W,int N)
{
      vector<vector<int>> dp(N+1,vector<int>(W+1,0));
      //We know the base case
      for(int i=0;i<=W;i++)
      {
            dp[0][i]=0;
      }
      for(int i=0;i<N;i++)
      {
            dp[i][0]=1;
      }
      for(int i=1;i<=N;i++)
      {
            for(int j=1;j<=W;j++)
            {
                  int take=0;
                  if(j>=weight[i])
                  {
                        take=dp[i-1][j-weight[i]]+value[i];
                  }
                  int notTake=dp[i-1][j];
                  dp[i][j]=max(take,notTake);
            }
      }
return dp[N][W];

}

int main()
{
      vector<int> weight={1,2,3};
      vector<int> value={4,5,6};
      int W=3;
      int n=weight.size();
      vector<vector<int>> dp(n,vector<int>(W+1,-1));
     // cout<<"The MAximum value is :"<<bottom_up(weight,value,W,W,n);
     cout<<solve(weight,value,value.size()-1,W,dp);
      return 0;
}