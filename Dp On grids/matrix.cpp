// #include<iostream>
// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//        vector<int> ans={3,4,1,7,9};
//       // sort(ans.begin(),ans.end());
//        vector<int> ans1;
//        vector<int> ans2;

//        for(int i=0;i<ans.size();i++)
//        {
//             if(i%2==0)
//             {
//                   ans1.push_back(ans[i]);

//             }
//             else
//             {
//                   ans2.push_back(ans[i]);
//             }
//        }
//        sort(ans1.begin(),ans1.end());
//       sort(ans2.begin(),ans2.end());
//        int ans4=ans1[ans1.size()-2]+ans2[ans2.size()-2];
//        cout<<ans4;
//        return 0;




// }

#include<iostream>
using namespace std;
#include<bits/stdc++.h>
int main()
{
      string s="apples";
      char ch1='a';
      char ch2='p';
      string ans="";
      ans=s;
      for(int i=0;i<s.length();i++)
      {
            if(s[i]==ch1)
            {
                  ans[i]=ch2;

            }
            else if(s[i]==ch2)
            {
                  ans[i]=ch1;
            }
            
      }
      cout<<ans;
}