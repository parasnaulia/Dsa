#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int solve(int i,int j,string s1,string s2, vector<vector<int>> &dp)
{
    if(i==0)
    {
        return j;
    }
    if(j==0)
    {
        return i;
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    if(s1[i-1]==s2[j-1])
    {
        return dp[i][j]= solve(i-1,j-1,s1,s2,dp);
    }
    else
    {
        int insert=1+solve(i,j-1,s1,s2,dp);
        int del=1+solve(i-1,j,s1,s2,dp);
        int rep=1+solve(i-1,j-1,s1,s2,dp);
        return dp[i][j]= min(insert,min(del,rep));
    }
}
int main()
{
      string s1="intention";
      string s2="execution";
      int n=s1.length();
      int m=s2.length();
       // vector<vector<int>> dp(n+1,vector<int> (m+1,-1));
      //cout<<solve(n,m,s1,s2,dp);
       vector<vector<int>> dp(n+1,vector<int> (m+1,0));
      //  return solve(n,m,s1,s2,dp);
      //writing the base case
      for(int i=0;i<=n;i++)
      {
          dp[i][0]=i;
      }
       for(int j=0;j<=m;j++)
      {
          dp[0][j]=j;
      }
      for(int i=1;i<=n;i++)
      {
          for(int j=1;j<=m;j++)
          {
              if(s1[i-1]==s2[j-1])
              {
                  dp[i][j]=dp[i-1][j-1];
              }
              else
              {
                  int insert=1+dp[i-1][j];
                  int del=1+dp[i][j-1];
                  int rep=1+dp[i-1][j-1];
                  dp[i][j]=min(insert,min(del,rep));
              }
          }
      }
      cout<<dp[n][m];

}