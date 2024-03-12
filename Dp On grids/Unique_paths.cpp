#include<iostream>
using namespace std;
#include<bits/stdc++.h>
int solve(int n,int m)
{
      if(n==0&&m==0)
      {
            return 1;
      }
      if(n<0||m<0)
      {
            return 0;
      }
      int left=solve(n-1,m);
      int right=solve(n,m-1);
      return left+right;

}
int main()
{
      int n=3;
      int m=7;
      cout<<solve(n-1,m-1);
      
}