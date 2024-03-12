#include<iostream>
using namespace std;
#include<bits/stdc++.h>
int solve(vector<int> &height,int index,int n,int k)
{
      if(index==0)
      {
            return 0;
      }
      int maxi=INT_MAX;
      for(int i=1;i<=k;i++)
      {
            if(index-i>=0){
            int ans=solve(height,index-i,n,k)+abs(height[index]-height[index-i]);
            maxi=min(ans,maxi);
            }
      }
      return maxi;
}
int main()
{
         int n=6;
      vector<int> height={10,20,30,40};
      vector<int> dp(n+1,-1);
      cout<<solve(height,height.size()-1,height.size(),3);

}