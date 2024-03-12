#include<iostream>
using namespace std;
//Time complexity n factorial 

#include<bits/stdc++.h>
void solve(vector<int> &nums,vector<int> &path,vector<vector<int>> &ans,vector<bool> &freq)
{
if(path.size()==nums.size())
{
      ans.push_back(path);
      return;


}
for(int i=0;i<nums.size();i++)
{
      if(freq[i]==false)
      {
            freq[i]=true;
            path.push_back(nums[i]);
            solve(nums,path,ans,freq);
            path.pop_back();
            freq[i]=false;

      }


}

}
int main()
{
      vector<int> nums={1,2,3};
      vector<int> path;
      vector<vector<int>> ans;
      vector<bool> freq(nums.size(),false);
      solve(nums,path,ans,freq);
      for(int i=0;i<ans.size();i++)
      {
            for(auto x:ans[i])
            {
                  cout<<x<<" ";
            }
            cout<<endl;

      }
}