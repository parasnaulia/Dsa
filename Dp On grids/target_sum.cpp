#include<iostream>
using namespace std;
#include<bits/stdc++.h>
int solve(int index,vector<int> &nums,int sum,int target)
{
      if(index<0)
      {
            if(target==sum)
            {
                  return 1;
            }
            return 0;
      }
      int take=solve(index-1,nums,sum+nums[index],target);
      int notTake=solve(index-1,nums,sum-nums[index],target);
      return take+notTake;
}
int main()
{
      vector<int> nums={1,1,1,1,1};
      int target=3;
      int sum=0;
      cout<<"Total combination is: "<<solve(nums.size()-1,nums,sum,target);
}