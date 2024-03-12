#include<iostream>
using namespace std;
#include<bits/stdc++.h>
vector<int> ans;
void Mapi(unordered_map<int,vector<int>> &umap,int u,int v)
{
      umap[u].push_back(v);
      umap[v].push_back(u);

}
void dfs(unordered_map<int,vector<int>> &umap,vector<int>&visited,int node)
{
      visited[node]=1;
      ans.push_back(node);
      for(auto x:umap[node])
      {
            if(!visited[x])
            {
                  dfs(umap,visited,x);
            }
      }
}
int main()
{
      int n=7;
      int m=6;
      vector<int> visited(n,0);
      unordered_map<int,vector<int>> umap;
      Mapi(umap,1,2);
      Mapi(umap,1,3);
      Mapi(umap,2,4);
       Mapi(umap,4,5);
      dfs(umap,visited,1);
      for(int i=0;i<ans.size();i++)
      {
            cout<<ans[i]<<" ";
      }
      cout<<endl;

      



      return 0;
}
