#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//printing the longest common sequence
vector<int> solve(string s)
{
    int i=0;
    int maxi=-1;
    int j=0;
    vector<int> ans;
    unordered_map<char,int> umap;
    while(j<s.length())

    {
        umap[s[j]]++;
        if(umap.size()==j-i+1)
        {
            if(maxi<j-i+1)
            {
                maxi=j-i+1;
                if(ans.size())
                {
                    ans.pop_back();
                    ans.pop_back();
                ans.push_back(i);
                ans.push_back(j);
                }
                else 
                {
                    ans.push_back(i);
                    ans.push_back(j);
                }
            }

        }
        else if(umap.size()<j-i+1)
        {
            while(umap.size()<j-i+1)
            {
                umap[s[i]]--;
                if(umap[s[i]]==0)
                {
                    umap.erase(s[i]);
                }
                i++;
            }
            
        }
        j++;


    }
    return ans;


}

int main()
{
    string s="geeksforgeeks";
    solve(s);
    vector<int> a=solve(s);
    cout<<"The Longest substring is:"<<endl;
    /*for(int i=0;i<a.size();i++)
    {
        cout<<a[i]<<" ";
    }
*/
int start=a[0];
int end=a[1];
for(int i=start;i<=end;i++)
{
    cout<<s[i]<<" ";
}
    return 0;
}