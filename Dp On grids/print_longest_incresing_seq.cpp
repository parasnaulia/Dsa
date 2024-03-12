#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
      vector<int> nums={1,2,3,4,5};
      //vector<int> dp(nums.size(),1);
      vector<int> temp(nums.size());
      for(int i=0;i<nums.size();i++)
      {
            temp[i]=i;
      }
int n=nums.size();
      vector<int> dp(n,1);
      for(int i=0;i<n;i++)
      {
            for(int j=0;j<=i-1;j++)
            {
                  if(nums[i]>nums[j])
                  {
                        if(dp[i]<1+dp[j])
                        {
                              dp[i]=1+dp[j];
                              temp[i]=j;
                        }
                  }

            }
      }
      int maxi=INT_MIN;
      int index=0;
      for(int i=0;i<nums.size();i++)
      {
            if(dp[i]>maxi)
            {
                  index=i;
                  maxi=dp[i];
            }
      }
      vector<int> ans;
      ans.push_back(nums[index]);
      int count=maxi-1;
      while(count>0)
      {
            int it=temp[index];
            ans.push_back(nums[it]);
            index=it;
            count--;



      }
      reverse(ans.begin(),ans.end());
       for(int i=0;i<ans.size();i++)
      {
            cout<<ans[i]<<" ";
      }
      cout<<endl;
      cout<<maxi<<endl;

      for(int i=0;i<nums.size();i++)
      {
            cout<<temp[i]<<" ";
      }
     
      



}