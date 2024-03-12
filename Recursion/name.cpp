#include<iostream>
using namespace std;
#include<bits/stdc++.h>
// void name(int n)
// {
//       if(n<=0)
//       {
//             return;
//       }
//       cout<<"Paras"<<endl;
//       name(n-1);
// }
void name1(int n)
{
      if(n<=0)
      {
            return;
      }
       cout<<n<<endl;
      name1(n-1);
     
}
void name2(int n,int i)
{
      if(i>n)
      {
            return;
      }
       
      name2(n,i+1);
      cout<<i<<endl;
     
}
int main()
{
      int n=4;
      // cout<<"Enter Th value of n"<<endl;
      // cin>>n;
     // name(n);
//      name1(n);
     name2(n,1);
     
      return 0;
}