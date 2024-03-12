#include<iostream>
using namespace std;
#include<bits/stdc++.h>
void Mapi(unordered_map<int,vector<int>> &umap,int u,int v)
{
      umap[u].push_back(v);
      umap[v].push_back(u);

}
 bool dfs(int node, int parent, unordered_map<int,vector<int>> &adj, vector<int> &vis) {
        vis[node] = 1;
        
        for(auto i: adj[node]) {
            if(!vis[i]) {
                if(dfs(i, node, adj, vis) == true) return true;
            }
            else if(i != parent&&vis[i]==1) {
                return true;
            }
        }
        
        return false;
    } 
    
   

int main()
{
      unordered_map<int,vector<int>> umap;
      Mapi(umap,1,2);
      Mapi(umap,1,3);
      // Mapi(umap,2,3);
      Mapi(umap,2,4);
       Mapi(umap,4,5);
       Mapi(umap,2,3);
       Mapi(umap,6,7);
bool is_valid=false;
       //Logic of Detect cycly using dfs
       vector<int> visited(8,0);
       int par=-1;

       for(int i=1;i<8;i++)
       {
            if(!visited[i]){
       if(dfs(i,par,umap,visited)==true)
       {
            is_valid=true;
       }
            }
       }
       if(is_valid)
       {
            cout<<"Cycle is present"<<endl;
       }
       else
       {
            cout<<" cycle is Not present"<<endl;
       }
       return 0;


}