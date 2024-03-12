#include<iostream>
using namespace std;
#include<bits/stdc++.h>
int solve(int n,int last,vector<vector<int>> &grid)
{
      if(n==0)
      {
            int maxi=0;
            
            for(int i=0;i<3;i++)
            {
                  if(i!=last)
                  {
                        maxi=max(maxi,grid[0][i]);
                  }
            }
            return maxi;
            //This is my base case
      }
      int maxi=0;
      for(int i=0;i<3;i++)
      {
            if(i!=last)
            {
                  int ans=grid[n][i]+solve(n-1,i,grid);
                  maxi=max(ans,maxi);


            }
      }
      return maxi;
}
//memozise code dp
                                                                      
int solve1(int n,int last,vector<vector<int>> &grid,vector<vector<int>>&dp)
{
      if(n==0)
      {
            int maxi=0;
            for(int i=0;i<3;i++)
            {
                  if(i!=last)
                  {
                        maxi=max(maxi,grid[0][i]);
                  }
            }
            return maxi;
            //This is my base case
      }
      if(dp[n][last]!=-1)
      {
          return dp[n][last];
      }
      int maxi=0;
      for(int i=0;i<3;i++)
      {
            if(i!=last)
            {
                  int ans=grid[n][i]+solve1(n-1,i,grid,dp);
                  maxi=max(ans,maxi);


            }
      }
      return  dp[n][last]=maxi;
}

int main()
{
      int n=4;
      vector<vector<int>> nums={{1,2,3},{2,3,4},{4,5,6},{7,8,9}};
       vector<vector<int>> dp(n+1,vector<int> (5,-1));
      cout<<"The maxi sum it can take is "<<solve1(3,3,nums,dp);
      return 0;
}