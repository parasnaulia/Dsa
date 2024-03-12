
#include<iostream>
using namespace std;
#include<bits/stdc++.h>

string maximumFrequency(string s){
        // Complete the function
       unordered_map<string,int>umap;
           string temp,result;
        vector<string>ans;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]==' ')
            {
                ans.push_back(temp);
                temp.clear();
            }
            else
            {
                temp+=s[i];
            }
        }
        ans.push_back(temp);
        for(int i=0;i<ans.size();i++)
        {
            umap[ans[i]]++;
        }
        int maxi=INT_MIN;
        for(auto x:umap)
        {
            if(maxi<x.second)
            {
                  maxi=x.second;
                s=x.first;
            }
        
        }
        
        return s;
    
    
}
int main()
{
      string s= "paras bhai ky yr paras ho paras tm bc paras";
      string ans=maximumFrequency(s);
      cout<<ans;
}