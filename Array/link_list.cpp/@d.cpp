#include<iostream>
using namespace std;
#include<bits/stdc++.h>
 bool checkXMatrix(vector<vector<int>>& grid) {
        int x=grid.size();
        int y=grid[0].size();
        bool is_valid=false;
        int j=0;
        int p=0;
        int q=y-1;
        int i=0;
   vector<vector<bool>> visited(x, vector<bool> (x, false));

       while(i<x&&j<y)
       {
            visited[i][j]==true;
           if(grid[i][j]==0)

           {
               is_valid=true;
               break;
           }
          
           i++;
           j++;
       }
       while(p<x&&q>=0)
       {
            visited[p][q]=true;
           
           if(grid[p][q]==0)
           {
               is_valid=true;
               break;
           }
          
           p++;
           q--;
       }
       if(is_valid)
       {
           return false;
       }
       for(int i=0;i<x;i++)
       {
           for(int j=0;j<y;j++)
           {
               if((grid[i][j]!=0)&&(visited[i][j]==false))
               {
                   return false;
               }
           }
       }

return true;
 }
int main()
{
    vector<vector<int>> ans={{2,0,0,1},{0,3,1,0},{0,5,2,0},{4,0,0,2}};
  bool ans2=checkXMatrix(ans);
  cout<<ans2<<endl;
    return 0;


}