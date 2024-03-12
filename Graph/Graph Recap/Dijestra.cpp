#include <iostream>
using namespace std;
#include <bits/stdc++.h>
void creation(unordered_map<int, vector<pair<int, int>>> &umap, int u, int v, int wt)
{
      umap[u].push_back({v, wt});
}
vector<int> Dikjestra(unordered_map<int, vector<pair<int, int>>> &umap, int s, int size)
{
      priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
      pq.push(make_pair(0, s));
      vector<int> dist(size, 1e9);
      dist[s] = 0;
      while (!pq.empty())
      {
            auto node = pq.top();
            pq.pop();

            int u = node.second;
            for (auto x : umap[u])
            {
                  int wt = x.second;
                  int v = x.first;
                  if (dist[u] + wt < dist[v])
                  {
                        dist[v] = dist[u] + wt;
                        pq.push(make_pair(dist[v], v));
                  }
            }
      }
      return dist;
}
int main()
{
      unordered_map<int, vector<pair<int, int>>> umap;
      creation(umap, 1, 2, 1);
      creation(umap, 1, 3, 2);
      creation(umap, 2, 4, 2);
      creation(umap, 3, 6, 1);
      creation(umap, 4, 5, 3);
      creation(umap, 6, 5, 5);
      vector<int> ans = Dikjestra(umap, 1, 6);
      for (int i = 1; i < ans.size(); i++)
      {
            cout << ans[i] << " ";
            
      }
}
