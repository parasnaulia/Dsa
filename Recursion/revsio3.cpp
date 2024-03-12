#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//I have to print teh unique elements
void solve(vector<int> &nums,int index,int n,vector<int> v, vector<vector<int>> &ans)
{
      ans.push_back(v);
      for(int i=index;i<nums.size();i++)
      {
            if(index!=i&&nums[i]==nums[i-1])
            {
                  continue;
            
            }
            v.push_back(nums[i]);
            solve(nums,i+1,n,v,ans);
            v.pop_back();
      


      }
}
int main()
{
      vector<int> nums={1,2,2};
      vector<int> v;
      vector<vector<int>> ans;
      solve(nums,0,nums.size(),v,ans);
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