#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main()
{
      string s="paras-naulia";
      int count=0;
      for(int i=0;i<s.length();i++)
      {
            if(s[i]=='-')
            {
                  count++;
            }
      }
      string ans="";
      while(count)
      {
            ans+='-';
            count--;
      }
      for(int i=0;i<s.length();i++)
      {
            if(s[i]=='-')
            {
                  continue;
            }
            ans+=s[i];
      }
cout<<ans;
return 0;

}
