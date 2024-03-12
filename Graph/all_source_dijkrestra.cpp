#include<iostream> 
using namespace std;
#include<bits/stdc++.h>
int main()
{
       unordered_map<int,vector<pair<int,int>>> umap;
      priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
// umap[1].push_back({2,1});
//       umap[1].push_back({3,2});
//       umap[2].push_back({3,-6});
int src=0;
      umap[0].push_back({1,1});
      umap[1].push_back({0,1});
      umap[1].push_back({2,2});
      umap[2].push_back({1,2});
       umap[2].push_back({4,2});
        umap[4].push_back({3,2});
        vector<int> distance(5,INT_MAX);
        vector<vector<int>> ans(5,vector<int> (5,INT_MAX));
        for(int i=0;i<ans.size();i++)
        {
            for(int j=0;j<ans[0].size();j++)
            {
                  if(i==j)
                  {
                        ans[i][j]=0;
                  }
                

            }
        }
         for(int i=0;i<ans.size();i++)
        {for(auto x:umap[i])
            {
                  int v=x.first;
                  int sum=x.second;
                  ans[i][v]=sum;
                

            }
        }
        
   pq.push({0,src});
   
   for(int i=0;i<5;i++)
   {
      distance[i]=0;
        while(!pq.empty())
        {
            int node=pq.top().first;
            for(auto x:umap[node])
            {
                  int wt=x.second;
                  int v=x.first;
                  if(distance[node]+wt<distance[v])
                  {
                        distance[v]=distance[node]+wt;
                        pq.push({distance[v],v});
                        ans[node][v]=distance[v];
                  }
            }
            
        }
   }
    for(int i=0;i<ans.size();i++)
        {
            for(int j=0;j<ans.size();j++)
            { cout<<ans[i][j]<<" ";
                

            }
            cout<<endl;
        }
   

}