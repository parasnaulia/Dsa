#include<iostream>
using namespace std;
#include<bits/stdc++.h>
int solve(string s1,string s2,int n,int m)
{
      if(n<0||m<0)
      {
            return 0;
      }
      int ans=0;
      if(s1[n]==s2[m])
      {
            ans=solve(s1,s1,n-1,m-1);
      }
      else
      {
            ans=max(solve(s1,s2,n-1,m),solve(s1,s2,n,m-1));
      }
      return ans;
}
int main()
{
      string s1="paras";
      string s2="raspa";
      int n=s1.length();
      int m=s2.length();
      cout<<"MAximum subsequence is:"<<solve(s1,s1,n-1,m-1);
      return 0;


}
