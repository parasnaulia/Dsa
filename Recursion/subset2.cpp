#include<iostream>
using namespace std;
//it is also the power set
//in this cae you have print the unique ele
#include<bits/stdc++.h>
void subset(vector<int> &nums,int index,vector<int> op,set<vector<int>> &ans)
{
      if(index>=nums.size())
      {
            ans.insert(op);
            
            return;
      }
     
      subset(nums,index+1,op,ans);
       op.push_back(nums[index]);
      subset(nums,index+1,op,ans);
}
int main()
{
      vector<int> nums={1,2,2};
      vector<int> op;
      set<vector<int>> ans;
      subset(nums,0,op,ans);
     // sort(ans.begin(),ans.end());
      set<int>::iterator itr;
  for ( auto vec : ans) {
        
        for (int num : vec) {
            cout << num << " ";
        }
        std::cout << std::endl;
    }
      return 0;
}

//Here the complexity is a dominating factor because for insertion in srt you need logn time complexity
