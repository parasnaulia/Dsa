#include<iostream>
using namespace std;
#include<bits/stdc++.h>
//Memo toh hogya hai bc
int solve(string s1,string s2,int n,int m,vector<vector<int>> &dp)
{
      if(n<0||m<0)
      {
            return 0;
      }
      if(dp[n][m]!=-1)
      {
            return dp[n][m];
      }
      
      
      if(s1[n]==s2[m])
      {
            return dp[n][m]=1+solve(s1,s2,n-1,m-1,dp);
      }
      else
      {
       return dp[n][m]=max(solve(s1,s2,n-1,m,dp),solve(s1,s2,n,m-1,dp));
      }
      
}
int main()
{
      string s1="parasnaulia";
      string s2="parasnauliya";
      int n=s1.length();
      int m=s2.length();
      vector<vector<int>> dp(n+1,vector<int> (m+1,-1));
      cout<<"MAximum subsequence is:"<<solve(s1,s2,n-1,m-1,dp);
      return 0;


}
