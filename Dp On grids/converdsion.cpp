
#include<iostream>
using namespace std;
#include<bits/stdc++.h>
int minCostToGivenString(string str1, string str2)
{

    int n=str1.length();
    int m=str2.length();
     vector<vector<int>> dp(n+1,vector<int> (m+1,0));
    if(n>m||m>n)
    {
        return -1;
    }
    // Write your Code here
   
    //Intializing the base case
    for(int i=0;i<=n;i++)
    {
        dp[i][0]=0;
    }
    for(int j=0;j<=m;j++)
    {
        dp[0][j]=0;
    }
    //Now applying the loops
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(str1[i-1]==str2[j-1])
            {
                dp[i][j]=1+dp[i-1][j-1];
            }
            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    //So this will be total number of operation to covert one string to another
    return  abs(n-dp[n][m]);



}
int main()
{
      string str1="AbcD";
      string str2="bcAD";
      int n=str1.length();
      int m=str2.length();
     
      cout<<minCostToGivenString(str1,str2);
}