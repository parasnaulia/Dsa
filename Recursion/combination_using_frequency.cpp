#include<iostream>
using namespace std;
#include<bits/stdc++.h>
void solve(int k,vector<int> &nums,vector<vector<int>> &ans,vector<int> op,vector<bool> freq)
{
      if(op.size()==k)
      {
            ans.push_back(op);
            return;
      }
      for(int i=0;i<nums.size();i++)
      {
            if(freq[i]==false)
            {
                  op.push_back(nums[i]);
                  freq[i]=true;
                  solve(k,nums,ans,op,freq);
                  freq[i]=false;
                  op.pop_back();

            }
      }
}
int main()
{
      vector<int> nums={1,2,3};
      vector<vector<int>> ans;
      vector<int> op;
      vector<bool> freq(3,false);
      solve(3,nums,ans,op,freq);
      for(int i=0;i<ans.size();i++)
      {
            for(auto x: ans[i])
            {
                  cout<<x<<" ";
            }
            cout<<endl;
      }




}
