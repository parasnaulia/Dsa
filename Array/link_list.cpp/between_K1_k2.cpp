#include<iostream> 
#include<bits/stdc++.h>
using namespace std;
vector<int> sum(vector<int> nums,int small,int large)
{
    priority_queue<int> p1;
    priority_queue<int,vector<int>,greater<int>> p2;
    for(int i=0;i<nums.size();i++)
    {
        p1.push(nums[i]);
        if(p1.size()>small)
        {
            p1.pop();
        }
    }
int smallest=p1.top();
for(int i=0;i<nums.size();i++)
    {
        p2.push(nums[i]);
        if(p2.size()>large)
        {
            p2.pop();
        }
    }
    vector<int> ans;

    int largest=p2.top();
    for(int i=0;i<nums.size();i++)
    {
        if(nums[i]>smallest&&nums[i]<largest)
        {
            
            ans.push_back(nums[i]);
        }
    }
    return ans;

}

int main()
{
    vector<int> nums={1,2,3,4,5,6,7,8,9,10};
  vector<int> ans=sum(nums,3,6);
  for(int i=0;i<ans.size();i++)
  {
    cout<<ans[i]<<" ";
  }

    return 0;
}