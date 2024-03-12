#include<iostream>
using namespace std;
#include<bits/stdc++.h>
int minSubArrayLen(int target, vector<int>& nums) {
        int i=0;
        int j=0;
        long long sum=0;
        int mini=INT_MAX;
        while(j<nums.size())
        {
            sum+=nums[j];
            if(sum<target)
            {
                j++;
            }
            else if(sum==target)
            {
                mini=min(mini,(j-i+1));
                j++;

            }
            else if(sum>target)
            {
                while(sum>target)
                {
                    sum=sum-nums[i];
                    i++;
                }

            }
        }
        return mini;
    }
    int main()
    {
        vector<int> ans={1,4,4};
        int k=4;
       int x= minSubArrayLen(k,ans);
       cout<<x;
       return 0;
        
    }