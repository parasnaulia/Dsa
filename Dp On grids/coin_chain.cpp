#include<iostream>
using namespace std;
#include<bits/stdc++.h>
int solve(int index,vector<int> &nums,int amount)
{
      if(index<0)
      {
            if(amount==0)
            {
                  return 0;
            }
            return INT_MAX;
      }
      int take=INT_MAX;
      if(amount>=nums[index])
      {
            take=1+solve(index,nums,amount-nums[index]);
      }
      int notTake=solve(index-1,nums,amount);
      return min(take,notTake);

}
int main()
{
      vector<int> nums={1,2,5,6,11};
      int amount=11;
      cout<<"The Minimum of coins is: "<<solve(nums.size()-1,nums,amount);
}