#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int solve(string s1,string s2,int i,int j)
{
      if(i<0||j<0)
      {
            return 0;
      }
      if(s1[i]==s2[j])
      {
            return 1+solve(s1,s2,i-1,j-1);
      }
      return 0;
}
int main()

{
      string s1="paras";
      string s2="apara";
      int n=s1.length();
      int m=s2.length();
      int maxi=INT_MIN;
      for(int i=0;i<n;i++)
      {
            for(int j=0;j<m;j++)
            {
            maxi=max(maxi,solve(s1,s2,i,j));
            }

      }
      cout<<"The MAximum Substing is :"<<maxi<<endl;
      
}