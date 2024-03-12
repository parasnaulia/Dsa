#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
vector<int> solve(vector<int> nums,int n)
{
    unordered_map<int,int> umap;
    for(int i=0;i<nums.size();i++)
    {
        umap[nums[i]]++;
    }
 //priority_queue<pi, vector<pi>, greater<pi> > pq;
priority_queue<pair<int, int> > pq;
 for(auto x:umap)
 {
    pq.push({x.second,x.first});
 }
vector<int> ans;
while(!pq.empty())
{
    int x=pq.top().second;
    int y=pq.top().first;
    for(int i=0;i<y;i++)
    {
        ans.push_back(x);

    }
    pq.pop();


}
return ans;

}
int main()
{
    vector<int> nums={3,3,5,5,2,1};
     vector<int> ans=solve(nums,nums.size());
     for(int i=0;i<ans.size();i++)
     {
        cout<<ans[i]<<" ";

         }    
         return 0;

}