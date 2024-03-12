#include<iostream>
using namespace std;
#include<bits/stdc++.h>
int solve(string &s1,string &s2,int i,int j,vector<vector<int>> &dp)
{
    if(i==s1.length()||j==s2.length())
    {
        return 0;
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    if(s1[i]==s2[j])
    {
        return dp[i][j]= 1+solve(s1,s2,i+1,j+1,dp);
    }
    return  dp[i][j]=0;
}
int main()
{
       string s1="parasnaulia";
      string s2="parasnauliya";
      int n=s1.length();
      int m=s2.length();
     

    int ans=0;
    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    for(int i=0;i<n;i++)
    {
        for (int j = 0; j < m; j++) {
          ans = max(ans, solve(s1, s2, i, j,dp));
        }
    }

    cout<<"longest substring "<<ans;
}
