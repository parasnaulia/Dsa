#include<iostream>
using namespace std;
#include<bits/stdc++.h>
vector<int> ans;
void Mapi(unordered_map<int,vector<int>> &umap,int u,int v)
{
      umap[u].push_back(v);
      umap[v].push_back(u);

}
void bfs(unordered_map<int,vector<int>> umap,vector<int> &visited,int node )
{
      visited[node]=1;
      queue<int> q;
      q.push(node);
      while(!q.empty())
      {
            int temp=q.front();
            q.pop();
           
            ans.push_back(temp);
      for(auto x:umap[temp])
      {
          if(!visited[x])
          {
            visited[x]=1;
            q.push(x);
          }

      }
      }


}
int main()
{
       int n=8;
      int m=6;
      vector<int> visited(8,0);
      unordered_map<int,vector<int>> umap;
      Mapi(umap,1,2);
      Mapi(umap,1,3);
      Mapi(umap,2,4);
       Mapi(umap,4,5);
       Mapi(umap,6,7);
       for(int i=1;i<8;i++)
       {
            if(!visited[i]){
             bfs(umap,visited,i);
            }

       }
      
       cout<<"Bfs traversal"<<endl;
       for(int i=0;i<ans.size();i++)
       {
            cout<<ans[i]<<" ";

       }
       cout<<endl;

      return 0;
}