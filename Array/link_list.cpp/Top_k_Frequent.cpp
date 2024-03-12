#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
vector<int> solve(vector<int> nums,int n,int k)
{
    unordered_map<int,int> umap;
    for(int i=0;i<nums.size();i++)
    {
        umap[nums[i]]++;
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int count=0;
    for(auto it=umap.begin();it!=umap.end();it++)
    {
        count++;
        pq.push({it->second,it->first});
        if(count>k)
        {
            pq.pop();

        }

        
    }
     vector<int> ans1;
    while(!pq.empty())
    {
        ans1.push_back(pq.top().second);
        pq.pop();

    }
   

   return ans1;


}
int main()
{
    vector<int> nums={1,1,1,2,2,3,3,3,4,5,5,5,5,5};
      vector<int> ans=solve(nums,nums.size(),2);
      for(int i=0;i<ans.size();i++)
      {
        cout<<ans[i]<<" ";

      }
    return 0;
}
