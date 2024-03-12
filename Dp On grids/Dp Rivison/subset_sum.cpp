#include <iostream>
using namespace std;
#include <bits/stdc++.h>
void solve(vector<int> &nums, vector<int> &path, vector<vector<int>> &ans, int index,int target)
{
      if(index>=nums.size())
      {
            if(target==0){
            ans.push_back(path);
            }
            return;
      }
     
      if(target>=nums[index])
      {
             path.push_back(nums[index]);
            solve(nums,path,ans,index,target-nums[index]);
             path.pop_back();
            
      }
     
      solve(nums,path,ans,index+1,target);




}
int main()
{
      vector<int> nums = {1, 2, 3};
      vector<vector<int>> ans;
      vector<int> path;
      solve(nums, path, ans, 0,3);
      for(int i=0;i<ans.size();i++)
      {
            for(int j=0;j<ans[i].size();j++)
            {
                  cout<<ans[i][j]<<" ";
            }
            cout<<endl;
      }
}

