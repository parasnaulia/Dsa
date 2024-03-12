#include<iostream>
using namespace std;
#include<bits/stdc++.h>
int solve(vector<int> &value,int i,int j)
{
      if(i>=j)
      {
            return 0;
      }
      int mini=INT_MAX; 
      for(int k=i;k<j;k++)
      {
            int steps=value[i-1]*value[j]*value[k]+solve(value,i,k)+solve(value,k+1,j);
            mini=min(steps,mini); 

            



      }

      return mini;
}
int main()
{
      vector<int> nums={40, 20, 30, 10, 30};
      cout<<solve(nums,1,nums.size()-1);

}