#include<iostream> 
using namespace std;
#include<bits/stdc++.h>
int main()
//Toposort is a linear arrgemnet of a node in which if there is an edge b/w u->v
//Then u will always comes before v;
//in this we have used bfs approach 

{
      unordered_map<int,vector<int>> umap;
      umap[0].push_back(1);
      umap[1].push_back(2);
      umap[0].push_back(3);
      umap[3].push_back(2);
      //Applying khnas algo
       int V=4;
       vector<int> indegree(V,0);
      for(int i=0;i<V;i++)
      {
            for(auto x:umap[i])
            {
                  indegree[x]++;

            }

      }
      queue<int> q;
      for(int i=0;i<indegree.size();i++)
      {
            if(indegree[i]==0)
            {
                  q.push(i);
            }

      }
      vector<int> ans;
      while(!q.empty())
      {
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto x: umap[node])
            {
                  indegree[x]--;
                  if(indegree[x]==0)
                  {
                        q.push(x);
                  }
            }
      }
      cout<<"Printing Topo Using khans algo"<<endl;
      for(int i=0;i<ans.size();i++)
      {
            cout<<ans[i]<<" ";
      }
      cout<<endl;


return 0;
}