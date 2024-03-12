#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int>& a1, vector<int>& a2) {
    vector<int> ans;
    for(int i=0;i<a1.size();i++)
    {
        int x=0;
        bool is_valid=false;
        while(x<=a1[i])
        {
           int y=a1[i]-x;
           if((x^y)==a2[i])
           {
            is_valid=true;
            break;

           }
           x++; 
        
        }
        if(is_valid)
        {
            int pp=2*x+3*(a1[i]-x);
            ans.push_back(pp);
        }
        else 
        {
            ans.push_back(0);
        }


    }
    return ans;
}

int main() {
    vector<int> a1 = {29, 36, 57};
    vector<int> a2 = {25, 18, 3};
    
    vector<int> result = solve(a1, a2);
    
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
cout<<endl;
cout<<"Hogya Bhenchod"<<endl;
}