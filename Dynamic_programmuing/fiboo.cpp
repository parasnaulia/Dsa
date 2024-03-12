#include<iostream>
using namespace std;
#include<bits/stdc++.h>
//its complexity is o(n)

int fiboo(int n,vector<int> &dp)
{
      if(n==1)
      {
            return 1;
      }
      if(n==0)
      {
            return 0;
      }
      if(dp[n]!=-1)
      {
            return dp[n];
      }
      return dp[n]=fiboo(n-1,dp)+fiboo(n-2,dp);
}
int fiboop_top_down(int n,vector<int> dp)
{
      dp[0]=0;
      dp[1]=1;
      for(int i=2;i<=n;i++)
      {
            dp[i]=dp[i-1]+dp[i-2];
      }
      return dp[n];
}
int main()
{
      vector<int> dp(9,-1);
      //int ans=fiboo(8,dp);
       
      int ans=fiboop_top_down(8,dp);
      cout<<ans;
      return 0;

      
}

