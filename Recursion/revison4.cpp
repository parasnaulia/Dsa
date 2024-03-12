#include<iostream>
using namespace std;
#include<bits/stdc++.h>
//complexity 2^target*n*logn(n);
//So we have to optimised it

void solve(vector<int> &nums,int target,vector<int> path,set<vector<int>> &ans,int index)
{
      if(nums.size()<=index)
      {
      if(target==0)
      {
            ans.insert(path);

           
      }
       return;

            }      
            if(nums[index]<=target)
      {
            path.push_back(nums[index]);
            solve(nums,target-nums[index],path,ans,index);
            path.pop_back();
      }
      solve(nums,target,path,ans,index+1);

}
int main()
{
      vector<int> nums={1,2,2,3,4};
      int target=5;
      vector<int> path;
      set<vector<int>> ans;
      solve(nums,target,path,ans,0);
      for(auto x:ans)
      {
            for(auto y:x)
            {
                  cout<<y<<" ";
            }
            cout<<endl;
      }

}
