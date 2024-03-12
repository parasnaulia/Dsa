#include<iostream>
using namespace std;
#include<bits/stdc++.h>
void Remove(stack<int> &st,int size,int count,int pp)
{
    if(size==count)
    {
        st.pop();
        st.push(pp);

        return;
    }
    int ele=st.top();
    st.pop();
    ++count;
    Remove(st,size,count,pp);
    st.push(ele);

}
int main()
{
    stack<int> ans;
    ans.push(1);
    ans.push(2);
    ans.push(3);
    ans.push(4);
     Remove(ans,4,1,0);
    cout<<"After Removing"<<endl;
   while(!ans.empty())
   {
    cout<<ans.top()<<" ";
    ans.pop();
   }
   
   

    return 0;

}
