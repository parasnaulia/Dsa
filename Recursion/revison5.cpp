#include<iostream>
using namespace std;
#include<bits/stdc++.h>
void solve(vector<int> &nums,int target,int index,vector<int> path,vector<vector<int>> &ans)
{
      if(index>=nums.size())
      {
            if(target==0)
            {
                  ans.push_back(path);

            }
            return;

      }
      if(target>=nums[index])
      {
            path.push_back(nums[index]);
            solve(nums,target-nums[index],index+1,path,ans);
            path.pop_back();

      }
      
      
            solve(nums,target,index+1,path,ans);
            return;
      
}
int main()
{
      vector<int> nums={1,2,3};
      int target=5;
      vector<int> path;
      vector<vector<int>> ans;
      solve(nums,target,0,path,ans);
      for(int i=0;i<ans.size();i++)
      {
            for(auto x:ans[i])
            {
                  cout<<x<<" ";
            }
            cout<<endl;
      }
}
