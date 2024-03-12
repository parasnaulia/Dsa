#include <iostream>
using namespace std;
#include <bits/stdc++.h>
void edges(vector<vector<int>> &edge, int u, int v, int wt)
{
      vector<int> ans;
      ans.push_back(u);
      ans.push_back(v);
      ans.push_back(wt);
      edge.push_back(ans);
}
vector<vector<int>> creation(vector<vector<int>> &edges)
{
      vector<vector<int>> ans(5, vector<int>(5, INT_MAX));

      for (auto x : edges)
      {
            int u = x[0];
            int v = x[1];
            int wt = x[2];
            ans[u][v] = wt;
      }
      return ans;
}
void Floyds(vector<vector<int>> &ans)
{
      // for a via
      for (int k = 0; k <= 4; k++)
      {
            for (int i = 0; i <= 4; i++)
            {
                  for (int j = 0; j <= 4; j++)
                  {
                        ans[i][j] = min(ans[i][j], ans[i][k] + ans[k][j]);
                  }
            }
      }
}
int main()
{
      vector<vector<int>> edg;
      edges(edg, 0, 1, 3);
      edges(edg, 1, 2, 3);
      edges(edg, 2, 3, 4);
      edges(edg, 3, 4, 3);
      edges(edg, 1, 4, 3);
      int size = 4;
      // Hmeha we have top fo via a thik because its a brute force approach and its is finding evert path via a somting and finding the minimum
      vector<vector<int>> ans = creation(edg);
      for (int i = 0; i <= 4; i++)
      {
            for (int j = 0; j <= 4; j++)
            {
                  cout << ans[i][j] << " ";
            }
            cout << endl;
      }

      cout << endl;
      Floyds(ans);
      for (int i = 0; i <= 4; i++)
      {
            for (int j = 0; j <= 4; j++)
            {
                  if (i == j)
                  {
                        ans[i][j] = 0;
                  }
            }
            cout << endl;
      }

      cout << "After Floyds " << endl;
      for (int i = 0; i <= 4; i++)
      {
            for (int j = 0; j <= 4; j++)
            {
                  cout << ans[i][j] << " ";
            }
            cout << endl;
      }

      return 0;
}