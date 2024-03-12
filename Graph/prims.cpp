#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//PRims algo ia use to find minimum spanning tree
int main()
{
      unordered_map<int,vector<pair<int,int>>> umap;
      umap[0].push_back({1,2});
      umap[0].push_back({2,3});
      umap[1].push_back({ 4,1});
      umap[4].push_back({3,3});
      umap[2].push_back({3,2});
      //Applying prims algorith
      //we will use priority queue
      priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
      pq.push({0,0});
      vector<int> visited(5,0);
      int sum1=0;
      while(!pq.empty())
      {
            int node=pq.top().second;
            int sum=pq.top().first;
            pq.pop();
            if(visited[node]==1)
            {
                  continue;
            }
            visited[node]=1;
            sum1+=sum;
            for(auto x:umap[node])
            {
                  int v=x.first;
                  int wt=x.second;
                  if(!visited[v])
                  {
                    
                        pq.push({wt,v});
                  }
            }
            
      }
      cout<<"Minimum sum is "<<sum1<<endl;





}
