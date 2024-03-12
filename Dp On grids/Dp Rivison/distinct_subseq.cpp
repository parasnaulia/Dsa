#include<iostream>
using namespace std;
#include<bits/stdc++.h>
int solve(string s1,string s2,int n,int m)
{
      if(n<0)
      {
            return 0;

      }
      if(m<0)
      {
            return 1;
      }
      if(s1[n]==s2[m])
      {
            return solve(s1,s2,n-1,m-1)+solve(s1,s2,n-1,m);
      }
      return solve(s1,s2,n-1,m);
}
int main()
{
      string s1="paras";
      string s2="as";
      int n=s1.length();
      int m=s2.length();
      cout<<solve(s1,s2,n-1,m-1)<<endl;
}