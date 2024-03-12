
#include<iostream>
using namespace std;
#include<bits/stdc++.h>
bool solve(int i,int j,string &s1,string &s2,vector<vector<int>> &dp)
{
    if(i<0&&j<0)
    {
        return true;
    
    }
    if(j<0&&i>=0)return false;
    if(j>=0&&i<0)
    {
        while(j>=0)
        {
            if(s2[j]!='*')
            {
                return false;
            }
           j--;
        }
        return true;
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    if(s1[i]==s2[j]||s2[j]=='?')
    {
        return  dp[i][j]=solve(i-1,j-1,s1,s2,dp);
    }
   
    else if(s2[j]=='*')
    {
        return  dp[i][j]=solve(i-1,j,s1,s2,dp)||solve(i,j-1,s1,s2,dp);
    }
    else {
        return dp[i][j]=false;
    }
}
int main()
{
      string s="paras";
      string p="aeadad";
      int n=s.length();
        int m=p.length();
        vector<vector<int>> dp(n+1,vector<int> (m+1,-1));
         cout<<solve(n-1,m-1,s,p,dp);

      
}
