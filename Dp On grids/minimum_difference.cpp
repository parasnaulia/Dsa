#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool solve2(vector<int>arr, int sum,vector<vector<int>> &dp){
        // code here
        int n = arr.size();
        
        for(int i = 0; i<n+1; i++){
            for(int j = 0; j<sum+1; j++){
                if(i==0){
                    dp[i][j] = false;
                }
                if(j == 0){
                    dp[i][j] = true;
                }
            }
        }
        for(int i = 1; i<n+1; i++){
            for(int j = 1; j<sum+1; j++){
                if(arr[i]<=sum){
                    dp[i][j] = dp[i-1][j-arr[i-1]]||dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][sum];
    }
  bool helper(int index,vector<int>&arr,int sum,vector<vector<int>>&dp)
    {
        if(sum==0) return true;
        if(index==0) return (sum==arr[index]);
        bool nottaken=helper(index-1,arr,sum,dp);
        bool taken=false;
        if(sum>=arr[index])
        {
            taken=helper(index-1,arr,sum-arr[index],dp);
        }
        
        return dp[index][sum]=taken or nottaken;
    }  
 bool solve2(vector<int>arr, int sum,vector<vector<int>> &dp){
        // code here
        int n = arr.size();
        
        for(int i = 0; i<n+1; i++){
            for(int j = 0; j<sum+1; j++){
                if(i==0){
                    dp[i][j] = false;
                }
                if(j == 0){
                    dp[i][j] = true;
                }
            }
        }
        for(int i = 1; i<n+1; i++){
            for(int j = 1; j<sum+1; j++){
                if(arr[i]<=sum){
                    dp[i][j] = dp[i-1][j-arr[i-1]]||dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][sum];
    }
int main()
{
      vector<int> nums={1,2,3};
      int sum=0;
      sort(nums.begin(),nums.end());
      for(int i=0;i<nums.size();i++)
      {
            sum+=nums[i];
      }
      int n=nums.size();
      vector<vector<int>> dp(nums.size(),vector<int> (sum+1,-1));
      vector<vector<int>> dp1(nums.size()+1,vector<int> (sum+1,-1));

      solve(nums,sum,nums.size()-1,dp);
     // helper(n-1,nums,sum,dp);
      solve2(nums,sum,dp1);
     // int mini=INT_MAX;
      // for(int i=0;i<dp[0].size();i++)
      // {
      //       if(dp[n-1][i])
      //       {
      //             int s1=i;
      //             int s2=sum-s1;
      //             mini=min(mini,abs(s1-s2));


      //       }
      // }
      for(int i=0;i<dp.size();i++)
      {
            for(int j=0;j<dp[0].size();j++)
            {
                  cout<<dp[i][j]<<" ";
            }
            cout<<endl;
      }
      cout<<endl;
      cout<<endl;
        for(int i=0;i<dp1.size();i++)
      {
            for(int j=0;j<dp1[0].size();j++)
            {
                  cout<<dp1[i][j]<<" ";
            }
            cout<<endl;
      }
      //cout<<"The Minimum diff is"<<endl;
      //cout<<mini;
      return 0;
}
