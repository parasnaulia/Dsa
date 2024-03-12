#include<iostream>
using namespace std;
#include<bits/stdc++.h>
void init(vector<int> &rank,vector<int>&par)
{
      for(int i=0;i<5;i++)
      {
            rank[i]=0;
            par[i]=i;
      }
}
int find_par(vector<int> &par,int node)
{
      if(par[node]==node)
      {
            return node;
      }
      return  par[node]=find_par(par,par[node]);
}
void union1(vector<int> &par,vector<int> &rank,int u,int v)
{
      int par1=find_par(par,u);
      int par2=find_par(par,v);
      if(rank[par1]<rank[par2])
      {
            par[par1]=par2;
      }
      else if(rank[par1]>rank[par2])
      {
            par[par2]=par1;
      }
      else
      {
            par[par1]=par2;
            rank[par2]++;
      }
}
int main()
{
         vector<pair<int,pair<int,int>>> umap;
      umap.push_back({1,{0,1}});
      umap.push_back({2,{0,2}});
      umap.push_back({2,{1,3}});
      umap.push_back({2,{3,4}});
        umap.push_back({4,{4,4}});
      //  unordered_map<int,vector<pair<int,int>>> umap;
      // umap[0].push_back({2,1});
      // umap[0].push_back({3,2});
      // umap[1].push_back({ 1,4});
      // umap[4].push_back({3,3});
      // umap[2].push_back({2,3});
      sort(umap.begin(),umap.end());
      vector<int> rank(5);
      vector<int> par(5);
      int sum=0;
     init(rank,par);
     vector<pair<int,int>> ans;
            
            for(auto x:umap)
            {
                  int u=x.second.first;
                  int v=x.second.second;
                  int wt=x.first;
                  int u1=find_par(par,u);
                  int v1=find_par(par,v);
                  if(v1!=u1)
                  {
                          sum+=wt;  
                          ans.push_back({u,v});
                      union1(par,rank,u1,v1);
                    
                  }
            }
      
      
      cout<<"The sum is "<<sum<<endl;
      cout<<endl;

      //printing The edges of minimum spanning tree
      for(int i=0;i<ans.size();i++)
      {
            cout<<ans[i].first<<","<<ans[i].second<<" "<<endl;
      }
      cout<<"Now this ends  The algo"<<endl;
      

return 0;

}