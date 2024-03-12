#include<iostream>
using namespace std;
#include<bits/stdc++.h>
stack<int> st;
void dfs(unordered_map<int,vector<int>> &umap,vector<int> &vis,int node)
{
      vis[node]=1;
      for(auto x: umap[node])
      {
            if(!vis[x])
            {
                  dfs(umap,vis,x);
            }
      }
      st.push(node);
      return;
}
void create(unordered_map<int,vector<int>> &umap,int u,int v)
{
      umap[u].push_back(v);
      
}

int main()
{
      unordered_map<int,vector<int>> umap;
      create(umap,1,2);
      create(umap,2,3);
      create(umap,3,4);
      create(umap,3,5);
      create(umap,2,4);
      // for(int i=1;i<=umap.size();i++)
      // {
      //       for(auto x:umap[i])
      //       {
      //             cout<<x<<" ";
                  
      //       }cout<<endl;
      // }
      int n=5;
      vector<int> vis(6,0);
      dfs(umap,vis,1);
      while(!st.empty())
      {
            cout<<st.top();
            st.pop();
      }
return 0;

}