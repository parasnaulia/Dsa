#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int solve( string &s,int i,int j,bool is_true)

{
      if(i>j) return 0;
      if(i==j)
      {
            if(is_true==true)
            {
                  if(s[i]=='T')
                  {
                        return 1;
                  }
                  else{
                        return 0;
                  }
            }
            else {
                  if(s[i]=='F')
                  {
                        return 1;
                  }
                 else
                 {
                        return 0;
                  }
            }
      }
     
    
      int ways=0;
      for(int k=i+1;k<j;k+=2)
      {
            //Here We will Do the partition
            int lt=solve(s,i,k-1,true);
             int rt=solve(s,k+1,j,true);
            int lf=solve(s,i,k-1,false);
            int rf=solve(s,k+1,j,false);
           if (s[k] == '&') {
            if (is_true == true) {
                ways += lt * rt;
            } else {
                ways += lt * rf + lf * rt + lf * rf;
            }
           }
            else if(s[k]=='|')
            {
                  if(is_true)
                  {
                        ways+=lt*rf+lf*rt+lt*rt;
                  }
                  else
                  {
                        ways+=lf*rf;
                  }
            }
            else
            {
                  if(is_true)
                  {
                        ways+=lt*rf+lf*rt;
                  }
                  else
                  {
                        ways+=lf*rf+lt*rt;
                  }
            }
      }
      return ways;
}
int main()
{
      string s="F|T^F";
      cout<<solve(s,0,s.length()-1,true);

}