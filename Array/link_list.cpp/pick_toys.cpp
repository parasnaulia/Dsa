#include<iostream>
using namespace std;
#include<bits/stdc++.h>
int solve(vector<int> nums)
{
    int i=0;
    int j=0;
    unordered_map<int,int> umap;
    int maxi=INT_MIN;
    while(j<nums.size())
    {
        umap[nums[j]]++;
        if(umap.size()<=2)
        {
            maxi=max(maxi,j-i+1);

        }
        else if(umap.size()>2)
        {
            while(umap.size()>2)
            {
                umap[nums[i]]--;
                if(umap[nums[i]]==0)
                {
                    umap.erase(nums[i]);
                }
                i++;
            }
        }
        j++;
    }
    return maxi;


}
int main()
{
vector<int> p={0,1,2,2};
int ans=solve(p);
cout<<"The ans is:"<<endl;
cout<<ans;
return 0;

}