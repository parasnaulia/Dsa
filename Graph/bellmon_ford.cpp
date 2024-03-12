#include<iostream>
using namespace std;
#include<bits/stdc++.h>

int main()
{
//       unordered_map<int,vector<pair<int,int>>> umap;
// umap[1].push_back({2,1});
//       umap[1].push_back({3,2});
//       umap[2].push_back({3,-6});
vector<vector<int>> nums={{1,2,3},{2,3,4},{3,1,-9}};

int V=4;
vector<int> distance(V,INT_MAX);
distance[1]=0;

for(int i=0;i<V-1;i++)
{
     for(auto x:nums)
      {
            int u=x[0];
            int v=x[1];
            int wt=x[2];

            if(distance[u]+wt<distance[v]&&distance[u]!=INT_MAX)
            {
                  distance[v]=distance[u]+wt;
            }
      }


}

bool is_valid=false;

//For Finding the Nagitive edge cycle
for(auto x:nums)
{
      int u=x[0];
      int v=x[1];
      int wt=x[2];
      if(distance[u]+wt<distance[v]&&distance[u]!=INT_MAX)
      {
            is_valid=true;
           
      }
}
if(is_valid)
{
      cout<<"cycle is present"<<endl;
}
else
{
      cout<<"Not Present"<<endl;
}



}