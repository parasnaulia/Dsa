//since we know that topsort is not valid for Cycles and cyclic GArph. its is only valid in 
//Dag sowe can use this concept here 
//
#include<iostream> 
using namespace std;
#include<bits/stdc++.h>
int main()
//Toposort is a linear arrgemnet of a node in which if there is an edge b/w u->v
//Then u will always comes before v;
//in this we have used bfs approach 

{
 unordered_map<int,vector<int>> umap;
      umap[1].push_back(2);
      umap[2].push_back(3);
      umap[3].push_back(4);
            umap[4].push_back(1);
      

     // umap[3].push_back(2);
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
      bool is_valid=true;
      for(int i=0;i<indegree.size();i++)
      {
            if(indegree[i]!=0)
            {
              is_valid=false;
            }
      }
if(is_valid)
{
      cout<<"no"<<endl;
}
else 
{
      cout<<" ya"<<endl;
}

      
    
}
      