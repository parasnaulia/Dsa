#include<iostream>
using namespace std;
#include<bits/stdc++.h>
void subset(vector<int> &nums,int index,vector<int> op,vector<vector<int>> &ans)
{
      if(index>=nums.size())
      {
            ans.push_back(op);
            for(int i=0;i<op.size();i++)
            {
                  cout<<op[i]<<" ";
            }
            cout<<endl;
            return;
      }
     
      subset(nums,index+1,op,ans);
       op.push_back(nums[index]);
      subset(nums,index+1,op,ans);
}
// void subset1(vector<int> &nums,int index,vector<int> output,vector<vector<int>> &ans)
// {

//     // if(index>=nums.size())
//     // {
//     //     ans.push_back(output);
//     //     return;
//     // }
//     // subset(nums,index+1,output,ans);
//     // int ele=nums[index];
//     // output.push_back(ele);
//     // subset(nums,index+1,output,ans);
// if(index>=nums.size())
// {
//     ans.push_back(output);
//     return;
// }
// output.push_back(nums[index]);
// subset1(nums,index+1,output,ans);
// output.pop_back();
// subset1(nums,index+1,output,ans);

    

// }
int main()
{
      vector<int> nums={1,2,3};
      vector<int> op;
      vector<vector<int>> ans;
      subset(nums,0,op,ans);
      sort(ans.begin(),ans.end());
      for(int i=0;i<ans.size();i++)
      {
           for(auto x:ans[i])
           {
            cout<<x<<" ";
           }
            cout<<endl;
      }
      return 0;
}