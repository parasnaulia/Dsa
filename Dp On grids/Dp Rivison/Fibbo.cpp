#include<iostream>
using namespace std;
#include<bits/stdc++.h>
int solve(int n,vector<int> &dp)
{
      if(n==0)
      {
            return 0;
      } 

      if(n==1)
      {
            return 1;
      }
      int left=solve(n-1,dp);
      int right=solve(n-2,dp);
      return dp[n]=left+right;
}
int main()
{
      int n=6;
      vector<int> height={10,20,30,40};
      vector<int> dp(n+1,-1);
      cout<<solve(height,height.size()-1);


}