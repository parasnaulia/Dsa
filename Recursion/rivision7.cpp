#include<iostream>
using namespace std;
//#include<algorithm>
#include<bits/stdc++.h>
void solve(vector<int> &nums,int index,vector<int> &path,vector<vector<int>> &ans,int target)
{
      if(target==0)
      {
            ans.push_back(path);
            return;
      }
      for(int i=index;i<nums.size();i++)
      {
            if(i!=index&&nums[i-1]==nums[i])
            {
                  continue;
            }
            if(target<nums[i])
            {
                  break;
            }
            path.push_back(nums[i]);
            solve(nums,i+1,path,ans,target-nums[i]);
            path.pop_back();
            
      }


}
int main()
{
      vector<int> nums={1,2,2};
      int target=3;
      sort(nums.begin(),nums.end());
      vector<int> path;
      vector<vector<int>> ans;
      solve(nums,0,path,ans,target);
      for(int i=0;i<ans.size();i++)
      {
            for(auto x:ans[i])
            {cout<<x<<" ";
            }
            cout<<endl;
      }
}