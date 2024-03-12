#include<iostream>
using namespace std;
#include<bits/stdc++.h>
int main()
{
      string s1="abcc";
      string s2="ascc";
      int n=s1.length();
      int m=s2.length();
      vector<vector<int>> dp(n+1,vector<int> (m+1,0));
      //Initializing base condition
      for(int i=0;i<=n;i++)
      {
            dp[i][0]=0;
      }
      for(int j=0;j<=m;j++)
      {
            dp[0][j]=0;
      }
      //Now writing the loops
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
                        dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                  }
            }
      }

      //Printing the dp
      for(int i=0;i<=n;i++)
      {
            for(int j=0;j<=m;j++)
            {
                  cout<<dp[i][j]<<" ";
            }
            cout<<endl;
      }

      //printing Lcs
      string ans="";
      int i=n;
      int j=m;
      while(i>0&&j>0)
      {
            if(s1[i-1]==s2[j-1])
            {
                  ans+=s1[i-1];
                  i--;
                  j--;
            }
            else{
                  if(dp[i-1][j]>=dp[i][j-1])
                  {
                        i--;
                  }
                  else if(dp[i-1][j]<dp[i][j-1])
                  {
                        j--;
                  }
            }
          

      }
      reverse(ans.begin(),ans.end());
      cout<<"The  Longest sequence will be "<<ans<<endl;
      return 0;

}