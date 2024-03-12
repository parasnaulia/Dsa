#include<iostream>
using namespace std;
#include<bits/stdc++.h>
void solve(int n,int index,vector<int> &nums,vector<int> path,vector<vector<int>> & ans)
{
      if(index>=n)
      {
            ans.push_back(path);
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
      vector<vector<int>> ans;
      solve(nums.size(),0,nums,v,ans);
      for(int i=0;i<ans.size();i++)
      {
            for(auto x: ans[i])
            {
                  cout<<x<<" ";

            }
            
            cout<<endl;
      }
      cout<<ans.size()<<" Number of sunbsets"<<endl;

}
