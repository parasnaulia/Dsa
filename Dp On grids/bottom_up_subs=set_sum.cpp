#include<iostream>
using namespace std;
#include<bits/stdc++.h>
int main()
{
      vector<int> nums={1,2,3};
      int target=3;
      int n=nums.size();
vector<vector<bool>> dp(n,vector<bool> (target+1,false));
//Writing the base case bro
for(int i=0;i<n;i++)
{
      dp[i][0]=true;
}
 dp[0][nums[0]] = true;
for(int i=1;i<n;i++)
{
      for(int j=1;j<=target;j++)
      {
            bool take=false;
            if(j>=nums[i])
            {
                  take=dp[i-1][j-nums[i]];
                  
            }
            bool notTake=dp[i-1][j];
            dp[i][j]=take||notTake;
            

      }
}
cout<<"Printing the dp"<<endl;
for(int i=0;i<dp.size();i++)
{
      for(int j=0;j<dp[0].size();j++)
      {
            cout<<dp[i][j]<<" ";
      }
      cout<<endl;
}
return 0;

}