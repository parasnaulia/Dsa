#include<iostream>
using namespace std;
#include<bits/stdc++.h>
bool is_valid(vector<vector<int>> &grid,vector<vector<int>> &distance,int i,int j,int n,int m,int dis)
{
      if(i>=0&&i<n&&j>=0&&j<m&&grid[i][j]==1&&1+dis<distance[i][j])
      {
            return true;
      }
      return false;
}
int main()
{
      int m=5;
      int n=5;
     vector<vector<int>> grid = {{1, 0, 1},
            {1, 0, 1},
            {1, 1, 1},
            {1, 1,1},
            {1, 0, 0}};
            int ans=0;
            vector<vector<int>> distance(5,vector<int> (5,INT_MAX));
            int x=0;
            int y=0;
            distance[x][y]=0;
           queue<pair<int,pair<int,int>>> q;
           q.push({0,{x,y}});
           int x1=4;
           int y1=0;
           while(!q.empty())
           {
            int dist=q.front().first;
            int i=q.front().second.first;
            int j=q.front().second.second;
            q.pop();
            if(is_valid(grid,distance,i+1,j,m,n,dist))
            {
                  distance[i+1][j]=1+dist;
                  q.push({1+dist,{i+1,j}});
                  if(i+1==x1&&j==y1)
                  {
                        ans=1+dist;
                        break;
                        
                  }
            }
            if(is_valid(grid,distance,i-1,j,m,n,dist))
            {
                  distance[i-1][j]=1+dist;
                  q.push({1+dist,{i-1,j}});
                  if(i-1==x1&&j==y1)
                  {
                        ans=1+dist;
                        break;
                        
                  }
            }
            if(is_valid(grid,distance,i,j+1,m,n,dist))
            {
                  distance[i][j+1]=1+dist;
                  q.push({1+dist,{i,j+1}});
                  if(i==x1&&j+1==y1)
                  {
                        ans=1+dist;
                        break;
                        
                  }
            }
            if(is_valid(grid,distance,i,j-1,m,n,dist))
            {
                  distance[i][j-1]=1+dist;
                  q.push({1+dist,{i,j-1}});
                  if(i==x1&&j-1==y1)
                  {
                        ans=1+dist;
                        break;
                        
                  }
            }
           }
         
      cout<<"The MiniMum path is"<<endl;
      cout<<ans;




}