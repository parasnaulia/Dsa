	#include<iostream>
using namespace std;
#include<bits/stdc++.h>
    
    
    string FirstNonRepeating(string A){
		    // Code here
		    string s="";
		    unordered_map<char,int> umap;
		    
		    for(int i=0;i<s.length();i++)
		    {
		        umap[A[i]]++;
		        
		    }
		    s+=A[0];
		    for(int i=1;i<A.length();i++)
		    {
		        if(A[i]==A[i-1])
		        {
		            s+="#";
		        }
		        else
		        {
		            if(umap[A[i-1]]==1)
		            {
		                s+=A[i-1];
		            }
		            else
		            {
		                s+=A[i];
		            }
		        }
		    }
		    
		    
		    
		    return s;
		}
        int main()
        {
            string a="aabc";
            string ans=FirstNonRepeating(a);
            cout<<ans;
            return 0;

        }