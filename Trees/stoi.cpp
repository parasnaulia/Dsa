#include<iostream>
using namespace std;
#include<bits/stdc++.h>
int main()
{
      // string s="123";
      // string s1="123";
      // cout<<"string concat"<<s+s1;
      // cout<<endl;
      // int x=stoi(s);
      // int y=stoi(s1);
      // cout<<x+y<<" after int co"<<endl;
      unordered_map<int,int> umap;
      umap[-3]=8;
      umap[0]=-1;
      umap[-1]=2;
      umap[-2]=3;
      umap[-2]=4;
//     for(auto i=umap.begin();i!=umap.end();i++)
//     {
//       cout<<umap[i]<<" ";
//     }
//cout<<umap[-1];
// vector<int> ans;
// for(auto x:umap)
// {
//       ans.push_back(x.first);

// }
// sort(ans.begin(),ans.end());
// // for(int i=0;i<ans.size();i++)
// // {
// //       cout<<ans[i]<<" ";
      
// // }
// for(int i=0;i<ans.size();i++)
// {
//       cout<<umap[ans[i]]<<endl;
// }
if(umap.find(0)==umap.end())
{
      cout<<"0 is present"<<endl;
}
else
{
      cout<<"sry"<<endl;
}

return 0;
}