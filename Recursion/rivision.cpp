#include<iostream>
using namespace std;
#include<bits/stdc++.h>
void solve(vector<int> &nums,vector<int> &ans,int sum,int n,int index)
{
      if(index>=nums.size())
      {
            ans.push_back(sum);
            return;
      }
  
      solve(nums,ans,sum+nums[index],n,index+1);
      solve(nums,ans,sum,n,index+1);
}
int main()
{
      vector<int> nums={1,2,2};
      vector<int> ans;
      int sum=0;
      solve(nums,ans,sum,nums.size(),0);
      for(int i=0;i<ans.size();i++)
      {
          cout<<ans[i]<<" ";
           
      }
      cout<<endl;
      return 0;

}