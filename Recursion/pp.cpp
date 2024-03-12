#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int main() {
	
	int num;
	cin >> num; 
	int A[num];
	int sum=0;
	int count=0;
	//sort(A,A+num);
	for(int i=0;i<num;i++)
	{
		if(A[i]>=0)
		{
			sum+=A[i];
			count++;
		}

	}
	cout<<sum;
	cout<<count;
	   

	   }