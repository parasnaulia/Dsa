     #include<iostream>
using namespace std;
#include<bits/stdc++.h>
int main()
{
       vector<int> arr={4,2,3};
      int k=2;
      int n=arr.size();
     
    
    	vector<vector<int>> dp(n,vector<int> (k+1,0));
	//Initializing The base condition
	for(int i=0;i<n;i++)
	{
		dp[i][0]=1;
	}
	//dp[0][arr[0]]=1;
	if(arr[0]<=k) dp[0][arr[0]]=1;
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<=k;j++)
		{
			int take=0;
			if(j>=arr[i])
			{
				take=dp[i-1][j-arr[i]];
			}
			int notTake=dp[i-1][j];
			dp[i][j]=(take+notTake);
		}
	}
for(int i=0;i<dp.size();i++)
{
      for(int j=0;j<dp[0].size();j++)
      {
            cout<<dp[i][j]<<" ";
      }
      cout<<endl;
}


}