#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int solve(vector<int> &weight,vector<int> &value,int W,int index)
{
      if(index<0)
      {
            
            return 0;
      
      }
      int take=INT_MIN;
      if(W>=weight[index])
      {
            take=value[index]+solve(weight,value,W-weight[index],index);
      }
      int notTake=solve(weight,value,W,index-1);
      return max(take,notTake);


}
int solve1(vector<int> &weight, vector<int> &value, int W, int index) {
    if (index < 0) {
        if (W == 0) {
            return 1; // One way to fill the knapsack
        }
        return 0; // No way to fill the knapsack
    }
    
    int take = 0;
    if (W >= weight[index]) {
        take = solve(weight, value, W - weight[index], index);
    }
    
    int notTake = solve(weight, value, W, index - 1);
    
    return take + notTake; // Count the total number of ways
}


int main()
{
      vector<int> weight={2,4,6};
      vector<int> value={5,11,13};
      int n=3;
      int W=10;
      cout<<solve(weight,value,W,n-1);

}
