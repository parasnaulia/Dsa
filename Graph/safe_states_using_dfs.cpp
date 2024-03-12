#include <iostream>
using namespace std;
#include <bits/stdc++.h>
vector<int> safe(8, 0);
void Mapi(unordered_map<int, vector<int>> &umap, int u, int v)
{
      umap[u].push_back(v);
      // umap[v].push_back(u);
}
bool dfs(int node, int parent, unordered_map<int, vector<int>> &adj, vector<int> &vis, vector<int> &path)
{
      vis[node] = 1;
      safe[node] = 0;
      path[node] = 1;
      for (auto i : adj[node])
      {
            if (!vis[i])
            {
                  if (dfs(i, node, adj, vis,path) == true)
                        return true;
            }
            else if (path[i]==1)
            {
                  return true;
            }
      }
      safe[node]=1;
path[node]=0;
      return false;
}

int main()
{
      unordered_map<int, vector<int>> umap;
      Mapi(umap, 1, 2);
      Mapi(umap, 1, 3);
      // Mapi(umap,2,3);
      Mapi(umap, 2, 4);
      Mapi(umap, 4, 5);
      Mapi(umap, 6, 7);
      bool is_valid = false;

      // Logic of Detect cycly using dfs
      vector<int> visited(8, 0);
      int par = -1;
      vector<int> path(8,0);

      for (int i = 1; i < 8; i++)
      {
            if (!visited[i])
            {
                  if (dfs(i, par, umap, visited,path) == true)
                  {
                        is_valid = true;
                  }
            }
      }
      for(int i=0;i<8;i++)
      {
            if(safe[i]==1)
            {
                  cout<<i<<" ";
            }cout<<endl;
      }
  
      if (is_valid)
      {
            cout << "Cycle is present" << endl;
      }
      else
      {
            cout << " cycle is Not present" << endl;
      }
      return 0;
}