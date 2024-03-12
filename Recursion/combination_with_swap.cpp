#include<iostream>
using namespace std;
#include<bits/stdc++.h>
void solve(vector<int> &nums,vector<vector<int>> &ans,int index)
{
      if(index>=nums.size())
      {
            ans.push_back(nums);
            return;
      }
      for(int i=index;i<nums.size();i++)
      {
            swap(nums[i],nums[index]);
            solve(nums,ans,index+1);
            swap(nums[i],nums[index]);
      }
}
int main()
{
      vector<int> nums={1,2,3};
      vector<vector<int>> ans;
      solve(nums,ans,0);
      for(int i=0;i<ans.size();i++)
      {
            for(auto x:ans[i])
            {
                  cout<<x<<" ";
            }
            cout<<endl;
      }
      return 0;
}
