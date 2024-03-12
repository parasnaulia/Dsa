#include<iostream>
using namespace std;
#include<bits/stdc++.h>
vector<long long int> solve(vector<int> ans,int K)
{
    int n=ans.size();
    long long int i=1;
    long long int j=1;
    deque<long long int> dq;
    vector<long long int> v;
     int maxi=INT_MIN;
    for(int i=0;i<K;i++)
    {
        maxi=max(maxi,ans[i]);

    }
    dq.push_back(maxi);
    j=K;
    while(j<n)
    {
         if(ans[j]<dq.front())
        {
            dq.push_back(ans[j]);
        }
       
         if(dq.empty())
        {
            vector<int> x;
            int maxi=INT_MIN;
            for(int k=i;k<=j;k++)
            {
                maxi=max(maxi,ans[k]);
            }
            dq.push_back(maxi);
        }
         

            if(j-i+1==K)
            {
                // if(dq.empty()==true)
                // {
                //     v.push_back(0);
                // }
                // else
               
                
                    v.push_back(dq.front());
                    if(dq.front()==ans[i])
                    {
                        dq.pop_front();
                    }
                    
                
                i++;
               
            }
            j++;

    }
    return v;
}

int main()
{
    vector<int> ans={-8, 2, 3, -6, 10};
     vector<long long int> v=solve(ans,2);
     cout<<"The ans is"<<endl;
     for(int i=0;i<v.size();i++)
     {
        cout<<v[i]<<" ";
     }
    return 0;
}