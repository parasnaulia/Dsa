
     #include<iostream>
using namespace std;
#include<bits/stdc++.h>
int count=0;
int binary_search(vector<int> &ans,int ele)
{
    int low=0;
    int high=ans.size()-1;
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        if(ans[mid]==ele)
        {
            return mid;
        }
        else if(ans[mid]<ele)
        {
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    return low;
}
int solve(vector<int> &nums,int prev,int maxi,int &count,int index)
{
      if(maxi==0)
      {
            count=count+1;
            return 0;

      }
      if(index>=nums.size())
      {
            return 0;
      }
      int take=0;
      if(prev==-1||nums[index]>nums[prev])
      {
            take=1+solve(nums,index,maxi-1,count,index+1);
      }
      
int notTake=0+solve(nums,prev,maxi,count,index+1);
return max(take,notTake);

}
int main()
{
      vector<int> nums={2,2,2,2,2};
       vector<int> lis;

              lis.push_back(nums[0]);

              for (int i = 0; i < nums.size(); i++)
              {
                     if (nums[i] > lis.back())
                     {
                        
                            lis.push_back(nums[i]);
                     }
                     else
                     {
                          int index= binary_search(lis, nums[i]);
                          lis[index]=nums[i];
                     }

                     
              }
              int maxi=lis.size();
              //cout<<maxi<<endl;
              int count=0;
            solve(nums,-1,maxi,count,0);
           cout<<count;



              
    }
