#include<iostream>
using namespace std;
#include<bits/stdc++.h>
int main()
{
      int n;
      int sum=0;
      cin>>n;
      for(int i=1;i<=10;i++)
      {
            cout<<n*i<<" ";
            sum+=n*i;

      }
      cout<<endl;
      cout<<sum;

}