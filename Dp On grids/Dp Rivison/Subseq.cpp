#include<iostream>
using namespace std;
#include<bits/stdc++.h>
int solve(string s1,string s2,int i,int j)
{
      if(i==0||j==0)
      {
            return 0;
      }
      if(s1[i-1]==s2[j-1])
      {
            return 1+solve(s1,s2,i-1,j-1);
      }
      int take1=solve(s1,s2,i-1,j);
      int take2=solve(s1,s2,i,j-1);
      return max(take1,take2);
}
int main()
{
      string s1="paras";
      string s2="raspa";
      int i=s1.length();
      int j=s2.length();
      int n=s1.length();
      int m=s2.length();
     // cout<<solve(s1,s2,i,j);
     //Bottom up dp
     //Writing the base case
     vector<vector<int>> dp(i+1,vector<int> (j+1,0));
     for(int i=0;i<=j;i++)
     {
      dp[i][0]=0;
     }
     for(int j=0;j<=i;j++)
     {
      dp[0][j]=0;
     }
     for(int i=1;i<=n;i++)
     {
      for(int j=1;j<=m;j++)
      {
            if(s1[i-1]==s2[j-1])
            {
                  dp[i][j]=1+dp[i-1][j-1];
            }
            else
            {
                  int pp1=dp[i-1][j];
                  int pp2=dp[i][j-1];
                  dp[i][j]=max(pp1,pp2);
            }

      }
     }
     cout<<dp[n][m]<<" ";
}