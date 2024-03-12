#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int> solve(vector<int> nums,int k)
{
    int i=0;
    int j=0;
    deque<int> dq;
    vector<int> ans;
    while(j<nums.size())
    {
        while(dq.size()>0&&nums[j]>dq.back())
        {
            dq.pop_back();
        }
        dq.push_back(nums[j]);
        if(j-i+1==k)
        {

            ans.push_back(dq.front());
            if(dq.front()==ans[i])
            {
                dq.pop_front();
                
            }
            i++;
        }
        j++;


    }
    return ans;
}
vector<int> solve1(vector<int> nums,int k)
{
    int i=0;
    int j=0;
    deque<int> dq;
    vector<int> ans;
    while(j<nums.size())
    {
        while(dq.size()>0&&nums[j]<dq.back())
        {
            dq.pop_back();
        }
        dq.push_back(nums[j]);
        if(j-i+1==k)
        {

            ans.push_back(dq.front());
            if(dq.front()==ans[i])
            {
                dq.pop_front();
                
            }
            i++;
        }
        j++;


    }
    return ans;
}
int main()
{
    vector<int> nums={2,-3,-4,-7,8};
    vector<int> small=solve1(nums,2);
    vector<int> larger=solve(nums,2);
    vector<int> sum;
    cout<<"Small"<<endl;
    for(int i=0;i<small.size();i++)
    {
        cout<<small[i]<<" ";
    }
    cout<<endl;
    cout<<"Larger"<<endl;
      for(int i=0;i<small.size();i++)
    {
        cout<<larger[i]<<" ";
    }
    cout<<endl;
    cout<<"Sum is"<<endl;
    for(int i=0;i<small.size();i++)
    {
        sum.push_back(larger[i]+small[i]);
    }
     for(int i=0;i<sum.size();i++)
 {
        cout<<sum[i]<<" ";
     }
    return 0;


}