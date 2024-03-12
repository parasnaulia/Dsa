#include<iostream>
using namespace std;
#include<bits/stdc++.h>
void solve(int n,int index,vector<int> &nums,vector<int> path,set<vector<int>> & ans)
{
      if(index>=n)
      {
            ans.insert(path);
            return;
      }
      path.push_back(nums[index]);
      solve(n,index+1,nums,path,ans);
      path.pop_back();
      solve(n,index+1,nums,path,ans);
      return;

}

int main()
{
      vector<int> nums={1,2,2};
      vector<int> v;
      set<vector<int>> ans;
      solve(nums.size(),0,nums,v,ans);
      for(auto x:ans)
      {
            for(int i=0;i<x.size();i++)
            {
                  cout<<x[i]<<" ";
            }
            cout<<endl;
      }
      cout<<ans.size()<<" Number of sunbsets"<<endl;

}
//Complexity is 2^n*nlogn

