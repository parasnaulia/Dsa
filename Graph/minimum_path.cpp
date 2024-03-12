#include<iostream>
using namespace std;
#include<bits/stdc++.h>
int main()
{
      unordered_map<int,vector<pair<int,int>>> umap;
      priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

      umap[0].push_back({1,1});
      umap[1].push_back({0,1});
      umap[1].push_back({2,2});
      umap[2].push_back({1,2});
       umap[2].push_back({4,2});
        umap[4].push_back({3,2});
    //  queue<pair<int,int>> q;
      int src=0;
      pq.push({0,src});
      vector<int> distance(5,INT_MAX);
      distance[0]=0;
      vector<int> par(5);
      for(int i=0;i<5;i++)
      {
            par[i]=i;
      }
      while(!pq.empty())
      {
            auto node=pq.top().second;
           
            pq.pop();
            for(auto x:umap[node])
            {
                   auto wt=x.second;
                  int v=x.first;
                 //Relaxation part
                 
                  if(distance[node]+wt<distance[v])
                  {
                        distance[v]=distance[node]+wt;
                        pq.push({distance[v],v});
                        par[v]=node;
                  }
            }
      }
      for(int i=0;i<par.size();i++)
      {
            cout<<par[i]<<" ";
      }
      cout<<endl;
      return 0;





}