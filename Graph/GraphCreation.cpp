#include<iostream>
using namespace std;

#include<bits/stdc++.h>
// class graph
// {
//       public:
//       int n;
//       int m;
//        vector<vector<int>> adj[3][3];

     
//       graph(int x,int y)
//       {
//             m=x;
//             n=y;
            

//       }
//       void insertUndirected(int u,int v)
//       {
//            adj[u][v]=1;
//            adj[v][u]=1;


//       }
//       void print()
//       {
//             for(int i=0;i<n;i++)
//             {
//                   for(int j=0;j<adj[i].size();j++)
//                   {
//                         cout<<adj[i][j]<<" ";
//                    }
//                   cout<<endl;
//             }
//       }

// };
void Unorder(vector<int> adj[],int u,int v)
{
      adj[u].push_back(v);
      adj[v].push_back(u);

}
void print(vector<int> adj[],int v)


{
      for(int i=0;i<v;i++)
      {
            for(auto y:adj[i])
            {
                  cout<<y<<" ";
            }
            cout<<endl;
      }
}
void Matrix(vector<vector<int>> &mat,int row,int col)
{
      mat[row][col]=1;
      mat[col][row]=1;


}
void UnorderList(unordered_map<int,vector<int>> &umap,int u,int v)
{
      umap[u].push_back(v);
      umap[v].push_back(u);
}
void  Mapi(unordered_map<int,vector<int>> umap,int nodes)
{
      for(int i=0;i<nodes;i++)
      {
            for(auto x:umap[i])
            {
                  cout<<x<<" ";
            }
            cout<<endl;
      }
}
void dfs(unordered_map<int,vector<int>> &umap,vector<int>&visited,int node)
{
      visited[node]=1;
      cout<<node;
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
     
      // graph g(3,3);
      // g.insertUndirected(0,3);
      // g.insertUndirected(3,1);
      // g.insertUndirected(1,2);
      // g.print();
      // int v=5;
      // vector<int> adj[5];
      // Unorder(adj,1,2);
      //  Unorder(adj,0,1);
      //   Unorder(adj,0,3);
      //   Unorder(adj,3,4);

      // cout<<"before"<<endl;
      // print(adj,5);
      //Printing in 2d Way
      
      // for(int i=0;i<v;i++)
      // {
      //       ans[i].push_back(i);

      //       for(int j=0;j<adj[i].size();j++)
      //       {
      //             ans[i].push_back(adj[i][j]);

      //       }
      // }
//       int m=5;
//       int n=5;
// vector<vector<int>> ans(n, vector<int> (m, 0));
//       Matrix(ans,1,4);
//       Matrix(ans,2,1);
//       Matrix(ans,3,1);
//       Matrix(ans,2,4);
//       Matrix(ans,3,4);
//       for(int i=0;i<n;i++)
//       {
            

//             for(int j=0;j<m;j++)
//             {
//                   cout<<ans[i][j]<<" ";

//             }
//             cout<<endl;
//       }


//Using map
int n=5;
int m=6;
vector<int> visited(n,0);
unordered_map<int,vector<int>> umap;
UnorderList(umap,0,1);
UnorderList(umap,1,2);
UnorderList(umap,0,3);
UnorderList(umap,3,4);
//Mapi(umap,5);
dfs(umap,visited,0);

      return 0;
}