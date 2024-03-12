#include<iostream>
using namespace std;
#include<bits/stdc++.h>
int main()
{
    queue<int> q;
    q.push(2);
    q.push(3);
    q.push(4);
    vector<int> ans;
    cout<<q.size();
    while(!q.empty())
    {
        ans.push_back(q.front());
        q.pop();
    }
    cout<<endl;
    for(int i=0;i<ans.size();i++)
    {
        q.push(ans[i]);
    }
    cout<<endl;
    while(!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }

}
