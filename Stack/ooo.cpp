#include<iostream>
using namespace std;
#include<bits/stdc++.h>
void deleteMid(stack<int>&s, int n)
    {
        stack<int> ans;
        if(n%2!=0)
        {
            int mid=((n+1)/2);
            while(!(mid==n))
            {
                ans.push(s.top());
                s.pop();
                mid++;
                
            }
        }
        else
        {
            int mid=(n/2);
            while(!(mid==n))
            {
                ans.push(s.top());
                s.pop();
                mid++;
            }
        }
       s.pop();
      while(!ans.empty())
      {
          s.push(ans.top());
          ans.pop();
      }
        
        
         
    }
int main()
{
    stack<int> s;
    for(int i=0;i<4;i++)
    {
        s.push(i);
    }
    deleteMid(s,5);
 while(!(s.empty()))
 {
    cout<<s.top();
    s.pop();
 }
 return 0;
}
