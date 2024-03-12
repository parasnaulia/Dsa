#include<iostream>
#include<bits/stdc++.h> 
using namespace std;
int solve(int arr[],int size,int largest)
{
    priority_queue <int, vector<int>, greater<int> > mx;
    for(int i=0;i<size;i++)
    {
        mx.push(arr[i]);
        if(i>=largest)

        {
            mx.pop();


        }
    }
 return mx.top();

}
int main()
{
    int arr[5]={2,4,5,6,7};
   int ans= solve(arr,5,4);
    cout<<"The 3rd largest ele in the is "<<ans<<endl;
    return 0;
}