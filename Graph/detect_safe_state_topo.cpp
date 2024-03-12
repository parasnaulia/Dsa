//we can use dfs directlr as we have done but we can also use topo sort because we know that topo does not work for a cycles seo we can just reverse a graph and apply toposort
#include<iostream>
using namespace std;
#include<bits/stdc++.h>
void Topo(unordered_map<int,vector<pair<int,int>>> &umap,vector<int> &visited,stack<int> &st,int node)
{
      visited[node]=1;
      for(auto x: umap[node])
      {
           
            if(visited[x.first]==0)
            {
                  Topo(umap,visited,st,x.first);

            }
      }
      st.push(node);

}

int main()
{
      unordered_map<int,vector<pair<int,int>>> umap;
      umap[0].push_back({2,1});
      umap[0].push_back({3,3});
      umap[2].push_back({4,2});
      umap[3].push_back({4,4});
      //Now Applying Topological sort
      vector<int> visited(5,0);
      stack<int> st;
      vector<int> distance(5,INT_MAX);
distance[0]=0;
int count=0;

      Topo(umap,visited,st,0);
      //Now We Get a TopoSorted Array
      while(!st.empty())
      {
            int node=st.top();
            st.pop();
            for(auto x:umap[node])
            {
                 
                  int u=node;
                  int v=x.first;
                  int sum=x.second;
                  if(distance[u]+sum<distance[v])
                  {
                        distance[v]=distance[u]+sum;
                  }
                  
            }
            
     }
     for(int i=0;i<distance.size();i++)
     {
      if(distance[i]==INT_MAX)
      {
            distance[i]=-1;
      }
     }
     for(int i=0;i<distance.size();i++)
     {
      cout<<distance[i]<<" ";
     }
     cout<<endl;
     cout<<count;

}