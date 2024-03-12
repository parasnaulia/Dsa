#include<iostream>
using namespace std;
//Time complexity n factorial 

#include<bits/stdc++.h>
void solve(vector<int> &nums,vector<int> &path,vector<vector<int>> &ans,int index)
{
      if(index>=nums.size())
      {
            ans.push_back(nums);
            return;

      }

for(int i=index;i<nums.size();i++)
{
      swap(nums[i],nums[index]);
      solve(nums,path,ans,index+1);
      swap(nums[i],nums[index]);






}

}
int main()
{
      vector<int> nums={1,2,3};
      vector<int> path;
      vector<vector<int>> ans;
     
      solve(nums,path,ans,0);
      for(int i=0;i<ans.size();i++)
      {
            for(auto x:ans[i])
            {
                  cout<<x<<" ";
            }
            cout<<endl;

      }
}