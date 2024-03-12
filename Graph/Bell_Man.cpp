#include <iostream>
using namespace std;
#include <bits/stdc++.h>
void edges(vector<vector<int>> &edge, int u, int v, int wt)
{
      vector<int> ans;
      ans.push_back(u);
      ans.push_back(v);
      ans.push_back(wt);
      edge.push_back(ans);
}
vector<int> bellFord(vector<vector<int>> &edges,int size,vector<int> &dist)
{
      dist[1]=0;
      // In bell Ford we have to relax the edge vertex-1 times
      for (int i = 1; i <size;i++)
      {
            for(auto x:edges)
            {
                  int u=x[0];
                  int v=x[1];
                  int wt=x[2];
                  //Relaxation Each edges V-1 Times
                  if(dist[u]!=INT_MAX&&dist[u]+wt<dist[v])
                  {
                        dist[v]=dist[u]+wt;
                  }

            }
      }
      return dist;
}
int main()
{
      vector<vector<int>> edg;
      edges(edg, 1, 2, 3);
      edges(edg, 2, 3, 4);
      edges(edg, 3, 4, 3);
      edges(edg, 1, 4, 3);
      int size = 4;
      vector<int> dist(5,INT_MAX);
      vector<int>ans=bellFord(edg,size,dist);
      for(int i=1;i<ans.size();i++)
      {
            cout<<ans[i]<<" ";
      }
      return 0;
}
